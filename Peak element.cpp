class Solution {
  public:
    int peakElement(vector<int> &arr) {
        arr.push_back(INT_MIN);
        arr.insert(arr.begin(),INT_MIN);
        for(int i=1;i<arr.size();i++)
        {
            if((arr[i]>arr[i+1]) && (arr[i]>arr[i-1]))
            return i;
        }
    }
};
