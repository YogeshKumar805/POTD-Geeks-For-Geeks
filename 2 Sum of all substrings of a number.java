class Solution {
    public static int sumSubstrings(String s) {
        // code here
        int ans[]=new int[1];
        rec(0,s.length(),s,ans,new HashSet<>());
        return ans[0];
    }
    private static void rec(int l,int r,String s,int ans[],Set<String> h){
        if(l>=r) return;
        String k=l+" "+r;
        if(!h.contains(k)){
            int p=Integer.parseInt(s.substring(l,r));
            ans[0]+=p;
        }
        h.add(k);
        rec(l+1,r,s,ans,h);
        rec(l,r-1,s,ans,h);
    }
}
