---
id: 1
title: Two Sum
difficulty: Easy
url: https://leetcode.com/problems/two-sum/
patterns: [complement-lookup]
concepts: [hash-map]
solved_by: [hehsun]
last_updated: 2026-10-16
---

# 0001. Two Sum

## Problem
Given an integer array `nums` and a `target`, return the indices of the two distinct elements that add up to `target` (exactly one solution exists).

## Key Insight
For each element, the partner you need is fixed (`target - x`). Instead of searching for it, remember every value you've already seen in a hash map, so each lookup is O(1).

## Solutions

### Solution A: One-pass hash map (by @hehsun, 2026-10-16)
- Idea: walk the array once. For each `nums[i]`, look up `target - nums[i]` in a `value -> index` map. If it's there, return both indices. If not, insert `nums[i] -> i`.
- Complexity: Time O(n), Space O(n). The brute-force nested loops are O(n²) time and O(1) space.

```cpp
unordered_map<int, int> mp;               // value -> index
for (int i = 0; i < nums.size(); i++) {
    auto it = mp.find(target - nums[i]);  // look up BEFORE inserting
    if (it != mp.end()) return {i, it->second};
    mp[nums[i]] = i;
}
return {};
```
- Note: [hehsun/0001-two-sum.md](../../notes/hehsun/0001-two-sum.md) · [submission](https://leetcode.com/problems/two-sum/submissions/2173862217)

## Pitfalls / Common Mistakes
- **Insert-then-check order.** If you insert `nums[i]` before looking up its complement, an element can pair with itself (e.g. `[3,2,4], target=6` would match index 0 with itself). Looking up first avoids this and still handles duplicates like `[3,3], target=6`.
- **Sorting + two pointers loses the original indices.** It only works if you sort `(value, index)` pairs. That costs O(n log n), so it's worse here, but it's the right tool for [0167 Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) where the input is already sorted.
- **State in a class member** (from @hehsun's own note): `mp` declared as a member of `Solution` keeps old entries if the same object is reused. Make it a local variable.

## Related Problems
- [0217 Contains Duplicate](0217-contains-duplicate.md): the same seen-values scan, where the complement is `x` itself, so a hash set is enough.
- LLM-suggested variants to practice: 0167 Two Sum II (two pointers on sorted input), 0015 3Sum, 0560 Subarray Sum Equals K (complement lookup on prefix sums), 0219 Contains Duplicate II.

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| 2026-10-16 | hehsun | 1 | AC | cpp | [note](../../notes/hehsun/0001-two-sum.md) |
