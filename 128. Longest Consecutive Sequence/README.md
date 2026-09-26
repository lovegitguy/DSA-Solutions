# LeetCode 128 — Longest Consecutive Sequence

## Problem

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

The sequence does not need to appear consecutively in the original array.

### Example

```text
Input:
nums = [100,4,200,1,3,2]

Output:
4
```

The longest consecutive sequence is:

```text
1 → 2 → 3 → 4
```

---

## Approach

The main idea is to use a `set`.

A C++ `set` provides two useful properties:

1. It automatically removes duplicates.
2. It automatically keeps elements sorted.

For example:

```text
nums = [100,4,200,1,3,2,2]

set:
1 2 3 4 100 200
```

After creating the set, we convert it into a vector so that we can easily compare neighboring elements using indexes.

```cpp
vector<int> v(s.begin(), s.end());
```

Now we can compare:

```cpp
v[i]
```

with:

```cpp
v[i-1]
```

If:

```cpp
v[i] == v[i-1] + 1
```

then the current consecutive sequence continues.

Otherwise, the current sequence starts again from `1`.

---

## Algorithm

1. If `nums` is empty, return `0`.
2. Insert all elements into a `set`.
3. Convert the set into a vector.
4. Start:

   ```cpp
   current = 1
   largest = 1
   ```
5. Iterate from index `1`.
6. Compare the current element with the previous element.
7. If they are consecutive:

   ```cpp
   current++
   ```
8. Otherwise:

   ```cpp
   current = 1
   ```
9. Keep updating:

   ```cpp
   largest = max(largest, current)
   ```
10. Return `largest`.

---

## Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        int current = 1;
        int largest = 1;

        for(int i = 1; i < v.size(); i++) {
            if(v[i] == v[i-1] + 1) {
                current++;
            }
            else {
                current = 1;
            }

            largest = max(largest, current);
        }

        return largest;
    }
};
```

---

## Example Walkthrough

Given:

```text
[100,4,200,1,3,2]
```

The set gives:

```text
1 2 3 4 100 200
```

Then we compare neighboring elements:

```text
1 → 2    consecutive → current = 2
2 → 3    consecutive → current = 3
3 → 4    consecutive → current = 4
4 → 100  broken      → current = 1
100 → 200 broken     → current = 1
```

The largest value of `current` was:

```text
4
```

Therefore:

```text
answer = 4
```

---

## Important C++ Lesson

While writing this solution, we encountered an important indexing issue.

This is dangerous:

```cpp
for(int i = 0; i < v.size(); i++) {
    if(v[i] == v[i-1] + 1)
```

When `i = 0`:

```cpp
v[i-1]
```

becomes:

```cpp
v[-1]
```

which is outside the vector.

Therefore, when comparing an element with its previous element, start from:

```cpp
for(int i = 1; i < v.size(); i++)
```

---

## STL Concepts Used

### `set`

```cpp
set<int> s;
```

A `set` stores unique elements in sorted order.

### Constructing a set from a vector

```cpp
set<int> s(nums.begin(), nums.end());
```

This inserts all elements from `nums`.

### Converting a set to a vector

```cpp
vector<int> v(s.begin(), s.end());
```

This gives us indexed access:

```cpp
v[i]
v[i-1]
```

---

## Complexity

Creating the set takes approximately:

```text
O(n log n)
```

because inserting elements into a balanced tree-based `set` takes `O(log n)`.

Converting the set to a vector:

```text
O(n)
```

Scanning the vector:

```text
O(n)
```

Overall:

```text
Time:  O(n log n)
Space: O(n)
```

---

## Key Takeaway

The important pattern learned here is:

```text
Set
 ↓
Remove duplicates
 ↓
Sorted elements
 ↓
Compare neighboring elements
 ↓
Track current sequence
 ↓
Track longest sequence
```

This solution is not the optimal solution for the problem, but it is a strong STL-based solution and demonstrates practical use of `set`.
