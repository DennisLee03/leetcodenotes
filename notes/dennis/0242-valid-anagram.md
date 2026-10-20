---
problem: 242
title: Valid Anagram
difficulty:  Easy
url: https://leetcode.com/problems/valid-anagram
---

## Attempt 1 — 2026-10-19
result:                AC
language: C++
time_spent:    4ms
used_hint:     no

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // different sizes, not anagram
        if(s.size() != t.size()) return false;

        unordered_map<char, int> um1, um2;

        for(size_t i=0; i<s.size(); i++) {
            if(um1.find(s[i]) != um1.end()) {
                um1[s[i]]++;
            } else {
                um1[s[i]] = 1;
            }
            if(um2.find(t[i]) != um2.end()) {
                um2[t[i]]++;
            } else {
                um2[t[i]] = 1;
            }
        }

        for(auto it = um1.begin(); it != um1.end(); it++) {
            // not found or not equal
            if(um2.find(it->first) == um2.end() || um2[it->first] != it->second) {    
                return false;
            }
        }
        return true;
    }
};
```

## Attempt 1 — 2026-10-19
result:                AC
language: C++
time_spent:    0ms
used_hint:     no

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // different sizes, not anagram
        if(s.size() != t.size()) return false;
        
        // 2 arrays to keep counts
        int sa[26] = {0};
        int ta[26] = {0};

        for(size_t i=0; i<s.size(); i++) {
            sa[s[i] - 'a']++;
            ta[t[i] - 'a']++;
        }

        for(size_t i=0; i<26; i++) {
            if(sa[i] != ta[i]) return false;
        }
        return true;
    }
};
```

### Notes
* 第一次使用 `unordered_map` 去 hash 出累加的 entry 來統計各個字元出現的次數來比對兩個字串
* 仔細看了 input 的限制之後就會看到它只會出現 [a-z] 索性就用 array 會更方便
* 偷看 solution 就發現總共三種解法:
    1. hash map
    2. array
    3. 排序兩個字串, 相等就是 anagram
        ```cpp
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
        ```
* C++ 的 `std::string` 一樣是有 iterator 的用法