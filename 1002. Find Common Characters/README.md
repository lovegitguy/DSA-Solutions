# 1002. Find Common Characters

## 🧩 Problem

Given a string array `words`, return a list of all characters that appear in **every string**, including duplicate characters.

### Example

```text
Input:
["bella","label","roller"]

Output:
["e","l","l"]
```

The character `l` appears twice in all three words, so it must appear twice in the answer.

---

## 💡 Approach

We use a **frequency array of size 26** to count how many times each lowercase English letter appears.

For every word:

1. Create a frequency array for that word.
2. Count each character using:

   ```cpp
   count[c - 'a']++;
   ```
3. For every letter, keep the **minimum frequency** seen across all words.
4. Finally, add each character to the answer according to its minimum frequency.

The minimum frequency is important because a character can only be included as many times as it appears in the word where it occurs the least.

### Example

For:

```text
bella
label
roller
```

The frequency of `l` is:

```text
bella  → 2
label  → 2
roller → 2
```

Therefore:

```text
minimum frequency = 2
```

So the answer contains:

```text
l, l
```

---

## 🧠 Important Concept Learned

### Frequency Counting

A frequency array can store how many times each character appears.

```cpp
int count[26] = {};
```

The expression:

```cpp
c - 'a'
```

converts a lowercase letter into an index:

```text
'a' → 0
'b' → 1
'c' → 2
...
'z' → 25
```

Therefore:

```cpp
count[c - 'a']++;
```

increases the frequency of the current character.

---

## 🛠️ STL / C++ Concepts Used

* `vector<string>`
* `vector<string> answer`
* Range-based `for` loop
* `string`
* `char`
* Arrays
* Frequency counting
* `min()`
* `push_back()`

---

## 💻 Solution

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> answer;

        int common[26];

        for(int i = 0; i < 26; i++) {
            common[i] = 100;
        }

        for(string word : words) {
            int count[26] = {};

            for(char c : word) {
                count[c - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                common[i] = min(common[i], count[i]);
            }
        }

        for(int i = 0; i < 26; i++) {
            while(common[i] > 0) {
                string letter(1, 'a' + i);
                answer.push_back(letter);
                common[i]--;
            }
        }

        return answer;
    }
};
```

---

## ⏱️ Complexity

Let:

* `N` = number of words
* `L` = total number of characters across all words

### Time Complexity

```text
O(L + 26 × N + 26 × answer_frequency)
```

Since `26` is a constant, this is effectively:

```text
O(L)
```

### Space Complexity

```text
O(26)
```

The frequency arrays contain only 26 positions.

---

## 📚 What I Learned From This Problem

* A `set` stores **unique values**, so it cannot preserve duplicate frequencies.
* Frequency counting is useful when we need to know **how many times** something occurs.
* A character can be converted into an array index using `c - 'a'`.
* When finding common characters, we need the **minimum frequency across all words**.
* This problem introduced the idea behind using a `map<char, int>` for frequency counting.

## 🔗 LeetCode

**Problem:** 1002. Find Common Characters

**Difficulty:** Easy
