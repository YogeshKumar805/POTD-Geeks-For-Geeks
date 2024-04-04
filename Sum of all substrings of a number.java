

//User function Template for Java

class Solution
{
    public static long sumSubstrings(String s)
    {
        int modulo = 1000000007;
        int n = s.length();
        long result = 0;
        long multiplier = 1; 
        for (int i = n - 1; i >= 0; i--) {
            int digit = s.charAt(i) - '0'; 
            result = (result + (digit * multiplier * (i + 1)) % modulo) % modulo;
            multiplier = (multiplier * 10 + 1) % modulo; 
        }
        return result;
    }
}
