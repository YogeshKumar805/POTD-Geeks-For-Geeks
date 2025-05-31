class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int value, row, col;
        priority_queue<
            tuple<int,int,int>, 
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > minHeap;
        for(int i=0; i<matrix.size(); i++){
            minHeap.push(make_tuple(matrix[i][0], i, 0));
        }
        while(k--){
            auto top = minHeap.top();
            value = get<0>(top);
            row = get<1>(top);
            col = get<2>(top);
            minHeap.pop();
            if(col+1<matrix[0].size()){
                minHeap.push(make_tuple(matrix[row][col+1], row, col+1));
            }
        }
        return value;
    }
};

