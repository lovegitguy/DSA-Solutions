# LeetCode 739 — Daily Temperatures

**Difficulty:** Medium
**Topics:** Array, Stack, Monotonic Stack
**Language:** C++

## Problem Statement

Given an array `temperatures` representing daily temperatures, return an array `answer` such that `answer[i]` is the number of days you must wait after day `i` to get a warmer temperature.

If there is no future day with a warmer temperature, `answer[i]` should be `0`.

### Example

**Input:**

```text
temperatures = [73,74,75,71,69,72,76,73]
```

**Output:**

```text
[1,1,4,2,1,1,0,0]
```

## Approach: Monotonic Decreasing Stack

We use a stack to efficiently track indices of days for which we have not yet found a warmer temperature.

The stack stores **indices, not temperature values**, because we need the indices to calculate the number of days between two temperatures.

### Algorithm

1. Create an answer vector initialized with zeros.
2. Create an empty stack to store indices.
3. Iterate through the temperature array.
4. For each temperature, compare it with the temperature at the index on top of the stack.
5. While the stack is not empty and the current temperature is warmer:

   * Retrieve the previous index from the stack.
   * Remove that index from the stack.
   * Calculate the waiting time using `current index - previous index`.
   * Store the result in the answer vector.
6. Push the current index onto the stack.
7. Return the answer vector.

Any indices remaining in the stack at the end have no warmer temperature in the future. Their answers remain `0`.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> st;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() &&
                   temperatures[st.top()] < temperatures[i]) {
                const int index = st.top();
                st.pop();
                ans[index] = i - index;
            }
            st.push(i);
        }

        return ans;
    }
};
```

## Dry Run

Consider the input:

```text
temperatures = [73,74,71,76]
```

| Day | Temperature | Operation                             | Answer      |
| --: | ----------: | ------------------------------------- | ----------- |
|   0 |          73 | Push index 0                          | `[0,0,0,0]` |
|   1 |          74 | Resolve index 0; push index 1         | `[1,0,0,0]` |
|   2 |          71 | Push index 2                          | `[1,0,0,0]` |
|   3 |          76 | Resolve indices 2 and 1; push index 3 | `[1,2,1,0]` |

**Final Output:**

```text
[1,2,1,0]
```

## Complexity Analysis

### Time Complexity: O(n)

Each index is pushed onto the stack exactly once and popped at most once. Therefore, the total number of stack operations is linear in the size of the input.

### Space Complexity: O(n)

The answer vector and the stack can each store up to `n` elements.

## Key Learnings

* A monotonic stack helps solve problems involving the next greater or smaller element.
* Storing indices allows us to calculate distances between elements.
* The `while` loop resolves all previous days for which the current temperature is warmer.
* Initializing the answer vector with zeros automatically handles days without a future warmer temperature.
* A nested-looking loop can still achieve O(n) time when each element is pushed and popped at most once.

## Conclusion

The monotonic decreasing stack provides an efficient O(n) solution to the Daily Temperatures problem, improving on the straightforward O(n²) brute-force approach.
