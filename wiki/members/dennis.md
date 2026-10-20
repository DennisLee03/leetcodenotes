# @dennis

## Stats
| Total | Easy | Medium | Hard |
|-------|------|--------|------|
| 4 | 4 | 0 | 0 |

Languages: C++ (0027, 0088, 0217, 0242)

| Pattern | Count | Notes |
|---------|-------|-------|
| [complement-lookup](../patterns/complement-lookup.md) | 1 | 0217 (hash set) |
| [frequency-count](../patterns/frequency-count.md) | 1 | 0242 (hash map → `int[26]`) |
| [two-pointers](../patterns/two-pointers.md) | 0 | 0027 and 0088 are two-pointer problems, but both were solved with `erase`/`insert`; not practiced yet |

## Strengths
- Uses problems to learn the language: the notes cover parameter passing, `vector` basics, `set` vs `unordered_set`, rehash ([0217](../problems/0217-contains-duplicate.md)), and iterator invalidation with diagrams ([0027](../problems/0027-remove-element.md), [0088](../problems/0088-merge-sorted-array.md)).
- Handles iterator invalidation correctly: continues from the iterator returned by `erase`/`insert` ([0027](../problems/0027-remove-element.md), [0088](../problems/0088-merge-sorted-array.md)).
- Reads constraints and optimizes: switched from `unordered_map` to `int[26]` after noticing the input is `a`–`z` only ([0242](../problems/0242-valid-anagram.md)).
- Self-corrects: found and wrote up the `erase(end())` undefined behavior in [0088](../problems/0088-merge-sorted-array.md)'s errata.
- Reviews alternatives after AC: recorded the editorial's three approaches for [0242](../problems/0242-valid-anagram.md).

## Weaknesses
- **Two pointers not yet practiced.** In-place array problems get solved with STL mutation calls (`erase`/`insert` in a loop, O(n²)) instead of read/write or back-fill pointers (O(n)) ([0027](../problems/0027-remove-element.md), [0088](../problems/0088-merge-sorted-array.md)).

## Recurring Mistake Patterns
- **Reaching for container operations without counting their cost.** `erase`/`insert` in a loop gives O(n²) in [0027](../problems/0027-remove-element.md) and [0088](../problems/0088-merge-sorted-array.md). Two data points.
- **Complexity details:** in [0217](../problems/0217-contains-duplicate.md), wrote `set` insert/delete as "O(log n) + rebalance" and left out "amortized" for `unordered_set` insert.
- **Verbose STL idioms:** `find` then `insert` ([0217](../problems/0217-contains-duplicate.md)), and `find` then `= 1` / `++` ([0242](../problems/0242-valid-anagram.md)), where `insert(x).second` and `mp[k]++` would do. Two data points.

## Review Queue
| Problem | Last attempt | Result | Next review | Reason |
|---------|--------------|--------|-------------|--------|
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | 2026-10-11 | AC | 2026-10-18 (overdue) | First AC without hints (+7 days) |
| [0027 Remove Element](../problems/0027-remove-element.md) | unknown | AC | 2026-10-26 | First AC without hints; date missing in the note, so counted from 2026-10-19 (+7). Suggestion: re-solve with read/write pointers |
| [0088 Merge Sorted Array](../problems/0088-merge-sorted-array.md) | unknown | AC | 2026-10-26 | First AC without hints; date missing in the note, so counted from 2026-10-19 (+7). Suggestion: Attempt 2 filling from the back |
| [0242 Valid Anagram](../problems/0242-valid-anagram.md) | 2026-10-19 | AC | 2026-10-26 | First AC without hints (editorial read only after AC) (+7 days) |
