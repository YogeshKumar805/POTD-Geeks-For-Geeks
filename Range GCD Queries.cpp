class Solution {
  public:
    
    int gcd(int a, int b) {
        
        if (b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
    
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, vector<int>& arr) {
        
        
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
        
        segmentTree[i] = gcd(segmentTree[2*i+1], segmentTree[2*i+2]);
        
    }
    
    void updateSegmentTree(int idx, int value, int i, int l, int r, vector<int>& segmentTree) {
        
        
        if (l == r) {
            segmentTree[i] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        
        if (idx <= mid) {
            updateSegmentTree(idx, value, 2*i+1, l, mid, segmentTree);
        } else {
            updateSegmentTree(idx, value, 2*i+2, mid+1, r, segmentTree);
        }
        
        segmentTree[i] = gcd(segmentTree[2*i+1], segmentTree[2*i+2]);
    }
    
    int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        
        if (r < start || end < l) {
            return 0;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l) / 2;
        
        int left = querySegmentTree(start, end, 2*i+1, l, mid, segmentTree);
        int right = querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
        
        return gcd(left, right);
    }
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        int n = arr.size();
        
        vector<int> segmentTree(4*n);
        
        buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        vector<int> ans;
        
        for (auto& q : queries) {
            
            int type = q[0];
            int l    = q[1];
            int r    = q[2];
            
            if (type == 1) {
                updateSegmentTree(l, r, 0, 0, n-1, segmentTree);
            } else {
                
                int result = querySegmentTree(l, r, 0, 0, n-1, segmentTree);
                ans.push_back(result);
            }
        }
        
        return ans;
    }
};
