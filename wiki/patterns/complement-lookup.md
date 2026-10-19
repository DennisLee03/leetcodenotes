# Complement Lookup (Hash Map of Seen Values)

## Definition and Signals
Scan the input once and store what you've seen in a [hash map](../concepts/hash-map.md). At each step, ask whether the value that would complete a valid answer (the *complement*) has already appeared.

Think of it when:
- you need a **pair** (or a subarray) whose values meet an exact relation: `a + b = target`, `a - b = k`, `prefix[j] - prefix[i] = k`
- the input is **unsorted** and you need **original indices**, so sorting is awkward
- the brute force is a nested loop over pairs, O(n²)

## Template Code
Distilled from [0001 Two Sum](../problems/0001-two-sum.md) (@hehsun, C++):

```cpp
unordered_map<int, int> seen;              // value -> index (or count)
for (int i = 0; i < n; i++) {
    int need = target - nums[i];           // the complement
    if (auto it = seen.find(need); it != seen.end())
        return {it->second, i};
    seen[nums[i]] = i;                     // insert AFTER the lookup
}
```

## Variants and Details
- **Look up before inserting.** This stops an element from pairing with itself. Duplicates still work because the earlier copy is already in the map.
- **What to store:** the index (to return positions), a count (to count pairs), or the earliest index (for the longest subarray).
- **Prefix-sum variant:** the complement is `prefix - k` and the map holds prefix sums (e.g. 0560 Subarray Sum Equals K, not yet in the wiki). Seed the map with `{0: 1}` or `{0: -1}`.
- **Sorted input:** use [two pointers](two-pointers.md) instead for O(1) extra space (0167 Two Sum II).
- **Degenerate form, where the complement is `x` itself:** duplicate detection. You only need membership, not an index, so a [hash set](../concepts/hash-set.md) is enough: `if (!seen.insert(x).second) return true;` ([0217](../problems/0217-contains-duplicate.md)).

## Problems in This Wiki
| Problem | Difficulty | How it's used |
|---------|------------|---------------|
| [0001 Two Sum](../problems/0001-two-sum.md) | Easy | `value -> index` map; look up `target - x` before inserting `x` |
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | Easy | hash set; the complement is `x` itself, so the first failed insert means a duplicate |

## Common Mistakes by Members
_(None recorded yet. @hehsun got the lookup-before-insert order right on the first try.)_
