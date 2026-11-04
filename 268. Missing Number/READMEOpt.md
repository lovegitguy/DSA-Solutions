# 268. Missing Number

## Problem

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Approach: Mathematical Formula

We know that the sum of the first `n` natural numbers starting from `0` is:

$$
Sum = \frac{n(n+1)}{2}
$$

Instead of checking every possible number, we calculate the expected sum and subtract the actual sum of the array.

The difference gives us the missing number.

## Logic

1. Calculate the expected sum using `n * (n + 1) / 2`.
2. Traverse the array and calculate its actual sum.
3. Subtract the actual sum from the expected sum.
4. The result is the missing number.

## Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;

        long long originalSum =
            (long long)nums.size() * (nums.size() + 1) / 2;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return originalSum - sum;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n)

  * Calculating the expected sum takes O(1).
  * Traversing the array takes O(n).

* **Space Complexity:** O(1)

  * Only a constant amount of extra memory is used.

## Key Learnings

* Applying mathematical formulas to solve array problems.
* Using the expected sum to identify missing elements.
* Avoiding unnecessary sorting or extra data structures.
* Understanding why `long long` helps prevent integer overflow.

