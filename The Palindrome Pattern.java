class Solution {
    public String pattern(int[][] arr) {
        // Code here
        int n=arr.length;
        int m=arr[0].length;
        
        for(int i=0;i<n;i++)
        {
            StringBuilder s1=new StringBuilder();
            StringBuilder s2=new StringBuilder();
            for(int j=0;j<m;j++)
            {
                s1.append(arr[i][j]);
                 s2.append(arr[i][j]);
            }
            String str1=s1.reverse().toString();
             String str2=s2.toString();
             
            if(str1.equals(str2))
            {
                String ans= i + " " +"R";
                return ans;
            }
            
        }
           for(int i=0;i<m;i++)
        {
            StringBuilder s1=new StringBuilder();
            StringBuilder s2=new StringBuilder();
            for(int j=0;j<n;j++)
            {
                s1.append(arr[j][i]);
                 s2.append(arr[j][i]);
            }
            String str1=s1.reverse().toString();
             String str2=s2.toString();
             
            if(str1.equals(str2))
            {
                String ans= i + " " +"C";
                return ans;
            }
            
        }
        
        return "-1";
    }
}
