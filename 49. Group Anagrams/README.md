# 49. Group Anagrams

## Problem

Given an array of strings `strs`, group the anagrams together.

Two strings are anagrams if they contain the same characters with the same frequencies, but possibly in a different order.

### Example

```text
Input:
["eat","tea","tan","ate","nat","bat"]

Output:
[
    ["bat"],
    ["nat","tan"],
    ["ate","eat","tea"]
]
```

The order of the groups does not matter.

---

## Key Idea

The main challenge is:

> How can we identify that two different strings are anagrams?

Consider:

```text
eat
tea
ate
```

They have different character orders, but they contain exactly the same characters.

If we sort each word:

```text
eat → aet
tea → aet
ate → aet
```

All three produce the same sorted string.

Therefore, the sorted version can be used as a **common key**.

---

## Approach

We use:

```cpp
map<string, vector<string>> groups;
```

The structure is:

```text
key                 value
--------------------------------
"aet"        →      ["eat", "tea", "ate"]
"ant"        →      ["tan", "nat"]
"abt"        →      ["bat"]
```

### Why `vector<string>` as the value?

Multiple words can belong to the same anagram group.

For example:

```text
"aet" → ["eat", "tea", "ate"]
```

Therefore, the value cannot be a single `string`.

We need:

```cpp
vector<string>
```

to store all the words belonging to that group.

---

## Step-by-Step

### Step 1: Create the map

```cpp
map<string, vector<string>> groups;
```

The key will be the sorted word.

---

### Step 2: Process every word

```cpp
for(string word : strs)
```

For each word, create a copy:

```cpp
string sortedWord = word;
```

We keep the original word because we eventually want to store it in the answer.

---

### Step 3: Sort the copy

```cpp
sort(sortedWord.begin(), sortedWord.end());
```

For example:

```text
word       sortedWord
---------------------
eat        aet
tea        aet
tan        ant
ate        aet
nat        ant
bat        abt
```

---

### Step 4: Add the original word to its group

```cpp
groups[sortedWord].push_back(word);
```

For example:

```cpp
groups["aet"].push_back("eat");
groups["aet"].push_back("tea");
groups["aet"].push_back("ate");
```

The map automatically keeps words with the same key together.

---

## Why Does This Work?

The important property is:

> Anagrams have the same characters with the same frequencies.

Sorting puts those characters into the same order.

For example:

```text
eat → aet
tea → aet
ate → aet
```

Because they all produce the same key, they are placed into the same vector.

Non-anagrams produce different keys:

```text
eat → aet
bat → abt
tan → ant
```

Therefore, they end up in different groups.

---

## Step 5: Build the Answer

Our map contains:

```text
"aet" → ["eat","tea","ate"]
"ant" → ["tan","nat"]
"abt" → ["bat"]
```

But the function needs:

```cpp
vector<vector<string>>
```

So we create:

```cpp
vector<vector<string>> answer;
```

Then iterate through the map:

```cpp
for(auto group : groups)
{
    answer.push_back(group.second);
}
```

Remember:

```text
group.first  → key
group.second → value
```

Since the value is the vector of anagrams, we add:

```cpp
group.second
```

to the answer.

---

## Complete Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;

        for(string word : strs){
            string sortedWord = word;

            sort(sortedWord.begin(), sortedWord.end());

            groups[sortedWord].push_back(word);
        }

        vector<vector<string>> answer;

        for(auto group : groups){
            answer.push_back(group.second);
        }

        return answer;
    }
};
```

---

## Complexity

Let:

* `n` = number of strings
* `k` = maximum length of a string

For each word, we sort its characters.

Sorting one word costs approximately:

```text
O(k log k)
```

For `n` words:

```text
O(n × k log k)
```

Because we use an ordered `map`, inserting/accessing a key also involves logarithmic map operations.

A more complete bound for this implementation is approximately:

```text
O(n × k log k + n log n)
```

depending on how the number of distinct keys relates to `n`.

Space complexity is approximately:

```text
O(n × k)
```

because the grouped strings and map keys must be stored.

---

## Important Pattern Learned

This problem introduces an important technique:

### Transform → Key → Group

```text
Original item
     ↓
Transform into a common representation
     ↓
Use representation as map key
     ↓
Store original item in the key's vector
```

For this problem:

```text
word
 ↓
sort characters
 ↓
sortedWord
 ↓
groups[sortedWord]
 ↓
push original word
```

This pattern can appear in many problems where different objects need to be recognized as belonging to the same category.

---

## What I Learned

* How to use `map<string, vector<string>>`.
* How a transformed value can be used as a map key.
* How sorting can create a common representation for anagrams.
* Why the original word must be preserved.
* How `.push_back()` adds multiple values to the same map key.
* How to extract `group.second` from a map.
* Why `map` can automatically organize/group related data.
* The difference between the **key used for grouping** and the **original data stored in the group**.

## Core Mental Model

```text
"eat"
   ↓ sort
"aet" ───────────────┐
                     │
"tea"                │
   ↓ sort            ├──→ groups["aet"]
"aet" ───────────────┘

"ate"
   ↓ sort
"aet"
```

Same transformed key → same group.

---

## LeetCode

**Problem:** 49. Group Anagrams

**Difficulty:** Medium

**Primary STL Concepts:**

* `map`
* `vector`
* `sort`
* range-based `for`
* `.push_back()`
* `pair` through `map` iteration
* `.first` / `.second`
