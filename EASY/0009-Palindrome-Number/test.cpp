// =====================================================
// LeetCode 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/
//
// For LeetCode submission: paste only the "Solution" class
// (or rename Solution1 → Solution).
// =====================================================

#include <string>
using namespace std;

// =====================================================
// Approach 1 — Reverse Half (My Solution)
// Time: O(log n) | Space: O(1)
// =====================================================
class Solution1 {
public:
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
};

// =====================================================
// Approach 2 — String Conversion + Two Pointers
// Time: O(log n) | Space: O(log n)
// =====================================================
class Solution2 {
public:
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
};