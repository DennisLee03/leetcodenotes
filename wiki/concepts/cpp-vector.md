# C++ `std::vector`

## Definition and Signals
A resizable, contiguous array, and the default container for almost every LeetCode array problem. You get O(1) random access, amortized O(1) `push_back`, and O(n) insert or erase in the middle, because everything after that position has to shift.

## Template Code
```cpp
#include <vector>
vector<int> v;                 // empty
vector<int> v(n, init);        // n copies of init
v[i];                          // no bounds check, like a C array
v.at(i);                       // bounds-checked: throws std::out_of_range
v.size();                      // number of elements stored
v.capacity();                  // number of elements the current buffer can hold
v.push_back(x);                // amortized O(1)
v.reserve(n);                  // pre-allocate; avoids reallocations
for (auto it = v.begin(); it != v.end(); ++it) cout << *it;
```

## Variants and Details

### size vs capacity
From @dennis's [0217 note](../../notes/dennis/0217-contains-duplicate.md): `size()` is how many elements exist, and `capacity()` is how many fit before the next reallocation. When `push_back` exceeds the capacity, the vector allocates a bigger buffer (roughly double), moves everything over, and frees the old one. That occasional O(n) move is why `push_back` is *amortized* O(1).

### Iterator invalidation
- **Reallocation** (`push_back` or `insert` beyond the capacity, or `reserve`) invalidates **all** iterators, pointers, and references into the vector.
- **`insert` / `erase` without reallocation** invalidates those at or after the position.
- Both `insert` and `erase` *return* a valid iterator, to the inserted element and to the element after the erased one. Always continue from the returned iterator: `it = v.erase(it);`.
- See [dangling references](cpp-references.md#dangling-references), which is the same issue for `T&`.

## Problems in This Wiki
| Problem | Difficulty | Use |
|---------|------------|-----|
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | Easy | where @dennis's vector basics notes (`at`, size vs capacity) were recorded |

## Common Mistakes by Members
_(None recorded yet.)_
