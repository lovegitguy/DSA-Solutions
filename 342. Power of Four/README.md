# Power of Four

## Problem

Given an integer `n`, return `true` if `n` is a **power of four**. Otherwise, return `false`.

A number is a power of four if it can be written as:

```text
4^k
```

where `k` is a non-negative integer.

### Example

**Example 1**

```text
Input: n = 16
Output: true
Explanation: 4² = 16
```

**Example 2**

```text
Input: n = 5
Output: false
```

**Example 3**

```text
Input: n = 1
Output: true
Explanation: 4⁰ = 1
```

---

## Approach

The simplest way to solve this is to repeatedly divide the number by `4`.

### Steps

1. If `n` is less than or equal to `0`, return `false`.
2. Keep dividing `n` by `4` while it is greater than `1`.
3. Before dividing, check whether `n` is perfectly divisible by `4`.
4. If it is not divisible by `4`, then it cannot be a power of four.
5. If we eventually reach `1`, the number is a power of four.

### Why does this work?

Powers of four follow this pattern:

```text
1 → 4 → 16 → 64 → 256 → 1024 → ...
```

Every number in this sequence can be repeatedly divided by `4` until it reaches `1`.

For example:

```text
64 → 16 → 4 → 1
```

But:

```text
20 → 5
```

Since `5` cannot be divided by `4` evenly, `20` is not a power of four.

---

## Code

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }

        while(n > 1) {
            if(n % 4 != 0) {
                return false;
            }

            n = n / 4;
        }

        return true;
    }
};
```

---

## Complexity

* **Time:** `O(log₄ n)` — we divide `n` by `4` in every iteration.
* **Space:** `O(1)` — only a few variables are used.

---

## Key Idea

> Keep dividing the number by `4`. If every division is exact and the number eventually becomes `1`, then it is a power of four.
