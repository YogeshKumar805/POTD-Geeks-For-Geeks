class Solution {
    // Function to find the first non-repeating character in a string.
    static char nonRepeatingChar(String s) {
        // Your code here
        LinkedHashMap<Character,Integer>hm=new LinkedHashMap<>();
        for(int i=0;i<s.length();i++)
        {
            hm.put(s.charAt(i),hm.getOrDefault(s.charAt(i),0)+1);
        }
        //System.out.println(hm);
        for(int i=0;i<s.length();i++)
        {
            //System.out.println(en.getKey()+" "+en.getValue());
            if(hm.get(s.charAt(i))==1)
            {
                return s.charAt(i);
            }
        }
        return '$';
    }
}
