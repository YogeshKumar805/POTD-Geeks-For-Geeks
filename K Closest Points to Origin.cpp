class Solution {
  public:
   int dis(int x, int y){
       return (x*x)+(y*y);
   }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<pair<int,pair<int,int>>>v;
         for(auto &i:points){
             int dist=dis(i[0],i[1]);
             v.push_back({dist,{i[0],i[1]}});
         }
         sort(v.begin(),v.end());
         vector<vector<int>>ans;
         for(int i=0;i<k;i++){
             ans.push_back({v[i].second.first,v[i].second.second});
         }
         return ans;
    }
};

