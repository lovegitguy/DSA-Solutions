# 414. Third Maximum Number

## Problem

Given an integer array `nums`, return the **third distinct maximum number** in the array. If the third maximum does not exist, return the maximum number.

## Approach: Using Set (STL)

### Intuition

A `set` automatically stores elements in **sorted ascending order** and removes duplicates.

We can use a set to:

1. Insert all elements of the array into the set.
2. Check whether the set contains at least three distinct elements.
3. If fewer than three distinct elements exist, return the largest element.
4. Otherwise, use a reverse iterator to access the third-largest element.

### Code

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        if(s.size() < 3) {
            return *s.rbegin();
        }
        else {
            auto it = s.rbegin();
            it++;
            it++;
            return *it;
        }
    }
};
```

### STL Concepts Used

* **`set<int>`**: Stores unique elements in sorted ascending order.
* **`s.rbegin()`**: Returns a reverse iterator pointing to the largest element.
* **`it++`**: Moves the reverse iterator towards smaller elements.
* **`s.size()`**: Returns the number of distinct elements.

### Complexity Analysis

Let `n` be the number of elements in `nums`.

* **Time Complexity:** `O(n log n)` — Inserting all elements into a set.
* **Space Complexity:** `O(n)` — The set can store up to `n` distinct elements.

## Key Takeaway

This problem demonstrates how `set` can simplify problems involving unique elements and sorted order.

Using reverse iterators allows us to access the largest, second-largest, and third-largest elements without manually sorting the array.
