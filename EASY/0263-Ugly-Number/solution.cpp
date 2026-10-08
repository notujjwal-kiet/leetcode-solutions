class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) return false;  // Rejects negative numbers

    for (int factor :
         {2, 3, 5}) {            // Defined a list of given factors inside loop
      while (n % factor == 0) {  // Loops through number
        n /= factor;             // n = n / factor;
      }
    }
    return n == 1;
  }
};
// Alternative approach
// while (n % 2 == 0) n /= 2;
// while (n % 3 == 0) n /= 3;
// while (n % 5 == 0) n /= 5;
// return n == 1;