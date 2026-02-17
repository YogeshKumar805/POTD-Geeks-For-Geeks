class Solution {
  public:
    virtual int overlapIntService(int i, int j, vector<int> &s, vector<int> &e){
      if(i>=s.size()) return 0;
      if(s[i]>e[j])
        return overlapIntService(i+1, j+1, s, e);
      return 1+overlapIntService(i+1, j, s, e);    
    }
  
    virtual int overlapInt(vector<vector<int>> &arr){
      vector<int> s, e;
      for(vector<int> &v: arr){
        s.push_back(v[0]); e.push_back(v[1]);  
      }
      
      sort(s.begin(), s.end());
      sort(e.begin(), e.end());
      
      return 1+overlapIntService(1, 0, s, e);
      
    }
    
    virtual ~Solution(){}
};
