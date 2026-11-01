# 1920. Build Array from Permutation

## Problem

Given a zero-indexed permutation array `nums`, construct an array `ans` such that:

`ans[i] = nums[nums[i]]`

Return the resulting array.

## Approach: Nested Array Indexing

We create a new vector to store the resulting elements and traverse the original array using an indexed `for` loop.

### Algorithm

1. Create an empty vector `ans`.
2. Iterate through the array using a `for` loop.
3. Access `nums[nums[i]]` for each index.
4. Insert the accessed element into `ans` using `push_back()`.
5. Return the answer vector.

## Code

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};
```

## Example

**Input:**

```text
nums = [0,2,1,5,3,4]
```

**Output:**

```text
[0,1,2,4,5,3]
```

## Complexity Analysis

* **Time Complexity:** `O(n)` — We traverse the array once.
* **Space Complexity:** `O(n)` — We create an additional vector to store the result.

## Key Learnings

* Practiced indexed array traversal.
* Understood nested array indexing.
* Used `push_back()` to construct a new vector.
* Improved understanding of accessing array elements through other array values.

## Key Takeaway

An array element can itself be used as an index to access another element. Mastering this concept builds a strong foundation for more advanced array problems.
