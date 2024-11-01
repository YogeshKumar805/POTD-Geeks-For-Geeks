class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector <int> rea; // rearranged
        int i= 0, j=arr.size() - 1;
        while (i<=j){
            if (i==j){
                rea.push_back(arr[i]);
            } else {
            rea.push_back(arr[i]);
            rea.push_back(arr[j]);
            }
            
            i++;
            j--;
        }
        int maxSum =0;
        int n = rea.size();
        for(int k = 0; k<n; k++){
            maxSum += abs(rea[k] - rea[(k + 1) % n]);
        }
        return maxSum;
    }
      
};
