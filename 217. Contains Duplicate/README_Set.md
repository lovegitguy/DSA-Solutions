# 217. Contains Duplicate

## 🧩 Problem

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is unique.

### Example

```text
Input:
nums = [1, 2, 3, 1]

Output:
true
```

---

## 💡 Approach

For this solution, I used a **`set`** to keep track of the elements I have already seen.

The important idea is:

> Before inserting an element into the set, check whether it already exists.

For every number in the array:

1. Search for the number in the set using `find()`.
2. If it is already present, a duplicate exists → return `true`.
3. Otherwise, insert it into the set.
4. If the loop finishes without finding a duplicate, return `false`.

---

## 🔄 Step-by-Step Example

For:

```text
nums = [1, 2, 3, 1]
```

Initially:

```text
set = {}
```

### `num = 1`

`1` is not in the set.

```text
set = {1}
```

### `num = 2`

`2` is not in the set.

```text
set = {1, 2}
```

### `num = 3`

`3` is not in the set.

```text
set = {1, 2, 3}
```

### `num = 1`

`1` is already in the set.

Therefore:

```text
return true;
```

---

## 🧠 STL Concepts Used

### `set`

```cpp
set<int> s;
```

A `set` stores unique elements.

### `find()`

```cpp
s.find(num)
```

Searches for `num` inside the set.

If the element is not found:

```cpp
s.find(num) == s.end()
```

If the element is found:

```cpp
s.find(num) != s.end()
```

### `insert()`

```cpp
s.insert(num);
```

Adds the number to the set.

---

## 💻 Solution

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        set<int> s;

        for(int num : nums)
        {
            if(s.find(num) != s.end())
            {
                return true;
            }
            else
            {
                s.insert(num);
            }
        }

        return false;
    }
};
```

---

## ⏱️ Complexity

Let `n` be the number of elements in `nums`.

### Time Complexity

Each `set` insertion/search takes `O(log n)`.

For `n` elements:

```text
O(n log n)
```

### Space Complexity

The set can store up to `n` unique elements:

```text
O(n)
```

---

## 🔁 Previous vs New Approach

I previously solved this problem using **sorting**.

### Sorting approach

```text
Sort the array
      ↓
Check adjacent elements
      ↓
Duplicate found?
```

Time:

```text
O(n log n)
```

Space:

```text
O(1)
```

### Set approach

```text
Create a set
      ↓
Check each number
      ↓
Already exists?
   ↙       ↘
 YES       NO
  ↓         ↓
true      insert
```

Time:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

## 📚 What I Learned

* How to use a `set` for duplicate detection.
* How `set.find()` works.
* Why checking **before inserting** is important.
* How `set` automatically maintains unique elements.
* How to use a range-based `for` loop with a set-based solution.
* How the same problem can be solved using different approaches.

### 🚀 Main Takeaway

> **A set is useful when I need to remember previously seen values and quickly check whether a value already exists.**
