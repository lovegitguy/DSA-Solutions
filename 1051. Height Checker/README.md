# 1051. Height Checker

## Problem

Students are standing in a line in a particular order represented by the `heights` array.

We need to determine how many students are not standing in the positions they would occupy if their heights were sorted in non-decreasing order.

Return the number of indices where the actual arrangement differs from the expected arrangement.

## Approach: Sorting and Comparison

### Intuition

We create a copy of the original array and sort it to obtain the expected order.

Then, we compare both arrays element by element.

Whenever the elements at the same index differ, we increment our counter.

### Algorithm

1. Create a copy of `heights` called `answer`.
2. Sort `answer` in ascending order.
3. Initialize `numberOfIndices = 0`.
4. Traverse both arrays using a loop.
5. If the elements at the same index are different, increment the counter.
6. Return the counter.

### Code

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> answer = heights;

        sort(answer.begin(), answer.end());

        int numberOfIndices = 0;

        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != answer[i]) {
                numberOfIndices++;
            }
        }

        return numberOfIndices;
    }
};
```

### STL Concepts Used

* **Vector Copying:** Creates an independent copy of the original array.
* **`sort()`:** Sorts the copied vector in ascending order.
* **Vector Indexing:** Compares elements at corresponding positions.

### Complexity Analysis

Let `n` be the number of elements in `heights`.

* **Time Complexity:** `O(n log n)` — Sorting the copied vector, followed by an `O(n)` comparison.
* **Space Complexity:** `O(n)` — Storing a copy of the original vector.

## Key Takeaway

This problem demonstrates how sorting can help identify positional differences between an original array and its expected sorted arrangement.

Instead of modifying the original array, we preserve it and compare it against a sorted copy.
