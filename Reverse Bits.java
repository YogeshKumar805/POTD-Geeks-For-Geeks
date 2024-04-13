

// User function Template for Java

class Solution {
    static Long reversedBits(Long x) {
        // code here
        Long ans = (long)0;
        int pos = 0;
        while (x != 0) {
            if (x % 2 == 1) {
                ans += (long)(Math.pow(2, (31-pos)));
            }
            x /= 2;
            pos++;
        }
        return ans;
    }
};
