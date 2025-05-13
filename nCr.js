class Solution {
    nCr(n, r) {
        if (r > n) return 0;
        function fact(num) {
            if(num <= 1) return 1;
            return num * fact(num-1);
        }
        return Math.round(fact(n) / (fact(n-r) * fact(r)))
    }
}
