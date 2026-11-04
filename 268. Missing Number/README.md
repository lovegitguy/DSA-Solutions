# 268. Missing Number

## Problem

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Approach: Sorting

Instead of using the mathematical summation formula, we first sort the array in ascending order.

After sorting, every element should ideally be equal to its corresponding index because the numbers start from `0`.

### Logic

1. Sort the array using `sort(nums.begin(), nums.end())`.
2. Traverse the sorted array using a loop.
3. Compare each element `nums[i]` with its index `i`.
4. If `nums[i] != i`, return `i` because that number is missing.
5. If every element matches its index, return `nums.size()` because the missing number is the last number in the range.

## Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }
};
```

## Complexity Analysis

| Complexity       | Value                             | Explanation                                               |
| ---------------- | --------------------------------- | --------------------------------------------------------- |
| Time Complexity  | O(n log n)                        | Sorting takes O(n log n), followed by a linear traversal. |
| Space Complexity | Depends on sorting implementation | `sort()` uses O(log n) auxiliary stack space typically.   |

## Key Learnings

* Sorting arrays using `sort()`.
* Understanding the relationship between array indices and values.
* Detecting missing elements through index comparison.
* Using early returns to avoid unnecessary iterations.
* Understanding how sorting simplifies array problems.


