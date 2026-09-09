# LeetCode 7 — Reverse Integer

**Difficulty:** Medium
**Problem:** [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## 📌 Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits reversed.

If reversing `x` causes the value to go outside the signed 32-bit integer range:

```text
[-2³¹, 2³¹ - 1]
```

return `0`.

> **Note:** The environment does not allow storing 64-bit integers.

### Examples

| Input  | Output |
| ------ | ------ |
| `123`  | `321`  |
| `-123` | `-321` |
| `120`  | `21`   |

---

## 💡 Approach

We can reverse the integer digit by digit.

For every iteration:

1. Extract the last digit using:

   ```cpp
   digit = x % 10;
   ```

2. Remove the last digit from `x`:

   ```cpp
   x /= 10;
   ```

3. Add the extracted digit to the reversed number:

   ```cpp
   reversed = reversed * 10 + digit;
   ```

The main challenge is **integer overflow**.

Since we cannot use a `long long`, we need to check whether multiplying `reversed` by `10` and adding the next digit would exceed the 32-bit integer range **before performing the operation**.

---

## 🔍 Overflow Handling

The valid 32-bit signed integer range is:

```text
INT_MIN = -2147483648
INT_MAX =  2147483647
```

Before calculating:

```cpp
reversed = reversed * 10 + digit;
```

we check:

```cpp
if (reversed > INT_MAX / 10 ||
    (reversed == INT_MAX / 10 && digit > 7))
    return 0;

if (reversed < INT_MIN / 10 ||
    (reversed == INT_MIN / 10 && digit < -8))
    return 0;
```

Why `7` and `-8`?

Because:

```text
INT_MAX = 2147483647
INT_MIN = -2147483648
```

The last valid digit for `INT_MAX` is `7`, while the last valid digit for `INT_MIN` is `-8`.

This allows us to detect overflow **without using a 64-bit integer**.

---

## 🧠 Algorithm

```text
Initialize reversed = 0

While x is not 0:

    digit = x % 10
    x = x / 10

    Check whether reversed * 10 + digit would overflow

    reversed = reversed * 10 + digit

Return reversed
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for positive overflow
            if (reversed > INT_MAX / 10 ||
                (reversed == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            // Check for negative overflow
            if (reversed < INT_MIN / 10 ||
                (reversed == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};
```

---

## 🧪 Example Walkthrough

### Input

```text
x = 123
```

### Step 1

```text
digit = 3
reversed = 0 * 10 + 3
         = 3
```

### Step 2

```text
digit = 2
reversed = 3 * 10 + 2
         = 32
```

### Step 3

```text
digit = 1
reversed = 32 * 10 + 1
         = 321
```

Therefore:

```text
Output = 321
```

---

## 🔴 Negative Numbers

The same logic works for negative numbers because C++ preserves the sign when using `%` and `/`.

For:

```text
x = -123
```

we get:

```text
digit = -3
digit = -2
digit = -1
```

and eventually:

```text
reversed = -321
```

---

## 🧩 Edge Cases

### Trailing zeros

```text
Input: 120
Output: 21
```

The zero disappears naturally because integer arithmetic does not preserve leading zeros.

### Single digit

```text
Input: 7
Output: 7
```

### Zero

```text
Input: 0
Output: 0
```

### Overflow

For example:

```text
Input: 1534236469
Output: 0
```

because its reversed value exceeds the signed 32-bit integer range.

---

## ⏱️ Complexity

Let `n` be the number of digits in `x`.

### Time Complexity

```text
O(log₁₀ |x|)
```

We process each digit exactly once.

### Space Complexity

```text
O(1)
```

Only a few integer variables are used.

---

## 📚 Key Takeaways

* Extract digits using `% 10`.
* Remove digits using `/ 10`.
* Build the reversed number using:

  ```cpp
  reversed = reversed * 10 + digit;
  ```
* Handle overflow **before** performing the multiplication.
* No `long long` is required.
* The solution uses constant extra space.

---

## 🔗 LeetCode

[LeetCode — Reverse Integer](https://leetcode.com/problems/reverse-integer/)
