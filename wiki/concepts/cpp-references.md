# C++ References and Parameter Passing

## Definition and Signals
How a function receives its arguments decides whether the data is copied and whether the caller sees your changes. On LeetCode the signature is fixed, but you still need to know what `vector<int>& nums` means: **you are editing the caller's array.**

## Template Code
From @dennis's [0217 note](../../notes/dennis/0217-contains-duplicate.md):

```cpp
bool f(vector<int> nums);         // (1) by value: copies the whole vector, O(n); changes stay local
bool f(vector<int>& nums);        // (2) by reference: an alias of the caller's vector; changes are visible outside
bool f(const vector<int>& nums);  // (3) by const reference: no copy, read-only
```

Rule of thumb: if you modify it, take `T&`. If you only read it, take `const T&`. Small types like `int` or `char` are passed by value.

## Variants and Details

### Reference vs pointer
@dennis's summary: a reference is "給很多限制的 pointer" (a pointer with many restrictions), basically a pointer with the dangerous parts removed. Compilers usually implement it as an address under the hood, but at the language level it is an **alias**:

| | pointer `T*` | reference `T&` |
|---|---|---|
| Can be null | yes | no |
| Must be initialized | no | yes |
| Can be re-pointed | yes (`p = &other`) | no, it's bound for life |
| Syntax | `*p`, `p->` | same as the original variable |
| Arithmetic | `p + 1` | not allowed |
| `&r`, `sizeof(r)` | the pointer's own address and size | the **referred object's** address and size |

```cpp
int a = 1, b = 2;
int& r = a;
r = b;   // assigns 2 to a; it does NOT rebind r to b
```

C has no references. When people talk about "pass by reference" in C, they mean passing a pointer.

### Dangling references
The "safety" isn't complete. A reference must never outlive the object it's bound to.
- Obvious case: returning a reference to a local variable. Compilers warn about this one.
- **Realistic case: a reference into a container that reallocates.**
  ```cpp
  vector<int> v = {1, 2, 3};
  int& first = v[0];
  v.push_back(4);     // may reallocate, which frees the old buffer
  cout << first;      // undefined behavior: no warning, and it may even "work"
  ```
  This is the same rule as [iterator invalidation](cpp-vector.md#iterator-invalidation). Iterators, pointers, and references are all addresses underneath.

## Problems in This Wiki
| Problem | Difficulty | Use |
|---------|------------|-----|
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | Easy | read-only input, so `const vector<int>&` would fit; sorting the by-reference `nums` would mutate the caller's array |

## Common Mistakes by Members
_(None recorded yet.)_
