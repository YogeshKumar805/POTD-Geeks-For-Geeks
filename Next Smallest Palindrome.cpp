class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
        vector<int> ans = num;
        for(int i = (n+1)/2, j = n-i-1 ; i < n ; i++) {
            if(num[j] > num[i]){
                while(i < n){
                    ans[i] = num[j];
                    i++;
                    j--;
                }
                return ans;
            } else if(num[j] < num[i]) break;
            ans[i] = num[j];
            j--;
        }
        
        for(int i = (n-1)/2 ; i >= 0 ; i--){
            if(num[i] != 9){ 
                ans[i]++;
                ans[n-i-1] = ans[i];
                i--;
                while(i >= 0){
                    ans[n-i-1] = ans[i];
                    i--;
                }
                return ans;
            }
            else {
                ans[i] = 0;
                ans[n-i-1] = 0;
            }
        }
        
        ans[0] = 1;
        for(int i = 1 ; i < n ; i++) ans[i] = 0;
        ans.push_back(1);
        return ans;
    }
};
