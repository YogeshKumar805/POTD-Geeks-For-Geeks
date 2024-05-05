class Solution{
    public ArrayList <Integer> verticalSum(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        TreeMap<Integer,Integer> map = new TreeMap<>();
        //map.put(0,root.data);
        dfs(root,0,map);
        for(int k : map.keySet()){
            res.add(map.get(k));
        }
        return res;
        
        
    }
    public void dfs(Node node ,int index,TreeMap<Integer,Integer> map){
        if(node==null) return;
        dfs(node.left,index-1,map);
        dfs(node.right,index+1,map);
        if(map.containsKey(index)){
            map.put(index,map.get(index)+node.data);
        }
        else{
            map.put(index,node.data);
        }
    }
}
