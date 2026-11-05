# 1572. Matrix Diagonal Sum

## Problem

Given a square matrix `mat`, return the sum of the elements on both its primary and secondary diagonals.

If the matrix has an odd number of rows, the middle element belongs to both diagonals and must only be counted once.

## Approach: Single Loop Traversal

1. Initialize `sum = 0`.
2. Traverse the matrix using a single loop.
3. Calculate the primary diagonal using:

   ```cpp
   mat[i][i]
   ```
4. Calculate the secondary diagonal using:

   ```cpp
   mat[i][mat.size() - 1 - i]
   ```
5. Add both diagonal elements to `sum`.
6. Check whether the matrix size is odd using:

   ```cpp
   mat.size() % 2 == 1
   ```
7. If the size is odd, subtract the center element once because it was counted twice.
8. Return the final sum.

## C++ Solution

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;

        for(int i = 0; i < mat.size(); i++) {
            sum += mat[i][i];
            sum += mat[i][mat.size() - 1 - i];
        }

        if(mat.size() % 2 == 1) {
            sum -= mat[mat.size() / 2][mat.size() / 2];
        }

        return sum;
    }
};
```

## Complexity Analysis

Let `n` be the number of rows (or columns) in the square matrix.

* **Time Complexity:** O(n) — We traverse the matrix once using a single loop.
* **Space Complexity:** O(1) — We use only one extra variable, `sum`.

## Key Concepts Learned

* 2D Vectors in C++
* Matrix Indexing
* Primary Diagonal Traversal
* Secondary Diagonal Traversal
* Single Loop Optimization
* Odd and Even Number Checking using `%`
* Avoiding Duplicate Counting
