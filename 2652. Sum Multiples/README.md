# LeetCode 2652 — Sum Multiples

## Problem Statement

Given a positive integer `n`, return the sum of all integers in the range `[1, n]` that are divisible by **3, 5, or 7**.

## Approach: Iteration and Conditional Checking

The solution iterates through every integer from `1` to `n` and checks whether it is divisible by `3`, `5`, or `7`.

### Steps

1. Initialize `sum = 0` to store the total.
2. Use a `for` loop to iterate from `1` through `n`.
3. For each integer `i`:

   * If `i % 3 == 0`, add `i` to `sum`.
   * Otherwise, if `i % 5 == 0`, add `i` to `sum`.
   * Otherwise, if `i % 7 == 0`, add `i` to `sum`.
4. Return `sum` after the loop finishes.

**Why use `else if`?**

An integer divisible by multiple numbers, such as `15`, must be added only once. The `if-else if` structure ensures that each qualifying integer contributes to the sum only once.

## C++ Solution

```cpp
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0)
                sum += i;
            else if (i % 5 == 0)
                sum += i;
            else if (i % 7 == 0)
                sum += i;
        }

        return sum;
    }
};
```

## Example

**Input:**

```text
n = 10
```

**Qualifying numbers:** `3, 5, 6, 7, 9, 10`

**Calculation:**

```text
3 + 5 + 6 + 7 + 9 + 10 = 40
```

**Output:**

```text
40
```

##  Complexity Analysis

* **Time Complexity:** `O(n)` — The loop checks every integer from `1` to `n`.
* **Space Complexity:** `O(1)` — Only a constant amount of extra space is used.

## Key Learnings

* Using the modulo operator (`%`) to check divisibility.
* Applying conditional statements to filter numbers.
* Accumulating a running total using `sum += i`.
* Avoiding duplicate additions when a number is divisible by multiple divisors.
* Practicing basic array-journey fundamentals: loops, conditions, and arithmetic.

## Optimization Note

The current solution is efficient for this problem's constraints. An alternative approach could use mathematical formulas to calculate the sum of multiples of `3`, `5`, and `7`, while applying inclusion-exclusion to avoid counting common multiples more than once.
