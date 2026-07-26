class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>>ans;
        ans.push_back({arr[0]}); // Store the root of tree
        
        queue<int>q; // For level order traversal
        q.push(0); // Storing index 
        
        
        // Level Order Traversal Starts
        while(!q.empty())
        {
            int size = q.size();
            vector<int>res; // For storing index of current level
            
            for(int i=0;i<size;i++)
            {
                int index = q.front();
                q.pop();
                
                if(2*index + 1 < n) 
                {
                    q.push(2*index+1);
                    res.push_back(arr[2*index+1]);
                }
                if(2*index + 2 < n)
                {
                    q.push(2*index+2);
                    res.push_back(arr[2*index+2]);
                }
            }
            sort(res.begin(), res.end());
            if(res.size() != 0)
            {
                ans.push_back(res);
            }
        }
        
        return ans;
    }
};
