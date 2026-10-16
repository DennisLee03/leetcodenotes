# Wiki Index

> Maintained by the LLM. Updated after every ingest / filed insight. Read this page first when answering queries.
> Format: `- [Title](path) — one-line summary | metadata`

## Overview
- [Overview](overview.md) — overall progress and observations

## Members
- [@hehsun](members/hehsun.md) — progress, strengths, review queue | 2 solved (1E 1M), C++ / C

## Patterns
- [Complement Lookup](patterns/complement-lookup.md) — one pass, check whether `target - x` has been seen in a hash map | 1 problem
- [Array Reversal](patterns/array-reversal.md) — rearrange blocks in place by reversing ranges (rotate, reverse words) | 1 problem
- [Two Pointers](patterns/two-pointers.md) — opposite-ends or fast/slow indices to avoid nested loops or extra buffers | 1 problem

## Concepts
- [Hash Map](concepts/hash-map.md) — O(1) average lookup; C++ `unordered_map` idioms and pitfalls | 1 problem

## Problems
- [0001. Two Sum](problems/0001-two-sum.md) — one-pass value→index hash map, look up the complement before inserting | Easy · complement-lookup · hehsun
- [0189. Rotate Array](problems/0189-rotate-array.md) — three reversals rotate right by k in O(1) space; normalize `k %= n` first | Medium · array-reversal, two-pointers · hehsun

## Insights
_(none yet)_
