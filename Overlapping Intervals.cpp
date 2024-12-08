class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            int pre_min=ans.back()[0];
            int pre_max=ans.back()[1];
            int curr_min=arr[i][0];
            int curr_max=arr[i][1];
            if(pre_max>=curr_min){
                ans.pop_back();
                ans.push_back({min(pre_min,curr_min),max(pre_max,curr_max)});
            }
            else
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

