# 1436. Destination City

**Difficulty:** Easy

**Topics:** Array, String, Hash Table, STL, `vector`, `unordered_set`

**LeetCode:** [Destination City](https://leetcode.com/problems/destination-city/)

---

## Problem Statement

You are given a list of travel paths where `paths[i] = [cityA, cityB]` represents a direct path from `cityA` to `cityB`.

Find the destination city.

The destination city is the city that has no outgoing path to another city.

It is guaranteed that the paths form a non-cyclic path that ends at the destination city.

### Example 1

**Input:**

```text
paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
```

**Output:**

```text
"Sao Paulo"
```

**Explanation:**

* London leads to New York.
* New York leads to Lima.
* Lima leads to Sao Paulo.
* Sao Paulo has no outgoing path, making it the destination city.

### Example 2

**Input:**

```text
paths = [["B","C"],["D","B"],["C","A"]]
```

**Output:**

```text
"A"
```

---

## Approach: Using an Unordered Set

The key observation is that **the destination city never appears as a starting city in any path**.

### Step 1: Store all starting cities

Create an `unordered_set<string>` to store the first city of every path.

```cpp
unordered_set<string> origin_cities;

for (const auto& a : paths) {
    origin_cities.insert(a[0]);
}
```

An `unordered_set` stores unique elements and supports efficient membership checks.

### Step 2: Find the destination city

Traverse the paths again and examine the ending city of each path.

```cpp
for (const auto& b : paths) {
    if (origin_cities.find(b[1]) == origin_cities.end()) {
        return b[1];
    }
}
```

**How does this work?**

* `find(b[1])` searches for the ending city in the set.
* If the city exists, it must be a starting city somewhere in the path list.
* If `find()` returns `origin_cities.end()`, the city is absent from the set.
* Therefore, that city is the destination.

### Step 3: Return the result

Return the first ending city that does not appear among the starting cities.

A fallback `return ""` can be included to satisfy the compiler's return requirements, although the problem guarantees a valid destination.

---

## C++ Solution

```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> origin_cities;

        for (const auto& a : paths) {
            origin_cities.insert(a[0]);
        }

        for (const auto& b : paths) {
            if (origin_cities.find(b[1]) == origin_cities.end()) {
                return b[1];
            }
        }

        return "";
    }
};
```

---

## Complexity Analysis

Let `n` be the number of paths.

**Time Complexity: O(n) average**

* The first loop inserts each starting city into the unordered set.
* The second loop searches for the destination city.
* Each hash-set insertion and lookup takes O(1) expected time, assuming well-distributed hashes and bounded-length city names.

**Space Complexity: O(n)**

The unordered set stores the unique starting cities. In the worst case, it contains one distinct city per path.

---

## Key Learnings

1. **`unordered_set`:** Stores unique elements and provides efficient average-case lookups.
2. **`insert()`:** Adds an element to the set if it isn't already present.
3. **`find()`:** Returns an iterator to an element if found.
4. **`end()`:** Represents the past-the-end iterator; comparing `find()` with `end()` tells us whether an element is absent.
5. **`const auto&`:** Avoids copying each inner vector during iteration and prevents accidental modification.
6. **Problem-solving insight:** Identifying what makes an element unique can simplify a problem considerably.

---


**What I practised:** Hashing, set membership, nested vectors, and range-based loops.
