class Solution {

  public:

    /* Returns count of pairs with difference k */

    int countPairsWithDiffK(vector<int>& arr, int k) {

        // code here

        unordered_map<int,int>mp;

        int c=0;

        for(auto num:arr){

            if(mp.count(num-k)){

                c+=mp[num-k];

            }   

            if(mp.count(num+k)){

                c+=mp[num+k];

            }

        mp[num]++;

        }

        return c;

    }

};
