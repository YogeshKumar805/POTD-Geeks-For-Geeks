class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
       
        if(type==1){
            while(k--){
                int top= dq.back();
                dq.pop_back();
                dq.push_front(top);
            }
        }
        else if(type==2){
            while(k--){
                int top=dq.front();
                dq.pop_front();
                dq.push_back(top);
            }
        }
            
        
    }
};

