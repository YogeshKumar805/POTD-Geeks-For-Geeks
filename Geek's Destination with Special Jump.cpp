class Solution {
  public:
    int minTime(int a, int b, int d, int l, int r) {
        const long long MOD = 1000000007LL;
        long long net = a - b;
        auto time_to = [&](long long x) -> long long {
            if (x <= 0) return 0;
            if (x <= a) return x;
            long long m = (x - a + net - 1) / net;
            return x + 2LL * b * m;
        };
        long long T0 = time_to(d);
        long long left = d - (long long)r;
        long long right = d - (long long)l;
        long long threshold = T0 - 1;
        long long lo = 0, hi = d, best = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (time_to(mid) <= threshold) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        auto sum_ceil_1_to = [&](long long M) -> long long {
            if (M <= 0) return 0;
            long long q = M / net;
            long long rr = M % net;
            return net * q * (q + 1) / 2 + (q + 1) * rr;
        };
        auto sum_f = [&](long long L, long long R) -> long long {
            if (L > R) return 0;
            long long cnt = R - L + 1;
            long long sum_s = cnt * (L + R) / 2;
            long long start_u = std::max(L, (long long)a + 1) - a;
            long long end_u = R - a;
            long long sum_g = 0;
            if (start_u <= end_u) {
                sum_g = sum_ceil_1_to(end_u) - sum_ceil_1_to(start_u - 1);
            }
            return sum_s + 2LL * b * sum_g;
        };
        long long sum = 0;
        if (best >= right) {
            sum = (right - left + 1) + sum_f(left, right);
        } else if (best < left) {
            sum = (right - left + 1) * T0;
        } else {
            long long cnt_jump = best - left + 1;
            long long cnt_t0 = right - best;
            sum = cnt_jump + sum_f(left, best) + cnt_t0 * T0;
        }
        return (int)(sum % MOD);
    }
};
