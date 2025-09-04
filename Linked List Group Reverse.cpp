class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        
        vector<int>v;
        Node*p=head;
        while(p!=NULL){
           v.push_back(p->data); 
           p=p->next;
        }
        
        int rem=v.size()%k;
        
        int i=0;
        while(i<v.size()-rem){
            
        reverse(v.begin()+i,v.begin()+i+k);
        i+=k;
        
        }
        
         
        if(i!=v.size()-1){
            reverse(v.begin()+i,v.end());
        }
        
        
       
        p=head;
        i=0;
        while(p!=NULL){
          p->data=v[i];
          i++;
          p=p->next;
        }
        return head;
        
    }
};
