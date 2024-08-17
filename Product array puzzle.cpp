class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        vector<long long int> mul;
        int n = nums.size();
        unsigned long long int tot = 1;
        int count = 0;
        for(auto it: nums){
            if(it!=0){
                tot *= it;
            }
            if(it==0){
                count++;
            }
            if(count>1){
                break;
            }
        }
        if(count>1){
            mul.resize(n, 0);
            return mul;
        }
        if(count>0){
            mul.resize(n, 0);
            for(int i=0; i<n; i++){
                if(nums[i] == 0){
                    mul[i] = tot;
                    return mul;
                }
            }
        }
        for(int i=0; i<n; i++){
            mul.push_back(tot/nums[i]);
        }
        return mul;
    }
};
