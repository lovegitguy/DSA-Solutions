# LeetCode 349 — Intersection of Two Arrays

## Problem

Given two integer arrays `nums1` and `nums2`, return their intersection.

Each element in the result must be **unique**.

### Example

```text
Input:
nums1 = [1, 2, 2, 3, 4]
nums2 = [2, 2, 3, 4, 4]

Output:
[2, 3, 4]
```

## Approach

We use nested loops.

1. Pick one element from `nums1`.
2. Check if that element has already appeared earlier in `nums1`.
3. If it has appeared before, skip it using `continue`.
4. Otherwise, search for it in `nums2`.
5. If it exists in `nums2`, add it to the result.
6. Use `break` after finding a match because we only need the element once.

## Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            bool founddigit=false;

            for(int k=0;k<i;k++){
                if(nums1[i]==nums1[k]){
                    founddigit=true;
                    break;
                }
            }
                if(founddigit){
                    continue;
                }

              for (int j = 0; j < nums2.size(); j++) {
                 if (nums1[i] == nums2[j]) {
                     ans.push_back(nums1[i]);
                      break;
                      }
            }
        }
        return ans;
    }
};
```

## Important Concepts

### `break`

Stops the current loop.

```cpp
break;
```

We use it when we have found what we're looking for.

### `continue`

Skips the current iteration and moves to the next one.

```cpp
continue;
```

We use it when the number has already been processed.

### `<` vs `<=`

When accessing array/vector indexes, use:

```cpp
i < nums1.size()
```

not:

```cpp
i <= nums1.size()
```

If the size is `5`, valid indexes are:

```text
0 1 2 3 4
```

Index `5` does not exist.

## Complexity

Let:

* `n` = size of `nums1`
* `m` = size of `nums2`

Because we use nested loops, the time complexity is approximately:

```text
O(n × m)
```

The result vector requires:

```text
O(n)
```

space in the worst case.

## What I Learned

* Nested loops
* Array/vector indexing
* `bool` variables
* `break`
* `continue`
* Checking duplicates
* Finding intersection between two arrays
* Why `i < size` is used instead of `i <= size`
