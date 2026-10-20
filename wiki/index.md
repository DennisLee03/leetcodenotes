# Wiki Index

> Maintained by the LLM. Updated after every ingest / filed insight. Read this page first when answering queries.
> Format: `- [Title](path) — one-line summary | metadata`

## Overview
- [Overview](overview.md) — overall progress and observations

## Members
- [@dennis](members/dennis.md) — progress, strengths, review queue | 4 solved (4E), C++
- [@hehsun](members/hehsun.md) — progress, strengths, review queue | 2 solved (1E 1M), C++ / C

## Patterns
- [Complement Lookup](patterns/complement-lookup.md) — one pass, check whether `target - x` (or `x` itself) has been seen in a hash map/set | 2 problems
- [Array Reversal](patterns/array-reversal.md) — rearrange blocks in place by reversing ranges (rotate, reverse words) | 1 problem
- [Frequency Count](patterns/frequency-count.md) — count occurrences (array for small alphabets, hash map otherwise) and compare counts | 1 problem
- [Two Pointers](patterns/two-pointers.md) — opposite-ends, read/write, or fill-from-back indices to avoid nested loops, O(n²) erase/insert, or extra buffers | 3 problems

## Concepts
- [C++ References](concepts/cpp-references.md) — pass by value vs `&` vs `const &`; reference vs pointer; dangling references | 2 problems
- [C++ vector](concepts/cpp-vector.md) — `at` vs `[]`, size vs capacity, iterator invalidation, `erase(end())` UB, O(n) erase/insert | 3 problems
- [Hash Map](concepts/hash-map.md) — O(1) average lookup; C++ `unordered_map` idioms (`mp[k]++` counting) and pitfalls | 2 problems
- [Hash Set](concepts/hash-set.md) — `unordered_set` vs `set`, `insert().second`, load factor & rehash, O(n) worst case | 1 problem

## Problems
- [0001. Two Sum](problems/0001-two-sum.md) — one-pass value→index hash map, look up the complement before inserting | Easy · complement-lookup · hehsun
- [0027. Remove Element](problems/0027-remove-element.md) — read/write pointers keep wanted elements in O(n); `erase` in a loop is O(n²) | Easy · two-pointers · dennis
- [0088. Merge Sorted Array](problems/0088-merge-sorted-array.md) — fill nums1 from the back; `insert` approach is O(n·(m+n)); `erase(end())` is UB | Easy · two-pointers · dennis
- [0189. Rotate Array](problems/0189-rotate-array.md) — three reversals rotate right by k in O(1) space; normalize `k %= n` first | Medium · array-reversal, two-pointers · hehsun
- [0217. Contains Duplicate](problems/0217-contains-duplicate.md) — hash-set seen scan, first failed insert = duplicate; sort alternative mutates input | Easy · complement-lookup · dennis
- [0242. Valid Anagram](problems/0242-valid-anagram.md) — compare character counts: hash map, `int[26]`, or sort | Easy · frequency-count · dennis

## Insights
_(none yet)_
