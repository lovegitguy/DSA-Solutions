# 448. Find All Numbers Disappeared in an Array

## Problem

Given an array `nums` of length `n` where all integers are in the range `[1, n]`, some elements appear twice while others appear once.

Return an array containing all the integers in the range `[1, n]` that do not appear in `nums`.

## Approach: Index Marking (Negative Marking)

Instead of using an additional data structure to track which numbers exist, we use the given array itself.

### Logic

1. Create an empty vector called `answer`.

2. Traverse the array using a loop.

3. Calculate the corresponding index using:

   `index = abs(nums[i]) - 1`

4. Check whether the element at that index is positive.

5. If positive, make it negative to indicate that the corresponding number has been visited.

6. Traverse the array again.

7. If an element is still positive, its corresponding number is missing.

8. Add `i + 1` to the answer vector.

### Why Negative Marking?

* Positive value indicates that the corresponding number has not been visited.
* Negative value indicates that the corresponding number exists in the array.
* `abs()` ensures that previously marked negative values can still be used to calculate the correct index.
* The condition `nums[index] > 0` prevents an already-negative value from becoming positive again.
## Code

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer;
        for(int i =0 ;i<nums.size();i++){
            int index = abs(nums[i]) - 1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }
        }

        for(int j=0;j<nums.size();j++){
            
            if(nums[j]>0){
                answer.push_back(j+1);
            }
        }
    return answer;
    }
};
```

---

## Complexity Analysis

| Complexity       | Value | Explanation                                            |
| ---------------- | ----- | ------------------------------------------------------ |
| Time Complexity  | O(n)  | Two traversals of the array.                           |
| Space Complexity | O(1)  | Constant auxiliary space, excluding the output vector. |

## Key Learnings

* Using array indices to represent numbers.
* Negative marking technique.
* Using `abs()` to handle previously modified elements.
* Solving problems without an additional visited array.
* Understanding in-place array manipulation.

## LeetCode

[Find All Numbers Disappeared in an Array – Problem 448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
