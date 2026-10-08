// =====================================================
// Approach 1 — Single Digit Trick (My Solution)
// Reduce n to a single digit. Happy single digits: 1 and 7.
// Time: O(log n) | Space: O(1)
// =====================================================

class Solution {
public:
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
};