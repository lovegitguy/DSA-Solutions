# 832. Flipping an Image

## Problem

Given an `n x n` binary matrix, flip the image horizontally and then invert it.

* **Horizontal Flip:** Reverse each row of the matrix.
* **Invert:** Change every `0` into `1` and every `1` into `0`.

Return the modified image.

## Approach: Reverse + Invert

The solution performs two operations on each row.

1. Use `reverse()` to reverse the elements of the current row.
2. Traverse the reversed row.
3. If an element is `0`, change it to `1`.
4. Otherwise, change it to `0`.
5. Return the modified matrix.

Since the matrix is modified directly, there is no need to create another matrix.

## Code

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(int i = 0; i < image.size(); i++) {
            reverse(image[i].begin(), image[i].end());

            for(int j = 0; j < image[i].size(); j++) {
                if(image[i][j] == 0) {
                    image[i][j] = 1;
                }
                else {
                    image[i][j] = 0;
                }
            }
        }

        return image;
    }
};
```

## Complexity Analysis

* **Time Complexity: O(n²)**

  * Reversing each row takes O(n).
  * Inverting each element takes O(n).
  * Both operations are performed for all `n` rows.

* **Space Complexity: O(1) auxiliary space**

  * The matrix is modified in place.
  * No additional matrix or data structure is created.

## Key Learnings

* Using `reverse()` from the C++ STL.
* Understanding horizontal flipping of a matrix.
* Inverting binary values using conditional statements.
* Modifying a 2D vector in place.
* Combining STL functions with nested loops.


