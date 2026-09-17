# 349. Intersection of Two Arrays

## 🧩 Problem

Given two integer arrays `nums1` and `nums2`, return their intersection.

The intersection should contain **only unique elements**.

### Example

```text
Input:
nums1 = [1, 2, 2, 1]
nums2 = [2, 2]

Output:
[2]
```

---

## 💡 My Approach

I used a **`set`** to store all the elements from `nums1`.

Since a `set` automatically stores **unique elements**, it is useful for checking whether an element from `nums2` exists in `nums1`.

Then I loop through `nums2`:

1. Check whether the element exists in the set using `set.find()`.
2. If it exists, check whether it is already present in `answer`.
3. If it is not already present, add it using `push_back()`.

---

## 🧠 Key STL Concepts Used

### `set`

```cpp
set<int> ans;
```

A `set` stores elements in sorted order and automatically removes duplicates.

### `insert()`

```cpp
ans.insert(n);
```

Adds an element to the set.

### `find()`

```cpp
ans.find(n2) != ans.end()
```

Checks whether `n2` exists in the set.

### `vector`

```cpp
vector<int> answer;
```

Used to store the final result.

### `find()` on a vector

```cpp
find(answer.begin(), answer.end(), n2) == answer.end()
```

Checks whether `n2` is already inside the result vector.

This prevents duplicate values in the final answer.

---

## 💻 My Solution

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> ans;
        vector<int> answer;

        for(int n : nums1)
        {
            ans.insert(n);
        }

        for(int n2 : nums2)
        {
            if(ans.find(n2) != ans.end())
            {
                if(find(answer.begin(), answer.end(), n2) == answer.end())
                {
                    answer.push_back(n2);
                }
            }
        }

        return answer;
    }
};
```

---

## 🔍 How It Works

For:

```text
nums1 = [1, 2, 2, 1]
nums2 = [2, 2, 3]
```

First, `nums1` is inserted into the set:

```text
set = {1, 2}
```

Then we check `nums2`:

```text
2 → exists → add to answer
2 → exists → already in answer → don't add
3 → doesn't exist → ignore
```

Final result:

```text
[2]
```

---

## ⏱️ Complexity

Let:

* `n` = size of `nums1`
* `m` = size of `nums2`

Building the set takes approximately:

```text
O(n log n)
```

Searching the set for each element takes:

```text
O(m log n)
```

The additional `find()` on the answer vector can take up to:

```text
O(m²)
```

in the worst case.

So this solution is mainly useful as **STL practice for `set`, `find()`, and duplicate handling**.

---

## 📚 What I Learned

* How to use `set` for unique elements.
* How to use `set.find()` to check membership.
* How `set` automatically removes duplicates.
* How to use `find()` with a `vector`.
* How to prevent duplicate elements in the result.
* How multiple STL containers can work together to solve a problem.

### 🚀 Main Takeaway

> **`set` is useful when I need uniqueness + fast membership checking.**
