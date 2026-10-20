---
problem: 27
title: Remove Element
difficulty: Easy           # Easy / Medium / Hard (optional — Claude can fill this in the wiki)
url: https://leetcode.com/problems/remove-element/
---

<!-- Save as notes/<your-handle>/<NNNN>-<slug>.md, e.g. notes/hehsun/0003-longest-substring-without-repeating-characters.md
     Solving it again later? Add a new "## Attempt N" section below. Write notes in any language. -->

## Attempt 1 — YYYY-MM-DD
result: AC               # AC / WA / TLE / MLE / RE / unfinished
language: C++
time_spent:            # optional, e.g. 30m
used_hint: no             # yes / no

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin(); it != nums.end(); ) {
            if(*it == val) {
                it = nums.erase(it);
                continue;
            }
            it++;
        }
        return nums.size();
    }
};
```

### Notes
* vector `erase()` 的效果
    ```plaintext
    {1, 2, 3, 4, 5, 6}
           ^
           it

    -------erase(it)---------

    {1, 2, _, 4, 5, 6}
           ^
           it(失效, iterator invalidation)

    {1, 2, 4, 5, 6}
           ^
           it(回傳補進的這位仁兄的指標)
    ```
* 其他 STL 容器使用 iterator 操作元素的時候要注意 iterator invalidation 的問題
