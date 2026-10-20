---
id: 242
title: Valid Anagram
difficulty: Easy
url: https://leetcode.com/problems/valid-anagram/
patterns: [frequency-count]
concepts: [hash-map, cpp-references]
solved_by: [dennis]
last_updated: 2026-10-20
---

# 0242. Valid Anagram

## Problem
Return `true` if string `t` is a rearrangement of string `s`, meaning both use exactly the same characters with the same counts. The input is lowercase English letters only.

## Key Insight
Two strings are anagrams exactly when their character counts match. Count the characters, then compare the counts. With a fixed alphabet of 26 letters, a plain `int[26]` is the counter.

## Solutions

### Solution A: Two hash maps (by @dennis, 2026-10-19)
- Idea: check the lengths first, count each string's characters into its own `unordered_map<char,int>`, then check that every key of `um1` has the same count in `um2`.
- Complexity: Time O(n), Space O(k), where k = number of distinct characters.

```cpp
if (s.size() != t.size()) return false;
unordered_map<char, int> um1, um2;
for (size_t i = 0; i < s.size(); i++) {
    if (um1.find(s[i]) != um1.end()) um1[s[i]]++; else um1[s[i]] = 1;
    if (um2.find(t[i]) != um2.end()) um2[t[i]]++; else um2[t[i]] = 1;
}
for (auto it = um1.begin(); it != um1.end(); it++)
    if (um2.find(it->first) == um2.end() || um2[it->first] != it->second) return false;
return true;
```
- Simplification: `um[c]++` already default-initializes a missing key to 0, so the `find`/else branches can be replaced with just `um1[s[i]]++;`. See [hash map](../concepts/hash-map.md).
- Note: [dennis/0242-valid-anagram.md](../../notes/dennis/0242-valid-anagram.md)

### Solution B: Two counting arrays (by @dennis, 2026-10-19)
- Idea: the member read the constraints (lowercase `a`–`z` only) and replaced the maps with `int sa[26], ta[26]`, indexed by `c - 'a'`.
- Complexity: Time O(n), Space O(1) (26 ints).

```cpp
int sa[26] = {0}, ta[26] = {0};
for (size_t i = 0; i < s.size(); i++) { sa[s[i] - 'a']++; ta[t[i] - 'a']++; }
for (size_t i = 0; i < 26; i++) if (sa[i] != ta[i]) return false;
return true;
```
- One array is enough (LLM suggestion): `cnt[s[i]-'a']++; cnt[t[i]-'a']--;`, then check that every entry is 0.

### Solution C: Sort and compare (from the LeetCode editorial, recorded in @dennis's note)
```cpp
sort(s.begin(), s.end());
sort(t.begin(), t.end());
return s == t;
```
- Complexity: Time O(n log n), Space O(1) to O(n) depending on the sort.
- It's safe to sort here because LeetCode passes `string s, string t` **by value**, so you're sorting copies and the caller's strings don't change. Compare with [0217](0217-contains-duplicate.md), where `nums` is passed by reference and sorting would change the caller's data. See [C++ References](../concepts/cpp-references.md).

## Pitfalls / Common Mistakes
- **Skipping the length check.** Without it, the one-directional comparison in Solution A (only iterating `um1`'s keys) would accept `s = "a", t = "ab"`. The early `size` check is what makes iterating one map sufficient.
- **`int[26]` only works for a fixed alphabet.** For the follow-up with Unicode input, go back to a hash map.
- **The `find`-then-insert dance** for counting is unnecessary in C++, because `operator[]` creates the entry with value 0.

## Related Problems
- [0217 Contains Duplicate](0217-contains-duplicate.md): also hash-based; it needs a set (membership) where this problem needs counts.
- [0001 Two Sum](0001-two-sum.md): hash map as a lookup table.
- LLM-suggested: 0383 Ransom Note (one count array), 0049 Group Anagrams (sorted string or count as the map key), 0438 Find All Anagrams in a String (counts plus a sliding window).

## Attempt History
| Date | Member | Attempt | Result | Language | Note |
|------|--------|---------|--------|----------|------|
| 2026-10-19 | dennis | 1 (hash map) | AC | cpp | [note](../../notes/dennis/0242-valid-anagram.md) |
| 2026-10-19 | dennis | 1 (count array) | AC | cpp | [note](../../notes/dennis/0242-valid-anagram.md) |
