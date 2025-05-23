class Solution {
    static int noOfWays(int m, int n, int x) {
        // code here
        return rec(m,n,x,new HashMap<>());
    }
    private static int rec(int m,int n,int x,Map<String,Integer> hm){
        if(x==0){
            if(n==0) return 1;
            return 0;
        }
        String key=m+" "+n+" "+x;
        if(hm.containsKey(key)) return hm.get(key);
        int ways=0;
        for(int i=m;i>0;i--){
            if(x>=i) ways+=rec(m,n-1,x-i,hm);
        }
        hm.put(key,ways);
        return ways;
    }
};
