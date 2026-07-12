class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        const int MOD = 1000000007;

        priority_queue<int> pq;

        for (int x : arr)
            if (x > 0)
                pq.push(x);

        long long ans = 0;

        while (k-- && !pq.empty()) {

            int cur = pq.top();
            pq.pop();

            ans = (ans + cur) % MOD;

            cur--;

            if (cur > 0)
                pq.push(cur);
        }

        return (int)ans;
    }
};
