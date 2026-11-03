# 27. Remove Element

## Problem

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. Return the number of elements that are not equal to `val`.

The order of the remaining elements does not matter.

## Approach: Two Pointers (Swap with Last Element)

### Intuition

Instead of shifting elements whenever we encounter `val`, we replace the unwanted element with the last element of the current array.

We use two variables:

* `i`: Tracks the current index.
* `n`: Tracks the effective size of the array.

### Algorithm

1. Initialize `i = 0` and `n = nums.size()`.
2. Traverse the array while `i < n`.
3. If `nums[i] == val`:

   * Replace `nums[i]` with the last element (`nums[n-1]`).
   * Decrease `n` because one unwanted element has been removed.
   * Do not increment `i`, because the newly replaced element still needs to be checked.
4. Otherwise, increment `i`.
5. Return `n` as the number of valid elements.

### Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};
```

### Complexity Analysis

Let `n` be the original size of the array.

* **Time Complexity:** `O(n)` — Each element is checked at most once.
* **Space Complexity:** `O(1)` — The operation is performed in-place without using extra space.

### Key Takeaway

This problem demonstrates an efficient two-pointer technique.

Instead of shifting elements or creating another array, we overwrite unwanted elements using the last available element.

**Important:** We don't increment `i` immediately after replacement because the new element at that position might also be equal to `val`.
