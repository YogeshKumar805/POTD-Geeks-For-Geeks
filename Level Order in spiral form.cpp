class Solution {
  public:
    vector<int> findSpiral(Node* r) {
        if(!r) return {};
        vector<int>a;
        stack<Node*>s1,s2;
        s1.push(r);
        while(!s1.empty()||!s2.empty()){
            while(!s1.empty()){
                Node*t=s1.top();s1.pop();
                a.push_back(t->data);
                if(t->right) s2.push(t->right);
                if(t->left)  s2.push(t->left);
            }
            while(!s2.empty()){
                Node*t=s2.top();s2.pop();
                a.push_back(t->data);
                if(t->left)  s1.push(t->left);
                if(t->right) s1.push(t->right);
            }
        }
        return a;
    }
};
