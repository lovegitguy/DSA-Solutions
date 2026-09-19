# 383. Ransom Note

## 🧩 Problem

You are given two strings:

* `ransomNote`
* `magazine`

Return `true` if `ransomNote` can be constructed using characters from `magazine`.

Each character from `magazine` can only be used once.

---

## 💡 Approach

We use a `map<char, int>` to store the frequency of each character in `magazine`.

For example:

```text
magazine = "aab"

'a' → 2
'b' → 1
```

Then we go through every character in `ransomNote`.

For each character:

1. Use `find()` to check whether the character exists in the map.
2. Check whether its frequency is greater than `0`.
3. If it does not exist or its frequency is `0`, return `false`.
4. Otherwise, decrease its frequency because we have used that character.

If every character in `ransomNote` can be obtained, return `true`.

---

## 🧠 Key STL Concepts

### `map<char, int>`

Stores a character as the key and its frequency as the value.

```cpp
map<char, int> frequency;
```

### Counting characters

```cpp
frequency[c]++;
```

This increases the frequency of character `c`.

### `find()`

```cpp
auto it = frequency.find(c);
```

Checks whether the character exists in the map.

If:

```cpp
it == frequency.end()
```

the character was not found.

### Accessing the frequency

```cpp
it->second
```

`second` represents the value stored in the map, which is the character's frequency.

### Using a character

```cpp
frequency[c]--;
```

We decrease the frequency because one character has been used.

---

## 💻 Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> s;

        for(char m : magazine) {
            s[m]++;
        }

        for(char r : ransomNote) {
            auto it = s.find(r);

            if(it == s.end() || it->second == 0) {
                return false;
            }

            s[r]--;
        }

        return true;
    }
};
```

---

## 🔍 Example

```text
ransomNote = "aa"
magazine   = "aab"
```

Frequency map:

```text
a → 2
b → 1
```

Process `ransomNote`:

```text
'a' → available → use one → a = 1
'a' → available → use one → a = 0
```

All required characters were available.

**Output: `true`**

---

## ⏱️ Complexity

Let:

* `n` = length of `magazine`
* `m` = length of `ransomNote`

### Time Complexity

```text
O(n log 26 + m log 26)
```

Since the keys are characters and there are at most 26 lowercase English letters, this is effectively:

```text
O(n + m)
```

### Space Complexity

```text
O(26)
```

At most 26 different lowercase English characters are stored in the map.

---

## 📚 What I Learned

* How to use `map<char, int>` for frequency counting.
* Difference between storing a value and counting a value.
* Using `find()` with a `map`.
* Understanding `iterator->second`.
* Decreasing a frequency when a character is consumed.
* Combining multiple STL concepts in one problem.

---

## 🏷️ LeetCode

**Problem:** 383. Ransom Note

**Difficulty:** Easy

**Topics:** String, Hash Table, Map
