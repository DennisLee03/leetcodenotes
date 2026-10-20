# Frequency Count

## Definition and Signals
Count how many times each value appears, then answer the question by comparing or querying the counts instead of the raw sequence.

Think of it when:
- the question is about **multisets**: anagrams, "can X be built from Y", "same characters"
- order doesn't matter, only how many of each
- you're asked for the most or least frequent item, or for items that appear exactly k times

## Template Code
Distilled from [0242 Valid Anagram](../problems/0242-valid-anagram.md) (@dennis, C++):

```cpp
// fixed small alphabet → array
int cnt[26] = {0};
for (char c : s) cnt[c - 'a']++;
for (char c : t) cnt[c - 'a']--;
for (int x : cnt) if (x != 0) return false;

// arbitrary keys → hash map
unordered_map<int, int> freq;
for (int x : nums) freq[x]++;          // operator[] starts missing keys at 0
```

## Variants and Details
- **Array vs hash map:** if the key space is small and known (`a`–`z`, digits, values ≤ 10⁵), an array is faster and uses O(1) space. Otherwise use a [hash map](../concepts/hash-map.md).
- **One counter, +/-:** increment for one input and decrement for the other, then check that everything is zero. This halves the memory and removes the second comparison loop.
- **Length check first** when comparing two multisets. It's cheap, and it lets you compare in one direction only.
- **Sorting is the alternative:** sorted sequences are equal exactly when the multisets are equal. It costs O(n log n) but needs no counter.
- **Sliding-window counts** (0438 Find All Anagrams, not yet in the wiki): keep counts for a moving window by adding the incoming element and removing the outgoing one.

## Problems in This Wiki
| Problem | Difficulty | How it's used |
|---------|------------|---------------|
| [0242 Valid Anagram](../problems/0242-valid-anagram.md) | Easy | compare character counts; hash map first, then `int[26]` |

## Common Mistakes by Members
- @dennis, [0242](../problems/0242-valid-anagram.md): `find` + manual `= 1` initialization before incrementing. `freq[c]++` already does this.
