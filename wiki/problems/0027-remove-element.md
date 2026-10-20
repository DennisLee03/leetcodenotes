---
id: 27
title: Remove Element
difficulty: Easy
url: https://leetcode.com/problems/remove-element/
patterns: [two-pointers]
concepts: [cpp-vector]
solved_by: [dennis]
last_updated: 2026-10-20
---

# 0027. Remove Element

## Problem
Remove every occurrence of `val` from `nums` in place and return the number of remaining elements `k`. Only the first `k` slots are checked, and their order doesn't matter.

## Key Insight
You don't have to physically delete anything. Copy every element you want to keep forward into a "write" slot, and the kept elements end up in the first `k` positions in one O(n) pass.

## Solutions

### Solution A: `vector::erase` with iterators (by @dennis, date not recorded)
- Idea: walk with an iterator; when `*it == val`, `erase` it and continue from the iterator that `erase` returns.
- Complexity: Time **O(n²)** worst case, because each `erase` shifts the whole tail left. Space O(1).
- Correctly handles [iterator invalidation](../concepts/cpp-vector.md#iterator-invalidation) by continuing from the returned iterator, so no element gets skipped.

```cpp
for (auto it = nums.begin(); it != nums.end(); ) {
    if (*it == val) { it = nums.erase(it); continue; }
    it++;
}
return nums.size();
```
- Note: [dennis/0027-remove-element.md](../../notes/dennis/0027-remove-element.md)

### Solution B: Read/write pointers (LLM-added, not a member submission)
- Idea: [two pointers](../patterns/two-pointers.md) in the same direction. `i` reads every element, `k` marks the next write slot. Copy only the elements you keep.
- Complexity: Time O(n), Space O(1).

```cpp
int k = 0;
for (int i = 0; i < nums.size(); i++)
    if (nums[i] != val) nums[k++] = nums[i];
return k;
```

### Solution C: erase–remove idiom (LLM-added, not a member submission)
- `std::remove` does Solution B for you: it moves the kept elements forward and returns the new logical end. Then one `erase` trims the tail. O(n).

```cpp
nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
return nums.size();
```

## Pitfalls / Common Mistakes
- **`erase` in a loop is O(n²).** Each call shifts everything after it. This is fine for n ≤ 100 (this problem's limit) but a trap on large inputs.
- **Forgetting that `erase` invalidates `it`.** Writing `nums.erase(it); it++;` is undefined behavior. Always use `it = nums.erase(it);`. @dennis did this correctly.
- **Advancing after erasing.** The returned iterator already points at the next element. That's why the member's loop uses `continue` instead of `it++`.

## Related Problems
- [0088 Merge Sorted Array](0088-merge-sorted-array.md): the same in-place vector editing, and the same `insert`/`erase` vs two-pointer trade-off.
- LLM-suggested: 0026 Remove Duplicates from Sorted Array, 0283 Move Zeroes, 0080 Remove Duplicates II (all read/write pointers).

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| unknown (before 2026-10-19) | dennis | 1 | AC | cpp | [note](../../notes/dennis/0027-remove-element.md) |
