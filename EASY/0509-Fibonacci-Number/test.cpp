#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// Approach 1 — Iterative (O(1) space) — MY SOLUTION
// Track only the last two Fibonacci numbers.
// Time: O(n) | Space: O(1)
// =====================================================
class Solution1 {
public:
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
};

// =====================================================
// Approach 2 — Recursive
// Direct translation of the math formula. Very slow for large n.
// Time: O(2^n) | Space: O(n) call stack
// =====================================================
class Solution2 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// =====================================================
// Approach 3 — Dynamic Programming (Memoization array)
// Cache results to avoid recomputation.
// Time: O(n) | Space: O(n)
// =====================================================
class Solution3 {
public:
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
};