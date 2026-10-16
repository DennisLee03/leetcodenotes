# LeetCode LLM Wiki — Schema

This repo is an **LLM-maintained knowledge base for our LeetCode practice**, based on Karpathy's "LLM Wiki" idea.
Instead of digging through our notes every time we ask a question (RAG), each note we write is "compiled" by the LLM into a persistent, interlinked markdown wiki, so knowledge compounds over time.

- **Humans**: solve problems, write code and notes in `notes/`, ask questions, set direction.
- **LLM (you)**: do all the bookkeeping — summarizing, categorizing, cross-linking, tracking weaknesses, maintaining the index and log.

This file is the schema. It defines structure, conventions, and workflows; the users and the LLM evolve it together.

---

## 1. Three-Layer Architecture

```
notes/                   # Layer 1: sources — OWNED BY HUMANS
  _template.md           # copy this to start a new note
  <member>/
    <NNNN>-<slug>.md     # one file per member per problem; re-attempts appended inside
  assets/                # screenshots, hand-drawn diagrams, etc.
wiki/                    # Layer 2: owned and maintained by the LLM
  index.md               # catalog of every page (read first when answering queries)
  log.md                 # chronological log (append-only)
  overview.md            # big picture: progress, pattern coverage, overall observations
  problems/<NNNN>-<slug>.md      # one page per problem
  patterns/<pattern-slug>.md     # solving patterns: sliding-window, two-pointers, monotonic-stack…
  concepts/<concept-slug>.md     # data structures / algorithms / language tricks: heap, union-find, python-bisect…
  members/<member>.md            # per member: progress, strengths/weaknesses, recurring mistakes, review queue
  insights/<slug>.md             # filed-back query answers: comparisons, syntheses, study plans
CLAUDE.md                # Layer 3: the schema (this file)
```

### Rules
- `notes/` belongs to the humans. They write and edit it freely. The LLM **reads it but never edits it**. Only exception: when a user pastes code in chat and asks you to save it, you may *create* the note file (or append a new attempt) on their behalf, copying their code and words verbatim.
- `wiki/` is written and maintained entirely by the LLM; users read it and don't edit it by hand (they ask the LLM instead).
- All wiki content is written in **English**. Notes may be in any language; quote them faithfully when citing.
- Link between pages with **relative markdown links** (e.g. `[Sliding Window](../patterns/sliding-window.md)`) so they work on both GitHub and Obsidian.
- Filenames are kebab-case; problem numbers are zero-padded to 4 digits (`0003-longest-substring-without-repeating-characters`).
- Member names are lowercase handles (e.g. `hehsun`); create `wiki/members/<member>.md` on first appearance.

---

## 2. Page Formats

### 2.1 Note `notes/<member>/<NNNN>-<slug>.md` (human-written)

Format lives in `notes/_template.md`. Frontmatter is what the LLM relies on; everything else is free-form.

```markdown
---
problem: 3
title: Longest Substring Without Repeating Characters
difficulty: Medium
url: https://leetcode.com/problems/longest-substring-without-repeating-characters/
---

## Attempt 1 — 2026-10-16
result: AC            # AC | WA | TLE | MLE | RE | unfinished
language: python
time_spent: 35m       # optional
used_hint: false      # looked at hints / editorial?

​```python
...
​```

### Notes
(approach, where you got stuck, takeaways, questions — any language, any length)

## Attempt 2 — 2026-10-23
...
```

- Re-solving a problem later → add a new `## Attempt N — <date>` section to the same file.
- Members may freely edit earlier attempts; the LLM re-reads the whole file on each ingest.
- Missing fields: infer what you can (problem metadata, language); ask about `result` / `used_hint` if they matter and aren't stated.

### 2.2 Problem page `wiki/problems/<NNNN>-<slug>.md`

```markdown
---
id: 3
title: Longest Substring Without Repeating Characters
difficulty: Medium
url: https://leetcode.com/problems/...
patterns: [sliding-window]
concepts: [hash-map]
solved_by: [hehsun]
last_updated: 2026-10-16
---

# 0003. Longest Substring Without Repeating Characters

## Problem (one or two sentences)
## Key Insight          # the "aha" of the problem, ideally one sentence
## Solutions
### Solution A: <name> (by @member, YYYY-MM-DD)
- Idea / complexity: Time O(?) Space O(?)
- Condensed code or key snippet
- Link to the member's note: [note](../../notes/<member>/<NNNN>-<slug>.md)
### Solution B: …
## Pitfalls / Common Mistakes   # distilled from members' WA/TLE attempts
## Related Problems             # same pattern or variants, with links
## Attempt History              # table: Date | Member | Attempt | Result | Language | Note link
```

