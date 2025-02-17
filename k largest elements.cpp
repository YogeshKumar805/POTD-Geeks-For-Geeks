class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int i=arr.size()-1;
        int cnt=0;
        while(i>=0 && cnt<k){
            ans.push_back(arr[i--]);
            cnt++;
        }
        return ans;
    }
};
