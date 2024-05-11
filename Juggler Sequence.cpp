class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        vector<long long>res;
        while(n != 1) {
            res.push_back(n);
            n = n&1 ? n*sqrt(n) : sqrt(n);
        }
        res.push_back(1);
        return res;
    }
};
