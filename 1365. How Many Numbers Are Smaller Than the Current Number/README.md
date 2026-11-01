# 1365. How Many Numbers Are Smaller Than the Current Number

## Problem

Given an integer array `nums`, return an array `answer` where `answer[i]` represents the number of elements strictly smaller than `nums[i]`.

## Approach: Brute Force (Nested Loops)

We use two nested loops to compare every element with every other element.

### Algorithm

1. Create an empty vector `answer`.
2. Traverse the array using an outer loop.
3. Initialize `count = 0` for each element.
4. Use an inner loop to compare the current element with every element in the array.
5. If `nums[i] > nums[j]`, increment `count`.
6. Push `count` into the answer vector.
7. Return the answer vector.

## Code

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++) {
            int count = 0;

            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] > nums[j] && j != i) {
                    count++;
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};
```

## Example

**Input:**

```text
nums = [8,1,2,2,3]
```

**Output:**

```text
[4,0,1,1,3]
```

## Complexity Analysis

* **Time Complexity:** `O(n²)` — For every element, we traverse the entire array.
* **Space Complexity:** `O(n)` — The answer vector stores `n` elements.

## Key Learnings

* Practiced nested `for` loops.
* Learned to compare every element against the entire array.
* Practiced using a counter to track conditions.
* Understood how to construct an answer vector using `push_back()`.

## Key Takeaway

Nested loops are useful when a problem requires comparing every element with every other element. This brute-force approach builds a strong foundation for understanding more optimized solutions.
