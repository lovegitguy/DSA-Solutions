# LeetCode 347 — Top K Frequent Elements

## Problem

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

### Example

```text
Input:
nums = [1,1,1,2,2,3]
k = 2

Output:
[1,2]
```

The frequencies are:

```text
1 → 3
2 → 2
3 → 1
```

The two most frequent elements are `1` and `2`.

---

## Approach

The solution uses three main STL structures:

```text
map
  ↓
frequency counting

vector<pair<int,int>>
  ↓
store number + frequency

sort
  ↓
arrange by frequency

take first k
  ↓
answer
```

---

## Step 1 — Count Frequencies

Use a `map<int,int>`:

```cpp
map<int,int> frequency;
```

For every number:

```cpp
for(int n : nums) {
    frequency[n]++;
}
```

For:

```text
[1,1,1,2,2,3]
```

the map becomes:

```text
1 → 3
2 → 2
3 → 1
```

The key represents the number and the value represents its frequency.

---

## Step 2 — Store Number and Frequency Together

Create:

```cpp
vector<pair<int,int>> elements;
```

Each pair represents:

```text
(number, frequency)
```

So:

```text
(1,3)
(2,2)
(3,1)
```

We transfer the map contents:

```cpp
for(auto n : frequency) {
    elements.push_back({n.first, n.second});
}
```

For a map element:

```cpp
n.first
```

is the number.

```cpp
n.second
```

is its frequency.

---

## Step 3 — Sort by Frequency

The default `sort()` would compare the first value of the pair.

But we need to compare the **frequency**, which is the second value.

Therefore we use a custom comparator:

```cpp
static bool largestFrequency(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}
```

This tells `sort()`:

> Put the pair with the larger frequency first.

Then:

```cpp
sort(elements.begin(), elements.end(), largestFrequency);
```

After sorting:

```text
(1,3)
(2,2)
(3,1)
```

---

## Step 4 — Take the First K Elements

If:

```text
k = 2
```

we take:

```text
elements[0]
elements[1]
```

But we only need the number, which is `.first`.

```cpp
for(int i = 0; i < k; i++) {
    answer.push_back(elements[i].first);
}
```

The result is:

```text
[1,2]
```

---

## Code

```cpp
class Solution {
public:

    static bool largestFrequency(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> frequency;
        vector<pair<int,int>> elements;
        vector<int> answer;

        for(int n : nums) {
            frequency[n]++;
        }

        for(auto n : frequency) {
            elements.push_back({n.first, n.second});
        }

        sort(elements.begin(), elements.end(), largestFrequency);

        for(int i = 0; i < k; i++) {
            answer.push_back(elements[i].first);
        }

        return answer;
    }
};
```

---

## STL Concepts Learned

### `map<int,int>`

Used as a frequency table:

```cpp
frequency[n]++;
```

Meaning:

> Increase the frequency associated with `n`.

---

### `pair<int,int>`

Stores two related values:

```cpp
pair<int,int>
```

In this problem:

```text
first  → number
second → frequency
```

---

### `vector<pair<int,int>>`

Allows us to store many `(number, frequency)` pairs:

```text
(1,3)
(2,2)
(3,1)
```

---

### Custom Comparator

```cpp
static bool largestFrequency(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}
```

This changes how `sort()` decides the ordering.

Instead of sorting by the number, we sort by frequency.

---

## Complexity

Let `n` be the number of elements in `nums` and `m` be the number of unique elements.

### Frequency counting

```text
O(n log m)
```

because `map` insertion/update takes `O(log m)`.

### Creating the pair vector

```text
O(m)
```

### Sorting

```text
O(m log m)
```

### Overall

```text
O(n log m + m log m)
```

Since `m <= n`, this is commonly simplified to:

```text
O(n log n)
```

Space complexity:

```text
O(m)
```

for the frequency map, pair vector, and answer.

---

## Important Learning Point

The major idea isn't simply:

> "Use a map."

It is:

```text
Count
 ↓
Represent
 ↓
Order
 ↓
Select
```

In this problem:

```text
map
 ↓
frequency

pair
 ↓
number + frequency

sort
 ↓
highest frequency first

k
 ↓
select top k
```

This pattern appears frequently in problems involving frequencies, rankings, and top-k queries.

---

## What I Learned

* `map<int,int>` can be used as a frequency table.
* `pair.first` and `pair.second` represent the two stored values.
* A `vector<pair<int,int>>` can convert map information into sortable data.
* `sort()` can use a custom comparator.
* A comparator can sort based on `pair.second` instead of `pair.first`.
* `static` allows the comparator to be passed directly to `sort()` when defined inside the class.
* The first `k` elements after sorting represent the top `k` frequencies.
