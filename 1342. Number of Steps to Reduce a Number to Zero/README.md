# Number of Steps to Reduce a Number to Zero

## Problem

Given an integer `num`, return the number of steps to reduce it to `0`.

In one step:

* If `num` is even, divide it by `2`.
* If `num` is odd, subtract `1`.

Continue until `num` becomes `0`.

### Example

```text
Input:
num = 14

Output:
6
```

The steps are:

```text
14 → 7 → 6 → 3 → 2 → 1 → 0
```

---

## Approach

We repeatedly check whether the current number is even or odd.

1. If `num` is even, divide it by `2`.
2. If `num` is odd, subtract `1`.
3. Increment the step counter after every operation.
4. Continue until `num` becomes `0`.

### Why does this work?

Every operation makes `num` smaller, so eventually it reaches `0`.

```text
Even → num / 2
Odd  → num - 1
```

---

## Code

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;

        while(num != 0) {
            if(num % 2 == 0) {
                num = num / 2;
            }
            else {
                num = num - 1;
            }

            result++;
        }

        return result;
    }
};
```

---

## Complexity

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## Key Idea

> *At every step, check whether the number is even or odd and perform the required operation until it reaches zero.*
