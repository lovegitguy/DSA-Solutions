# 1351. Count Negative Numbers in a Sorted Matrix

## Problem

You are given an `m × n` matrix where:
- Each row is sorted in non-increasing order.
- Each column is sorted in non-increasing order.

Return the total number of negative numbers in the matrix.

## Approach 1: Brute Force (Nested Loops)

We traverse the entire matrix using two nested loops.

1. The outer loop iterates through every row.
2. The inner loop iterates through every column.
3. If `grid[i][j] < 0`, increment the counter.
4. Return the final count.

## C++ Solution

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] < 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

## Complexity Analysis

Let:
- `m` = number of rows.
- `n` = number of columns.

**Time Complexity: `O(m × n)`**

We visit every element in the matrix exactly once.

**Space Complexity: `O(1)`**

We only use one additional variable, `count`.

## Key Learnings

- Traversing a 2D matrix using nested loops.
- Accessing matrix elements using `grid[i][j]`.
- Counting elements that satisfy a condition.
- Understanding brute-force approaches before optimization.

## Takeaway

A straightforward nested-loop traversal is often the easiest way to solve matrix problems. However, when a matrix has sorted rows and columns, we can use that property to develop a more efficient approach.

## Future Optimization

An optimized solution can achieve `O(m + n)` time using staircase traversal.