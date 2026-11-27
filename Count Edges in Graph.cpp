class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int edgeCount = 0;
        for(vector<int> &neigh: adj){
            edgeCount += neigh.size();
        }
        return edgeCount/2;
    }
};
