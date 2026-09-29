# LeetCode 219 — Contains Duplicate II

## Problem

Given an integer array `nums` and an integer `k`, determine whether there are two distinct indices `i` and `j` such that:

* `nums[i] == nums[j]`
* `abs(i - j) <= k`

Return `true` if such a pair exists, otherwise return `false`.

---

## Approach

We use an `unordered_map` to store the **last index** where each number appeared.

```cpp
unordered_map<int, int> lastIndex;
```

The key is the number, and the value is its most recent index.

For every element:

1. Check whether the number already exists in the map.
2. If it exists, get its previous index.
3. Check whether the distance between the current index and previous index is at most `k`.
4. If yes, return `true`.
5. Update the number's index to the current index.

### Why store only the last index?

Suppose the same number appeared at indices:

```text
2, 5, 10
```

When we reach index `10`, the closest previous occurrence is index `5`.

So we only need the **most recent occurrence**. If index `5` is more than `k` away, any earlier occurrence such as `2` will be even farther away.

---

## Example

```text
nums = [1, 2, 3, 1]
k = 3
```

Processing:

```text
index 0 → 1
lastIndex = {1 : 0}

index 1 → 2
lastIndex = {1 : 0, 2 : 1}

index 2 → 3
lastIndex = {1 : 0, 2 : 1, 3 : 2}

index 3 → 1
1 already exists at index 0

abs(3 - 0) = 3
3 <= k

return true
```

---

## Code

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for(int i = 0; i < nums.size(); i++) {

            if(lastIndex.find(nums[i]) != lastIndex.end()) {
                int previousIndex = lastIndex[nums[i]];

                if(abs(i - previousIndex) <= k) {
                    return true;
                }
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};
```

---

## Important C++ Detail

Be careful with parentheses.

### Correct

```cpp
abs(i - previousIndex) <= k
```

First calculate:

```cpp
i - previousIndex
```

then take `abs()`, then compare with `k`.

### Incorrect

```cpp
abs(i - previousIndex <= k)
```

Here the expression:

```cpp
i - previousIndex <= k
```

is evaluated first and produces a boolean (`true` or `false`), which is then passed to `abs()`.

---

## Complexity

### Time

Average:

```text
O(n)
```

Each element performs an average `O(1)` `unordered_map` lookup and insertion/update.

### Space

```text
O(n)
```

In the worst case, every number is different and the map stores all `n` elements.

---

## Key Concept Learned

This problem combines two ideas:

```text
unordered_map
      +
last occurrence / index tracking
```

The important pattern is:

```cpp
if(map.find(x) != map.end()) {
    int previousIndex = map[x];

    // compare current index with previous index
}

map[x] = currentIndex;
```

This is a very useful pattern for problems involving:

* duplicate elements
* previous occurrences
* distance between occurrences
* frequency/index tracking
* "last seen" information

### Mental Model

Think of the map as:

```text
number → last place where I saw it
```

For example:

```text
1 → 7
5 → 9
3 → 12
```

When another `1` appears at index `10`, we immediately know its previous position was `7`.
