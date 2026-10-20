---
id: 88
title: Merge Sorted Array
difficulty: Easy
url: https://leetcode.com/problems/merge-sorted-array/
patterns: [two-pointers]
concepts: [cpp-vector]
solved_by: [dennis]
last_updated: 2026-10-20
---

# 0088. Merge Sorted Array

## Problem
`nums1` has length `m + n`: its first `m` values are sorted and the last `n` slots are zero padding. `nums2` holds `n` sorted values. Merge `nums2` into `nums1` in place so `nums1` ends up fully sorted.

## Key Insight
The padding at the end of `nums1` is free space. Fill `nums1` **from the back** with the larger of the two current tails, and you never overwrite a value you still need: O(m + n), no shifting.

## Solutions

### Solution A: `vector::insert` with iterators (by @dennis, date not recorded)
- Idea: drop the `n` padding slots, then walk `nums1`. Whenever `*it1 > *it2`, insert `*it2` before `it1`. Afterwards, append whatever is left of `nums2`.
- Complexity: Time **O(n·(m+n))** worst case, because each `insert` shifts the tail. Space O(1) extra.
- After `it1 = nums1.insert(it1, *it2)`, `it1` points at the inserted value, so `it1++` returns to the original element and compares it against the next `*it2`. Nothing gets skipped.
- Side detail: erasing doesn't shrink `capacity()`, so `nums1` never grows past its original `m+n` capacity and never reallocates. The code is safe either way, because it uses `insert`'s return value.

```cpp
for (size_t i = 0; i < n; i++) nums1.erase(nums1.end() - 1);   // or nums1.resize(m)

auto it2 = nums2.begin();
for (auto it1 = nums1.begin(); it1 != nums1.end() && it2 != nums2.end(); it1++) {
    if (*it1 > *it2) {
        it1 = nums1.insert(it1, *it2);
        it2++;
    }
}
for (; it2 != nums2.end(); it2++) nums1.push_back(*it2);
```
- Note: [dennis/0088-merge-sorted-array.md](../../notes/dennis/0088-merge-sorted-array.md)

### Solution B: Fill from the back with three pointers (LLM-added, not a member submission)
- Idea only. @dennis plans to try this as Attempt 2, so the code is left out on purpose: point `i` at the last real value of `nums1`, `j` at the last value of `nums2`, and `w` at the last slot of `nums1`. Repeatedly write the larger of `nums1[i]` and `nums2[j]` into `nums1[w]`. When should the loop stop, and what do you still need to copy afterwards?
- Complexity: Time O(m + n), Space O(1).

## Pitfalls / Common Mistakes
- **`erase(nums1.end())` is undefined behavior.** `end()` is one past the last element, so there's nothing to erase. @dennis's earlier version did this and still passed by luck: in libstdc++ the "shift the tail" step does nothing for that position, so the call happened to act like `pop_back()`. Caught and fixed in the member's own errata. Use `pop_back()`, `erase(end() - 1)`, or simply `resize(m)`.
- **Comparing against the zero padding.** If the padding isn't removed first, `nums2` values get compared with the trailing zeros, which breaks on negative numbers.
- **Forgetting the leftovers.** The merge loop stops when either side runs out, so the rest of `nums2` still has to be appended.
- **Merging front-to-back in place overwrites data.** That's why the in-place O(m+n) solution goes back-to-front.
- `size_t i < n` compares unsigned with signed `int n`. That's a compiler warning, so use `int i`.

## Related Problems
- [0027 Remove Element](0027-remove-element.md): the same in-place vector editing; container `erase` (O(n²)) vs two pointers (O(n)).
- LLM-suggested: 0021 Merge Two Sorted Lists, 0977 Squares of a Sorted Array (fill from the back), 0350 Intersection of Two Arrays II.

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| unknown (before 2026-10-19) | dennis | 1 | AC | cpp | [note](../../notes/dennis/0088-merge-sorted-array.md) |
