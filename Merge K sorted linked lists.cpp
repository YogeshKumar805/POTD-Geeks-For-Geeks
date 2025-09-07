class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        bool check=true;
        Node* st=new Node(-1);
        Node* head=st;
        while(check){
            int minNum=INT_MAX;
            int mini=-1;
            check=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i] && arr[i]->data<minNum){
                    minNum=arr[i]->data;
                    mini=i;
                    check=1;
                }
                
            }
            if(mini!=-1){
                Node* temp=new Node(minNum);
                st->next=temp;
                st=temp;
                arr[mini]=arr[mini]->next;
            }
        }
        return head->next;
    }
};
