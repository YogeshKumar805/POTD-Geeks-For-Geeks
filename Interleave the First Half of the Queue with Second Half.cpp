class Solution {
  public:
    void rearrangeQueue(queue<int> &q){
      queue<int> t1;
      
      int n=(q.size())/2;
      int nc = n; 
      while(n--){
        t1.push(q.front()); q.pop();      
      }
      
      n=nc;
      while(n--){  
        q.push(t1.front()); t1.pop();
        q.push(q.front()); q.pop();        
      }
      
      return;
    }
};
