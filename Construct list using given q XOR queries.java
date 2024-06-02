class Solution {
    public static ArrayList<Integer> constructList(int q, int[][] queries) {
        ArrayList<Integer> res = new ArrayList<>();
        int totalXor = 0;
        
        for(int i = q - 1; i >= 0; i--) {
            int id = queries[i][0], num = queries[i][1];
            
            if(id == 0)
                res.add(totalXor ^ num);
            else
                totalXor ^= num;
        }
        
        res.add(0 ^ totalXor);
        Collections.sort(res);
        
        return res;
    }
}
