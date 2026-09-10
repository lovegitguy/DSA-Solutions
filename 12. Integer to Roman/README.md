# LeetCode 12 — Integer to Roman

**Difficulty:** Medium

**Problem:** [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

## 📌 Problem Statement

Given an integer `num`, convert it to a Roman numeral.

Roman numerals are represented using the following symbols:

| Symbol | Value |
| :----: | ----: |
|    I   |     1 |
|    V   |     5 |
|    X   |    10 |
|    L   |    50 |
|    C   |   100 |
|    D   |   500 |
|    M   |  1000 |

Roman numerals also use subtractive notation:

```text
4    → IV
9    → IX
40   → XL
90   → XC
400  → CD
900  → CM
```

### Examples

```text
Input: 3749

Output: MMMDCCXLIX

Input: 58

Output: LVIII

Input: 1994

Output: MCMXCIV
```

---

## 💡 Approach

We use a **Greedy Approach**.

The idea is to always choose the **largest possible Roman numeral value** and subtract it from `num`.

We store the values and their corresponding Roman symbols in **descending order**:

```text
1000 → M
900  → CM
500  → D
400  → CD
100  → C
90   → XC
50   → L
40   → XL
10   → X
9    → IX
5    → V
4    → IV
1    → I
```

For each value:

1. Check whether `num` is greater than or equal to that value.
2. If it is, append the corresponding symbol.
3. Subtract the value from `num`.
4. Repeat until the value can no longer be used.

---

## 🔍 Step-by-Step

Consider:

```text
num = 1994
```

Initially:

```text
num = 1994
result = ""
```

Take `1000`:

```text
1994 - 1000 = 994
result = "M"
```

Take `900`:

```text
994 - 900 = 94
result = "MCM"
```

Take `90`:

```text
94 - 90 = 4
result = "MCMXC"
```

Take `4`:

```text
4 - 4 = 0
result = "MCMXCIV"
```

Therefore:

```text
1994 → MCMXCIV
```

---

## 🔢 Why Do We Include 900, 400, 90, 40, 9 and 4?

Roman numerals use **subtractive notation**.

For example, instead of writing:

```text
IIII
```

we write:

```text
IV
```

Similarly:

```text
9   → IX
40  → XL
90  → XC
400 → CD
900 → CM
```

By including these values in our array, the greedy approach automatically generates the correct Roman numeral.

---

## 🧠 Algorithm

```text
Create a list of Roman values in descending order.

For every value and symbol:
    While num >= value:
        Append symbol to result
        Subtract value from num

Return result
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> values = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string result = "";

        for (auto &[value, symbol] : values) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
```

---

## 🧪 Dry Run

Consider:

```text
num = 58
```

Start:

```text
result = ""
num = 58
```

`50 → L`

```text
num = 8
result = "L"
```

`5 → V`

```text
num = 3
result = "LV"
```

`1 → I`

```text
num = 2
result = "LVI"
```

`1 → I`

```text
num = 1
result = "LVII"
```

`1 → I`

```text
num = 0
result = "LVIII"
```

Final answer:

```text
58 → LVIII
```

---

## 📊 Another Example

For:

```text
num = 3749
```

We can break it down as:

```text
3749 = 3000 + 700 + 40 + 9
```

Roman representation:

```text
3000 → MMM
700  → DCC
40   → XL
9    → IX
```

Therefore:

```text
3749 → MMMDCCXLIX
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(1)
```

There are only a fixed number of Roman numeral values.

Even though a `while` loop is used, the input range is limited (`1` to `3999`), so the number of operations is bounded by a constant.

### Space Complexity

```text
O(1)
```

The lookup table contains a fixed number of values.

The output string is not considered extra auxiliary space.

---

## 📚 Key Takeaways

* Use a **greedy approach** to convert an integer to Roman numerals.
* Store Roman numeral values in **descending order**.
* Include subtractive combinations such as `IV`, `IX`, `XL`, `XC`, `CD`, and `CM`.
* Always choose the largest possible value first.
* Continue subtracting until the number becomes `0`.
* The solution runs in **O(1)** time and uses **O(1)** auxiliary space.

---

## 🔗 LeetCode

[LeetCode — Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
