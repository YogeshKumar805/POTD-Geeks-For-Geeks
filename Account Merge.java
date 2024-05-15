class DisjointSet{
    int parent[];
    int size[];
    DisjointSet(int V){
        parent = new int[V];
        size = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    public int findUPar(int node){
        if(node==parent[node])
        return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    public void unionBySize(int u,int v){
        int uPar = findUPar(u);
        int vPar = findUPar(v);
        if(size[uPar]<size[vPar]){
            size[vPar]+=size[uPar];
            parent[uPar] = vPar;
        }else{
            size[uPar]+=size[vPar];
            parent[vPar] = uPar;
        }
    }
}
class Solution {
  static List<List<String>> accountsMerge(List<List<String>> accounts) {
    // code here
    int n = accounts.size();
    DisjointSet ds = new DisjointSet(n);
    
    HashMap<String,Integer> hm = new HashMap<>();
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts.get(i).size();j++){
            String mail = accounts.get(i).get(j);
            if(!hm.containsKey(mail))
                hm.put(mail,i);
            else
                ds.unionBySize(i,hm.get(mail));
        }
    }
    
    List<List<String>> mails = new ArrayList<>();
    for(int i=0;i<n;i++)
        mails.add(new ArrayList<>());
        
    for(Map.Entry e:hm.entrySet()){
        int upNode = ds.findUPar((int)e.getValue());
        mails.get(upNode).add((String)e.getKey());
    }
        
    for(int j=0,i=0;i<mails.size();){
        if(mails.get(i).size()<=0){
            mails.remove(i);
            j++;
        }
        else{
            Collections.sort(mails.get(i));
            mails.get(i++).add(0,accounts.get(j++).get(0));
        }
    }
     return mails;
  }
}
