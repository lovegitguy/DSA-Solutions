# 1732. Find the Highest Altitude

##  Problem

A biker is riding on a road with `n + 1` points at different altitudes. The biker starts at altitude `0`, and the `gain` array represents the net altitude change between consecutive points.

Return the **highest altitude** reached during the trip.

##  Approach: Prefix Sum

We use two variables:

* `currentAltitude`: Tracks the biker's current altitude.
* `highestAltitude`: Stores the maximum altitude reached so far, initialized to `0` because the biker starts at altitude `0`.

### Algorithm

1. Initialize `currentAltitude = 0` and `highestAltitude = 0`.
2. Iterate through the `gain` array.
3. Add each element to `currentAltitude` to calculate the new altitude.
4. Update `highestAltitude` using `max()`.
5. Return `highestAltitude`.

##  Solution (C++)

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];
            highestAltitude = max(currentAltitude, highestAltitude);
        }

        return highestAltitude;
    }
};
```

##  Example

**Input:**

```text
gain = [-5, 1, 5, 0, -7]
```

**Altitude changes:**

| Point | Gain | Current Altitude |
| ----- | ---: | ---------------: |
| Start |    — |                0 |
| 1     |   -5 |               -5 |
| 2     |   +1 |               -4 |
| 3     |   +5 |                1 |
| 4     |    0 |                1 |
| 5     |   -7 |               -6 |

**Output:**

```text
1
```

**Explanation:** The highest altitude reached during the trip is `1`.

##  Complexity Analysis

* **Time Complexity:** `O(n)` — We traverse the `gain` array once.
* **Space Complexity:** `O(1)` — We use only two additional variables.

## Key Concepts Learned

* Arrays and iteration
* Prefix sums / cumulative sums
* Tracking a running maximum using `max()`
* Time and space complexity analysis

##  Takeaway

The key insight is that each element in `gain` represents a change in altitude, not the altitude itself. By maintaining a running sum, we calculate the altitude at each point and track the maximum without creating an additional array.
