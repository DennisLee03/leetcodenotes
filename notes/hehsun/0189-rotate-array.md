---
problem: 189
title: Rotate Array
difficulty: Medium
url: https://leetcode.com/problems/rotate-array/
---

## Attempt 1 — 2026-10-16
result: AC
language: c
time_spent: 20m 10s
used_hint:

```c
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp;
        temp = nums[end];
        nums[end] = nums[start];
        nums[start] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (k == 0)
        return;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
```

### Notes

