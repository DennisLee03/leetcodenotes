# Log

> Append-only. Format: `## [YYYY-MM-DD] <ingest|query|lint|review|schema> | <title> | <member>`
> Recent entries: `grep "^## \[" wiki/log.md | tail -10`

## [2026-10-16] schema | Initialize LLM Wiki structure | -
- Created CLAUDE.md, raw/, wiki/, templates/, .claude/commands/

## [2026-10-16] schema | Replace raw/ with human-owned notes/ | -
- Members write their own notes in notes/<member>/<NNNN>-<slug>.md (template: notes/_template.md); LLM reads only
- /ingest with no args now picks up new/changed notes
