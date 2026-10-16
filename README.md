# leetcodenotes
Group Notes for LeetCode — an LLM-maintained knowledge base for our practice (based on [Karpathy's LLM Wiki](https://gist.github.com/karpathy/442a6bf555914893e9891c11519de94f)).

## Architecture
| Layer | Location | Maintained by |
|---|---|---|
| Notes (sources) | `notes/<member>/` — your own code and notes, one file per problem | **You** (LLM only reads) |
| Wiki | `wiki/` — problems, patterns, concepts, members, insights | LLM |
| Schema | `CLAUDE.md` — structure, formats, workflows | Humans and LLM together |

## Workflow
1. Copy `notes/_template.md` → `notes/<you>/<NNNN>-<slug>.md`, write your code and notes (any language). Re-solving later? Add an `## Attempt 2` section.
2. In Claude Code, run `/ingest` — it finds new/changed notes and compiles them into `wiki/`.

## Commands (open Claude Code in this folder)
| Command | Purpose |
|---|---|
| `/ingest` | Compile all new/changed notes into the wiki |
| `/ingest notes/hehsun/0003-....md` | Ingest one specific note |
| `/ask Which sliding window problems am I shaky on?` | Ask the wiki a question |
| `/review hehsun` | Get today's problems to review |
| `/lint` | Periodic wiki health check |

Shortcut: paste code in chat and say "ingest this" — Claude will create the note file for you.

## Entry points
- [wiki/index.md](wiki/index.md) — catalog of all pages
- [wiki/overview.md](wiki/overview.md) — progress overview
- [wiki/log.md](wiki/log.md) — change log
