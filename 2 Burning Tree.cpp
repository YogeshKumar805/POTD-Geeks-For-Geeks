class Solution {
  public:
    unordered_map<int, vector<Node *>> mp;
    void create_adjacency(Node * root)
    {
        if(!root)
        return;
        
        if(root->left)
        {
            mp[root->data].push_back(root->left);
            mp[root->left->data].push_back(root);
        }
        if(root->right)
        {
            mp[root->data].push_back(root->right);
            mp[root->right->data].push_back(root);
        }
        
        create_adjacency(root->left);
        create_adjacency(root->right);
    }
    int findDepth(int s)
    {
        int res = 0;
        int n = mp.size();
        unordered_set<int> st;
        queue<pair<int, int>>q;
        q.push({s,0});
        
        while(!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            res = max(res, top.second);
            st.insert(top.first);
            
            for(auto it : mp[top.first])
            if(st.find(it->data)==st.end())
            q.push({it->data,top.second+1});
            
        }
        return res;
    }
    int minTime(Node* root, int target) {
        create_adjacency(root);
        return findDepth(target);
    }
};
