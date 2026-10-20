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
- **Read/write (same direction):** `i` reads every element and `k` writes the ones you keep (`if (keep(a[i])) a[k++] = a[i];`). This is the O(n) replacement for calling `vector::erase` in a loop, which is O(n²) ([0027](../problems/0027-remove-element.md)). `std::remove` implements exactly this.
- **Fill from the back:** when merging into a buffer that has spare space at the end, write the largest remaining element at the back so you never overwrite unread data ([0088](../problems/0088-merge-sorted-array.md)).

## Problems in This Wiki
| Problem | Difficulty | How it's used |
|---------|------------|---------------|
| [0027 Remove Element](../problems/0027-remove-element.md) | Easy | Read/write pointers (LLM-added solution; @dennis used `erase`) |
| [0088 Merge Sorted Array](../problems/0088-merge-sorted-array.md) | Easy | Three pointers filling from the back (LLM-described; @dennis used `insert`) |
| [0189 Rotate Array](../problems/0189-rotate-array.md) | Medium | Opposite-ends swap inside the `reverse` helper ([array reversal](array-reversal.md)) |

## Common Mistakes by Members
- @dennis, [0027](../problems/0027-remove-element.md) and [0088](../problems/0088-merge-sorted-array.md): used container `erase`/`insert` inside a loop where two pointers would be O(n). Correct, but O(n²).
