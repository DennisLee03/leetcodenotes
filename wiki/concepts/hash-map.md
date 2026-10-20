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

- **Counting:** `mp[key]++` is enough, because a missing key is created with value 0. You don't need `if (find) ++ else = 1`. See [frequency count](../patterns/frequency-count.md).
- When the keys come from a small fixed range (e.g. `a`–`z`), a plain array `int cnt[26]` beats a hash map ([0242](../problems/0242-valid-anagram.md)).

## Problems in This Wiki
| Problem | Difficulty | Use |
|---------|------------|-----|
| [0001 Two Sum](../problems/0001-two-sum.md) | Easy | `value -> index` map for [complement lookup](../patterns/complement-lookup.md) |
| [0242 Valid Anagram](../problems/0242-valid-anagram.md) | Easy | `char -> count` maps for [frequency count](../patterns/frequency-count.md) |

## Common Mistakes by Members
- @hehsun, [0001](../problems/0001-two-sum.md): declared the map as a class member instead of a local. Harmless on LeetCode, but the member caught it in their own note.
- @dennis, [0242](../problems/0242-valid-anagram.md): `find` + manual `= 1` before incrementing. Redundant, since `operator[]` default-initializes to 0.
