# Hash Set (`unordered_set`) and `set`

## Definition and Signals
A container that stores **keys only** and answers "is X in here?" fast. `unordered_set` is a hash table with O(1) average insert, find, and erase. `set` is a self-balancing BST (a red-black tree in practice) that keeps keys sorted, with O(log n) operations.

Signals: "have I seen this value before?", deduplication, membership checks inside a loop. If you also need a value per key (an index or a count), use a [hash map](hash-map.md) instead.

## Template Code

**C++**
```cpp
unordered_set<int> s;
s.reserve(n);                         // optional: pre-allocate buckets, avoids rehashing
if (!s.insert(x).second) { /* x was already present */ }
s.count(x);                           // 0 or 1, easy-to-read existence check
s.find(x) != s.end();                 // same check, gives you an iterator
s.erase(x);                           // erase by key
```

## Variants and Details

### `set` vs `unordered_set`
From @dennis's [0217 note](../../notes/dennis/0217-contains-duplicate.md), with the complexities corrected:

| | `set` | `unordered_set` |
|---|---|---|
| Ordering | sorted | none |
| Implementation | self-balancing BST (red-black tree) | hash table |
| Find | O(log n) | O(1) average, O(n) worst |
| Insert | O(log n), and rebalancing is already included | O(1) average (amortized, because of rehash), O(n) worst |
| Erase | O(log n) | O(1) average, O(n) worst |
| Extra | `lower_bound`, `upper_bound`, in-order iteration | `reserve`, `bucket_count`, `load_factor` |

Pick `set` only when you need order or a predecessor/successor (e.g. 0220 Contains Duplicate III).

### Buckets, load factor, rehash
- An element goes into bucket `hash(x) % bucket_count`. A lookup jumps straight to that bucket and scans only its short chain. That's why the average is O(1).
- **Load factor** = `size() / bucket_count()`. When an insert pushes it above `max_load_factor()` (default 1.0), the table **rehashes**: it allocates more buckets (roughly double) and moves every element into its new bucket.
- One rehash costs O(n), but it happens rarely enough that insert stays **amortized O(1)**, the same way `vector::push_back` does.
- Erase never rehashes, because the table doesn't shrink on its own. Its O(n) worst case comes only from collisions.

### Worst case O(n)
If many keys collide into one bucket, every operation scans a long chain. Normal data almost never does this. Adversarial "anti-hash" tests (common on Codeforces, rare on LeetCode) can push `unordered_*` into TLE.

### Iterator invalidation
- **Rehash invalidates all iterators**, but **references and pointers to elements stay valid**. Each element is its own node, so a rehash relinks the buckets without moving the nodes.
- Compare this with [vector](cpp-vector.md), where a reallocation invalidates iterators, references, and pointers alike.

## Problems in This Wiki
| Problem | Difficulty | Use |
|---------|------------|-----|
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | Easy | seen-set: the first failed insert means a duplicate |

## Common Mistakes by Members
- @dennis, [0217](../problems/0217-contains-duplicate.md): `find` then `insert` (two hash lookups) where one `insert(x).second` would do. Correct, just slightly wasteful.
