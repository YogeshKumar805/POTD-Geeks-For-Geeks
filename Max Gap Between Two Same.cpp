class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int>cha(26,-1);
        int maxgap=-1;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(cha[index]==-1){
                cha[index]=i;
            }else{
                int gap=i-cha[index]-1;
                 maxgap=max(maxgap,gap);
            }
        }
        return maxgap;
    }
};
