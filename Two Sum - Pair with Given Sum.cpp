class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        int i = 0;
        int j = arr.size()-1;
        sort(arr.begin(), arr.end());
        while(i < j){
            int res = arr[i] + arr[j];
            if(res == target){
                return true; 
            }
            if(res < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
