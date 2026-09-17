# 💎 771. Jewels and Stones

## 📝 Problem

You're given two strings:

* `jewels` — characters representing types of jewels.
* `stones` — characters representing stones you have.

Return the number of stones that are also jewels.

Each character in `stones` is checked individually.

### Example

```text
Input:
jewels = "aA"
stones = "aAAbbbb"

Output:
3
```

Explanation:

* `'a'` → Jewel ✅
* `'A'` → Jewel ✅
* `'A'` → Jewel ✅
* `'b'` → Not a jewel ❌
* `'b'` → Not a jewel ❌
* `'b'` → Not a jewel ❌
* `'b'` → Not a jewel ❌

Therefore, the answer is `3`.

---

## 💡 Approach

I used a `set<char>` to store all the characters from `jewels`.

A `set` stores only unique values and keeps them sorted.

```cpp
set<char> s;

for(char a : jewels){
    s.insert(a);
}
```

Then I loop through every character in `stones`.

For each stone, I use `find()` to check whether it exists in the jewel set.

```cpp
for(char c : stones){
    if(s.find(c) != s.end()){
        count++;
    }
}
```

If the character is found, I increase `count`.

Finally, I return the count.

---

## 💻 Solution

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s;
        int count = 0;

        for(char a : jewels){
            s.insert(a);
        }

        for(char c : stones){
            if(s.find(c) != s.end()){
                count++;
            }
        }

        return count;
    }
};
```

---

## 🔑 STL Concepts Used

### `set<char>`

Stores unique characters.

```cpp
set<char> s;
```

### `insert()`

Adds a character to the set.

```cpp
s.insert(a);
```

### `find()`

Searches for a character.

```cpp
s.find(c)
```

If the character exists:

```cpp
s.find(c) != s.end()
```

If it doesn't exist:

```cpp
s.find(c) == s.end()
```

### Range-based `for` loop

Used to process each character:

```cpp
for(char c : stones)
```

---

## ⏱️ Complexity

Let:

* `J` = length of `jewels`
* `S` = length of `stones`

### Time Complexity

```text
O(J log J + S log J)
```

Since `set` operations take `O(log J)`.

Because the character set is very small in this problem, this is effectively very fast.

### Space Complexity

```text
O(J)
```

The set stores the unique jewel characters.

---

## 📚 What I Learned

* How to use `set<char>`.
* How to insert characters into a set.
* How to use `find()` with a set.
* How to check whether an iterator is equal to `end()`.
* How to loop through a string using a range-based `for` loop.
* Why `return` must be placed **outside** the loop when all elements need to be processed.
* Practical use of `set` for membership checking.

---

## 🚀 Key Takeaway

Instead of comparing every stone with every jewel using nested loops, store the jewel characters in a set and check each stone against it.

```text
jewels → set → {unique jewels}
                 ↓
stones → check each character
                 ↓
          found → count++
```
