
# 453. Minimum Moves to Equal Array Elements

## Problem

Given an integer array `nums`, find the minimum number of moves required to make all array elements equal.

In one move, you can increment `n - 1` elements by 1.

## Approach: Mathematical Observation + Minimum Element

Instead of incrementing `n - 1` elements, we can think of it as **decrementing one element by 1**.

To make all elements equal with minimum moves, we need to bring every element down to the smallest element in the array.

### Algorithm

1. Find the minimum element using `ranges::min(nums)`.
2. Calculate the difference between every element and the minimum.
3. Add all differences to get the minimum number of moves.
4. Return the accumulated sum.

## Code

```cpp
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    const int mn = ranges::min(nums);
    return accumulate(nums.begin(), nums.end(), 0,
    [&](int acc, int num) { return acc + (num - mn); });
  }
};
```

## Complexity Analysis

* **Time Complexity:** `O(n)`

  * Finding the minimum takes `O(n)`.
  * Accumulating the differences takes `O(n)`.

* **Space Complexity:** `O(1)`

  * Only a constant amount of extra space is used.

## Key Learnings

* Used `ranges::min()` to find the smallest element.
* Used `accumulate()` with a custom lambda function.
* Understood how a mathematical transformation can simplify an array problem.
* Recognized that incrementing `n - 1` elements is equivalent to decrementing one element.

## Key Takeaway

Sometimes, changing how we interpret an operation makes a problem much easier. Instead of simulating moves, we can use a mathematical observation to calculate the answer directly.
