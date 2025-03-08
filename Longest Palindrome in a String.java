class Solution {
    
   static  String find(String s, int x, int y){
        String temp="";
        while(x>=0 && y<s.length() && s.charAt(x)==s.charAt(y)){
            temp=s.substring(x,y+1);
            x--;
            y++;
        }
        return temp;
    }
    
    
    
    static String longestPalindrome(String s) {
        int ans=0;
        String temp="";
        for(int i=0;i<s.length()-1;i++){
            String a=find(s, i, i);
            String b=find(s, i, i+1);
            if(a.length()>ans){
                temp=a;
                ans=a.length();
            }
            if(b.length()>ans){
                temp=b;
                ans=b.length();
            }
        }
        return temp;
        
    }
}
