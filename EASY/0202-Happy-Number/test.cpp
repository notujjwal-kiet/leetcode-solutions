#include <iostream>
#include <unordered_set>
using namespace std;

// =====================================================
// Approach 2 — Set / Cycle Detection
// Remember visited numbers. If we see one again → loop.
// Time: O(log n) | Space: O(log n)
// =====================================================
class Solution2 {
public:
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
};

// =====================================================
// Approach 3 — Slow & Fast Pointers
// If there's a cycle, pointers meet. If fast reaches 1 → happy.
// Time: O(log n) | Space: O(1)
// =====================================================
class Solution3 {
public:
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
};

// =====================================================
// TESTS — run all three approaches on the same inputs
// =====================================================
int main() {
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;

    int tests[] = {19, 2, 1, 7, 20, 100, 1111111};
    int expected[] = {1, 0, 1, 1, 0, 1, 1};  // 1 = happy, 0 = not
    int n = sizeof(tests) / sizeof(tests[0]);

    cout << "n\t\tExpected\tS1\tS2\tS3\tMatch?" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        int a = s1.isHappy(tests[i]);
        int b = s2.isHappy(tests[i]);
        int c = s3.isHappy(tests[i]);
        bool allMatch = (a == b && b == c && a == expected[i]);

        cout << tests[i] << "\t\t" << expected[i] << "\t\t"
             << a << "\t" << b << "\t" << c << "\t"
             << (allMatch ? "✅" : "❌") << endl;
    }

    return 0;
}