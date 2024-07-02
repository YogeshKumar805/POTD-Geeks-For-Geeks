class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string s="";
        while(head!=NULL){
            s+=head->data;
            head=head->next;
        }
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
};
