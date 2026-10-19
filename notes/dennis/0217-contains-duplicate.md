---
problem: 217
title: Contains Duplicate
difficulty: Easy
url: https://leetcode.com/problems/contains-duplicate
---

<!-- Save as notes/<your-handle>/<NNNN>-<slug>.md, e.g. notes/hehsun/0003-longest-substring-without-repeating-characters.md
     Solving it again later? Add a new "## Attempt N" section below. Write notes in any language. -->

## Attempt 1 — YYYY-MM-DD
result:  AC            # AC / WA / TLE / MLE / RE / unfinished
language: C++
time_spent:     # optional, e.g. 30m
used_hint:  no         # yes / no

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        size_t size = nums.size();
        for(size_t i=0; i<size; i++) {
            if(s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
        }

        return false;
    }
};
```

### Notes

#### Set

#### Call by Reference/Value