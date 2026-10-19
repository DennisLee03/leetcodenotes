---
problem: 217
title: Contains Duplicate
difficulty: Easy
url: https://leetcode.com/problems/contains-duplicate
---

<!-- Save as notes/<your-handle>/<NNNN>-<slug>.md, e.g. notes/hehsun/0003-longest-substring-without-repeating-characters.md
     Solving it again later? Add a new "## Attempt N" section below. Write notes in any language. -->

## Attempt 1 — 2026-10-11
result:  AC
language: C++
time_spent:
used_hint:  no

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

#### Call by Reference/Value
大概會有三種形式去傳遞參數, 以 `vector<int>` 為例:
```cpp
bool containsDuplicate(vector<int> nums);        // (1) call by value
bool containsDuplicate(vector<int>& nums);       // (2) call by reference
bool containsDuplicate(const vector<int>& nums); // (3) call by constant reference
```

1. **call by value**: 複製整個參數的資料進入這個 function 內部, 花費 $O(n)$, 在此執行任何操作都是在這個複本上運行, 不會影響 caller 的資料內容
2. **call by reference**: 把 caller 提供的參數作一個別名在此 function 內部使用, 任何操作都會影響 caller 的提供的那個參數, 就是給很多限制的 pointer(例如一定要初始化, 不能改 pointer 指向)
3. **call by constant reference**: read-only reference

#### Vector
> resizable contiguous array
* Access Element:
     1. 可以使用 `operator[]` 拿出 element, 就像是 C 的 array 那樣使用
     2. 但它可以使用 `at()` 去拿出 element, 這個 member function 會 check boundary
* Capacity:
     1. `size()` returns #elements
     2. `capacity()` returns #elements can be held in current storage

#### Unordered Set, Set

||set|unordered_set|
|---|---|---|
|Ordering|yes|no|
|Implementation|self-balancing BST|hash table|
|Search time|$O(log(n))$|$O(1)$, $O(n)$ worst case|
|Insert time|$O(log(n)) + rebalance$|same as search|
|Delete time|$O(log(n)) + rebalance$|same as search|

* rehash:
     * 當 $load\, factor$ = $\frac{\#elements}{\#buckets}$ 超過設定的數值時, 就需要弄出更多 bucket, 分配 elements 進去新的 buckets 當中, 這件事情就是 rehash
     * `unordered_set` 底層實作是 hash table 所以 insert 可能會 rehash