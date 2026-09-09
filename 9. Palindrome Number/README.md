# LeetCode 9 — Palindrome Number

**Difficulty:** Easy
**Problem:** [Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## 📌 Problem Statement

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

A palindrome number reads the same forward and backward.

### Examples

```text
Input: 121
Output: true

Input: -121
Output: false

Input: 10
Output: false
```

---

## 💡 Approach

Instead of reversing the entire number, we reverse only **half of the digits**.

This approach has two advantages:

* It avoids unnecessary work.
* It avoids integer overflow that could occur when reversing the entire number.

We maintain two values:

* `x` — the remaining first half of the number.
* `reversedhalf` — the reversed second half.

We continue extracting digits until:

```cpp
x <= reversedhalf
```

At this point, we have processed approximately half of the digits.

---

## 🔍 Step-by-Step

Consider:

```text
x = 1221
```

Initially:

```text
x = 1221
reversedhalf = 0
```

Extract the last digit:

```text
reversedhalf = 1
x = 122
```

Extract another digit:

```text
reversedhalf = 12
x = 12
```

Now:

```text
x = 12
reversedhalf = 12
```

The two halves are equal, so `1221` is a palindrome.

---

## 🔢 Handling Odd Number of Digits

Consider:

```text
x = 12321
```

After processing half of the digits:

```text
x = 12
reversedhalf = 123
```

The middle digit `3` belongs to `reversedhalf`.

We remove the middle digit using:

```cpp
reversedhalf / 10
```

Therefore:

```text
12 == 123 / 10
12 == 12
```

So the number is a palindrome.

---

## 🚫 Edge Cases

### Negative Numbers

Negative numbers are not considered palindromes.

```text
-121 → false
```

Therefore:

```cpp
if (x < 0)
    return false;
```

### Numbers Ending in Zero

A positive number ending in `0` cannot be a palindrome.

For example:

```text
10 → false
```

The only exception is `0` itself.

```cpp
if (x % 10 == 0 && x != 0)
    return false;
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedhalf = 0;

        while (x > reversedhalf) {
            reversedhalf = reversedhalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedhalf || x == reversedhalf / 10;
    }
};
```

---

## 🧠 Why Does This Work?

There are two possible cases.

### Even Number of Digits

Example:

```text
1221
```

Split into:

```text
12 | 21
```

Reverse the second half:

```text
12 | 12
```

So:

```cpp
x == reversedhalf
```

is true.

### Odd Number of Digits

Example:

```text
12321
```

Split around the middle:

```text
12 | 3 | 21
```

After reversing:

```text
12 | 123
```

The middle digit doesn't need to be compared, so remove it:

```cpp
reversedhalf / 10
```

Then:

```text
12 == 12
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(log₁₀(n))
```

We process approximately half of the digits.

### Space Complexity

```text
O(1)
```

Only a constant number of integer variables are used.

---

## 📚 Key Takeaways

* A negative number cannot be a palindrome.
* A positive number ending in `0` cannot be a palindrome.
* Only half of the digits need to be reversed.
* For odd-length numbers, the middle digit can be ignored.
* This approach avoids reversing the complete integer.
* The solution uses constant extra space.

---

## 🔗 LeetCode

[LeetCode — Palindrome Number](https://leetcode.com/problems/palindrome-number/)
