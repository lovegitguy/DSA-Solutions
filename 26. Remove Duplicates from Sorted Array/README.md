# LeetCode 26 — Remove Duplicates from Sorted Array

## Problem

Given an integer array `nums` sorted in non-decreasing order, remove duplicates in-place so that each unique element appears only once.

Return the number of unique elements, `k`. The first `k` elements of the array must contain the unique elements in their original order.

## Approach: Two Pointers

Since the array is sorted, duplicate elements appear next to each other. We can compare each element with the element immediately before it to identify unique values.

### Algorithm

1. If the array is empty, return `0`.
2. Initialize `k = 1`, because the first element is always unique when the array is non-empty.
3. Iterate through the array starting at index `1`.
4. If `nums[i] != nums[i - 1]`, the current element is unique:

   * Place it at `nums[k]`.
   * Increment `k`.
5. Return `k`.

## C++ Solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```

## Example

**Input:**

```text
nums = [0,0,1,1,1,2,2,3,3,4]
```

**Output:**

```text
k = 5
```

The first five elements become:

```text
[0,1,2,3,4]
```

## Complexity Analysis

* **Time Complexity:** O(n), because each element is visited once.
* **Auxiliary Space Complexity:** O(1), because the array is modified in-place without using another array.

## Key Learnings

* Using the sorted property to identify duplicates efficiently.
* Applying the Two Pointers technique.
* Modifying an array in-place.
* Tracking the number of unique elements using an index.

## Conclusion

This solution efficiently removes duplicates from a sorted array in O(n) time and O(1) auxiliary space.
