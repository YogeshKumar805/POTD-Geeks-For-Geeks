class Solution {
public:
    int countgroup(vector<int>& arr) {
        int XOR = 0, ans = 1, mod = 1e9+7;
        for(int &x: arr) XOR ^= x;
        if(XOR) return 0;     // Checking if overall XOR is nonzero or not
        for(int i=0; i<arr.size()-1; ++i){
            ans = (ans * 2) % mod;
        }
        return ans - 1;
    }
};
