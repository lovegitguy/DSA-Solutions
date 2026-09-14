# Power of Three

## Problem

Given an integer `n`, return `true` if `n` is a **power of three**. Otherwise, return `false`.

A number is a power of three if it can be written as:

```text
3^k
```

where `k` is a non-negative integer.

### Example

**Example 1**

```text
Input: n = 27
Output: true
Explanation: 3³ = 27
```

**Example 2**

```text
Input: n = 0
Output: false
```

**Example 3**

```text
Input: n = 9
Output: true
Explanation: 3² = 9
```

---

## Approach

We can repeatedly divide the number by `3`.

### Steps

1. If `n` is less than or equal to `0`, return `false`.
2. Keep dividing `n` by `3` while `n` is greater than `1`.
3. Before dividing, check whether `n` is perfectly divisible by `3`.
4. If it is not divisible by `3`, then it cannot be a power of three.
5. If `n` eventually becomes `1`, return `true`.

### Why does this work?

Powers of three follow this pattern:

```text
1 → 3 → 9 → 27 → 81 → 243 → ...
```

Every number in this sequence can be repeatedly divided by `3` until it reaches `1`.

For example:

```text
81 → 27 → 9 → 3 → 1
```

But:

```text
20 → 6 → ...
```

Since `20` is not perfectly divisible by `3`, it cannot be a power of three.

---

## Code

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }

        while(n > 1) {
            if(n % 3 != 0) {
                return false;
            }

            n = n / 3;
        }

        return true;
    }
};
```

---

## Complexity

* **Time:** `O(log₃ n)` — `n` is divided by `3` in every iteration.
* **Space:** `O(1)` — no extra space is required.

---

## Key Idea

> Keep dividing `n` by `3`. If every division is exact and `n` eventually becomes `1`, then it is a power of three.
