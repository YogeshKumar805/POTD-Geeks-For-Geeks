class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double sum = 0;
        
        priority_queue<double> pq;
        
        for(auto i : arr){
            sum += i;
            pq.push(i);
        }
        
        double half = sum/2.0;
        
        int count = 0;
        
        while(sum > half){
            count++;
            double f = pq.top();
            pq.pop();
            sum -= f;
            sum += (f/2.0);
            pq.push(f/2.0);
        }
        
        return count;
    }
};
