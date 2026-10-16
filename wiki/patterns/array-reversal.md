# Array Reversal (Reverse-Based Rearrangement)

## Definition and Signals
Rearrange blocks of an array or string **in place** by reversing ranges. Reversing a whole sequence swaps the order of its blocks, and reversing each block again restores the order inside each one.

Think of it when:
- you need to **rotate** an array or string, or **swap two adjacent blocks**, with O(1) extra space
- you need to reverse the **order of words** but not the letters inside each word
- the obvious solution copies into a second buffer, and the follow-up asks for in-place

## Template Code
Distilled from [0189 Rotate Array](../problems/0189-rotate-array.md) (@hehsun, C):

```c
void reverse(int* a, int l, int r) {      // inclusive [l, r]
    while (l < r) {
        int t = a[l]; a[l] = a[r]; a[r] = t;
        l++; r--;
    }
}

// rotate right by k
k %= n;
reverse(a, 0, n - 1);
reverse(a, 0, k - 1);
reverse(a, k, n - 1);
```

## Variants and Details
- **Right rotation by k:** reverse the whole array, then `[0,k-1]` and `[k,n-1]`.
- **Left rotation by k:** reverse `[0,k-1]` and `[k,n-1]` first, then the whole array (or right-rotate by `n-k`).
- **Normalize k first** (`k %= n`). Otherwise the block bounds go out of range.
- **Reverse words:** reverse the whole string, then reverse each word (0151).
- The `reverse` helper itself is the opposite-ends case of [two pointers](two-pointers.md).

## Problems in This Wiki
| Problem | Difficulty | How it's used |
|---------|------------|---------------|
| [0189 Rotate Array](../problems/0189-rotate-array.md) | Medium | Reverse the whole array, then each of the two blocks, to rotate right in O(1) space |

## Common Mistakes by Members
_(None recorded yet. @hehsun normalized `k` and got the block bounds right on the first try.)_
