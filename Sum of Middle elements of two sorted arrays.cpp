class Solution {
public:
    int SumofMiddleElements(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> vec;
        int i = 0, j = 0;
        while (i < n && j < m && vec.size() <= n) {
            if (arr1[i] <= arr2[j]) {
                vec.push_back(arr1[i]);
                i++;
            } else {
                vec.push_back(arr2[j]);
                j++;
            }
        }
        int mid1 = vec[n - 1];
        int mid2 = vec[n];
        return mid1 + mid2;
    }
};
