# 3Sum

## Problem

Given an integer array `nums`, find all unique triplets `[nums[i], nums[j], nums[k]]` such that:

```text
nums[i] + nums[j] + nums[k] = 0
```

The solution should **not contain duplicate triplets**.

### Example

```text
Input:
nums = [-1, 0, 1, 2, -1, -4]

Output:
[[-1, -1, 2], [-1, 0, 1]]
```

---

## Approach

The main idea is:

1. **Sort the array.**
2. Fix one element using `i`.
3. Use two pointers:

   * `j` starts just after `i`
   * `k` starts at the end
4. Calculate:

```cpp
sum = nums[i] + nums[j] + nums[k];
```

5. Move the pointers based on the sum:

   * `sum < 0` → increase `j`
   * `sum > 0` → decrease `k`
   * `sum == 0` → store the triplet and move both pointers
6. Skip duplicate values to make sure the answer contains only unique triplets.

---

## Why Sorting Helps

After sorting, the array has an ordered structure.

For example:

```text
[-4, -1, -1, 0, 1, 2]
```

If:

```text
nums[i] + nums[j] + nums[k] < 0
```

we know the sum is too small, so we need a **larger value**.

Therefore:

```cpp
j++;
```

If the sum is too large:

```cpp
k--;
```

This allows us to find the required triplets without checking every possible combination.

---

## Duplicate Handling

There are two important places where duplicates are skipped.

### Duplicate `i`

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

This prevents generating the same set of triplets from the same starting value.

### Duplicate `j` and `k`

After finding a valid triplet:

```cpp
j++;
k--;
```

we skip repeated values:

```cpp
while (j < k && nums[j] == nums[j - 1])
    j++;

while (j < k && nums[k] == nums[k + 1])
    k--;
```

This ensures that duplicate triplets aren't added to the answer.

---

## Complexity

### Time Complexity

```text
O(n²)
```

Sorting takes:

```text
O(n log n)
```

The two-pointer search runs in:

```text
O(n²)
```

So the overall complexity is:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

excluding the space used to store the resulting triplets.

---

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};
```

---

## What I Learned

* Using `sort()` to create an ordered structure.
* Applying the **two-pointer technique**.
* Reducing a brute-force `O(n³)` approach to `O(n²)`.
* Handling duplicate values carefully.
* Understanding how pointer movement can be decided from the current sum.
* Combining loops with STL algorithms to solve array problems efficiently.
