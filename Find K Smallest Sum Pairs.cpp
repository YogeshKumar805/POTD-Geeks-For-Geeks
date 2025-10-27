class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mnHp;
        set<vector<int>> chek;
        
        mnHp.push({arr1[0]+arr2[0], 0, 0});
        chek.insert({0, 0});
        
        int cnt=0, flg=1;
        
        while (cnt++ < k && flg) {
            vector<int> tem = mnHp.top();
            mnHp.pop();
            int i = tem[1];
            int j = tem[2];
            ans.push_back({arr1[i], arr2[j]});
            
            flg = 0;
            if (i+1 < arr1.size()) {
                vector<int> tem1 = {i+1, j};
                if (chek.find(tem1) == chek.end()) {
                    mnHp.push({arr1[i+1]+arr2[j], i+1, j});
                    chek.insert({i+1, j});
                }
                flg = 1;
            }
            
            if (j+1 < arr2.size()) {
                vector<int> tem2 = {i, j+1};
                if (chek.find(tem2) == chek.end()) {
                    mnHp.push({arr1[i]+arr2[j+1], i, j+1});
                    chek.insert({i, j+1});
                }
                flg = 1;
            }
        }
        return ans;
    }
};
