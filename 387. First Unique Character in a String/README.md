# 387. First Unique Character in a String

## Problem

Given a string `s`, find the first non-repeating character in it and return its index.

If there is no unique character, return `-1`.

### Example

```text
Input:  s = "leetcode"
Output: 0
```

The character `'l'` appears only once and is the first unique character.

Another example:

```text
Input:  s = "loveleetcode"
Output: 2
```

The first unique character is `'v'`, which is at index `2`.

---

## Approach

We use a `map<char, int>` to store the frequency of every character.

### Step 1: Count frequencies

Traverse the string and increase the frequency of each character:

```cpp
map<char, int> frequency;

for(char c : s){
    frequency[c]++;
}
```

For example:

```text
s = "leetcode"
```

The map will contain approximately:

```text
l → 1
e → 3
t → 1
c → 1
o → 1
d → 1
```

### Step 2: Find the first unique character

Traverse the **original string** from left to right.

For every character, check whether its frequency is `1`.

```cpp
for(int i = 0; i < s.size(); i++){
    if(frequency[s[i]] == 1){
        return i;
    }
}
```

We return `i` because the problem asks for the **index**, not the character itself.

If no character has frequency `1`, return:

```cpp
return -1;
```

---

## Why Two Passes?

We cannot reliably determine whether a character is unique while doing the first pass because we have not seen the entire string yet.

For example:

```text
s = "aab"
```

When we first see `'a'`, its current frequency is `1`.

But later we discover another `'a'`.

So we:

```text
Pass 1 → count everything
Pass 2 → find the first character whose final count is 1
```

This is a common pattern for **frequency-counting problems**.

---

## Important Detail

We iterate through the original string in the second pass instead of iterating through the map.

Why?

A `map` keeps its keys sorted, while the problem asks for the **first unique character according to the original string order**.

For example:

```text
s = "loveleetcode"
```

We need to check characters in this order:

```text
l → o → v → e → ...
```

not in sorted map order.

---

## Code

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> frequency;

        for(char c : s){
            frequency[c]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(frequency[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};
```

---

## Complexity

Let `n` be the length of the string and `k` be the number of distinct characters.

### Time Complexity

Using `map`, each insertion/access takes `O(log k)`.

The two passes therefore take:

```text
O(n log k)
```

### Space Complexity

The map stores the distinct characters:

```text
O(k)
```

---

## What I Learned

* How to use `map<char, int>` for frequency counting.
* How `frequency[c]++` automatically creates and increments a key.
* Why frequency problems often require two passes.
* Why we scan the original string instead of the sorted `map`.
* Why returning `i` gives the required character index.
* How to return `-1` when no unique character exists.

## Pattern Learned

```text
Create frequency map
        ↓
Count every element
        ↓
Scan original data
        ↓
Find element with required frequency
        ↓
Return its position/value
```

This frequency-map pattern will be useful for many future string and array problems.
