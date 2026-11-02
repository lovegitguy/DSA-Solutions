# 462. Minimum Moves to Equal Array Elements II

## Problem Statement

Given an integer array `nums`, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element by 1.

## Approach: Sorting + Median

1. **Sort the array** using `sort(nums.begin(), nums.end())`.
2. Find the **median** of the sorted array using `nums[nums.size()/2]`.
3. Iterate through the array and calculate the absolute difference between each element and the median.
4. Add all differences to `moves`.
5. Return the total number of moves.

### Code

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;

        for(int i = 0; i < nums.size(); i++) {
            int target = nums[nums.size()/2];
            moves += abs(nums[i] - target);
        }

        return moves;
    }
};
```

## Why Median?

The median minimizes the sum of absolute differences between all elements and a single target value.

Therefore, converting every element to the median requires the minimum number of moves.

## Complexity Analysis

* **Time Complexity:** `O(n log n)`

  * Sorting takes `O(n log n)`.
  * Traversing the array takes `O(n)`.

* **Space Complexity:** `O(1)` auxiliary space (excluding sorting implementation details).

## Key Learnings

* Using `sort()` to arrange array elements.
* Understanding and finding the median.
* Using `abs()` to calculate absolute differences.
* Applying mathematical observations to optimize a problem.
