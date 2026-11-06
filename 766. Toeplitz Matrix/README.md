# 766. Toeplitz Matrix

## Problem
A matrix is called a **Toeplitz Matrix** if every diagonal from top-left to bottom-right contains the same elements.

Return `true` if the matrix is Toeplitz; otherwise, return `false`.

## Approach: Adjacent Diagonal Comparison

Instead of checking every complete diagonal separately, we compare each element with its bottom-right diagonal neighbour.

For every position `(i, j)`, we check:

`matrix[i][j] == matrix[i+1][j+1]`

If any pair is different, the matrix is not Toeplitz, so we immediately return `false`.

If all comparisons match, we return `true`.

## C++ Solution

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for(int i = 0; i < matrix.size() - 1; i++) {
            for(int j = 0; j < matrix[i].size() - 1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(m × n)` — We traverse the matrix and perform one comparison for each eligible cell.
- **Space Complexity:** `O(1)` — We use no additional data structure; only loop variables.

Here, `m` represents the number of rows and `n` represents the number of columns.

## Key Learnings

- Understanding how 2D matrix indices work.
- Comparing diagonal neighbours using `matrix[i+1][j+1]`.
- Avoiding out-of-bounds access by stopping before the last row and column.
- Using early return to avoid unnecessary comparisons.

## Takeaway

A Toeplitz Matrix does not require checking entire diagonals individually. Comparing every element with its bottom-right neighbour is sufficient to verify the property.