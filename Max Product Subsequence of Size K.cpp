class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());

        int res = 1;
        int left = 0, right = arr.size() - 1;

        bool allNegs = arr[right] < 0 && (k % 2 == 1);

        if (k % 2 == 1) {
            res *= arr[right--];
            k--;
        }

        while (k) {
            int leftProd = arr[left] * arr[left + 1];
            int rightProd = arr[right] * arr[right - 1];

            if (!allNegs && leftProd > rightProd) {
                res *= leftProd;
                left += 2;
            } else {
                res *= rightProd;
                right -= 2;
            }

            k -= 2;
        }

        return res;
    }
};
