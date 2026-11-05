# 1380. Lucky Numbers in a Matrix

## Problem

Given an `m x n` matrix of distinct numbers, return all Lucky Numbers in the matrix.

A Lucky Number is an element that is:

* The minimum element in its row.
* The maximum element in its column.

Both conditions must be satisfied.

## Approach: Row Minimum and Column Maximum

1. Calculate the number of rows (`m`) and columns (`n`).
2. Create two vectors:

   * `rowMins` stores the minimum element of each row.
   * `colMax` stores the maximum element of each column.
3. Initialize `rowMins` with `INT_MAX` and `colMax` with `INT_MIN`.
4. Traverse the matrix using nested loops:

   * Use `min()` to find the minimum of each row.
   * Use `max()` to find the maximum of each column.
5. Traverse the matrix again.
6. Check whether each element satisfies both conditions:

   ```cpp
   matrix[i][j] == rowMins[i] && matrix[i][j] == colMax[j]
   ```
7. If both conditions are true, add the element to the result vector.
8. Return the result.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMins(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowMins[i] = min(rowMins[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == rowMins[i] &&
                   matrix[i][j] == colMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};
```

## Complexity Analysis

Let:

* `m` = Number of rows.

* `n` = Number of columns.

* **Time Complexity:** O(m × n) — We traverse the entire matrix twice.

* **Space Complexity:** O(m + n) — We use two auxiliary vectors to store row minimums and column maximums.

## Key Concepts Learned

* 2D Vectors in C++
* Matrix Traversal using Nested Loops
* Row-wise Minimum Calculation
* Column-wise Maximum Calculation
* `min()` and `max()` STL Functions
* `INT_MAX` and `INT_MIN`
* Precomputation
* Comparing Row and Column Properties
