class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here


        priority_queue<int,vector<int>, greater<int>>pq;
        int i,j=0;
        int n=arr.size();

       //step1: process for k+1 elements
        for(i=0;i<=k;i++){
            pq.push(arr[i]);
        }

       //step 2 : process for remaining k+1 to n elements
       for(int i=k+1;i<n;i++){
           arr[j++]=pq.top();
           pq.pop();
           pq.push(arr[i]);
       }
       //step 3 : extract k elements from min heap 
        while(!pq.empty() ){
            int top=pq.top();
            pq.pop();
            arr[j++]=top;
        }
    }
};
