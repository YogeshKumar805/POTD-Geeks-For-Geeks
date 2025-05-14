class Solution {
    public String countAndSay(int n) {
        String base = "1";
        
        while (--n > 0) {
            StringBuilder temp = new StringBuilder();
            char ch = base.charAt(0);
            int count = 1;
            
            for (int i = 1; i < base.length(); i++) {
                if (base.charAt(i) == ch) {
                    count++;
                } else {
                    temp.append(count);
                    temp.append(ch);
                    ch = base.charAt(i);
                    count = 1;
                }
            }
            temp.append(count);
            temp.append(ch);
            
            base = temp.toString();
        }
        
        return base;
    }
