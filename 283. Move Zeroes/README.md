# LeetCode #283 — Move Zeroes

## Problem Statement

Given an integer array `nums`, move all zeroes to the end of the array while maintaining the relative order of all non-zero elements.

The operation must be performed **in-place**, without making a copy of the array.

## Approach: Two Pointers

I used a two-step approach to move all non-zero elements to the beginning of the array and fill the remaining positions with zeroes.

### Step 1: Move Non-Zero Elements

* Initialize an index `i = 0` to track the position where the next non-zero element should be placed.
* Iterate through the array using a range-based `for` loop.
* Whenever a non-zero element is encountered, assign it to `nums[i]` and increment `i`.
* This preserves the relative order of all non-zero elements.

### Step 2: Fill Remaining Positions with Zeroes

* After processing all elements, `i` points to the first position that should contain a zero.
* Use a `while` loop to fill every remaining position with zero until the end of the array.

## C++ Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (const int num : nums)
            if (num != 0)
                nums[i++] = num;

        while (i < nums.size())
            nums[i++] = 0;
    }
};
```

## Example

**Input:**

```text
nums = [0, 1, 0, 3, 12]
```

**Output:**

```text
[1, 3, 12, 0, 0]
```

### Dry Run

| Element | Action                               | Array             |
| ------- | ------------------------------------ | ----------------- |
| 0       | Skip                                 | [0, 1, 0, 3, 12]  |
| 1       | Place at index 0                     | [1, 1, 0, 3, 12]  |
| 0       | Skip                                 | [1, 1, 0, 3, 12]  |
| 3       | Place at index 1                     | [1, 3, 0, 3, 12]  |
| 12      | Place at index 2                     | [1, 3, 12, 3, 12] |
| —       | Fill remaining positions with zeroes | [1, 3, 12, 0, 0]  |

## Complexity Analysis

* **Time Complexity:** O(n) — The algorithm traverses the array once to move non-zero elements and once more to fill the remaining positions with zeroes. Both passes are linear.
* **Space Complexity:** O(1) — The solution modifies the original array in-place and uses only a constant amount of additional space.

## Key Learnings

* Practiced in-place array manipulation.
* Learned how to preserve the relative order of elements.
* Applied index tracking to place elements efficiently.
* Used a range-based `for` loop to traverse a vector.
* Understood how to achieve linear time complexity with constant extra space.

## Conclusion

This solution efficiently moves all zeroes to the end of the array while preserving the order of non-zero elements. It satisfies the in-place requirement and achieves **O(n) time complexity and O(1) auxiliary space complexity**.
