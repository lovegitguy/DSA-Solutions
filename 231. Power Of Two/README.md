# Power of Two

## Problem

Given an integer `n`, return `true` if `n` is a **power of two**. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that:

```text
n = 2^x
```

### Example

```text
Input:
n = 16

Output:
true
```

Because:

```text
16 → 8 → 4 → 2 → 1
```

Another example:

```text
Input:
n = 12

Output:
false
```

Because:

```text
12 → 6 → 3
```

`3` cannot be divided by `2` evenly.

---

## Approach

We repeatedly divide `n` by `2`.

1. If `n` is less than or equal to `0`, it cannot be a power of two.
2. While `n` is greater than `1`:

   * Check if `n` is divisible by `2`.
   * If it is not divisible by `2`, return `false`.
   * Otherwise, divide `n` by `2`.
3. If we successfully reach `1`, the number is a power of two.

### Example

For `16`:

```text
16 → 8 → 4 → 2 → 1
```

Every division is exact, so the answer is `true`.

For `12`:

```text
12 → 6 → 3
```

`3 % 2 != 0`, so the answer is `false`.

---

## Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }

        while(n > 1) {
            if(n % 2 != 0) {
                return false;
            }

            n = n / 2;
        }

        return true;
    }
};
```

---

## Complexity

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## Key Idea

> *Keep dividing the number by 2. If we can reach 1 using only exact divisions, the number is a power of two.*
