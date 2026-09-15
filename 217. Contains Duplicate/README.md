# 217. Contains Duplicate

**Difficulty:** Easy
**Language:** C++

## Problem

Given an integer array `nums`, return `true` if any value appears at least twice in the array. Otherwise, return `false`.

## Approach

First, sort the array using `sort()`.

After sorting, duplicate values will be next to each other. So we compare every element with the element immediately after it.

* If `nums[i] == nums[i + 1]`, a duplicate exists → return `true`.
* If we finish checking the array without finding a duplicate → return `false`.

## Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
```

## Complexity

* **Time:** O(n log n) — sorting the array
* **Space:** O(1) extra space (ignoring the sorting implementation)

## STL Concepts Practiced

* `vector`
* `sort()`
* `begin()`
* `end()`
* Vector indexing
* Iterator ranges: `[begin, end)`
* Range-based thinking after sorting

## What I Learned

Sorting can make a problem much easier. Instead of comparing every element with every other element, sorting puts equal values together, allowing duplicates to be detected by checking neighboring elements.
