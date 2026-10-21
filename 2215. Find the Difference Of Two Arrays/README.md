# 2215. Find the Difference of Two Arrays

**Difficulty:** Easy

**Topics:** Array, Hash Table, STL, `vector`, `unordered_set`

**LeetCode:** [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/)

---

## Problem Statement

Given two integer arrays, `nums1` and `nums2`, return a list containing two lists:

* `answer[0]` contains all distinct integers in `nums1` that are not present in `nums2`.
* `answer[1]` contains all distinct integers in `nums2` that are not present in `nums1`.

The order of the elements in the result does not matter.

### Example 1

**Input:**

```text
nums1 = [1, 2, 3]
nums2 = [2, 4, 6]
```

**Output:**

```text
[[1, 3], [4, 6]]
```

**Explanation:**

* `1` and `3` appear in `nums1` but not in `nums2`.
* `4` and `6` appear in `nums2` but not in `nums1`.
* The element `2` appears in both arrays and is excluded.

---

## Approach: Using Unordered Sets

### Step 1: Convert Both Arrays into Unordered Sets

Create two `unordered_set` containers:

```cpp
const unordered_set<int> set1{nums1.begin(), nums1.end()};
const unordered_set<int> set2{nums2.begin(), nums2.end()};
```

This automatically removes duplicate elements from each array.

### Step 2: Create the Answer Container

```cpp
vector<vector<int>> ans(2);
```

The answer contains two vectors:

* `ans[0]` stores elements exclusive to `set1`.
* `ans[1]` stores elements exclusive to `set2`.

### Step 3: Find Elements Exclusive to the First Set

```cpp
for (const int num : set1)
    if (!set2.contains(num))
        ans[0].push_back(num);
```

For every element in `set1`, check whether it exists in `set2`.

If it does not exist, add it to `ans[0]`.

### Step 4: Find Elements Exclusive to the Second Set

```cpp
for (const int num : set2)
    if (!set1.contains(num))
        ans[1].push_back(num);
```

Repeat the same process in the opposite direction.

### Step 5: Return the Result

```cpp
return ans;
```

---

## C++ Solution

```cpp
class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    const unordered_set<int> set1{nums1.begin(), nums1.end()};
    const unordered_set<int> set2{nums2.begin(), nums2.end()};
    vector<vector<int>> ans(2);

    for (const int num : set1)
      if (!set2.contains(num))
        ans[0].push_back(num);

    for (const int num : set2)
      if (!set1.contains(num))
        ans[1].push_back(num);

    return ans;
  }
};
```

---

## Complexity Analysis

Let `n` be the size of `nums1` and `m` be the size of `nums2`.

**Time Complexity:** `O(n + m)` on average.

* Constructing the two unordered sets takes `O(n + m)` expected time.
* Checking membership for each element takes expected `O(1)` per lookup.
* Both sets are traversed once.

**Space Complexity:** `O(n + m)`.

The unordered sets and the answer vectors can collectively store up to `O(n + m)` elements.

---

## Key Learnings

1. `unordered_set` automatically stores only distinct elements.
2. `unordered_set::contains()` checks whether an element exists in the set. It is available in C++20 and later.
3. `!set.contains(num)` identifies elements absent from a set.
4. Iterating over an unordered set avoids processing duplicate values from the original array.
5. The order of elements in an `unordered_set` is unspecified, which is acceptable when the problem allows any result order.

---


