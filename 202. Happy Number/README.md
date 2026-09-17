# 202. Happy Number

## 🧩 Problem

Given a positive integer `n`, determine whether it is a **happy number**.

A happy number is a number that eventually becomes `1` when repeatedly replaced by the sum of the squares of its digits.

If the process enters a cycle that never reaches `1`, the number is not happy.

### Example

```text
Input: n = 19

19 → 82 → 68 → 100 → 1

Output: true
```

---

## 💡 Approach

I used a **`set`** to keep track of numbers that have already appeared.

The process works like this:

1. Create an empty `set` called `seen`.
2. Continue while `n` is not `1`.
3. Check whether `n` has already appeared in `seen`.
4. If it has appeared before, a cycle exists, so return `false`.
5. Otherwise, insert `n` into the set.
6. Extract each digit using `% 10`.
7. Square each digit and add it to `total`.
8. Set `n = total` and repeat.
9. If `n` reaches `1`, return `true`.

---

## 🧠 Why Do We Need a Set?

Some numbers enter an endless cycle.

For example:

```text
4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
```

When `4` appears again, we know that the process is repeating.

The set allows us to detect this:

```cpp
if(seen.find(n) != seen.end())
{
    return false;
}
```

---

## 💻 Solution

```cpp
class Solution {
public:
    bool isHappy(int n) {

        set<int> seen;

        while(n != 1)
        {
            if(seen.find(n) != seen.end())
            {
                return false;
            }

            seen.insert(n);

            int total = 0;

            while(n != 0)
            {
                int digit = n % 10;
                total += digit * digit;
                n = n / 10;
            }

            n = total;
        }

        return true;
    }
};
```

---

## 🔍 Important Parts

### Extracting a digit

```cpp
int digit = n % 10;
```

Gets the last digit of `n`.

### Removing the last digit

```cpp
n = n / 10;
```

For example:

```text
19 → 1
1 → 0
```

### Calculating the square

```cpp
total += digit * digit;
```

For `19`:

```text
1² + 9²
= 1 + 81
= 82
```

### Detecting a cycle

```cpp
if(seen.find(n) != seen.end())
```

If the number already exists in `seen`, the process is repeating.

---

## ⏱️ Complexity

The number of possible values encountered before reaching `1` or entering a cycle is limited.

For each value, we process its digits.

### Time Complexity

Approximately:

```text
O(log n)
```

per transformation, with a small bounded number of transformations for this problem.

### Space Complexity

```text
O(k)
```

where `k` is the number of values stored in `seen`.

---

## 📚 What I Learned

* How to use a `set` for **cycle detection**.
* How `set.find()` can check whether a value has appeared before.
* How `set.insert()` keeps track of visited values.
* How `% 10` extracts digits.
* How `/ 10` removes digits.
* How nested loops can solve a problem with repeated digit transformations.
* How to turn a raw approach into a complete LeetCode solution.

### 🚀 Main Takeaway

> **A `set` can be used to remember previously seen values and detect cycles.**
