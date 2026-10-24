# LeetCode 1480: Running Sum of 1d Array

## Problem

Given an array `nums`, return an array `runningSum` where each element is the sum of all elements from index `0` to the current index.

### Example

**Input:**

```text
nums = [1, 2, 3, 4]
```

**Output:**

```text
[1, 3, 6, 10]
```

**Explanation:**

* `runningSum[0] = 1`
* `runningSum[1] = 1 + 2 = 3`
* `runningSum[2] = 1 + 2 + 3 = 6`
* `runningSum[3] = 1 + 2 + 3 + 4 = 10`

## Approach: Brute Force

I used two nested loops to calculate the running sum for every index.

1. The outer loop iterates through each index `i` of the input array.
2. For every index `i`, I initialize `sum = 0`.
3. The inner loop traverses the array from index `0` to index `i`, adding each element to `sum`.
4. After calculating the running sum, I append it to the `answer` vector.
5. Finally, I return `answer`.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = 0; j <= i; j++) {
                sum += nums[j];
            }

            answer.push_back(sum);
        }

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity:** `O(n²)` — For each index `i`, the inner loop recalculates the sum from the beginning of the array. Across all iterations, the total number of additions is proportional to `n(n + 1) / 2`.
* **Auxiliary Space Complexity:** `O(1)` — Only a constant amount of additional working space is used, excluding the output vector.
* **Output Space Complexity:** `O(n)` — The `answer` vector stores `n` running sums.

## Key Learnings

* Practiced array traversal using nested loops.
* Learned to calculate prefix sums by accumulating elements from the beginning of an array.
* Understood how repeatedly calculating sums increases time complexity.
* Identified an opportunity to optimize the solution by reusing previously calculated running sums.

## Possible Optimization

The solution can be optimized to **`O(n)` time** by adding each element to the previous running sum instead of recalculating the sum from the beginning every time.

This problem introduces the **prefix sum pattern**, which is useful for solving more advanced array and subarray problems.
