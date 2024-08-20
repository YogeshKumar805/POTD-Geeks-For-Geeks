
class Solution {
  public:
    int ans{0};
  
    pair<int, bool> go(Node* r, int t)
    {
        // base case
        if(!r) return {0, false};
        
        // Recursive case
        pair<int, bool> ld = go(r->left, t);
        pair<int, bool> rd = go(r->right, t);
        
        if(r->data == t)
        {
           ans = max({ans, ld.first, rd.first});
           return {1, true};
        }
        
        int cmx = ld.first + rd.first;
        
        if(ld.second == true)
        {
            ans = max(ans, cmx);
            ld.first++;
            return ld;
        }
        else if(rd.second == true)
        {
            ans = max(ans, cmx);
            rd.first++;
            return rd;
        }
        
        return {max(ld.first, rd.first) + 1, false};
    }
  
    int minTime(Node* root, int target) 
    {
        go(root, target);
        
        return ans;
    }
};
