# Two Pointers

## Definition and Signals
Keep two indices into a sequence and move them according to a rule, so you avoid an O(n²) nested loop or an extra buffer. Common forms:
- **Opposite ends:** `l = 0, r = n-1`, both moving inward (reversal, palindrome check, pair sum on sorted input).
- **Same direction (fast/slow):** a read pointer and a write pointer (removing elements in place, deduplication).

Think of it when the input is **sorted**, when you must work **in place**, or when you're comparing or swapping elements from both ends.

## Template Code
Opposite-ends swap, distilled from [0189 Rotate Array](../problems/0189-rotate-array.md) (@hehsun, C):

```c
int l = start, r = end;        // inclusive
while (l < r) {
    int t = a[l]; a[l] = a[r]; a[r] = t;
    l++; r--;
}
```

## Variants and Details
- `while (l < r)` vs `while (l <= r)`: when swapping, `l == r` is the middle element, so `<` is enough.
- Pair sum on **sorted** input (0167 Two Sum II) uses two pointers instead of [complement lookup](complement-lookup.md). That gives O(1) space, but it needs the input sorted.

## Problems in This Wiki
| Problem | Difficulty | How it's used |
|---------|------------|---------------|
| [0189 Rotate Array](../problems/0189-rotate-array.md) | Medium | Opposite-ends swap inside the `reverse` helper ([array reversal](array-reversal.md)) |

## Common Mistakes by Members
_(None recorded yet.)_
