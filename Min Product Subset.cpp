class Solution {
public:
    int minProd(vector<int>& arr) {

        long long mul = 1;

        vector<int> neg, pos;
        int z = 0;

        for (auto it : arr) {
            if (it > 0)
                pos.push_back(it);
            else if (it < 0)
                neg.push_back(it);
            else
                z++;
        }

        if (neg.empty()) {
            if (z)
                return 0;
            return *min_element(pos.begin(), pos.end());
        }

        sort(neg.begin(), neg.end());
        for (int i = 0, n = (neg.size() % 2 ? neg.size() : neg.size() - 1);
             i < n; i++)
            mul *= neg[i];

        for (auto it : pos)
            mul *= it;
            
        return mul;
    }
};
