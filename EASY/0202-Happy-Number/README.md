# 202. Happy Number

**Difficulty:** 🟢 Easy
**Link:** https://leetcode.com/problems/happy-number/

## Problem
Write an algorithm to determine if a number `n` is happy.

A **happy number** is defined by the following process:
1. Start with any positive integer.
2. Replace it with the sum of the squares of its digits.
3. Repeat until the number becomes `1` (happy) or loops forever (not happy).

Return `true` if `n` is happy, otherwise `false`.

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

## Approach 1 — My Solution (Single Digit Trick)
Keep reducing the number until it becomes a single digit (0–9).
At that point, the only single-digit happy numbers are `1` and `7`.

1. While `n > 9`:
   - Compute the sum of squares of its digits.
   - Replace `n` with that sum.
2. When `n` is a single digit, return `true` if it's `1` or `7`, else `false`.

```cpp
bool isHappy(int n) {
    while (n > 9) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return (n == 1 || n == 7);
}
```

## Approach 2 — Alternative (Set / Cycle Detection)
Since an unhappy number eventually falls into a repeating cycle, we
can detect it using a `set` to remember numbers we've already seen.

1. While `n != 1` and `n` is not already in the set:
   - Insert `n` into the set.
   - Compute the sum of squares of its digits.
2. Return `true` if `n == 1`, else `false`.

```cpp
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}
```

## Approach 3 — Alternative (Slow & Fast Pointers)
Two pointers walk through the sequence at different speeds.
If they meet, there's a cycle → not happy. If the fast pointer
reaches `1`, it's happy.

```cpp
int squareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = squareSum(n);
    while (fast != 1 && slow != fast) {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    }
    return fast == 1;
}
```

## Key Insight
An unhappy number always falls into the cycle:
**4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4**

Once you know this cycle exists, you can detect "unhappy" in three ways:
- **Approach 1:** Reduce to a single digit and check if it's `1` or `7`.
- **Approach 2:** Remember visited numbers in a `set`.
- **Approach 3:** Use two pointers to detect the loop.

## Complexity
|         Approach        |   Time   |    Space   |
|-------------------------|----------|------------|
| 1 — Single Digit Trick  | O(log n) |   O(1)     |
| 2 — Set                 | O(log n) |   O(log n) |
| 3 — Slow & Fast Pointers| O(log n) |   O(1)     |

## Example Dry Run (n = 19)
| Step | n  |       Sum of squares    | Next n |
|------|----|-------------------------|--------|
| 1    | 19 | 1² + 9² = 1 + 81        |   82   |
| 2    | 82 | 8² + 2² = 64 + 4        |   68   |
| 3    | 68 | 6² + 8² = 36 + 64       |   100  |
| 4    | 100| 1² + 0² + 0²            |   1    |
| 5    | 1  | Single Digit → Happy ✅ |   —   |