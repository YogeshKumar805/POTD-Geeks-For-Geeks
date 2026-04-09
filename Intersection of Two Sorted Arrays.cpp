class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
            if(ans.empty()||ans.back()!=a[i]){
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }else if(a[i]<b[j])i++;
        else j++;}
        return ans;
    }
};
