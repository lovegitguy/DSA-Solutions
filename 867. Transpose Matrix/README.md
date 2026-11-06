# 867. Transpose Matrix

## Problem
Given a 2D integer matrix, return its transpose.

The transpose of a matrix is obtained by flipping the matrix over its main diagonal, switching its rows and columns.

## Approach: Nested Loops + 2D Vector

### 1. Find Matrix Dimensions

First, calculate the number of rows and columns.

```cpp
int m = matrix.size();
int n = matrix[0].size();
```

- `m` represents the number of rows.
- `n` represents the number of columns.

### 2. Initialize the Answer Matrix

Since transposition swaps rows and columns, the resulting matrix will have `n` rows and `m` columns.

```cpp
vector<vector<int>> answer(n, vector<int>(m));
```

This creates a 2D vector with the required dimensions.

### 3. Traverse the Original Matrix

Use nested loops to visit every element.

```cpp
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        answer[j][i] = matrix[i][j];
    }
}
```

The important observation is that the row and column indices are swapped:

- Original position: `matrix[i][j]`
- Transposed position: `answer[j][i]`

### 4. Return the Result

Return the newly created transposed matrix.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> answer(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                answer[j][i] = matrix[i][j];
            }
        }

        return answer;
    }
};
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(m × n) | Every matrix element is visited once. |
| Space | O(m × n) | A new matrix is created to store the transpose. |

## Key Learnings

1. `matrix.size()` returns the number of rows.
2. `matrix[0].size()` returns the number of columns.
3. A 2D vector can be initialized using `vector<vector<int>>(rows, vector<int>(columns))`.
4. Matrix transposition swaps row and column indices.
5. `answer[j][i] = matrix[i][j]` is the central operation.

## Tags
`Array` `Matrix` `2D Vector` `Nested Loops`

**Status:** Solved

**Key Takeaway:** Transposition changes the dimensions of a matrix from `m × n` to `n × m` by swapping the row and column indices.