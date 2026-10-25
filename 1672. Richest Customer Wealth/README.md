# 1672. Richest Customer Wealth

##  Problem

You are given an `m x n` integer matrix called `accounts`, where `accounts[i][j]` represents the amount of money the `i-th` customer has in the `j-th` bank.

Each customer may have accounts in multiple banks.

Return the **wealth of the richest customer**, where a customer's wealth is the sum of money across all their bank accounts.

## Approach: Nested Loops + Maximum Element

We use a nested loop to calculate each customer's total wealth and store the results in a vector. Then, we use `max_element()` to find the maximum wealth.

### Algorithm

1. Create an empty vector called `answer` to store each customer's total wealth.
2. Iterate through each customer using the outer loop.
3. Initialize `sum = 0` for each customer.
4. Use the inner loop to add the balances of all their bank accounts.
5. Store the customer's total wealth in `answer`.
6. Use `max_element()` to find the maximum wealth.
7. Return the maximum value.

## Solution (C++)

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        vector<int> answer;

        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;

            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }

            answer.push_back(sum);
        }

        int max_val = *max_element(answer.begin(), answer.end());

        return max_val;
    }
};
```

##  Example

**Input:**

```text
accounts = [[1, 2, 3], [3, 2, 1], [4, 5, 6]]
```

**Customer Wealth:**

| Customer   | Account Balances | Total Wealth |
| ---------- | ---------------- | -----------: |
| Customer 1 | 1, 2, 3          |            6 |
| Customer 2 | 3, 2, 1          |            6 |
| Customer 3 | 4, 5, 6          |           15 |

**Output:**

```text
15
```

**Explanation:** Customer 3 has the highest total wealth, which is `15`.

##  Complexity Analysis

Let:

* `m` = number of customers

* `n` = number of banks per customer

* **Time Complexity:** `O(m × n)` — We visit every account balance once. Finding the maximum in `answer` takes an additional `O(m)` time, which is dominated by `O(m × n)`.

* **Space Complexity:** `O(m)` — The `answer` vector stores the total wealth of every customer.

##  Key Concepts Learned

* Two-dimensional vectors (`vector<vector<int>>`)
* Nested loops
* Calculating row sums
* Using `max_element()` from the C++ STL
* Dereferencing iterators using `*`
* Time and space complexity analysis

## Takeaway

Each row in the matrix represents one customer, and each element in that row represents their balance in a particular bank.

By calculating the sum of each row, we obtain every customer's wealth. The maximum row sum gives us the richest customer's wealth.

**Optimization opportunity:** We can eliminate the `answer` vector and track the maximum wealth directly while calculating each customer's sum, reducing auxiliary space from `O(m)` to `O(1)`.
