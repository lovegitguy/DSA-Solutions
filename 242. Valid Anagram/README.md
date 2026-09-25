# LeetCode 242 — Valid Anagram

## Problem

Given two strings `s` and `t`, determine whether `t` is an anagram of `s`.

Two strings are anagrams if they contain the **same characters with the same frequencies**, regardless of their order.

### Example

```text
s = "listen"
t = "silent"
```

Both strings contain:

```text
l → 1
i → 1
s → 1
t → 1
e → 1
n → 1
```

Therefore:

```text
true
```

---

## Approach

Use a `map<char, int>` to keep track of the frequency difference between the two strings.

### Step 1 — Check the lengths

Anagrams must contain the same number of characters.

```cpp
if(s.length() != t.length()){
    return false;
}
```

If their lengths are different, they cannot be anagrams.

### Step 2 — Add frequencies from `s`

```cpp
for(char c : s){
    frequency[c]++;
}
```

For:

```text
s = "aab"
```

the map becomes:

```text
a → 2
b → 1
```

### Step 3 — Subtract frequencies from `t`

```cpp
for(char c : t){
    frequency[c]--;
}
```

If:

```text
t = "baa"
```

then:

```text
a → 0
b → 0
```

Everything has balanced.

### Step 4 — Check the final frequencies

```cpp
for(auto pair : frequency){
    if(pair.second != 0){
        return false;
    }
}
```

If any frequency is not `0`, the strings contain different character counts.

Otherwise:

```cpp
return true;
```

---

## Complete Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> frequency;

        if(s.length() != t.length()){
            return false;
        }

        for(char c : s){
            frequency[c]++;
        }

        for(char c : t){
            frequency[c]--;
        }

        for(auto pair : frequency){
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};
```

---

## Key Concept

The important idea is **frequency balancing**.

Instead of separately comparing two frequency maps:

```text
First string  → add
Second string → subtract
```

For example:

```text
s = "aab"
t = "baa"

a → +1 +1 -1 -1 = 0
b → +1 -1     = 0
```

Every character ends at `0`, so the strings are anagrams.

If a character occurs more times in one string:

```text
a → 1
```

or:

```text
a → -1
```

then the strings are not anagrams.

---

## C++ Concepts Used

### `map<char, int>`

Stores a character and its frequency.

```cpp
map<char, int> frequency;
```

Example:

```text
'a' → 3
'b' → 1
'c' → 2
```

### Range-based `for` loop

```cpp
for(char c : s)
```

Processes every character in the string.

### `frequency[c]++`

Increases the frequency of a character.

### `frequency[c]--`

Decreases the frequency of a character.

### `pair.second`

When iterating through a map:

```cpp
for(auto pair : frequency)
```

`pair.first` is the key:

```text
character
```

`pair.second` is the value:

```text
frequency
```

---

## Complexity

Let `n` be the length of the strings.

Building and checking the map takes approximately:

```text
Time: O(n log k)
Space: O(k)
```

where `k` is the number of distinct characters.

For the normal lowercase-English-letter version, `k ≤ 26`, making this effectively close to **O(n)**.

---

## What I Learned

* A `map<char, int>` can be used to count character frequencies.
* The same map can be used to compare two strings by **adding for one and subtracting for the other**.
* An anagram does not require characters to appear in the same order.
* Equal frequency means the final frequency difference is `0`.
* `pair.second` gives the value stored in a map.
* Checking string length first can eliminate impossible cases immediately.

## Pattern Learned

```text
Frequency Counting
        ↓
First input → increment
Second input → decrement
        ↓
Check whether everything returned to 0
        ↓
Anagram / Not Anagram
```
