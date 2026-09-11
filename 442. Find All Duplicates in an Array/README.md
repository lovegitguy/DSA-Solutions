# Find All Duplicates in an Array

## Problem

Given an integer array `nums` of length `n` where:

* `nums[i]` is in the range `[1, n]`
* Each integer appears **once or twice**

Return an array containing all the integers that appear twice.

### Example

```text
Input:
nums = [4,3,2,7,8,2,3,1]

Output:
[2,3]
```

---

## Approach

We use the array itself to keep track of which numbers have already been visited.

For every number `x`:

1. Take its absolute value using `abs(nums[i])`.
2. Use `x - 1` as an index.
3. If `nums[x - 1]` is already negative, `x` has appeared before, so it is a duplicate.
4. Otherwise, make `nums[x - 1]` negative to mark `x` as visited.

### Why `x - 1`?

The numbers range from `1` to `n`, while array indexes range from `0` to `n - 1`.

So:

```text
number 1 → index 0
number 2 → index 1
number 3 → index 2
...
number n → index n - 1
```

---

## Code

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i]);

            if(nums[x-1]<0){
                ans.push_back(x);
            }
            else{
                nums[x-1]=-nums[x-1];
            }
        }

        return ans;
    }
};
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` extra space, excluding the output array.

---

## Key Idea

> Use the sign of each element to mark whether a number has already been seen.

This allows us to find duplicates without using an additional `set`, `map`, or frequency array.
