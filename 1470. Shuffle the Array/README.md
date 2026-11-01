# 1470. Shuffle the Array

## Problem

Given an array `nums` containing `2n` elements in the form `[x1, x2, ..., xn, y1, y2, ..., yn]`, rearrange it into `[x1, y1, x2, y2, ..., xn, yn]`.

## Approach: Two-Half Array Indexing

We use a single `for` loop to access corresponding elements from both halves of the original array.

### Algorithm

1. Create an empty vector called `answer`.
2. Iterate from `i = 0` to `i < n`.
3. Push `nums[i]` into the answer vector.
4. Push `nums[i+n]` into the answer vector.
5. Return the resulting vector.

## Code

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;

        for(int i = 0; i < n; i++) {
            answer.push_back(nums[i]);
            answer.push_back(nums[i+n]);
        }

        return answer;
    }
};
```

## Example

**Input:**

```text
nums = [2,5,1,3,4,7]
n = 3
```

**Output:**

```text
[2,3,5,4,1,7]
```

### Dry Run

| i | nums[i] | nums[i+n] |
| - | ------- | --------- |
| 0 | 2       | 3         |
| 1 | 5       | 4         |
| 2 | 1       | 7         |

Result: `[2,3,5,4,1,7]`

## Complexity Analysis

* **Time Complexity:** `O(n)` — We traverse the first half of the array once.
* **Space Complexity:** `O(n)` — The answer vector stores `2n` elements.

## Key Learnings

* Practiced accessing elements from two halves of an array.
* Understood how `i+n` accesses the corresponding element in the second half.
* Learned when a single loop is sufficient instead of nested loops.
* Practiced using `push_back()` to construct a new vector.

## Key Takeaway

Understanding array indexing helps simplify problems. Sometimes, one loop is all you need!
