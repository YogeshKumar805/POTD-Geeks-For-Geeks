class Solution {
  public:
  
    struct Node{
        Node* child[26];
        int cnt;
        
        Node(){
            cnt=0;
            for(int i=0; i<26; i++){
                child[i]=NULL;
            }
        }
    };
    
    void insert(string &s, Node* root){
        Node* node=root;
        
        for(char &ch:s){
            int ind=(ch-'a');
            if(node->child[ind]==NULL){
                node->child[ind]=new Node();
            }
            node=node->child[ind];
            node->cnt++;
        }
    }
    
    string getPref(string &s, Node* root){
        Node* node=root;
        string ans="";
        for(char &ch:s){
            int ind=(ch-'a');
            node=node->child[ind];
            ans+=ch;
            if(node->cnt==1) break;
        }
        return ans;
    }
  
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        Node* root=new Node();
        for(string &s:arr){
            insert(s, root);
        }
        vector<string>ans;
        for(string &s:arr){
            ans.push_back(getPref(s, root));
        }
        return ans;
    }
};
