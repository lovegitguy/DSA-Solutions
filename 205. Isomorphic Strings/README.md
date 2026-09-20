# 205. Isomorphic Strings

## Problem

Given two strings `s` and `t`, determine whether they are isomorphic.

Two strings are isomorphic if the characters in `s` can be replaced to get `t`.

Each character must map to exactly one character, and two different characters cannot map to the same character.

### Example

```text
Input:
s = "egg"
t = "add"

Output:
true
```

The mapping is:

```text
e → a
g → d
```

---

## Approach

I used two maps to maintain the relationship between the characters.

```cpp
map<char, char> st;
map<char, char> ts;
```

The first map stores the mapping from `s` to `t`.

The second map stores the reverse mapping from `t` to `s`.

For every pair of characters:

1. Check whether the character from `s` already has a mapping.
2. If it does and the mapping is different, return `false`.
3. Check whether the character from `t` already has a reverse mapping.
4. If it does and the mapping is different, return `false`.
5. Otherwise, store both mappings.

If all characters are processed successfully, the strings are isomorphic.

---

## C++ Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> st;
        map<char, char> ts;

        for(int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];

            if(st.find(a) != st.end() && st[a] != b) {
                return false;
            }

            if(ts.find(b) != ts.end() && ts[b] != a) {
                return false;
            }

            st[a] = b;
            ts[b] = a;
        }

        return true;
    }
};
```

---

## Concepts Used

* `map<char, char>`
* `find()`
* Key-value relationships
* Bidirectional mapping
* Iteration through strings
* Character indexing
* `return false`
* `return true`

---

## Complexity

Let `n` be the length of the strings.

Each character is processed once.

Because `map` operations take `O(log 26)` for lowercase English letters, which is effectively constant:

**Time Complexity:** `O(n log 26)`

**Space Complexity:** `O(26)`, effectively `O(1)` for a fixed alphabet.

---

## What I Learned

* A `map` does not only have to store frequencies.
* `map<char, char>` can represent relationships between characters.
* Sometimes one map is not enough when a relationship must work in both directions.
* `find()` can be used before accessing a key to determine whether a mapping already exists.
* A mapping problem can be solved by maintaining consistency while traversing the strings.
