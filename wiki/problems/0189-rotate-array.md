---
id: 189
title: Rotate Array
difficulty: Medium
url: https://leetcode.com/problems/rotate-array/
patterns: [array-reversal, two-pointers]
concepts: []
solved_by: [hehsun]
last_updated: 2026-10-16
---

# 0189. Rotate Array

## Problem
Rotate the integer array `nums` to the right by `k` steps, in place (`k` can be larger than `n`).

## Key Insight
Rotating right by `k` moves the last `k` elements to the front. Reversing the whole array puts both blocks in the right place but backwards, so reversing each block again fixes them. This uses O(1) extra space.

## Solutions

### Solution A: Three reversals (by @hehsun, 2026-10-16)
- Idea: `k %= n`. Then reverse `[0, n-1]`, reverse `[0, k-1]`, and reverse `[k, n-1]`.
- Complexity: Time O(n) (each element is swapped at most twice), Space O(1).

```c
void reverse(int* nums, int start, int end) {   // two pointers moving inward
    while (start < end) {
        int temp = nums[end];
        nums[end] = nums[start];
        nums[start] = temp;
        start++; end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (k == 0) return;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
```
- Note: [hehsun/0189-rotate-array.md](../../notes/hehsun/0189-rotate-array.md)

### Solution B: Extra array (LLM-added, not a member submission)
- `out[(i + k) % n] = nums[i]`, then copy `out` back. Time O(n), Space O(n). Simplest to get right, but it doesn't meet the O(1)-space follow-up.

### Solution C: Cyclic replacements (LLM-added, not a member submission)
- Move each element directly to `(i + k) % n`, following each cycle until it returns to its start. There are `gcd(n, k)` cycles. Time O(n), Space O(1), but the cycle bookkeeping makes it easier to get wrong than Solution A.

## Pitfalls / Common Mistakes
- **Forgetting `k %= n`.** When `k >= n`, `reverse(nums, 0, k - 1)` reads past the end of the array. @hehsun handled this.
- **Reversal order vs. rotation direction.** Reverse the whole array first, then `[0,k-1]` and `[k,n-1]`: this rotates **right**. Reversing `[0,k-1]` and `[k,n-1]` first and then the whole array rotates **left** by `k`. For a right rotation with parts-first, the split point must be `n-k`.
- **Off-by-one in the split.** The two blocks are `[0, k-1]` and `[k, n-1]` (inclusive bounds), not `[0, k]`.

## Related Problems
_(No other problems in this wiki use this pattern yet. LLM-suggested practice: 0061 Rotate List, 0151 Reverse Words in a String (the same reverse-whole-then-parts trick), 0796 Rotate String, 0344 Reverse String.)_

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| 2026-10-16 | hehsun | 1 | AC | c | [note](../../notes/hehsun/0189-rotate-array.md) |
