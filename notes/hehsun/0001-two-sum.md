---
problem: 1
title: Two Sum
difficulty: Easy
url: https://leetcode.com/problems/two-sum/
---

## Attempt 1 — 2026-10-16
result: AC
language: cpp
time_spent:
used_hint:
submission: https://leetcode.com/problems/two-sum/submissions/2173862217

```cpp
class Solution {
public:
    unordered_map<int, int> mp;

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                return {i, it->second};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
```

### Notes
- Approach: one-pass hash map from value to index. For each `nums[i]`, look up its complement `target - nums[i]`. If it was seen before, return both indices. Otherwise store `nums[i] -> i`.
- Checking the complement **before** inserting the current number means an element can't pair with itself, and duplicates like `[3,3], target=6` still work.
- Complexity: Time O(n), Space O(n). Brute force (two nested loops) is O(n²).
- Returning `{i, it->second}` puts the indices in reverse order, which is fine because any order is accepted.
- Possible improvement: `mp` is a class member, so it would keep old data if the same `Solution` object were reused for another input. Declaring it inside `twoSum` is safer.
