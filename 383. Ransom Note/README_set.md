# 383. Ransom Note

## Problem

Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed using the letters from `magazine`.

Each character from `magazine` can be used **only once**.

If the magazine does not contain enough copies of a required character, return `false`.

---

## Example

```text
Input:
ransomNote = "aa"
magazine = "aab"

Output:
true
```

The magazine contains two `a` characters, which is enough to construct `"aa"`.

Another example:

```text
Input:
ransomNote = "aa"
magazine = "ab"

Output:
false
```

The magazine contains only one `a`, but the ransom note requires two.

---

## Approach

We use a `map<char, int>` to store the frequency of each character in the magazine.

```cpp
map<char, int> frequency;
```

Here:

* `char` → the character
* `int` → the number of times that character appears

### Step 1: Count characters in `magazine`

```cpp
for(char m : magazine)
{
    frequency[m]++;
}
```

For:

```text
magazine = "aabbc"
```

the map becomes:

```text
a → 2
b → 2
c → 1
```

`frequency[m]++` increases the count whenever a character is encountered.

---

### Step 2: Check characters required by `ransomNote`

We loop through every character in `ransomNote`:

```cpp
for(char c : ransomNote)
```

For each character, we check whether the magazine still has one available:

```cpp
if(frequency[c] <= 0)
{
    return false;
}
```

If the frequency is `0`, there are no copies left to use.

Then we consume one copy:

```cpp
frequency[c]--;
```

This is important because every character from the magazine can only be used once.

---

## Key Idea

The important pattern is:

```text
Magazine
   ↓
Count available characters
   ↓
ransomNote asks for characters
   ↓
Check if character is available
   ↓
Use one → frequency[c]--
   ↓
Continue
```

For example:

```text
magazine = "aabbc"

Initial frequency:

a → 2
b → 2
c → 1
```

If the ransom note is:

```text
"aabc"
```

we consume the characters:

```text
a → 2 → 1
a → 1 → 0
b → 2 → 1
c → 1 → 0
```

Every required character was available, so the answer is `true`.

---

## C++ Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> frequency;

        for(char m : magazine) {
            frequency[m]++;
        }

        for(char c : ransomNote) {
            if(frequency[c] <= 0) {
                return false;
            }

            frequency[c]--;
        }

        return true;
    }
};
```

---

## Complexity

Let:

* `m` = length of `magazine`
* `n` = length of `ransomNote`

### Time Complexity

Using `map`, each insertion/access takes `O(log k)`, where `k` is the number of distinct characters.

Overall:

```text
O((m + n) log k)
```

Since the character set is limited, `k` is small in practice.

### Space Complexity

```text
O(k)
```

for storing the character frequencies.

---

## Concepts Learned

* `map<char, int>`
* Frequency counting
* Range-based `for` loop
* `frequency[c]++`
* `frequency[c]--`
* Checking available frequency
* Using a frequency map to solve a string problem
* The concept of **consuming available resources**

---

## Key Takeaway

A frequency map can be used not only to **count** elements, but also to **track how many are still available**.

```cpp
frequency[c]++;
```

means:

> I found/added one character.

```cpp
frequency[c]--;
```

means:

> I used one character.

This **count → check → consume** pattern is an important technique for many DSA problems.
