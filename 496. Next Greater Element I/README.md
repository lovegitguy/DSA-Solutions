# LeetCode 496 — Next Greater Element I

## Problem

Given two arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`, find the next greater element for every element in `nums1`.

The next greater element of an element `x` is the first element to the right of `x` in `nums2` that is greater than `x`.

If there is no greater element, return `-1`.

### Example

```text
nums1 = [4,1,2]
nums2 = [1,3,4,2]
```

Output:

```text
[-1,3,-1]
```

Explanation:

* `4` → no greater element → `-1`
* `1` → next greater element is `3`
* `2` → no greater element → `-1`

## Approach

This solution uses:

* `stack`
* `unordered_map`

We first process `nums2` and determine the next greater element for every number.

The stack stores numbers for which we have not yet found a greater element.

When we encounter a number greater than the element at the top of the stack, that current number is the next greater element for the stack's top element.

For example:

```text
nums2 = [1,3,4,2]
```

Start:

```text
1
```

`3` is greater than `1`, so:

```text
greater[1] = 3
```

Then:

```text
3
```

`4` is greater than `3`, so:

```text
greater[3] = 4
```

Finally, `4` and `2` have no greater element to their right, so:

```text
greater[4] = -1
greater[2] = -1
```

We then use the hash map to construct the answer for `nums1`.

## Algorithm

1. Create an empty stack.
2. Create an `unordered_map` called `greater`.
3. Traverse `nums2`.
4. While the stack is not empty and the top element is smaller than the current number:

   * Store the current number as the next greater element of the stack top.
   * Remove the stack top.
5. Push the current number into the stack.
6. After processing `nums2`, all remaining elements have no greater element, so map them to `-1`.
7. Traverse `nums1` and retrieve each answer from the hash map.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greater;
        stack<int> st;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                greater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        while(!st.empty()) {
            greater[st.top()] = -1;
            st.pop();
        }

        vector<int> answer;

        for(int num : nums1) {
            answer.push_back(greater[num]);
        }

        return answer;
    }
};
```

## Dry Run

For:

```text
nums2 = [1,3,4,2]
```

### Process `1`

```text
stack = [1]
```

### Process `3`

`3 > 1`

```text
greater[1] = 3
stack = [3]
```

### Process `4`

`4 > 3`

```text
greater[3] = 4
stack = [4]
```

### Process `2`

`2 < 4`

```text
stack = [4,2]
```

No elements greater than `4` or `2` appear afterward.

Therefore:

```text
greater[4] = -1
greater[2] = -1
```

Final map:

```text
1 → 3
3 → 4
4 → -1
2 → -1
```

For:

```text
nums1 = [4,1,2]
```

we get:

```text
4 → -1
1 → 3
2 → -1
```

Final answer:

```text
[-1,3,-1]
```

## Complexity

### Time Complexity

```text
O(n + m)
```

Every element in `nums2` is pushed into and popped from the stack at most once, and `nums1` is traversed once.

### Space Complexity

```text
O(n)
```

The stack and hash map can contain up to `n` elements.

## Key DSA Concepts

### Stack

The stack follows:

```text
LIFO
Last In, First Out
```

Here, it helps us keep track of elements waiting for their next greater element.

### Monotonic Stack

The stack is maintained so that elements waiting for a greater value remain in decreasing order.

This pattern is called a **monotonic stack**.

### unordered_map

The hash map allows us to quickly retrieve the answer for each number:

```cpp
greater[num]
```

Average lookup time:

```text
O(1)
```

## What I Learned

* How a stack can be used to find the next greater element.
* How the monotonic stack pattern works.
* How `unordered_map` can store the result for fast lookup.
* Why each element only needs to be pushed and popped once.
* How combining two STL structures can reduce a brute-force solution to linear time.
