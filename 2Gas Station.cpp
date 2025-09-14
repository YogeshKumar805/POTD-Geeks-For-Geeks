class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int sum1 = 0 , sum2 = 0;
        for(auto i: gas)sum1+=i;
        for(auto i: cost)sum2+=i;
        if(sum2>sum1)return -1;   // check if cost is > the availagle gas
        int sum =0 , ind =0;
        for(int i=0;i<gas.size() ; i++){    // kadane algorithm on gas[i] - cost[i];
            sum+= (gas[i] - cost[i]);
            if(sum <0){
                sum = 0;
                ind = i+1;
            }
        }
        return ind;
        
    }
};

