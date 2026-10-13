# 283. Move Zeroes

**Platform:** LeetCode
**Difficulty:** Easy
**Topics:** Array, Two Pointers

## Problem Statement

Given an integer array `nums`, move all `0`s to the end of it while maintaining the relative order of the non-zero elements.

The operation must be performed in place without making a copy of the array.

## Approach: Move Non-Zero Elements First

1. Initialize an index `i = 0` to track the position where the next non-zero element should be placed.
2. Traverse the array using a range-based for loop.
3. Whenever a non-zero element is encountered, place it at index `i` and increment `i`.
4. After processing all non-zero elements, fill the remaining positions with zeros.

This approach preserves the relative order of all non-zero elements and modifies the original array.

## C++ Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (const int num : nums) {
            if (num != 0) {
                nums[i++] = num;
            }
        }

        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};
```

## Example

**Input:**

```text
nums = [0,1,0,3,12]
```

**Output:**

```text
[1,3,12,0,0]
```

**Explanation:**

The non-zero elements `1`, `3`, and `12` retain their original relative order. Both zeros are moved to the end.

## Complexity Analysis

* **Time Complexity:** `O(n)` — The array is traversed twice in the worst case.
* **Auxiliary Space Complexity:** `O(1)` — The solution modifies the original array without creating another array.

## Key Learnings

* Using an index to track the next valid position.
* Modifying an array in place.
* Preserving the relative order of elements.
* Using a range-based for loop in C++.
* Applying the two-pointer technique to array problems.

## Conclusion

The solution efficiently moves all zeros to the end while maintaining the relative order of non-zero elements. It achieves linear time complexity and constant auxiliary space.
