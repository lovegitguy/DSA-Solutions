# 🧩 Two Sum

> **LeetCode #1 — Easy**

A clean and efficient solution to the classic **Two Sum** problem using a **Hash Map**, achieving **O(n)** time complexity.

---

## 📌 Problem

Given an array of integers `nums` and an integer `target`, return the **indices of the two numbers** such that they add up to `target`.

### Rules

* Each input has **exactly one valid solution**.
* You may **not use the same element twice**.
* The answer can be returned in **any order**.

---

## 💡 Example

### Example 1

```text
Input:
nums = [2, 7, 11, 15]
target = 9

Output:
[0, 1]

Explanation:
nums[0] + nums[1] = 2 + 7 = 9
```

### Example 2

```text
Input:
nums = [3, 2, 4]
target = 6

Output:
[1, 2]
```

### Example 3

```text
Input:
nums = [3, 3]
target = 6

Output:
[0, 1]
```

---

## 🚀 Approach

A brute-force solution would check every possible pair, resulting in:

```text
O(n²)
```

Instead, we use a **Hash Map** to reduce the complexity to **O(n)**.

For every number:

```text
complement = target - current_number
```

We check whether the complement already exists in the Hash Map.

If it exists, we've found our answer.

Otherwise, we store the current number and its index.

### 🔍 Step-by-Step

For:

```text
nums = [2, 7, 11, 15]
target = 9
```

| Index | Number | Complement | Action                      |
| :---: | :----: | :--------: | :-------------------------- |
|  `0`  |   `2`  |     `7`    | Store `2 → 0`               |
|  `1`  |   `7`  |     `2`    | Found `2` → return `[0, 1]` |

---

## 🧠 Algorithm

```text
1. Create an empty Hash Map.
2. Traverse the array from left to right.
3. For each element:
   a. Calculate complement = target - nums[i].
   b. Check if complement exists in the map.
   c. If yes, return [map[complement], i].
   d. Otherwise, store nums[i] with its index.
4. Return an empty array if no solution exists.
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value            |
| ---------- | ---------------- |
| 🕐 Time    | **O(n)** average |
| 💾 Space   | **O(n)**         |

### Why O(n)?

We traverse the array only once, and Hash Map lookup is **O(1)** on average.

This is significantly better than the brute-force **O(n²)** approach.

---

## 📋 Constraints

```text
2 ≤ nums.length ≤ 10⁴

-10⁹ ≤ nums[i] ≤ 10⁹

-10⁹ ≤ target ≤ 10⁹
```

There is **exactly one valid answer**.

---

## 🔑 Key Concept

The core idea behind this solution is the **complement technique**:

```text
current number + complement = target
```

Therefore:

```text
complement = target - current number
```

Instead of searching the entire array for the required number, we use a Hash Map to check whether we've already encountered it.

---

## 📚 What I Learned

* Using `unordered_map` in C++
* Hash Map based searching
* Reducing `O(n²)` solutions to `O(n)`
* Understanding the **complement pattern**
* Storing values along with their indices

---

## 🏆 LeetCode

**Problem:** Two Sum
**Difficulty:** Easy
**Problem #**: 1

🔗 https://leetcode.com/problems/two-sum/

---

## ⭐ If this helped you

If you found this solution useful, consider giving the repository a ⭐ and checking out the other LeetCode solutions!

---

<div align="center">

### 💻 Keep Coding • Keep Learning • Keep Improving 🚀

</div>
