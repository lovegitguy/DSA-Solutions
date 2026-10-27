# LeetCode 1295 — Find Numbers with Even Number of Digits

## Problem

Given an array of integers `nums`, return the number of elements that contain an even number of digits.

## Approach: Range Checking

Instead of counting the digits of every number individually, we check whether each number falls within a range representing an even number of digits.

### Algorithm

1. Initialize `ans = 0` to count the numbers with an even number of digits.
2. Traverse the array using a range-based `for` loop.
3. Check whether each number:

   * Is between 10 and 99 (two digits).
   * Is between 1000 and 9999 (four digits).
   * Is equal to 100000 (six digits).
4. If any condition is satisfied, increment `ans`.
5. Return `ans`.

## C++ Solution

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (int num : nums)
            if (9 < num && num < 100 ||
                999 < num && num < 10000 ||
                num == 100000)
                ++ans;

        return ans;
    }
};
```

## Example

**Input:**

```text
nums = [12, 345, 2, 6, 7896]
```

**Output:**

```text
2
```

**Explanation:**

* `12` has 2 digits.
* `345` has 3 digits.
* `2` has 1 digit.
* `6` has 1 digit.
* `7896` has 4 digits.

Only `12` and `7896` have an even number of digits, so the answer is `2`.

## Complexity Analysis

* **Time Complexity:** O(n), where `n` is the number of elements in the array. Each element is checked once.
* **Auxiliary Space Complexity:** O(1), because only a constant amount of additional memory is used.

## Key Learnings

* Traversing vectors using range-based `for` loops.
* Using comparison operators to check numeric ranges.
* Combining conditions with logical OR (`||`) and AND (`&&`).
* Counting elements that satisfy a condition.

## Conclusion

This solution efficiently counts numbers with an even number of digits by checking their numeric ranges without explicitly counting their digits.
