# Log

> Append-only. Format: `## [YYYY-MM-DD] <ingest|query|lint|review|schema> | <title> | <member>`
> Recent entries: `grep "^## \[" wiki/log.md | tail -10`

## [2026-10-16] schema | Initialize LLM Wiki structure | -
- Created CLAUDE.md, raw/, wiki/, templates/, .claude/commands/

## [2026-10-16] schema | Replace raw/ with human-owned notes/ | -
- Members write their own notes in notes/<member>/<NNNN>-<slug>.md (template: notes/_template.md); LLM reads only
- /ingest with no args now picks up new/changed notes

## [2026-10-16] ingest | 0001 Two Sum | hehsun
- Created: problems/0001-two-sum, patterns/complement-lookup, concepts/hash-map, members/hehsun
- Updated: index, overview
- Sources: notes/hehsun/0001-two-sum.md
- Notes: Attempt 1 AC (cpp). `used_hint` and `time_spent` left blank; assumed no hint, so next review is 2026-10-23.
