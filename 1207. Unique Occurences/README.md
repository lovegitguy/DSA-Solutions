# LeetCode 1207 — Unique Number of Occurrences

## Problem

Given an integer array `arr`, return `true` if the number of occurrences of every value in the array is unique. Otherwise, return `false`.

### Example

```text
Input: arr = [1,2,2,1,1,3]

Frequencies:
1 → 3
2 → 2
3 → 1

Output: true
```

The frequencies are `3, 2, 1`, and all of them are unique.

---

## Approach

The problem can be divided into two steps.

### 1. Count the frequency of every number

Use an `unordered_map<int, int>`.

The key stores the number and the value stores how many times that number occurs.

```cpp
unordered_map<int, int> frequency;
```

For every element:

```cpp
frequency[n]++;
```

For example:

```text
[1,1,1,2,2,3]
```

produces:

```text
1 → 3
2 → 2
3 → 1
```

### 2. Check whether the frequencies are unique

Use a `set<int>` to store the frequencies that have already appeared.

For every key-value pair in the frequency map:

```cpp
x.first
```

represents the number, while:

```cpp
x.second
```

represents its frequency.

Before inserting the frequency into the set, check whether it already exists.

```cpp
if (occurrences.find(x.second) != occurrences.end()) {
    return false;
}
```

If the frequency already exists, two different numbers have the same frequency.

Otherwise, insert it:

```cpp
occurrences.insert(x.second);
```

If the entire map is processed without finding a duplicate frequency, return `true`.

---

## Code

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        set<int> occurrences;

        for (int n : arr) {
            frequency[n]++;
        }

        for (auto x : frequency) {
            if (occurrences.find(x.second) != occurrences.end()) {
                return false;
            }

            occurrences.insert(x.second);
        }

        return true;
    }
};
```

## Complexity

Let `n` be the number of elements in the array.

* Time: `O(n log n)` in the worst case because of `set` operations.
* Space: `O(n)`

The frequency map itself takes average `O(1)` time per insertion.

## Key Concepts Learned

* `unordered_map` for frequency counting
* `set` for storing unique values
* `x.first` represents the key
* `x.second` represents the value
* `find()` checks whether an element exists
* `operator[]` can create/update a value in an `unordered_map`

## Pattern

A useful pattern to remember:

```text
Array
  ↓
unordered_map
  ↓
Calculate frequencies
  ↓
set
  ↓
Check whether frequencies repeat
```

The important idea is:

**Use the data structure according to the job it needs to perform.**

`unordered_map` answers:

> "How many times did this value occur?"

`set` answers:

> "Have I already seen this frequency?"
