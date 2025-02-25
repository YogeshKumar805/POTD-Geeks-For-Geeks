class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;
        
        //next smaller element---
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                right[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            right[s.top()]=n;
            s.pop();
        }
        
        // stack should be empty---
        while(!s.empty()){
            s.pop();
        }
        
        //previous smaller element---
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                left[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            left[s.top()]=-1;
            s.pop();
        }
        
        //calculate the max-area
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i]*(right[i]-left[i]-1));
        }
        
        return ans;
    }
};
