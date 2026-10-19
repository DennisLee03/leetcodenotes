# Overview

> Big-picture summary maintained by the LLM.

## Progress
| Member | Total | Easy | Medium | Hard | Last submission |
|--------|-------|------|--------|------|-----------------|
| [hehsun](members/hehsun.md) | 2 | 1 | 1 | 0 | 2026-10-16 |
| [dennis](members/dennis.md) | 1 | 1 | 0 | 0 | 2026-10-11 |

## Pattern Coverage
| Pattern | Problems | Proficiency notes |
|---------|----------|-------------------|
| [complement-lookup](patterns/complement-lookup.md) | 2 | hehsun: solid on the basic form (0001); dennis: degenerate hash-set form (0217) |
| [array-reversal](patterns/array-reversal.md) | 1 | hehsun: optimal O(1)-space rotation on the first try (0189) |
| [two-pointers](patterns/two-pointers.md) | 1 | hehsun: opposite-ends swap only (0189); sorted-pair and fast/slow forms not yet practiced |

## Observations
- Three problems ingested (2 Easy, 1 Medium): @hehsun 2 (C++, C), @dennis 1 (C++).
- @dennis is using early Easy problems to learn C++ STL fundamentals (references, `vector`, `unordered_set`); those notes now live in the concept pages [cpp-references](concepts/cpp-references.md), [cpp-vector](concepts/cpp-vector.md), [hash-set](concepts/hash-set.md).
- @hehsun's notes already cover complexity, edge cases, and self-review, which gives ingests a lot to work with.

## Suggested Next Steps
- Reinforce array reversal: **0151 Reverse Words in a String**, **0061 Rotate List** (the linked-list version of rotation).
- Extend complement lookup: **0560 Subarray Sum Equals K** (prefix-sum variant), **0219 Contains Duplicate II** (natural next step after 0217).
- Compare against two pointers: **0167 Two Sum II**, then **0015 3Sum**.
- Start a second core pattern, e.g. sliding window (**0003 Longest Substring Without Repeating Characters**).
