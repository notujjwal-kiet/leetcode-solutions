# 9. Palindrome Number

**Difficulty:** 🟢 Easy
**Link:** https://leetcode.com/problems/palindrome-number/

## Problem
Given an integer `x`, return `true` if `x` is a palindrome, and 
`false` otherwise.

A number is a palindrome if it reads the same forwards and backwards.

## Note (Local Testing vs LeetCode)

For **local development**, include the necessary headers and a `main()`. 
See `test.cpp` for a runnable example.

For **LeetCode**, only paste the `Solution` class — no includes, no `main()`.

## Approach 1 — My Solution (Reverse Half)
Reverse only half the digits and compare with the remaining half.
This avoids overflow and extra memory.

1. Reject negative numbers and numbers ending in 0 (except 0 itself).
2. Reverse digits from the right into `reversed` until `x <= reversed`.
3. Compare `x` with `reversed` (even length) or `reversed / 10` (odd length).

```cpp
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}
```

## Approach 2 — Alternative (String Conversion + Two Pointers)
Convert to a string and use two pointers moving from both ends.

```cpp
#include <string>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    string s = to_string(x);
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

## Key Insight
You only need to reverse **half** the number. Once both halves meet 
in the middle, you can just compare them — no need to reverse the 
entire number (which risks integer overflow).

## Complexity
|         Approach        |   Time   |   Space  |
|-------------------------|----------|----------|
| 1 — Reverse Half (mine) | O(log n) | O(1)     |
| 2 — String Conversion   | O(log n) | O(log n) |

## Example Dry Run (x = 12321)
| Iteration |   x   | reversed |
|-----------|-------|----------|
|  start    | 12321 | 0        |
|  1        | 1232  | 1        |
|  2        | 123   | 12       |
|  3        | 12    | 123      |

Loop stops because `12 > 123` is false.
- `x == reversed`? → 12 == 123 ❌
- `x == reversed / 10`? → 12 == 12 ✅ → return true

## Edge Cases Handled
- **Negative numbers** → false
- **Zero** → true (special case, not caught by the `% 10` check)
- **Numbers ending in 0** (10, 100, 1200) → false
- **Single digits** (0–9) → true