# 566. Reshape the Matrix

## Problem

Given a 2D matrix `mat` and two integers `r` and `c`, reshape the matrix into a new matrix with `r` rows and `c` columns.

The elements must remain in the same order.

If reshaping is not possible, return the original matrix.

## Approach: Nested Loops + Index Mapping

The idea is to traverse the original matrix and place each element into its correct position in the reshaped matrix.

First, check whether reshaping is possible by comparing the total number of elements:

`Original Rows × Original Columns = New Rows × New Columns`

If the totals are different, return the original matrix.

Otherwise, create a new matrix using:

```cpp
vector<vector<int>> result(r, vector<int>(c));
```

Use a counter `k` to track the position of each element in the new matrix.

Calculate its destination using:

* New Row = `k / c`
* New Column = `k % c`

## Code

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        if(mat.size() * mat[0].size() != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        int k = 0;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                result[k / c][k % c] = mat[i][j];
                k++;
            }
        }

        return result;
    }
};
```

## Complexity Analysis

**Time Complexity: O(m × n)**

* We traverse every element of the original matrix exactly once.
* Each element is placed into the new matrix in constant time.

**Space Complexity: O(r × c)**

* We create a new matrix containing `r × c` elements.
* The counter variable uses O(1) extra space.

## Key Learnings

* Understanding 2D vectors in C++.
* Initializing a matrix with predefined rows and columns.
* Traversing a 2D matrix using nested loops.
* Converting a linear index into 2D coordinates.
* Using integer division `/` and modulo `%` for index mapping.
* Preserving element order while reshaping a matrix.

