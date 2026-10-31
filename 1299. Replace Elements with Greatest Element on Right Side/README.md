# 1299. Replace Elements with Greatest Element on Right Side

## Problem

Given an array `arr`, replace every element with the greatest element among the elements to its right. Replace the last element with `-1`.

## Approach: Right-to-Left Traversal

Instead of repeatedly searching for the greatest element on the right, maintain a variable called `maxOfRight`.

1. Initialize `maxOfRight = -1`, since the last element must be replaced with `-1`.
2. Traverse the array from right to left.
3. Use `exchange(arr[i], maxOfRight)` to:

   * Replace `arr[i]` with the current maximum from its right.
   * Return the original value of `arr[i]`.
4. Update `maxOfRight` using `max()` to maintain the greatest element encountered so far.
5. Return the modified array.

## C++ Solution

```cpp
class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int maxOfRight = -1;

    for (int i = arr.size() - 1; i >= 0; --i)
      maxOfRight = max(maxOfRight, exchange(arr[i], maxOfRight));

    return arr;
  }
};
```

## Complexity Analysis

* **Time Complexity:** O(n) — We traverse the array exactly once.
* **Space Complexity:** O(1) — We modify the original array using only one additional variable.

## Key Learnings

* Right-to-left array traversal.
* Maintaining a running maximum.
* Using `exchange()` to replace a value while retrieving its original value.
* Optimizing repeated maximum searches into a single traversal.
