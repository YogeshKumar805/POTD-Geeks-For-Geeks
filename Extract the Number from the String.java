class Solution {
    long ExtractNumber(String sentence) {
        // code here
        String split[]=sentence.split(" ");
       
        long ans=0;
        for(int i=0;i<split.length;i++)
        {
            String res=split[i];
            if(!Character.isLetter(res.charAt(0)))
            {
               if(res.indexOf("9")==-1)
               {
                   if(ans<Long.parseLong(res))
                   {
                   ans=Long.parseLong(res);
                   }
               }
            }
        }
        if(ans!=0)
        {
        return ans;
        }
        else
        {
            return -1;
        }
    }
}
