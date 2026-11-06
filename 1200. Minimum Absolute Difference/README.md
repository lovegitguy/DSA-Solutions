# 1200. Minimum Absolute Difference

## Problem
Given an array of distinct integers, find all pairs of elements with the minimum absolute difference. Return the pairs in ascending order.

## Approach: Sorting + Minimum Difference Tracking

### 1. Sorting
- First, sort the array in ascending order using `sort()`.
- After sorting, the minimum absolute difference will always occur between neighbouring elements.
- This eliminates the need to compare every possible pair.

### 2. Initialize Variables
- Create a 2D vector `answer` to store the pairs.
- Initialize `minDiff = INT_MAX` to track the smallest difference found so far.

### 3. Traverse the Array
- Iterate through the sorted array.
- Calculate the difference between consecutive elements:

```cpp
int diff = arr[i+1] - arr[i];
```

- If `diff` is smaller than `minDiff`:
  - Update `minDiff`.
  - Use `answer.clear()` to remove previously stored pairs because they no longer have the minimum difference.

- If `diff == minDiff`:
  - Store the current pair using `push_back()`.

### 4. Return the Answer
Return the `answer` vector containing all pairs with the minimum absolute difference.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> answer;

        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;

        for(int i = 0; i < arr.size()-1; i++) {
            int diff = arr[i+1] - arr[i];

            if(diff < minDiff) {
                minDiff = diff;
                answer.clear();
            }

            if(diff == minDiff) {
                answer.push_back({arr[i], arr[i+1]});
            }
        }

        return answer;
    }
};
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n log n) | Sorting takes O(n log n), traversal takes O(n). |
| Auxiliary Space | O(1)* | Sorting space depends on the sorting implementation. |
| Output Space | O(n) | Stores the resulting pairs. |

*Excluding sorting implementation details and the output vector.*

## Key Learnings

1. Sorting helps identify the closest neighbouring elements.
2. `INT_MAX` can initialize a minimum-tracking variable.
3. `answer.clear()` removes outdated results when a smaller minimum is discovered.
4. `push_back()` stores pairs inside a 2D vector.
5. A single traversal can both track the minimum and collect valid pairs when previous results are cleared correctly.

