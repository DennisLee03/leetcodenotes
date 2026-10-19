---
problem: 88
title: Merge Sorted Array
difficulty: Easy           # Easy / Medium / Hard (optional — Claude can fill this in the wiki)
url: https://leetcode.com/problems/merge-sorted-array/
---

<!-- Save as notes/<your-handle>/<NNNN>-<slug>.md, e.g. notes/hehsun/0003-longest-substring-without-repeating-characters.md
     Solving it again later? Add a new "## Attempt N" section below. Write notes in any language. -->

## Attempt 1 — YYYY-MM-DD
result: AC           # AC / WA / TLE / MLE / RE / unfinished
language: C++
time_spent:            # optional, e.g. 30m
used_hint: no          # yes / no

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(size_t i=0; i<n; i++) nums1.erase(nums1.end());

        auto it2 = nums2.begin();
        for(auto it1 = nums1.begin(); it1 != nums1.end() && it2 != nums2.end(); it1++) {
            if(*it1 > *it2) {
                it1 = nums1.insert(it1, *it2);
                it2++;
            }
        }
        for(; it2 != nums2.end(); it2++) {
            nums1.push_back(*it2);
        }
    }
};
```

### Notes

