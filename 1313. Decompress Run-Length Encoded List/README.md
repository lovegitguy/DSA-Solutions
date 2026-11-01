# 1313. Decompress Run-Length Encoded List

## Problem

Given an integer array `nums`, decompress it using the run-length encoding format.

Each pair of elements represents:

* `nums[i]` = frequency (number of repetitions).
* `nums[i+1]` = value to repeat.

Return the decompressed array.

## Approach: Nested Loops

We use two nested loops to process each frequency-value pair and insert the required number of repetitions into a new vector.

### Algorithm

1. Create an empty vector called `answer`.
2. Traverse the input array using an outer loop.
3. Increment `i` by 2 to process two elements at a time.
4. Use `nums[i]` to determine the frequency.
5. Use an inner loop to repeat the value `nums[i+1]` according to its frequency.
6. Insert each repetition using `push_back()`.
7. Return the decompressed array.

## Code

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;

        for(int i = 0; i < nums.size(); i += 2) {
            for(int j = 0; j < nums[i]; j++) {
                answer.push_back(nums[i+1]);
            }
        }

        return answer;
    }
};
```

## Example

**Input:**

```text
nums = [2,5,3,7]
```

**Output:**

```text
[5,5,7,7,7]
```

### Dry Run

| Frequency | Value | Result  |
| --------- | ----- | ------- |
| 2         | 5     | 5, 5    |
| 3         | 7     | 7, 7, 7 |

Final Answer: `[5,5,7,7,7]`

## Complexity Analysis

Let `n` be the input array size and `k` be the decompressed output size.

* **Time Complexity:** `O(n + k)` — We process every frequency-value pair and insert all required repetitions.
* **Space Complexity:** `O(k)` — The answer vector stores the decompressed elements.

## Key Learnings

* Practiced nested loops.
* Learned to process array elements in pairs using `i += 2`.
* Understood the difference between frequency and value.
* Practiced using one loop to control repetition.
* Improved array indexing and vector manipulation skills.

## Key Takeaway

Nested loops are useful when an operation needs to be repeated a specific number of times. Processing elements in pairs is also a useful array technique.
