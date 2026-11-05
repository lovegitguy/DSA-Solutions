# 118. Pascal's Triangle

## Problem

Given an integer `numRows`, generate the first `numRows` of Pascal's Triangle.

In Pascal's Triangle:

* The first and last elements of every row are always `1`.
* Every middle element is the sum of the two elements directly above it from the previous row.

## Approach: Dynamic Row Construction

1. Create an empty 2D vector `answer` to store the triangle.

2. Iterate from `0` to `numRows - 1`.

3. For every iteration, create a new row of size `i + 1`, initialized with `1`.

4. Calculate the middle elements using the previous row:

   ```cpp
   row[j] = answer[i-1][j-1] + answer[i-1][j];
   ```

5. Add the completed row to `answer` using `push_back()`.

6. Return the generated triangle.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        for(int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for(int j = 1; j < i; j++) {
                row[j] = answer[i-1][j-1] + answer[i-1][j];
            }

            answer.push_back(row);
        }

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n²) — We construct `n` rows, containing a total of n(n+1)/2 elements.
* **Space Complexity:** O(n²) — The resulting Pascal's Triangle stores n(n+1)/2 elements.

## Key Concepts Learned

* 2D Vectors in C++
* Nested Loops
* Dynamic Row Construction
* `vector<int>(size, value)`
* `push_back()`
* Accessing Previous Rows
* Building Pascal's Triangle Using Previous Results
