class Solution {
  public:
  
    static bool cmp(string a , string b){
              
 
               if (a+b>b+a){
                    return true;
               }
               else{
                    
                     return false;  
               }
              
                
    }
    string findLargest(vector<int> &arr) {
     
                   int n =arr.size();
                   vector<string>st;
                   for(int i=0;i<arr.size();i++){
                          st.push_back(to_string(arr[i]));
                   }
                   
                   sort(st.begin(),st.end(),cmp);
                   
                    // for(string i:st) cout<<i<<" ";
                        if (st[0] == "0") {
                            return "0";
                        }
                    
                    string ans ="";
                    for(string i:st)ans+=i;
                    
                    //   int i=0;
                    // while (i<ans.size() && ans[i]=='0') i++;
                    //  string res = "";
                    // for(int j=i;j<ans.size();j++)res+=ans[j];
                    
                    // if (res.size()==0) return "0";
                  return ans;
                   
     
        
    }
};
