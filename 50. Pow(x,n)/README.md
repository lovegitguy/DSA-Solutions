# Pow(x, n)

### Problem

Calculate `xⁿ` efficiently.

### Approach

Use **Binary Exponentiation (Fast Power)**:

* `n == 0` → return `1`
* `n < 0` → return `1 / xⁿ`
* `n` is odd → multiply by `x`
* `n` is even → square `x` and halve `n`

Instead of reducing `n` one by one, we reduce it by half whenever possible.

### Example

```text
x = 2, n = 10

2¹⁰ → 4⁵ → 4 × 16² → 4 × 256 → 1024
```

### Complexity

```text
Time:  O(log n)
Space: O(log n)   // recursion stack
```

### Solution

```cpp
class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0)
            return 1;

        if (n < 0)
            return 1 / myPow(x, -n);

        if (n % 2 == 1)
            return x * myPow(x, n - 1);

        return myPow(x * x, n / 2);
    }
};
```

### Key Takeaway

**Keep cutting the exponent in half — that's the trick behind Fast Power.**
