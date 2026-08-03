class Solution {
	public:
	int maxSumWithK(vector<int>& arr, int k) {
		int n = arr.size();
		int curr_sum = 0;
		for (int i = 0; i < k; i++) {
			curr_sum += arr[i];
		}
		int max_sum = curr_sum;
		int prefix_max = -10001;
		for (int i = k; i < n; i++) {
			curr_sum += arr[i] - arr[i - k];
			prefix_max = max({0, arr[i - k], prefix_max + arr[i - k]});
			max_sum = max(max_sum, curr_sum + prefix_max);
		}
		return max_sum;
	}
};
