---
description: Compile new/changed notes in notes/ (or pasted code) into the wiki
argument-hint: [note path | member + pasted code] (empty = all pending notes)
---
Run the Ingest workflow from CLAUDE.md §3.1.

User input:
$ARGUMENTS

Checklist:
0. Empty input → find pending notes under `notes/` (new/modified since last ingest), list them, confirm. Pasted code → save it to `notes/<member>/<NNNN>-<slug>.md` verbatim first.
1. Read each note fully. Never edit the user's notes.
2. Give brief feedback (core idea, complexity, bugs / cleaner approach, pattern) and answer questions in the notes.
3. Update problems / patterns / concepts / members pages with two-way links.
4. Update index.md and overview.md; append to log.md with a `- Sources:` line.
5. List the files changed.
