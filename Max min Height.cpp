class Solution {
  public:
    bool check(vector<int>& arr, int k, int w, long long m){
        vector<long long> carry(arr.size(), 0);
        long long val = 0;

        for(int i = 0; i < arr.size(); i++){
            if(i != 0)
                carry[i] += carry[i-1];

            long long cur = (long long)arr[i] + carry[i];

            if(cur >= m)
                continue;
            else{
                long long d = m - cur;
                val += d;
                carry[i] += d;
                if(i + w < arr.size())
                    carry[i + w] -= d;
            }
        }
        return val <= k;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        long long ans = 0;
        long long low = *min_element(arr.begin(), arr.end());
        long long high = 1e9;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(check(arr, k, w, mid)){
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};

