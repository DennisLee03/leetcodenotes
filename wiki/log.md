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

## [2026-10-20] ingest | 0027 Remove Element | dennis
- Created: problems/0027-remove-element
- Updated: patterns/two-pointers, concepts/cpp-vector, members/dennis, index, overview
- Sources: notes/dennis/0027-remove-element.md
- Notes: Attempt 1 AC (cpp), no hint, `erase` loop O(n²). Note date is still `YYYY-MM-DD`; recorded as unknown and the review counted from 2026-10-19 (first commit), so next review is 2026-10-26. Added LLM read/write-pointer and erase–remove solutions.

## [2026-10-20] ingest | 0088 Merge Sorted Array | dennis
- Created: problems/0088-merge-sorted-array
- Updated: patterns/two-pointers, concepts/cpp-vector, problems/0027-remove-element (related link), members/dennis, index, overview
- Sources: notes/dennis/0088-merge-sorted-array.md
- Notes: Attempt 1 AC (cpp), no hint, `insert` loop O(n·(m+n)). Member's errata on `erase(end())` UB recorded as a pitfall. Back-fill solution described at hint level only (no code), because the member plans to try it as Attempt 2. Date unknown, so next review is 2026-10-26.

## [2026-10-20] ingest | 0242 Valid Anagram | dennis
- Created: problems/0242-valid-anagram, patterns/frequency-count
- Updated: concepts/hash-map, concepts/cpp-references, problems/0217-contains-duplicate (related link), members/dennis, index, overview
- Sources: notes/dennis/0242-valid-anagram.md
- Notes: Two AC solutions on 2026-10-19 (hash map, then `int[26]`), both headed "Attempt 1"; treated as one attempt with two solutions. `time_spent` holds runtimes (4ms / 0ms), not solving time. Editorial was read after AC, so `used_hint: no` was kept. Next review is 2026-10-26.
