class Solution {

    public ArrayList<Integer> nextLargerElement(int[] arr) {

        // code here

        Stack<Integer> st = new Stack<>();

        int n = arr.length ;

        ArrayList<Integer> res = new ArrayList<>();

        int ans[] = new int[n];

        

        for(int i = n-1 ; i>=0 ; i--){

            

            while(!st.isEmpty() && st.peek() <= arr[i]){

                st.pop();

            }

            

            if(st.isEmpty()){

              ans[i] = -1;

               

            }

            

            else{

                ans[i] = st.peek();

                

            }

            

             st.push(arr[i]);

        }

        

        for(int i = n-1 ; i>=0 ; i--){

            

            while(!st.isEmpty() && st.peek() <= arr[i]){

                st.pop();

            }

            

            if(st.isEmpty())

            break;

            

           if(ans[i] == -1)

            ans[i] = st.peek();

            

        }

        

        for(int i = 0 ; i<n ;i++)

        res.add(ans[i]);

        

        return res;

        

        

        

    }

}