### 2.3 Pattern / Concept pages
- **Definition and signals** (which problem features should make you think of it)
- **Template code** (the cleanest version distilled from members' actual code)
- **Variants and details** (boundaries, off-by-one, when to shrink the window…)
- **Problems in this wiki that use it** (sorted by difficulty, one line each on how it's used)
- **Common mistakes by members**

### 2.4 Member page `wiki/members/<member>.md`
- Stats: problems solved (Easy/Medium/Hard), count per pattern
- Strengths / weaknesses (with evidence: cite specific problems)
- Recurring mistake patterns (e.g. "often gets binary search boundaries wrong")
- **Review queue**: table `Problem | Last attempt | Result | Next review | Reason`
  - Simple spaced repetition: AC without hints → +7 days; AC with hints → +3 days; not passed → +1 day; AC again on review → double the interval.

### 2.5 index.md
Lists **every** wiki page by category: `- [Title](path) — one-line summary | metadata`. Categories: Overview / Members / Patterns / Concepts / Problems (by number) / Insights.

### 2.6 log.md (append-only)
Each entry uses a fixed heading format so `grep "^## \[" wiki/log.md` works:

```
## [2026-10-16] ingest | 0003 Longest Substring… | hehsun
- Created: problems/0003-…, patterns/sliding-window
- Updated: members/hehsun, index, overview
- Notes: …
```
Types: `ingest` / `query` / `lint` / `review` / `schema`.

---

## 3. Workflows

### 3.1 Ingest (process new or changed notes)
Triggered by `/ingest`, "ingest my notes", or a user pasting code in chat.

0. **Find what to ingest.**
   - User named a file or pasted code → that one. If pasted, first save it to `notes/<member>/<NNNN>-<slug>.md` (create, or append a new attempt) per §2.1, verbatim.
   - Otherwise → pending notes = files under `notes/` that are new or modified since they were last ingested. Detect them with `git status --porcelain notes/` plus `git log --since=<date of last ingest in log.md> --name-only -- notes/`, and any note file not yet linked from a problem page. List them and confirm before proceeding.
1. **Read the note** (whole file, all attempts).
2. **Discuss with the user**: brief feedback on the newest attempt — core idea, complexity, any bugs or cleaner approaches, which pattern it belongs to. Respond to questions in their notes. Feedback goes in chat and the wiki, **not** into their note.
3. **Update the problem page**: create if missing; otherwise merge in the new solution / mistakes / attempts (never overwrite another member's solution).
4. **Update pattern / concept pages**: create if missing; add the problem, and add any new template variant or pitfall this code reveals.
5. **Update the member page**: stats, strengths/weaknesses, mistake patterns, review queue.
6. **Update cross-links between related problems** (both directions).
7. **Update `index.md` and `overview.md`**, and append to `log.md` — include the ingested note paths on a `- Sources:` line.
8. Finish with a short list of the pages changed.

A single ingest typically touches 5–10 files; that's expected. With several pending notes, process them one at a time.

### 3.2 Query (when a user asks a question)
1. Read `wiki/index.md` first, then the relevant pages; fall back to `notes/` only when needed.
2. Cite wiki pages (with links) in the answer.
3. If the answer has lasting value (comparison table, topic synthesis, study plan), **file it** into `wiki/insights/` and update the index and log. You may ask the user before filing.

### 3.3 Lint (periodic health check)
Check and fix:
- Orphan pages (nothing links to them), broken links
- Pages missing from or stale in index.md
- Mismatches between a problem page's `patterns` frontmatter and the pattern page's problem list
- Obviously wrong complexity claims, contradictory statements
- Pattern/concept pages that should exist but don't (mentioned ≥ 2 times)
- Notes not yet ingested; member stats that disagree with actual notes; stale review queues
- Suggestions: important patterns not yet touched, good next problems to practice
Finally append a `lint` entry to log.md and report to the user.

### 3.4 Review
Read the member's review queue, pick problems due today (or overdue), and give only the problem plus hint-level guidance — never the answer. When the user re-solves it (new attempt in their note), run the ingest workflow and update the next review date.

---

## 4. Other Conventions
- No fabrication: if you add a "standard solution" that no member submitted, label it `(LLM-added, not a member submission)`.
- Preserve each member's coding style; condensed code lives in the wiki, original code always stays in `notes/`.
- Dates are always `YYYY-MM-DD`.
- Collaboration: each member can ingest on their own branch and then merge; on wiki conflicts, rewrite the page by merging both sides' content.
