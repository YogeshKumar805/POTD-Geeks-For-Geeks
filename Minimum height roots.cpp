class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>degree(V,0);
        
        for(auto &e:edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
            
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        
        queue<int>q;
        
        for(int i = 0; i < V; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        
        int rem=V;
        
        
        while(rem>2)
        {
            int size=q.size();
            
            rem-=size;
            while(size--){
                
                int first=q.front();q.pop();
                
            for(auto &child:adj[first])
            {
                degree[child]--;
                    if(degree[child] == 1) {
                        q.push(child);
                    }
            }
                
                
            }
            
            
        }
        
           vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};

