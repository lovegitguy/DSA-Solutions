# 169. Majority Element

## Problem

Given an array `nums` of size `n`, find the majority element.

The majority element is the element that appears more than `⌊n/2⌋` times.

It is guaranteed that the majority element always exists.

## Approach: Sorting

### Intuition

We can sort the array in ascending order.

Since the majority element appears more than half the time, it will always occupy the middle position of the sorted array.

Therefore, we can simply return the element at index `nums.size() / 2`.

### Algorithm

1. Sort the array using `sort()`.
2. Find the middle index using `nums.size() / 2`.
3. Return the element at that index.

### Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```

### STL Concepts Used

* **`sort()`**: Sorts the array in ascending order.
* **`vector.size()`**: Returns the number of elements in the array.
* **Indexing:** Accesses the middle element using `nums[nums.size()/2]`.

### Complexity Analysis

Let `n` be the number of elements in the array.

* **Time Complexity:** `O(n log n)` — Sorting the array.
* **Space Complexity:** `O(1)` auxiliary space for the sorting approach (excluding implementation-dependent stack space).

## Key Takeaway

Sorting makes this problem straightforward.

Because the majority element appears more than `n/2` times, it must occupy the middle position of the sorted array.

This eliminates the need to explicitly count the frequency of every element.
