# 905. Sort Array By Parity

## Problem Statement

Given an integer array `nums`, move all even integers to the beginning of the array, followed by all odd integers.

The relative order of even and odd elements does not need to be maintained.

## Approach: Two Pointers

We use two pointers to rearrange the array in-place.

* `left`: Starts at the beginning of the array.
* `right`: Starts at the end of the array.

### Algorithm

1. Initialize `left = 0` and `right = nums.size() - 1`.
2. Run a `while` loop as long as `left < right`.
3. If `nums[left]` is even, increment `left` because it is already in the correct position.
4. Otherwise, swap `nums[left]` with `nums[right]` and decrement `right`.
5. Return the modified array.

### Code

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            if(nums[left] % 2 == 0) {
                left++;
            }
            else {
                swap(nums[left], nums[right]);
                right--;
            }
        }

        return nums;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n) — Each pointer traverses the array at most once.
* **Space Complexity:** O(1) — Rearrangement happens directly in the original array.

## Key Learnings

* Understanding the Two Pointer technique.
* Using `% 2` to identify even and odd numbers.
* Using `swap()` to exchange array elements.
* Modifying an array in-place without creating an additional vector.
* Understanding how pointer movement can eliminate unnecessary operations.

## Important Observation

We don't need to check whether the right element is odd before swapping.

If the left element is odd, swapping it with the right element is safe. If the right element is even, it moves to the correct side. The next iteration checks the new left element.
