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

## [2026-10-16] ingest | 0189 Rotate Array | hehsun
- Created: problems/0189-rotate-array, patterns/array-reversal, patterns/two-pointers
- Updated: members/hehsun, patterns/complement-lookup (link to two-pointers), index, overview
- Sources: notes/hehsun/0189-rotate-array.md
- Notes: Attempt 1 AC (c, 20m 10s), three-reversal O(1) space. Note was created from a screenshot pasted in chat. `used_hint` left blank; assumed no hint, so next review is 2026-10-23.

## [2026-10-19] ingest | 0217 Contains Duplicate | dennis
- Created: problems/0217-contains-duplicate, concepts/hash-set, concepts/cpp-references, concepts/cpp-vector, members/dennis
- Updated: patterns/complement-lookup, concepts/hash-map, problems/0001-two-sum (related link), index, overview
- Sources: notes/dennis/0217-contains-duplicate.md
- Notes: Attempt 1 AC (cpp), no hint, dated 2026-10-11, so the review (2026-10-18) is already overdue. Corrected the note's complexity table (rebalance is inside O(log n); unordered insert is amortized). 0027 and 0088 notes exist but were not ingested (placeholder dates, empty notes).
