class Solution {
    public int evaluate(String[] arr) {
        // code here
        Stack<Integer> st =new Stack<>();
        for(int i=0 ;i<arr.length;i++)
        {
            try {  
                int str = Integer.parseInt(arr[i]); 
                st.add(str);
            } catch(NumberFormatException e){  
                
                int num=0;
                int op1=st.pop();
                int op2=st.pop();
                
                if(arr[i].equals("*"))
                    num=op2*op1;
                else if(arr[i].equals("+"))
                    num=op2+op1;
                else if(arr[i].equals("-"))
                    num=op2-op1;
                else if(arr[i].equals("/"))
                    num=op2/op1;
                    
                st.push(num);
              }  
        }
        return st.peek();
    }
}
