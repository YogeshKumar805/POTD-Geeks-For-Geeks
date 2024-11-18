class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int ct = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] <= arr[i-1]){
                ct++;
            }
        }
        if(ct == arr.size()-1){
            sort(arr.begin(),arr.end());
            return;
        }
        int idx = arr.size()-1;
        while(idx > 0 and arr[idx-1] >= arr[idx]){
            idx--;
        }
        int t = arr.size()-1;
        while(t > idx-1){
            if(arr[t] > arr[idx-1]){
                break;
            }
            t--;
        }
        swap(arr[t], arr[idx-1]);
        reverse(arr.begin()+idx,arr.end());
    }
};
