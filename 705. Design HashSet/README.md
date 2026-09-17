# 705. Design HashSet

## 🧩 Problem

Design a HashSet without using any built-in hash table libraries.

The HashSet should support three operations:

* `add(key)` — Add `key` to the set.
* `remove(key)` — Remove `key` if it exists.
* `contains(key)` — Return `true` if `key` exists, otherwise return `false`.

---

## 💡 My Approach

Instead of using the built-in `set`, I used a **`vector<int>`** to store the keys.

For every operation, I use `find()` to search for the key.

### `add(key)`

1. Search for `key` using `find()`.
2. If the key already exists, do nothing.
3. Otherwise, add it using `push_back()`.

### `remove(key)`

1. Search for `key`.
2. If it exists, `find()` returns an iterator pointing to it.
3. Remove that exact element using `erase(iterator)`.

### `contains(key)`

1. Search for `key`.
2. If the iterator is not `data.end()`, the key exists.
3. Return `true` or `false`.

---

## 🧠 STL Concepts Used

### `vector`

```cpp
vector<int> data;
```

Used as the underlying container for storing the keys.

### `find()`

```cpp
auto it = find(data.begin(), data.end(), key);
```

Searches for `key` inside the vector.

The important check is:

```cpp
it != data.end()
```

which means the element was found.

### `push_back()`

```cpp
data.push_back(key);
```

Adds a new key to the vector.

### `erase()`

```cpp
data.erase(it);
```

Removes the element at the iterator's position.

---

## 💻 My Solution

```cpp
class MyHashSet {
    vector<int> data;

public:

    MyHashSet() {
       
    }

    void add(int key) {
        auto it = find(data.begin(), data.end(), key);

        if(it != data.end()) {
            return;
        }
        else {
            data.push_back(key);
        }
    }

    void remove(int key) {
        auto it = find(data.begin(), data.end(), key);

        if(it != data.end()) {
            data.erase(it);
        }

        return;
    }

    bool contains(int key) {
        auto n = find(data.begin(), data.end(), key);

        if(n != data.end()) {
            return true;
        }

        return false;
    }
};
```

---

## 🔍 Example

Operations:

```text
add(1)
add(2)
contains(1)
contains(3)
add(2)
remove(2)
contains(2)
```

Result:

```text
true
false
false
```

The second `add(2)` does not create a duplicate because `add()` checks whether the key already exists.

---

## ⏱️ Complexity

Because we are using a vector and `find()`:

### `add()`

Searching takes:

```text
O(n)
```

### `remove()`

Searching takes:

```text
O(n)
```

### `contains()`

Searching takes:

```text
O(n)
```

### Space Complexity

The vector can store up to `n` keys:

```text
O(n)
```

---

## 📚 What I Learned

* How to use `vector` as the underlying storage for a custom data structure.
* How to use `find()` to search for an element.
* The difference between `data.end()` and a valid iterator.
* How `erase(iterator)` removes a specific element.
* How to prevent duplicate values manually.
* How to implement `add`, `remove`, and `contains` operations.

### 🚀 Main Takeaway

> **`find()` gives me an iterator, and that iterator can be used with `erase()` to remove the exact element I found.**
