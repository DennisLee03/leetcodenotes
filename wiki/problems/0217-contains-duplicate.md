---
id: 217
title: Contains Duplicate
difficulty: Easy
url: https://leetcode.com/problems/contains-duplicate/
patterns: [complement-lookup]
concepts: [hash-set, cpp-references, cpp-vector]
solved_by: [dennis]
last_updated: 2026-10-19
---

# 0217. Contains Duplicate

## Problem
Given an integer array `nums`, return `true` if any value appears at least twice, otherwise `false`.

## Key Insight
Remember every value you've seen in a [hash set](../concepts/hash-set.md). The first time a value is already there, you've found a duplicate, and the O(1) average lookup makes the whole scan O(n).

## Solutions

### Solution A: Seen set, one pass (by @dennis, 2026-10-11)
- Idea: walk the array. If `nums[i]` is already in the set, return `true`. Otherwise insert it.
- Complexity: Time O(n) average, Space O(n).

```cpp
unordered_set<int> s;
for (size_t i = 0; i < nums.size(); i++) {
    if (s.find(nums[i]) != s.end()) return true;
    else s.insert(nums[i]);
}
return false;
```
- Cleaner version (LLM suggestion): `insert` returns `pair<iterator, bool>`, so one call both checks and inserts, and you hash once instead of twice.
  ```cpp
  for (int x : nums)
      if (!s.insert(x).second) return true;
  ```
- Note: [dennis/0217-contains-duplicate.md](../../notes/dennis/0217-contains-duplicate.md)

### Solution B: Sort, then compare neighbors (LLM-added, not a member submission)
- After `sort(nums.begin(), nums.end())`, duplicates are next to each other, so check `nums[i] == nums[i-1]`.
- Complexity: Time O(n log n), Space O(1) extra (ignoring the sort's own stack).
- Trade-off: `nums` is passed **by reference**, so sorting changes the caller's array. See [C++ References](../concepts/cpp-references.md).

## Pitfalls / Common Mistakes
- **`find` + `insert` = two hash lookups.** It's correct, but `insert(x).second` does both in one.
- **Average vs worst case.** `unordered_set` operations are O(1) *on average*, and O(n) in the worst case when everything collides into one bucket. Say "average O(1)", not just "O(1)".
- **Sorting mutates the input** (Solution B). That's fine on LeetCode, but not when the caller still needs the original order.

## Related Problems
- [0001 Two Sum](../problems/0001-two-sum.md): same "have I seen it?" scan, but it looks up `target - x` instead of `x` and needs a map to remember indices.
- [0242 Valid Anagram](0242-valid-anagram.md): also hash-based, but it needs counts (a map or an array) where this problem needs membership. Its sort solution is safe because the strings are passed by value; here, sorting would change the caller's `nums`.
- LLM-suggested variants to practice: 0219 Contains Duplicate II (seen-set inside a sliding window of size k), 0220 Contains Duplicate III (ordered `set` + `lower_bound`), 0128 Longest Consecutive Sequence (hash-set membership).

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| 2026-10-11 | dennis | 1 | AC | cpp | [note](../../notes/dennis/0217-contains-duplicate.md) |
