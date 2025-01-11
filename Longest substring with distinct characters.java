class Solution {
    public int longestUniqueSubstr(String s) {
        HashMap<Character,Integer> map=new HashMap<>();
        int i=0;
        int j=0;
        int n=s.length();
        int ans=1;
        while(j<n){
            char chr=s.charAt(j);
            map.put(chr, map.getOrDefault(chr,0)+1);
            if(map.size()==(j-i)+1){
            	ans=Math.max(ans, (j-i+1));
                j++;                
            }else {
                while(i<n && map.size()!=(j-i+1)){
                    char temp=s.charAt(i);
                    if(map.get(temp)>1){
                        map.put(chr, map.get(chr)-1);
                    }else {
                        map.remove(temp);
                    }
                    i++;
                }
                if(map.size()==(j-i)+1) ans=Math.max(ans, (j-i+1));
                
                j++;
            }
        }
        return ans;
    }
}
