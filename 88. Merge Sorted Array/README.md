# LeetCode 88: Merge Sorted Array

##  Problem

Given two integer arrays, `nums1` and `nums2`, sorted in non-decreasing order, merge `nums2` into `nums1` so that the final array is also sorted in non-decreasing order.

* `m` represents the number of valid elements in `nums1`.
* `n` represents the number of elements in `nums2`.
* `nums1` has enough space to accommodate all elements from both arrays.
* The merged result must be stored directly in `nums1`.

##  Approach: Three Pointers

Instead of merging from the beginning and potentially overwriting valid elements, we merge the arrays **from the end**.

We use three pointers:

* `i = m - 1`: Points to the last valid element of `nums1`.
* `j = n - 1`: Points to the last element of `nums2`.
* `k = m + n - 1`: Points to the last position of the merged array.

### Algorithm

1. Initialize the three pointers.
2. Continue while `j >= 0`, meaning elements from `nums2` still need to be merged.
3. If `i >= 0` and `nums1[i] > nums2[j]`:

   * Copy `nums1[i]` into `nums1[k]`.
   * Decrement `i` and `k`.
4. Otherwise:

   * Copy `nums2[j]` into `nums1[k]`.
   * Decrement `j` and `k`.
5. Stop when all elements from `nums2` have been placed.

Any remaining elements in `nums1` are already in their correct positions.

##  C++ Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};
```

##  Example

**Input:**

```text
nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3
```

**Output:**

```text
[1, 2, 2, 3, 5, 6]
```

##  Complexity Analysis

### Time Complexity: O(m + n)

Each element from the two arrays is processed at most once.

### Auxiliary Space Complexity: O(1)

The algorithm modifies `nums1` directly and uses only three integer pointers. No additional array is created.

##  Key Learnings

* The **two-pointer technique** can be extended to three pointers when merging arrays in place.
* Processing elements from the end helps prevent overwriting valid data.
* The `while (j >= 0)` condition is sufficient because any remaining elements in `nums1` are already correctly positioned.
* The condition `i >= 0` prevents accessing invalid indices when all valid elements of `nums1` have been processed.
* The post-decrement operator (`k--`, `i--`, and `j--`) updates the index after using its current value.

##  Pattern

**In-place Array Merging + Two Pointers**

This technique is useful for merging sorted arrays and understanding how to manipulate arrays without allocating extra space.
