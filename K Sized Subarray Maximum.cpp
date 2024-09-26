class Solution {
  public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        deque<int>dq;
        vector<int>ans;
        int i=0,j=0,n=arr.size();
        while(j < n){
            while(dq.size() > 0 and arr[dq.front()] < arr[j]){
                dq.pop_front();
            }
            dq.push_front(j);
            if(j-i+1 < k){
                j++;
            }
            else{
                ans.push_back(arr[dq.back()]);
                if(i == dq.back()){
                    dq.pop_back();
                }
                i++;j++;
            }
        }
        
        return ans;
    }
};
