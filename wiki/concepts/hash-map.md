# Hash Map

## Definition and Signals
A key-to-value store with average O(1) insert, lookup, and erase (worst case O(n) under heavy collisions). Use it when you need to answer "have I seen X?" or "where/how many times did X appear?" fast.

Signals: membership checks inside a loop, counting frequencies, grouping by key, or replacing an inner search loop (O(n²) → O(n)).

## Template Code

**C++** (`unordered_map`)
```cpp
unordered_map<int, int> mp;
mp.reserve(n);                       // optional: avoids rehashing
auto it = mp.find(key);              // lookup without inserting
if (it != mp.end()) use(it->second);
mp[key] = value;                     // insert / overwrite
mp.count(key);                       // 0 or 1, existence check
```

## Variants and Details
- **`mp[key]` inserts a default value if the key is missing.** Use `find` or `count` when you only want to check, so you don't add junk entries.
- `unordered_map` has no ordering. Use `map` (red-black tree, O(log n)) when you need sorted keys or `lower_bound`.
- Only need "seen or not", with no value per key? Use a [hash set](hash-set.md). That page also covers buckets, load factor, rehash, and the O(n) worst case, all of which apply to `unordered_map` as well.
- Keep the map **local to the function**. A class-member map carries state between calls (see @hehsun's note on [0001](../problems/0001-two-sum.md)).

## Problems in This Wiki
| Problem | Difficulty | Use |
|---------|------------|-----|
| [0001 Two Sum](../problems/0001-two-sum.md) | Easy | `value -> index` map for [complement lookup](../patterns/complement-lookup.md) |

## Common Mistakes by Members
- @hehsun, [0001](../problems/0001-two-sum.md): declared the map as a class member instead of a local. Harmless on LeetCode, but the member caught it in their own note.
