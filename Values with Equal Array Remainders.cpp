class Solution {
public:
    int sameMod(vector<int>& arr) {
        int n = arr.size();
        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) return -1;

        int g = 0;
        for (int i = 1; i < n; i++) {
            g = std::gcd(g, std::abs(arr[i] - arr[0]));
        }

        int count = 0;
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;
                if (i * i != g) {
                    count++;
                }
            }
        }

        return count;
    }
};
