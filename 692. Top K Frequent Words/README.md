# LeetCode 692 — Top K Frequent Words

## Problem

Given an array of strings `words` and an integer `k`, return the `k` most frequent words.

The words must be ordered by:

1. **Higher frequency first**
2. If two words have the same frequency, **alphabetically smaller word first**

### Example

```text
Input:
words = ["i","love","leetcode","i","love","coding"]
k = 2

Output:
["i","love"]
```

Frequencies:

```text
i        → 2
love     → 2
coding   → 1
leetcode → 1
```

`i` and `love` have the same frequency, so alphabetical order is used.

---

## Approach

This solution builds directly on the frequency and sorting pattern learned in:

* LeetCode 347 — Top K Frequent Elements
* LeetCode 451 — Sort Characters By Frequency

The main difference is that this problem requires a **tie-breaker**.

The overall process is:

```text
words
  ↓
count frequency using map
  ↓
store (word, frequency) in vector<pair>
  ↓
sort using two rules
  ↓
take first k words
```

---

## Step 1 — Count Word Frequencies

Use:

```cpp
map<string, int> frequency;
```

The word is the key and its frequency is the value.

```cpp
for(string c : words) {
    frequency[c]++;
}
```

For:

```text
["i","love","leetcode","i","love","coding"]
```

the map contains:

```text
coding   → 1
i        → 2
leetcode → 1
love     → 2
```

---

## Step 2 — Create Word-Frequency Pairs

Create:

```cpp
vector<pair<string, int>> elements;
```

Each pair contains:

```text
first  → word
second → frequency
```

Transfer the map into the vector:

```cpp
for(auto n : frequency) {
    elements.push_back({n.first, n.second});
}
```

This gives us a structure that can be sorted.

---

## Step 3 — Create a Two-Level Comparator

The most important new concept in this problem is the comparator.

There are two possible situations.

### Case 1 — Different Frequencies

```cpp
if(a.second != b.second) {
    return a.second > b.second;
}
```

If the frequencies are different, the word with the **higher frequency** comes first.

Example:

```text
a = {"love", 3}
b = {"i", 2}
```

Since:

```text
3 > 2
```

`love` comes first.

---

### Case 2 — Same Frequency

If the frequencies are equal:

```cpp
else {
    return a.first < b.first;
}
```

Now frequency cannot determine the order, so we use alphabetical order.

Example:

```text
a = {"love", 2}
b = {"i", 2}
```

Compare:

```text
"love" < "i"
```

This is false.

Therefore `"i"` comes first.

---

## Comparator

```cpp
static bool largestFrequency(pair<string,int> a, pair<string,int> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}
```

The priority is:

```text
Priority 1:
Higher frequency

Priority 2:
Alphabetically smaller word
```

The second rule is only used when the first rule results in a tie.

---

## Step 4 — Sort

```cpp
sort(elements.begin(), elements.end(), largestFrequency);
```

After sorting, the most important words appear first.

For example:

```text
Before:

love     → 2
i        → 2
coding   → 1
leetcode → 1


After:

i        → 2
love     → 2
coding   → 1
leetcode → 1
```

---

## Step 5 — Take the First K Words

Once sorted, the first `k` elements are the required answer.

```cpp
for(int i = 0; i < k; i++) {
    answer.push_back(elements[i].first);
}
```

Only the word is needed, so we use:

```cpp
elements[i].first
```

---

## Final Code

```cpp
class Solution {
public:
    static bool largestFrequency(pair<string,int> a, pair<string,int> b) {
        if(a.second != b.second) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> frequency;
        vector<pair<string, int>> elements;
        vector<string> answer;

        for(string c : words) {
            frequency[c]++;
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

## STL Concepts Used

### `map<string, int>`

Used for frequency counting.

```cpp
frequency[word]++;
```

The key is a `string` and the value is an `int`.

---

### `pair<string, int>`

Stores:

```text
word + frequency
```

Access them using:

```cpp
element.first
element.second
```

---

### `vector<pair<string,int>>`

The map is converted into a vector because we want to sort the word-frequency pairs.

---

### `sort()`

```cpp
sort(elements.begin(), elements.end(), largestFrequency);
```

Uses the custom comparator to determine the ordering.

---

## Complexity

Let:

* `n` = number of words
* `m` = number of unique words

### Frequency counting

Because `map` is ordered:

```text
O(n log m)
```

### Moving elements into the vector

```text
O(m)
```

### Sorting

```text
O(m log m)
```

### Taking the first `k`

```text
O(k)
```

Overall:

```text
O(n log m + m log m)
```

Space complexity:

```text
O(m)
```

excluding the returned answer.

---

## Connection With Previous Problems

This problem is a direct continuation of the frequency pattern.

### LeetCode 347

```text
frequency
    ↓
sort by frequency
    ↓
take first k
```

### LeetCode 451

```text
frequency
    ↓
sort by frequency
    ↓
reconstruct using frequency
```

### LeetCode 692

```text
frequency
    ↓
sort by frequency
    ↓
if tied → alphabetical order
    ↓
take first k
```

The new concept is the **tie-breaker comparator**.

---

## Key Takeaway

A comparator doesn't have to use only one rule.

We can define priorities:

```text
1st priority → frequency
2nd priority → alphabetical order
```

The general pattern is:

```cpp
if(primary_property_is_different) {
    compare_using_primary_property;
}
else {
    compare_using_secondary_property;
}
```

This pattern is extremely useful when sorting objects that have multiple attributes.
