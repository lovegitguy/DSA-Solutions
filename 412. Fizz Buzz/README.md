# Fizz Buzz

## Problem

Given an integer `n`, return a string array containing the numbers from `1` to `n`.

But there are a few rules:

* If the number is divisible by **3**, add `"Fizz"`.
* If the number is divisible by **5**, add `"Buzz"`.
* If the number is divisible by **both 3 and 5**, add `"FizzBuzz"`.
* Otherwise, add the number itself as a string.

### Example

**Example 1**

```text
Input: n = 3
Output: ["1", "2", "Fizz"]
```

**Example 2**

```text
Input: n = 5
Output: ["1", "2", "Fizz", "4", "Buzz"]
```

**Example 3**

```text
Input: n = 15
Output: ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]
```

---

## Approach

We can solve this by looping from `1` to `n` and checking each number.

### Steps

1. Create a `vector<string>` to store the answer.
2. Loop through every number from `1` to `n`.
3. First check if the number is divisible by **both 3 and 5**.
4. If not, check if it is divisible by **3**.
5. If not, check if it is divisible by **5**.
6. If none of these conditions are true, convert the number to a string and add it.
7. Return the vector.

### Why check 3 and 5 first?

A number like `15` is divisible by both `3` and `5`.

If we checked only:

```cpp
if(i % 3 == 0)
```

first, `15` would become `"Fizz"` instead of `"FizzBuzz"`.

So the combined condition must come first:

```cpp
i % 3 == 0 && i % 5 == 0
```

---

## Code

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0)
                answer.push_back("FizzBuzz");

            else if(i % 3 == 0)
                answer.push_back("Fizz");

            else if(i % 5 == 0)
                answer.push_back("Buzz");

            else
                answer.push_back(to_string(i));
        }

        return answer;
    }
};
```

---

## Complexity

* **Time:** `O(n)` — we check every number from `1` to `n`.
* **Space:** `O(n)` — the answer vector stores `n` strings.

---

## Key Idea

> Loop through every number and use the remainder operator `%` to check divisibility. Handle the `3 && 5` case first, then `3`, then `5`, otherwise store the number itself.
