# LeetCode 451 — Sort Characters By Frequency

## Problem

Given a string `s`, sort it in decreasing order based on the frequency of each character.

Characters with higher frequency should appear before characters with lower frequency.

### Example

```text
Input:
"tree"

Output:
"eetr"
```

`e` appears twice, while `t` and `r` appear once, so `e` comes first.

---

## Approach

The solution follows the same frequency-based pattern learned in **Top K Frequent Elements (LeetCode 347)**.

### Step 1 — Count character frequencies

Use a `map<char, int>` to store how many times each character appears.

```cpp
map<char, int> frequency;

for(char c : s) {
    frequency[c]++;
}
```

For:

```text
"tree"
```

we get:

```text
e → 2
r → 1
t → 1
```

---

### Step 2 — Move the frequencies into a vector

Create:

```cpp
vector<pair<char, int>> elements;
```

Each pair stores:

```text
(character, frequency)
```

Transfer the map contents:

```cpp
for(auto n : frequency) {
    elements.push_back({n.first, n.second});
}
```

So the vector contains elements such as:

```text
(e, 2)
(r, 1)
(t, 1)
```

---

### Step 3 — Sort by frequency

We need the highest frequency first.

The comparator compares the `.second` value of each pair:

```cpp
static bool largestFrequency(pair<char,int> a, pair<char,int> b) {
    return a.second > b.second;
}
```

Then:

```cpp
sort(elements.begin(), elements.end(), largestFrequency);
```

After sorting:

```text
(e, 2)
(r, 1)
(t, 1)
```

Characters with larger frequencies come first.

---

### Step 4 — Reconstruct the answer

Now we go through every pair.

The character must be added as many times as its frequency.

```cpp
for(auto element : elements) {
    for(int i = 0; i < element.second; i++) {
        answer += element.first;
    }
}
```

For:

```text
(e, 2)
(r, 1)
(t, 1)
```

we construct:

```text
ee + r + t
```

giving:

```text
"eert"
```

Any valid ordering among characters with equal frequencies is acceptable.

---

## Final Code

```cpp
class Solution { 
public: 
     
    static bool largestFrequency(pair<char,int> a, pair<char,int> b) { 
        return a.second > b.second; 
    } 
 
    string frequencySort(string s) { 
        map<char, int> frequency; 
        vector<pair<char, int>> elements; 
        string answer = ""; 
 
        for(char c : s) { 
            frequency[c]++; 
        } 
 
        for(auto n : frequency) { 
            elements.push_back({n.first, n.second}); 
        } 
        
        sort(elements.begin(), elements.end(), largestFrequency); 
        
        for(auto element : elements) { 
            for(int i = 0; i < element.second; i++) { 
                answer += element.first; 
            } 
        } 
        
        return answer;    
    } 
};
```

---

## STL Concepts Used

### `map<char, int>`

Used for frequency counting.

```cpp
frequency[c]++;
```

The character is the key and its occurrence count is the value.

---

### `pair<char, int>`

Stores two related pieces of information:

```text
character → frequency
```

Access them using:

```cpp
element.first
element.second
```

---

### `vector<pair<char, int>>`

Allows us to store all character-frequency pairs together and sort them.

---

### Custom Comparator

```cpp
static bool largestFrequency(...)
```

The comparator tells `sort()`:

> Put the element with the larger frequency first.

---

### Nested Loop

The outer loop selects the character.

The inner loop repeats that character according to its frequency.

```cpp
for(auto element : elements) {
    for(int i = 0; i < element.second; i++) {
        answer += element.first;
    }
}
```

---

## Complexity

Let `n` be the length of the string and `m` be the number of unique characters.

### Frequency counting

Using `map`:

```text
O(n log m)
```

### Sorting

```text
O(m log m)
```

### Constructing the answer

```text
O(n)
```

Overall:

```text
O(n log m + m log m)
```

Since `m <= n`, this is commonly described as:

```text
O(n log n)
```

Space complexity:

```text
O(n)
```

because we store the unique character-frequency pairs and the resulting string.

---

## Connection With LeetCode 347

This problem reinforces the pattern from **Top K Frequent Elements**:

```text
Count frequency
      ↓
Store (element, frequency)
      ↓
Sort by frequency
```

The difference is what happens afterward.

### LeetCode 347

```text
Sort
 ↓
Take first K elements
```

### LeetCode 451

```text
Sort
 ↓
Use every element
 ↓
Repeat each character according to its frequency
 ↓
Build answer
```

This is an important pattern:

> **Frequency → organize → sort → use frequency to construct the result.**

---

## Key Takeaway

The important part of this problem is not just sorting characters.

It is learning how to turn frequency information into a structure that can be sorted:

```cpp
map<char,int>
        ↓
vector<pair<char,int>>
        ↓
sort by pair.second
        ↓
reconstruct using pair.second
```

This is the same reasoning pattern you used in LeetCode 347, extended to a full-string reconstruction problem.
