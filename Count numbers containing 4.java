class Solution {
    public static int countNumberswith4(int n) {
        // code here
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(checkFour(i)) cnt++;
        }
        return cnt;
    }
    static boolean checkFour(int n){
        while(n>0){
            int digit=n%10;
            if(digit==4) return true;
            n=n/10;
        }
        return false;
    }
}
