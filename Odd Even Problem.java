class Solution {
    public static String oddEven(String s) {
        int a[]=new int[26];
        for(int i=0;i<s.length();i++){
            a[s.charAt(i)-'a']++;
        }
        int x=0,y=0;
        for(int i=0;i<26;i++){
            if(a[i]!=0 && a[i]%2==0 && (i+1)%2==0)x++;
            else if(a[i]%2!=0 && (i+1)%2!=0)y++;
        }
        int ans=x+y;
        return (ans%2==0)?"EVEN":"ODD";
    }
}
