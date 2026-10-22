# 724. Find Pivot Index

**Difficulty:** Easy
**Topics:** Array, Prefix Sum
**Language:** C++

## Problem Statement

Given an integer array `nums`, find the pivot index.

The pivot index is the index where the sum of all elements strictly to the left equals the sum of all elements strictly to the right.

* If the pivot is at index `0`, the left sum is `0`.
* If the pivot is the last index, the right sum is `0`.
* If multiple pivot indices exist, return the leftmost one.
* If no pivot index exists, return `-1`.

**Problem Link:** https://leetcode.com/problems/find-pivot-index/

## Approach: Total Sum and Running Left Sum

Instead of calculating the left and right sums independently for every index, calculate the total sum once and maintain a running left sum.

### Algorithm

1. Initialize `totalSum` and `leftSum` to `0`.

2. Traverse the array once to calculate `totalSum`.

3. Traverse the array again, considering each index as a potential pivot.

4. Calculate the right sum using:

   `rightSum = totalSum - leftSum - nums[i]`

5. If `leftSum == rightSum`, return the current index `i`.

6. Otherwise, add the current element to `leftSum` and continue.

7. If no pivot is found, return `-1`.

### C++ Solution

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        int leftsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            int rightsum = totalsum - leftsum - nums[i];

            if (rightsum == leftsum) {
                return i;
            }

            leftsum += nums[i];
        }

        return -1;
    }
};
```

## Example

**Input:**

```text
nums = [1, 7, 3, 6, 5, 6]
```

**Output:**

```text
3
```

**Explanation:**

At index `3`, the current element is `6`.

* Left sum: `1 + 7 + 3 = 11`
* Right sum: `5 + 6 = 11`

Since both sums are equal, the pivot index is `3`.

## Complexity Analysis

**Time Complexity: O(n)**

The first loop calculates the total sum in `O(n)` time. The second loop checks each index in `O(n)` time.

Overall, `O(n) + O(n) = O(n)`.

**Auxiliary Space Complexity: O(1)**

The algorithm uses a constant number of variables and does not create additional arrays.

## Key Learning

The main lesson is that knowing the total sum and the sum of the elements to the left is enough to calculate the right sum.

This avoids repeatedly traversing both sides of the array for every candidate pivot index.
