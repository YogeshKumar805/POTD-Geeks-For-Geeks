class Solution {
    public ArrayList<Integer> nextGreater(int[] arr) {
        // code here
        int n=arr.length;
        Stack<Integer>st=new Stack<>();
        for(int i=n-2;i>=0;i--)
        {
            while(!st.isEmpty()  && st.peek()<=arr[i])
            {
                st.pop();
            }
            st.push(arr[i]);
        }
        ArrayList<Integer>ans=new ArrayList<>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.isEmpty()  && st.peek()<=arr[i])
            {
                st.pop();
            }
            if(st.isEmpty())ans.add(-1);
            else ans.add(st.peek());
            st.push(arr[i]);
        }
        Collections.reverse(ans);
        return ans;
    }
}
