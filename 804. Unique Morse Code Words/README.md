#  804. Unique Morse Code Words

## 📝 Problem

Given an array of strings `words`, convert every word into its Morse code representation.

Each lowercase English letter has a corresponding Morse code.

After converting all the words, return the number of **unique Morse code representations**.

### Example

```text
Input:
words = ["gin", "zen", "gig", "msg"]

Output:
2
```

The transformations are:

```text
gin → --...-.
zen → --...-.

gig → --...--.
msg → --...--.
```

Although there are 4 words, there are only **2 unique Morse representations**.

---

## 💡 Approach

I used a `set<string>` to store the complete Morse representation of every word.

### Step 1 — Store Morse codes

An array of 26 strings stores the Morse code for each letter from `a` to `z`.

```cpp
string morse[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};
```

### Step 2 — Process each word

For every word, create an empty string:

```cpp
string combined = "";
```

Then process every character in that word.

```cpp
for(char c : word){
    string morsequivalent = morse[c - 'a'];
    combined += morsequivalent;
}
```

`c - 'a'` converts the character into an array index.

For example:

```text
'g' - 'a' = 6
```

So:

```cpp
morse[c - 'a']
```

gives the Morse code for `g`.

### Step 3 — Store the complete representation

After converting the entire word:

```cpp
s.insert(combined);
```

The `set` automatically removes duplicate Morse representations.

Finally:

```cpp
return s.size();
```

returns the number of unique transformations.

---

## 💻 Solution

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;

        string morse[26] = {
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--.."
        };

        for(string word : words){
            string combined = "";

            for(char c : word){
                string morsequivalent = morse[c - 'a'];
                combined += morsequivalent;
            }

            s.insert(combined);
        }

        return s.size();
    }
};
```

---

## 🔑 STL Concepts Used

### `set<string>`

Used to store only unique complete Morse representations.

```cpp
set<string> s;
```

### `insert()`

Adds the complete Morse string to the set.

```cpp
s.insert(combined);
```

If the same Morse representation already exists, the set doesn't add another copy.

### Range-based `for` loops

Outer loop:

```cpp
for(string word : words)
```

Processes every word.

Inner loop:

```cpp
for(char c : word)
```

Processes every character in the current word.

---

## 🧠 Important Concept Learned

This problem introduced **nested range-based loops**:

```text
words
  ↓
each word
  ↓
each character
  ↓
Morse code
  ↓
complete Morse representation
  ↓
set
```

The `set` is used **after the complete word has been converted**, not for individual characters.

---

## ⏱️ Complexity

Let:

* `N` = number of words
* `L` = average length of each word

### Time Complexity

Approximately:

```text
O(N × L × log N)
```

The words are converted in `O(N × L)` time, and inserting each complete representation into a set takes logarithmic time.

### Space Complexity

```text
O(N × L)
```

The set stores the unique Morse representations.

---

## 📚 What I Learned

* How to work with `set<string>`.
* How to store complete strings in a set.
* How sets automatically remove duplicates.
* How to use nested range-based `for` loops.
* How to map characters to an array using `c - 'a'`.
* How to build a larger string using `+=`.
* How to convert individual characters and combine their representations.
* How to use STL concepts together to solve a real LeetCode problem.

---

## 🚀 Key Takeaway

The main idea was:

```text
WORD
 ↓
break into characters
 ↓
convert each character to Morse
 ↓
join into ONE complete Morse string
 ↓
insert into set
 ↓
set.size() = unique representations
```

This problem was a practical combination of **strings + arrays + nested loops + set**.
