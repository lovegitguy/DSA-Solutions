# LeetCode 977 — Squares of a Sorted Array

**Difficulty:** Easy
**Approach:** Brute Force + Sorting
**Language:** C++

## Intuition

Square every element of the given array and store the squared values in a separate vector using `push_back()`.

Since squaring negative numbers can disturb the sorted order, sort the resulting vector using `sort()`.

## Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;

        for(int n : nums) {
            answer.push_back(n * n);
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n log n)

  * Traversing the array takes O(n).
  * Sorting takes O(n log n).

* **Space Complexity:** O(n)

  * A separate vector stores the squared elements.

## Key Learnings

* Range-based for loops.
* `push_back()` to insert elements.
* Using `sort()` to arrange elements in ascending order.
* Squaring negative numbers can change the original order.
