# 1920. Build Array from Permutation

## Problem

Given a zero-indexed permutation array `nums`, construct an array `ans` of the same length such that:

`ans[i] = nums[nums[i]]`

Return the resulting array.

## Approach: Array Indexing

We create a new vector called `ans` to store the resulting elements.

### Algorithm

1. Create an empty vector `ans`.
2. Traverse the original array using a `for` loop.
3. For each index `i`, access `nums[nums[i]]`.
4. Insert the resulting value into `ans` using `push_back()`.
5. Return the completed answer vector.

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

* **Time Complexity:** `O(n)` — We traverse the array exactly once.
* **Space Complexity:** `O(n)` — We create an additional vector to store the answer.

## Key Learnings

* Practiced indexed `for` loop traversal.
* Understood nested array indexing: `nums[nums[i]]`.
* Practiced inserting elements using `push_back()`.
* Learned how to construct and return a new vector.

## Key Takeaway

Array elements can themselves be used as indices to access other elements. Understanding indexing is fundamental to solving more advanced array problems.
