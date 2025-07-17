class Solution {

    private int countPrimeInFactorial(int n, int p) {
        int count = 0;
        while (n > 0) {
            n /= p;
            count += n;
        }
        return count;
    }

    public int maxKPower(int n, int k) {
        int ans = Integer.MAX_VALUE;

        int tempK = k;
        for (int i = 2; i * i <= tempK; i++) {
            if (tempK % i == 0) {
                int countK = 0;
                while (tempK % i == 0) {
                    countK++;
                    tempK /= i;
                }
                int countN = countPrimeInFactorial(n, i);

                ans = Math.min(ans, countN / countK);
            }
        }

        if (tempK > 1) {
            int countN = countPrimeInFactorial(n, tempK);
            ans = Math.min(ans, countN / 1);
        }

        return (ans == Integer.MAX_VALUE) ? 0 : ans;
    }
}
