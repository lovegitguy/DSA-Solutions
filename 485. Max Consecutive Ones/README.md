# LeetCode 485 — Max Consecutive Ones

## Problem

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

### Example

```text
Input:  [1,1,0,1,1,1]
Output: 3
```

The longest consecutive sequence is `1,1,1`.

## Approach

Maintain two variables:

* `current` — length of the current consecutive sequence of `1`s.
* `answer` — maximum sequence found so far.

When the current number is `1`, increase `current`.

When the current number is `0`, reset `current` to `0`.

After increasing `current`, update `answer`.

## Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int answer = 0;

        for(int n : nums) {
            if(n == 1) {
                current++;
                answer = max(answer, current);
            }
            else {
                current = 0;
            }
        }

        return answer;
    }
};
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

## Key Learning

This is a basic example of a **running count + maximum** pattern.

The same pattern appears in many problems involving consecutive elements or continuous segments.
