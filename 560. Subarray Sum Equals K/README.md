# LeetCode 560 — Subarray Sum Equals K

## Problem

Given an integer array `nums` and an integer `k`, return the total number of **continuous subarrays** whose elements add up to `k`.

A subarray must contain consecutive elements.

### Example

```text
nums = [1, 1, 1]
k = 2
```

The valid subarrays are:

```text
[1,1]
[1,1]
```

Therefore:

```text
answer = 2
```

---

## Approach

This solution uses a **brute-force approach** with two nested loops.

The idea is:

1. Start from every possible index.
2. Create a running `sum`.
3. Extend the subarray one element at a time.
4. Whenever `sum == k`, increase `count`.
5. Return the total count.

---

## Step-by-Step

### Outer loop

```cpp
for(int i = 0; i < nums.size(); i++)
```

The outer loop chooses the **starting position** of the subarray.

For:

```text
nums = [1, 2, 1]
```

`i` can represent:

```text
i = 0 → start from 1
i = 1 → start from 2
i = 2 → start from 1
```

---

### Reset the sum

```cpp
int sum = 0;
```

For every new starting position, we need a fresh sum.

---

### Inner loop

```cpp
for(int j = i; j < nums.size(); j++)
```

The inner loop extends the subarray from the starting position.

For example, if:

```text
i = 0
```

we examine:

```text
[1]
[1,2]
[1,2,1]
```

---

### Add the current element

```cpp
sum += nums[j];
```

Instead of calculating every subarray's sum from scratch, we keep a running sum.

For:

```text
nums = [1,2,1]
```

starting at index `0`:

```text
sum = 1
sum = 3
sum = 4
```

---

### Check whether the sum equals `k`

```cpp
if(sum == k){
    count++;
}
```

Whenever the current continuous section has exactly the required sum, we found one valid subarray.

---

## Complete Solution

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;

            for(int j = i; j < nums.size(); j++){
                sum += nums[j];

                if(sum == k){
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

## Example Walkthrough

Consider:

```text
nums = [1, 2, 1, 1]
k = 3
```

Starting from index `0`:

```text
[1]       → 1
[1,2]     → 3 ✓
[1,2,1]   → 4
[1,2,1,1] → 5
```

One valid subarray is found.

Starting from index `1`:

```text
[2]       → 2
[2,1]     → 3 ✓
[2,1,1]   → 4
```

Another valid subarray is found.

Starting from index `2`:

```text
[1]       → 1
[1,1]     → 2
```

No match.

Starting from index `3`:

```text
[1] → 1
```

No match.

Therefore:

```text
answer = 2
```

---

## Why This Works

Every possible starting position is considered by the outer loop.

For each starting position, the inner loop considers every possible ending position.

Therefore, every possible continuous subarray is examined.

Whenever its sum equals `k`, `count` is increased.

---

## Complexity

There are two nested loops.

### Time Complexity

```text
O(n²)
```

In the worst case, we examine approximately every possible pair of starting and ending positions.

### Space Complexity

```text
O(1)
```

Apart from the input array, the algorithm only uses:

```text
count
sum
i
j
```

No additional data structure grows with the input size.

---

## Important Concepts Learned

### 1. Continuous subarray

A subarray must contain consecutive elements.

For:

```text
[1,2,3]
```

`[1,2]` is a subarray.

`[2,3]` is a subarray.

`[1,3]` is **not** a subarray because `2` was skipped.

### 2. Running sum

Instead of repeatedly calculating:

```text
1 + 2
1 + 2 + 3
```

we maintain:

```cpp
sum += nums[j];
```

This lets us extend the current subarray efficiently.

### 3. Brute force

When a problem asks us to count all possible subarrays, a useful first approach is:

```text
Choose starting point
        ↓
Expand ending point
        ↓
Maintain current result
        ↓
Check condition
```

---

## Next Optimization

This solution is correct, but `O(n²)` can become slow for large arrays.

The next optimization uses:

```text
Prefix Sum + map
```

The important mathematical observation is:

```text
currentPrefix - previousPrefix = k
```

Therefore:

```text
previousPrefix = currentPrefix - k
```

Instead of checking every possible subarray explicitly, we can use a frequency map to remember how many times each prefix sum has appeared.

That reduces the solution to approximately:

```text
Time: O(n)
Space: O(n)
```

The brute-force solution should be understood first because the optimized solution is based on the same underlying idea of finding subarray sums.
