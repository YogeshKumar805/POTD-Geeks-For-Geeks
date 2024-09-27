class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // array of minimal cost reaching to every destination
        int n = arr.size();
        vector<int> minCost(n,10001);
        minCost[0] = 0;
        // outer loop runs from each element
        // n-1 means that last element is not a source, just destination
        for(int i=0; i<n-1; i++)
        {
            // inner loop juns k destination elements
            for(int j=i+1; j < n && j<i+1+k; j++)
            {
                // calculate jump cost and store in minCost array
                int cost = abs(arr[i] - arr[j]);
                minCost[j] = min(minCost[j], minCost[i] + cost);
            }
        }
        return minCost[n-1];
    }
};
