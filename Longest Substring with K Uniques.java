class Solution {
     int find(int chr[]){
         int cnt=0;
         for(int a:chr)if(a!=0)cnt++;
         return cnt;
     }
    public int longestKSubstr(String s, int k) {
        int i=0;
        int j=0;
        int n=s.length();
        int ans=0;
        int chr[]=new int[26];
        while(j<n){
            char ch=s.charAt(j);
             chr[ch-'a']++;
            if(find(chr)<k){
               
                j++;
            }else if(find(chr)==k){
                int temp=j-i+1;
                ans=Math.max(temp, ans);
                j++;
            }else {
                while(j<n && find(chr)>k){
                    char tmpChr=s.charAt(i);
                    chr[tmpChr-'a']--;
                    i++;
                }
                
                if(find(chr)==k){
                    int temp=j-i+1;
                    ans=Math.max(temp, ans);
                }
                j++;
            }
        }
        
        return ans==0?-1:ans;
    }
}
