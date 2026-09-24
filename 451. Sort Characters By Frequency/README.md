# LeetCode 451 — Sort Characters By Frequency

## Problem

Given a string `s`, sort it in decreasing order based on the frequency of each character.

Characters with higher frequency must appear before characters with lower frequency.

The exact order between characters having the same frequency does not matter.

### Example

```text
Input:
"tree"

Output:
"eert"
```

Frequency:

```text
e → 2
t → 1
r → 1
```

Therefore, `e` must appear before `t` and `r`.

---

## Approach

The solution uses three main steps:

```text
Count → Convert → Sort → Build
```

### 1. Count character frequencies

Use a `map<char, int>`.

```cpp
map<char, int> frequency;

for(char c : s) {
    frequency[c]++;
}
```

For:

```text
"banana"
```

the map becomes conceptually:

```text
a → 3
b → 1
n → 2
```

The map is being used as a frequency table.

---

### 2. Convert the map into a vector

A map is useful for counting, but we want to sort characters according to their frequency.

So we store each character and its frequency as a pair:

```cpp
vector<pair<char, int>> characters;

for(auto it : frequency) {
    characters.push_back(it);
}
```

The vector now contains:

```text
(a, 3)
(b, 1)
(n, 2)
```

---

### 3. Sort by frequency

We sort using the second element of each pair:

```cpp
sort(characters.begin(), characters.end(), [](auto &a, auto &b) {
    return a.second > b.second;
});
```

Here:

```cpp
a.second
```

means the frequency of character `a`.

The `>` makes the sorting order descending.

For example:

```text
(a,3)
(b,1)
(n,2)
```

becomes:

```text
(a,3)
(n,2)
(b,1)
```

---

### 4. Build the answer

For every character, append it as many times as its frequency.

```cpp
answer.append(it.second, it.first);
```

If:

```text
(a,3)
```

then:

```cpp
answer.append(3, 'a');
```

produces:

```text
"aaa"
```

This avoids manually writing another loop.

---

## Complete Code

```cpp
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        
        for(char c : s) {
            frequency[c]++;
        }

        vector<pair<char, int>> characters;

        for(auto it : frequency) {
            characters.push_back(it);
        }

        sort(characters.begin(), characters.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string answer;

        for(auto it : characters) {
            answer.append(it.second, it.first);
        }

        return answer;
    }
};
```

## Complexity

Let `n` be the length of the string and `k` be the number of distinct characters.

### Frequency counting

```text
O(n log k)
```

because insertion into a `map` takes `O(log k)`.

### Sorting

```text
O(k log k)
```

because we sort the distinct characters.

### Building the result

```text
O(n)
```

because every character is added to the answer.

Overall:

```text
O(n log k + k log k)
```

Since the number of possible characters is usually bounded by a small constant, this is effectively very efficient for typical inputs.

Space complexity:

```text
O(n + k)
```

for the output string and the frequency/vector structures.

---

## Key Concepts Learned

* `map<char, int>` for frequency counting
* `frequency[c]++`
* `pair<char, int>`
* `vector<pair<char,int>>`
* `.first` → character
* `.second` → frequency
* custom sorting with a lambda
* descending sort using `>`
* `string::append(count, character)`
* Converting data from one representation to another before processing

## Main Lesson

A useful DSA pattern from this problem is:

> **Choose the data structure according to the operation you need.**

A `map` is convenient for counting.

A `vector` is convenient for sorting.

Therefore, we don't force one data structure to do everything. We transform the data when the required operation changes.
