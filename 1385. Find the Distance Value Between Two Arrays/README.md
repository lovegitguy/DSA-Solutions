# 1385. Find the Distance Value Between Two Arrays

## Problem

Given two integer arrays `arr1` and `arr2`, and an integer `d`, return the distance value between the two arrays.

The distance value is the number of elements `arr1[i]` such that there is no element `arr2[j]` satisfying:

`|arr1[i] - arr2[j]| <= d`

In simpler words, count how many elements in `arr1` have an absolute difference greater than `d` from **every element in `arr2`**.

## Approach: Brute Force (Nested Loops)

1. Initialize `answer = 0` to count valid elements.
2. Traverse every element of `arr1` using an outer loop.
3. Create a Boolean variable `valid = true` for each element.
4. Use an inner loop to compare the current element of `arr1` with every element of `arr2`.
5. Calculate the absolute difference using `abs()`.
6. If the absolute difference is less than or equal to `d`, mark the element as invalid and use `break` to stop further comparisons.
7. After completing the inner loop, if `valid` is still true, increment `answer`.
8. Return the final answer.

## C++ Solution

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int answer = 0;

        for(int i = 0; i < arr1.size(); i++) {
            bool valid = true;

            for(int j = 0; j < arr2.size(); j++) {

                if(abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                answer++;
            }
        }

        return answer;
    }
};
```

## Complexity Analysis

* **Time Complexity:** O(n × m)

  * `n` is the size of `arr1`.
  * `m` is the size of `arr2`.
  * In the worst case, every element of `arr1` is compared with every element of `arr2`.

* **Space Complexity:** O(1)

  * Only a few extra variables (`answer`, `valid`, `i`, and `j`) are used.
  * No additional data structures are required.

## Key Concepts Learned

* Nested Loops
* Boolean Flags (`bool`)
* Absolute Difference (`abs()`)
* Early Termination using `break`
* Conditional Counting

## Key Takeaway

A Boolean flag helps track whether an element satisfies a particular condition.

Using `break` avoids unnecessary comparisons once an invalid condition is found.

**Important:** Increment the answer only after checking the current element against all elements of the second array.
