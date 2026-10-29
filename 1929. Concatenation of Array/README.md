# LeetCode 1929: Concatenation of Array

## Problem

Given an integer array `nums` of length `n`, create a new array `ans` of length `2 * n` by concatenating `nums` with itself.

In other words:

* `ans[i] = nums[i]`
* `ans[i + n] = nums[i]`

## Approach

1. Calculate the size of the input array using `nums.size()` and store it in `n`.
2. Create a new vector `ans` of size `2 * n`. Its elements are initially initialized to `0`.
3. Iterate through the original array using a `for` loop.
4. For each index `i`, assign `nums[i]` to both `ans[i]` and `ans[i + n]`.
5. Return the completed array.

### Key Concept: Multiple Assignment

```cpp
ans[i] = ans[i + n] = nums[i];
```

This statement assigns `nums[i]` to `ans[i + n]` first, then assigns the same value to `ans[i]`.

This allows us to populate both halves of the result array in a single statement.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; ++i) {
            ans[i] = ans[i + n] = nums[i];
        }

        return ans;
    }
};
```

## Example

**Input:**

```text
nums = [1, 2, 1]
```

**Output:**

```text
[1, 2, 1, 1, 2, 1]
```

**Explanation:**

The original array has three elements, so the result array has six positions.

| Index `i` | `nums[i]` | `ans[i]` | `ans[i + n]` |
| --------: | --------: | -------: | -----------: |
|         0 |         1 |        1 |            1 |
|         1 |         2 |        2 |            2 |
|         2 |         1 |        1 |            1 |

The original array is copied into both halves of `ans`.

## Complexity Analysis

* **Time Complexity:** `O(n)` — We traverse the input array once, performing constant-time assignments at each iteration.
* **Space Complexity:** `O(n)` — The result vector contains `2n` elements, requiring linear space.

## Key Takeaways

* `nums.size()` returns the number of elements in a vector.
* `vector<int> ans(2 * n)` creates a vector with `2n` elements.
* Array indexing allows us to place each element in two different positions.
* Multiple assignment lets us initialize both halves in one statement.

## Conclusion

This solution efficiently concatenates an array with itself using a single loop and direct indexing. It demonstrates how understanding vector initialization and array indices can produce clean, efficient C++ code.
