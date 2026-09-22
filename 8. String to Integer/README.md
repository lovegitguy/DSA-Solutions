# LeetCode 8 — String to Integer (atoi)

## Problem

Given a string `s`, convert it into a 32-bit signed integer.

The conversion follows these rules:

1. Ignore leading whitespace.
2. Check for an optional `+` or `-` sign.
3. Read the digits until a non-digit character is encountered.
4. If no valid number is found, return `0`.
5. If the number goes outside the 32-bit signed integer range, clamp it to:

   * `INT_MAX = 2147483647`
   * `INT_MIN = -2147483648`

### Examples

```text
Input:  "42"
Output: 42
```

```text
Input:  "   -42"
Output: -42
```

```text
Input:  "4193 with words"
Output: 4193
```

```text
Input:  "words and 987"
Output: 0
```

---

## Approach

We process the string from left to right.

### 1. Skip leading spaces

```cpp
while (i < s.size() && s[i] == ' ') {
    i++;
}
```

We move the index forward until we reach a non-space character.

### 2. Handle the sign

If the current character is `+` or `-`, we store the sign.

```cpp
if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
    if (s[i] == '-') {
        sign = -1;
    }
    i++;
}
```

The default sign is `1`.

### 3. Build the number digit by digit

For every digit:

```cpp
num = num * 10 + (s[i] - '0');
```

For example, converting `"123"`:

```text
num = 0

0 * 10 + 1 = 1
1 * 10 + 2 = 12
12 * 10 + 3 = 123
```

`(s[i] - '0')` converts a character such as `'7'` into the integer `7`.

### 4. Stop at a non-digit

The loop continues only while the current character is a digit:

```cpp
while (i < s.size() && isdigit(s[i]))
```

For:

```text
"4193 with words"
```

we process:

```text
4193
```

and stop when we reach the space/letters.

### 5. Handle integer overflow

The result must remain within the 32-bit signed integer range.

```cpp
if (sign * num > INT_MAX) {
    return INT_MAX;
}

if (sign * num < INT_MIN) {
    return INT_MIN;
}
```

A `long long` is used while constructing the number so that we have extra space to detect overflow safely.

---

## Code

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long num = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};
```

## Complexity

### Time Complexity

```text
O(n)
```

We scan the string at most once.

### Space Complexity

```text
O(1)
```

Only a few variables are used regardless of the input size.

---

## Key Concepts Learned

* String traversal
* Character checking with `isdigit()`
* Converting a character digit using `s[i] - '0'`
* Handling positive and negative signs
* Building an integer digit by digit
* Handling integer overflow
* Using `long long` for intermediate calculations

## Key Formula

```cpp
num = num * 10 + (s[i] - '0');
```

This is the main idea behind converting a sequence of digit characters into an integer.
