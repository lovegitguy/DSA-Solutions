# 290. Word Pattern

## Problem

Given a `pattern` string and a string `s`, determine whether `s` follows the same pattern.

Each character in `pattern` must correspond to exactly one word in `s`, and each word must correspond to exactly one character.

### Example

```text
Input:
pattern = "abba"
s = "dog cat cat dog"

Output:
true
```

The mapping is:

```text
a → dog
b → cat
```

Since the same pattern characters always map to the same words, and the same words always map back to the same pattern characters, the pattern is valid.

---

## Approach

We use **two maps** to maintain a two-way relationship.

### Map 1: Character → Word

```cpp
map<char, string> patterntoWord;
```

This stores:

```text
a → dog
b → cat
```

### Map 2: Word → Character

```cpp
map<string, char> wordtoPattern;
```

This stores the reverse relationship:

```text
dog → a
cat → b
```

Using two maps is important because we need to make sure the relationship works in **both directions**.

---

## Why Do We Need Two Maps?

Consider:

```text
pattern = "ab"
s = "dog dog"
```

If we only checked:

```text
a → dog
b → dog
```

there would be no problem from the first map alone.

But the pattern requires every word to represent only one character.

The reverse map catches this:

```text
dog → a
```

Then we try:

```text
dog → b
```

This is a conflict, so we return `false`.

Therefore, we maintain:

```text
character → word
word → character
```

---

## Extracting Words with `stringstream`

The string `s` contains multiple words separated by spaces:

```text
"dog cat cat dog"
```

We use:

```cpp
stringstream ss(s);
```

Then:

```cpp
string word;
```

and extract one word at a time:

```cpp
ss >> word;
```

The stream gives us:

```text
dog
cat
cat
dog
```

We create the `stringstream` **before the loop** so that it remembers its current position as we move through the words.

---

## Algorithm

For every character in `pattern`:

1. Extract the next word from `s`.
2. If there is no word available, return `false`.
3. Check whether the character already has a mapping.
4. If it does and the mapped word is different, return `false`.
5. Check whether the word already has a mapping.
6. If it does and the mapped character is different, return `false`.
7. Store both mappings.
8. After the loop, check whether extra words remain.
9. If extra words exist, return `false`.
10. Otherwise, return `true`.

---

## Code

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> patterntoWord;
        map<string, char> wordtoPattern;

        stringstream ss(s);
        string word;

        for(int i = 0; i < pattern.size(); i++) {
            if(!(ss >> word)) {
                return false;
            }

            if(patterntoWord.find(pattern[i]) != patterntoWord.end()
               && patterntoWord[pattern[i]] != word) {
                return false;
            }

            if(wordtoPattern.find(word) != wordtoPattern.end()
               && wordtoPattern[word] != pattern[i]) {
                return false;
            }

            patterntoWord[pattern[i]] = word;
            wordtoPattern[word] = pattern[i];
        }

        if(ss >> word) {
            return false;
        }

        return true;
    }
};
```

---

## Dry Run

### Input

```text
pattern = "abba"
s = "dog cat cat dog"
```

### `i = 0`

```text
pattern[i] = 'a'
word = "dog"
```

Maps:

```text
a → dog
dog → a
```

### `i = 1`

```text
pattern[i] = 'b'
word = "cat"
```

Maps:

```text
a → dog
b → cat

dog → a
cat → b
```

### `i = 2`

```text
pattern[i] = 'b'
word = "cat"
```

Existing mapping:

```text
b → cat
```

Current word is also:

```text
cat
```

No conflict.

### `i = 3`

```text
pattern[i] = 'a'
word = "dog"
```

Existing mapping:

```text
a → dog
```

Again, no conflict.

No extra words remain.

Therefore:

```cpp
return true;
```

---

## Important Map Operations Used

### `find()`

```cpp
patterntoWord.find(pattern[i])
```

Checks whether a mapping for that character already exists.

If it is not found:

```cpp
patterntoWord.find(pattern[i]) == patterntoWord.end()
```

If it exists:

```cpp
patterntoWord.find(pattern[i]) != patterntoWord.end()
```

---

### Accessing a Map Value

```cpp
patterntoWord[pattern[i]]
```

If:

```text
a → dog
```

then:

```cpp
patterntoWord['a']
```

gives:

```text
dog
```

---

### Inserting / Updating

```cpp
patterntoWord[pattern[i]] = word;
```

means:

```text
character → word
```

And:

```cpp
wordtoPattern[word] = pattern[i];
```

means:

```text
word → character
```

---

## Complexity

Let `n` be the number of characters in `pattern` and `m` be the length of `s`.

Each map operation takes `O(log k)` where `k` is the number of stored mappings because `map` is an ordered map.

Overall:

```text
Time:  O(n log n)
Space: O(n)
```

The `stringstream` processing is also linear in the size of `s`.

---

## Key Concepts Learned

* `map<char, string>`
* `map<string, char>`
* Two-way mapping
* `map::find()`
* Checking whether a key already exists
* Accessing values using `map[key]`
* Inserting/updating map entries
* `stringstream`
* Extracting words using `>>`
* Detecting conflicting mappings
* Detecting missing or extra words

---

## Connection to LeetCode #205

This problem is very similar to **LeetCode #205 — Isomorphic Strings**.

In #205:

```text
char → char
char → char
```

Here:

```text
char → string
string → char
```

The main idea is the same:

> When a relationship must work in both directions, maintain two mappings and check both before storing a new relationship.

---

## Key Takeaway

The most important idea from this problem is **two-way mapping**.

We don't just ask:

```text
Does this character always map to the same word?
```

We also ask:

```text
Does this word always map to the same character?
```

That's why we use:

```cpp
map<char, string> patterntoWord;
map<string, char> wordtoPattern;
```

This prevents inconsistent relationships such as:

```text
a → dog
b → dog
```

or:

```text
a → dog
a → cat
```

Both mappings must remain consistent for the pattern to be valid.
