# 509. Fibonacci Number

**Difficulty:** 🟢 Easy
**Link:** https://leetcode.com/problems/fibonacci-number/

## Problem
The Fibonacci numbers, commonly denoted `F(n)`, form a sequence 
called the Fibonacci sequence, where each number is the sum of 
the two preceding ones, starting from `0` and `1`.

- `F(0) = 0`
- `F(1) = 1`
- `F(n) = F(n-1) + F(n-2)` for `n > 1`

Given `n`, return `F(n)`.

## Note (Local Testing vs LeetCode)

For **local development** in VS Code, you need these lines:

```cpp
#include <iostream>
using namespace std;

int main() {
    // test code here
}
```

For **LeetCode**, you don't need any of these — the platform handles it.

## Approach 1 — My Solution (Iterative, O(1) Space)
Track only the last two Fibonacci numbers instead of storing the 
whole sequence. This is the optimal solution.

1. Handle base cases: `n == 0` → 0, `n == 1` → 1.
2. Keep two variables: `first = 0`, `second = 1`.
3. Loop from `i = 2` to `n`:
   - Compute `next = first + second`
   - Shift: `first = second`, `second = next`
4. Return `second` (which now holds `F(n)`).

```cpp
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int first = 0;
    int second = 1;

    for (int i = 2; i <= n; i++) {
        int next = first + second;
        first = second;
        second = next;
    }

    return second;
}
```

## Approach 2 — Alternative (Recursion)
The mathematical definition translated directly into code.
Simple to read but very slow — exponential time.

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

## Approach 3 — Alternative (Memoization / DP)
Same as recursion, but cache results to avoid recomputation.

```cpp
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

## Key Insight
You don't need to store the whole sequence — only the **last two** 
numbers are needed to compute the next one. That's what reduces 
space from O(n) to O(1).

## Complexity
|       Approach       |  Time  |     Space       |
|----------------------|--------|-----------------|
| 1 — Iterative (mine) |  O(n)  | O(1)            |
| 2 — Recursive        |  O(2ⁿ) | O(n) call stack |
| 3 — DP with array    |  O(n)  | O(n)            |

## Example Dry Run (n = 5)
|   i   | first | second | next |
|-------|-------|--------|------|
| start |   0   |   1    |   -  |
|   2   |   1   |   1    |   1  |
|   3   |   1   |   2    |   2  |
|   4   |   2   |   3    |   3  |
|   5   |   3   |   5    |   5  |

Returns `5` ✅