class Solution {
    void rearrange(ArrayList<Integer> arr) {
        int len = arr.size();
        
        ArrayList<Integer> p = new ArrayList<>();
        ArrayList<Integer> n = new ArrayList<>();
        
        for(int i=0; i<len; i++){
            int ele = arr.remove(0);
            
            if(ele >= 0) p.add(ele);
            else n.add(ele);
        }
        
        while(p.size() != 0 || n.size() != 0){
            if(p.size() > 0) arr.add(p.remove(0));
            if(n.size() > 0) arr.add(n.remove(0));
        }
    }
}
