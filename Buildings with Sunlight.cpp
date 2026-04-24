class Solution {
public:
    int visibleBuildings(vector<int>& arr) {
        int cnt = 1;
        int maxi = arr[0];
        for(int i = 1;i<arr.size();i++){
             if(arr[i] >= maxi){
                 cnt++;
                 maxi = arr[i];
             }
        }
        return cnt;
    }
};
