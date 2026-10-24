# LeetCode 1480: Running Sum of 1d Array

## Problem

Given an integer array `nums`, return an array `runningSum` where `runningSum[i]` is the sum of all elements from index `0` to index `i`.

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

* Index 0: `1`
* Index 1: `1 + 2 = 3`
* Index 2: `1 + 2 + 3 = 6`
* Index 3: `1 + 2 + 3 + 4 = 10`

## Approach: Prefix Sum

Instead of recalculating the sum from the beginning for every index, I reuse the running sum calculated for the previous index.

1. Create an empty vector called `answer`.
2. Store the first element of `nums` in `answer` because the first running sum is simply `nums[0]`.
3. Iterate through the remaining elements, starting at index `1`.
4. Add the current element `nums[i]` to the previous running sum `answer[i - 1]`.
5. Append the calculated sum to `answer`.
6. Return the completed vector.

### Key Formula

For the first element:

`answer[0] = nums[0]`

For every subsequent element:

`answer[i] = nums[i] + answer[i - 1]`

## C++ Solution

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;

        answer.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i] + answer[i - 1];
            answer.push_back(sum);
        }

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity: O(n)** — The array is traversed once, and each iteration performs a constant amount of work.
* **Auxiliary Space Complexity: O(1)** — No additional working data structure is required beyond a constant number of variables, excluding the output.
* **Output Space Complexity: O(n)** — The `answer` vector stores one running sum for each input element.

## Example Dry Run

Input: `nums = [1, 2, 3, 4]`

| Index `i` | Current Element `nums[i]` | Previous Running Sum | New Running Sum |
| --------- | ------------------------: | -------------------: | --------------: |
| 0         |                         1 |       Not applicable |               1 |
| 1         |                         2 |                    1 |               3 |
| 2         |                         3 |                    3 |               6 |
| 3         |                         4 |                    6 |              10 |

Output: `[1, 3, 6, 10]`

## What I Learned

* How to traverse an array efficiently.
* How to use previously calculated results to avoid repeated work.
* How the prefix sum pattern works.
* How to improve a brute-force solution from `O(n²)` time to `O(n)` time.
* Why the first element needs separate initialization when using the previous prefix sum.

## Optimization Insight

My initial brute-force approach recalculated the sum from index `0` for every position, resulting in `O(n²)` time complexity.

The optimized approach reuses the previous running sum, reducing the time complexity to `O(n)`.

This technique is a foundation for more advanced prefix sum and subarray problems.
