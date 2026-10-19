# 523. Continuous Subarray Sum

**Difficulty:** Medium
**Topics:** Array, Hash Table, Prefix Sum, Modular Arithmetic

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if the array contains a continuous subarray of at least two elements whose sum is a multiple of `k`. Otherwise, return `false`.

A number is a multiple of `k` if it can be expressed as `n * k` for some integer `n`.

## Example 1

**Input:**

```cpp
nums = [23, 2, 4, 6, 7], k = 6
```

**Output:**

```cpp
true
```

**Explanation:**

The subarray `[2, 4]` has a sum of `6`, which is divisible by `6`.

## Example 2

**Input:**

```cpp
nums = [23, 2, 6, 4, 7], k = 6
```

**Output:**

```cpp
true
```

**Explanation:**

The subarray `[2, 6, 4]` has a sum of `12`, which is divisible by `6`.

## Example 3

**Input:**

```cpp
nums = [23, 2, 6, 4, 7], k = 13
```

**Output:**

```cpp
false
```

**Explanation:**

There is no continuous subarray of at least two elements whose sum is a multiple of `13`.

## Approach: Prefix Sum + Unordered Map

We use a prefix sum and an `unordered_map` to solve the problem efficiently.

### 1. Prefix Sum

A prefix sum represents the cumulative sum of elements from the beginning of the array to the current index.

Instead of storing the entire prefix sum, we store its remainder when divided by `k`.

```cpp
prefix += nums[i];

if (k != 0)
    prefix %= k;
```

### 2. Store Remainders and Indices

We use an `unordered_map<int, int>` named `prefixToIndex`.

* **Key:** Remainder of the prefix sum.
* **Value:** First index where that remainder appeared.

We initialize the map with:

```cpp
unordered_map<int, int> prefixToIndex{{0, -1}};
```

This handles subarrays beginning at index `0`.

### 3. Check for a Repeated Remainder

Suppose two prefix sums have the same remainder when divided by `k`.

Their difference must be divisible by `k`.

Therefore, the sum of the elements between those two prefix positions is a multiple of `k`.

We check whether the remainder already exists:

```cpp
if (const auto it = prefixToIndex.find(prefix);
    it != prefixToIndex.cend()) {
    if (i - it->second > 1)
        return true;
}
```

The condition `i - it->second > 1` ensures that the subarray contains at least two elements.

### 4. Store Only the First Occurrence

If the remainder has not appeared before, store its index:

```cpp
else {
    prefixToIndex[prefix] = i;
}
```

We keep the earliest index because a larger distance between indices makes it easier to satisfy the minimum subarray length requirement.

## C++ Solution

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];

            if (k != 0)
                prefix %= k;

            if (const auto it = prefixToIndex.find(prefix);
                it != prefixToIndex.cend()) {
                if (i - it->second > 1)
                    return true;
            } else {
                prefixToIndex[prefix] = i;
            }
        }

        return false;
    }
};
```

## Complexity Analysis

Let `n` be the number of elements in `nums`.

* **Time Complexity:** `O(n)` on average, because each element requires a constant number of average-case hash map operations.
* **Space Complexity:** `O(min(n, |k|))` for nonzero `k`, since there are at most `|k|` distinct nonnegative remainders. When `k = 0`, the map can contain up to `O(n)` distinct prefix sums.

## Key Takeaways

1. Prefix sums allow us to reason about subarray sums without checking every possible subarray.
2. Equal remainders indicate that the sum between two prefix positions is divisible by `k`.
3. An `unordered_map` helps us remember the first occurrence of each remainder.
4. Initializing the map with `{0, -1}` handles subarrays that start at index `0`.
5. The index difference must be greater than `1` because the subarray must contain at least two elements.

## Related Concepts

* Prefix Sum
* Hash Maps in C++
* Modular Arithmetic
* Subarray Problems
