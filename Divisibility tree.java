class Solution {
    static int ans=0;
    
    int wrk(ArrayList<ArrayList<Integer>>al,  int vs[], int i){
        vs[i]=1;
        int sz=1;
        for(int s:al.get(i)){
            if(vs[s]==0){
                int t=wrk(al,vs,s);
                sz+=t;
                if(t%2==0)ans++;
                
            }
            
        }
        return sz;
        
    }
    public int minimumEdgeRemove(int n, int[][] edges) {
        ans=0;
        ArrayList<ArrayList<Integer>> al= new ArrayList<>();
        for(int i=0;i<=n;i++){
            al.add(new ArrayList<>());
            
        }
        for(int i[]:edges){
            al.get(i[0]).add(i[1]);
            al.get(i[1]).add(i[0]);}
            
            int vs[]= new int[n+1];
            for(int i=1;i<vs.length;i++){
                if(vs[i]==0){
                    wrk(al,vs,i);
                }
                
            }
            return ans;
    }
}
