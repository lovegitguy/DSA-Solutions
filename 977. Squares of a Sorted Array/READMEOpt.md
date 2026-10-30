# LeetCode 977 — Squares of a Sorted Array

**Difficulty:** Easy
**Approach:** Two Pointers
**Language:** C++

## Intuition

Since the input array is already sorted, the largest squared value must be located at either the leftmost or rightmost position.

Instead of sorting the squared elements again, use two pointers to compare both ends and fill the answer vector from right to left.

## Algorithm

1. Initialize `left = 0`.
2. Initialize `right = nums.size() - 1`.
3. Create an answer vector of the same size as the input.
4. Initialize `k` to the last index of the answer vector.
5. Compare the squares of the leftmost and rightmost elements.
6. Place the larger square at `answer[k]`.
7. Move the corresponding pointer inward.
8. Decrement `k` after every iteration.
9. Continue until `left > right`.

## Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());

        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;

        while(left <= right) {
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                answer[k] = nums[left] * nums[left];
                left++;
            }
            else {
                answer[k] = nums[right] * nums[right];
                right--;
            }

            k--;
        }

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n)

  * Every element is processed exactly once.
  * No additional sorting is required.

* **Space Complexity:** O(n)

  * The answer vector stores the resulting squared elements.

## Key Learnings

* Two Pointers technique.
* Comparing elements from both ends.
* Preallocating a vector using `vector<int> answer(nums.size())`.
* Using `answer[k]` for direct index-based assignment.
* Filling an array from right to left.
* Optimizing O(n log n) to O(n).
