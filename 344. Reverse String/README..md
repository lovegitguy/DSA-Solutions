# LeetCode #344 — Reverse String

## Problem Statement

Write a function that reverses an array of characters in-place.

The solution must use **O(1) extra memory**, meaning we cannot create another array or vector to store the reversed characters.

## Approach: Two Pointers

I used the **two-pointer technique** to reverse the input vector without creating an additional vector.

### How It Works

1. Initialize `i = 0` to point to the first element.
2. Initialize `j = s.size() - 1` to point to the last element.
3. Continue while `i < j`, ensuring the pointers have not met or crossed.
4. Swap the elements at `s[i]` and `s[j]` using `swap()`.
5. Increment `i` and decrement `j` to move both pointers toward the center.
6. Stop when the pointers meet or cross.

This reverses the array by exchanging elements from opposite ends and moving inward.

## C++ Solution

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            swap(s[i], s[j]);

            i++;
            j--;
        }
    }
};
```

**Note:** Your original condition, `i < j && i <= j`, works, but `i <= j` is redundant because `i < j` already guarantees it. Using just `i < j` is cleaner.

## Example

**Input:**

```text
s = ['h', 'e', 'l', 'l', 'o']
```

**Output:**

```text
s = ['o', 'l', 'l', 'e', 'h']
```

### Dry Run

| Step | `i` | `j` | Operation                     | Array             |
| ---- | --: | --: | ----------------------------- | ----------------- |
| 1    |   0 |   4 | Swap `h` and `o`              | `[o, e, l, l, h]` |
| 2    |   1 |   3 | Swap `e` and `l`              | `[o, l, l, e, h]` |
| 3    |   2 |   2 | Stop because `i < j` is false | `[o, l, l, e, h]` |

The array is now reversed.

## Complexity Analysis

* **Time Complexity: O(n)** — The pointers move toward the center, processing approximately half the elements. Each swap takes constant time.
* **Space Complexity: O(1)** — The original vector is modified directly, and only two integer variables are used.

## Key Learnings

* Understood the two-pointer technique.
* Practiced swapping elements in-place.
* Learned how to traverse an array from opposite ends.
* Understood how to avoid unnecessary extra memory.
* Learned that a loop condition should express exactly when processing must continue.

## Conclusion

The two-pointer technique provides an efficient way to reverse an array in-place. This problem builds a foundation for more advanced array problems involving opposite-direction pointers, such as checking palindromes and finding pairs in sorted arrays.
