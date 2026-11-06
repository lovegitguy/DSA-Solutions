# 1252. Cells with Odd Values in a Matrix

## Problem

You are given an `m × n` matrix initially filled with zeros and a list of coordinates called `indices`.

For every coordinate `[ri, ci]`:
- Increment every cell in row `ri` by 1.
- Increment every cell in column `ci` by 1.

Return the total number of cells containing odd values after all operations.

## Approach: Boolean Arrays + XOR

Instead of creating and updating the entire matrix, we use two boolean arrays:

- `rows` — tracks whether each row has been incremented an odd number of times.
- `cols` — tracks whether each column has been incremented an odd number of times.

Both arrays are initialized with `false`.

### 1. Process the indices

For every coordinate `[ri, ci]`, toggle the corresponding row and column:

```cpp
rows[index[0]] = rows[index[0]] ^ true;
cols[index[1]] = cols[index[1]] ^ true;
```

The XOR (`^`) operator toggles a boolean value:
- `false ^ true = true`
- `true ^ true = false`

This means:
- Odd number of increments → `true`
- Even number of increments → `false`

### 2. Count odd-valued cells

A cell receives increments from both its row and its column.

Therefore, its final value is odd when exactly one of the two corresponding boolean values is `true`.

We use XOR again:

```cpp
ans += rows[i] ^ cols[j];
```

If the XOR result is `true`, the cell contains an odd value, so we increment `ans`.

## C++ Solution

```cpp
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans = 0;

        vector<bool> rows(m);
        vector<bool> cols(n);

        for (const vector<int>& index : indices) {
            rows[index[0]] = rows[index[0]] ^ true;
            cols[index[1]] = cols[index[1]] ^ true;
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans += rows[i] ^ cols[j];

        return ans;
    }
};
```

## Complexity Analysis

Let:
- `m` = number of rows
- `n` = number of columns
- `k` = number of coordinates in `indices`

**Time Complexity: `O(k + m × n)`**
- Processing all coordinates takes `O(k)`.
- Checking every cell takes `O(m × n)`.

**Space Complexity: `O(m + n)`**
- The `rows` vector stores `m` boolean values.
- The `cols` vector stores `n` boolean values.
- No complete matrix is created.

## Key Learnings

- Using `vector<bool>` to track boolean states.
- Understanding XOR (`^`) as a toggle operation.
- Using parity (odd/even number of increments) instead of storing actual values.
- Optimizing a matrix problem by avoiding unnecessary matrix modifications.
- Using range-based `for` loops with `const vector<int>&`.

## Takeaway

We don't always need to construct or modify an entire matrix to solve a matrix problem.

By tracking whether each row and column has been incremented an odd or even number of times, XOR allows us to determine the parity of every cell efficiently.