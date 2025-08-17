class Solution {
  public:
    
     int c;
    static bool cmp(int a ,int b){
          
            if (abs(a)<abs(b)){
                   return true;
            }
            else{
                 return false;
            }
          
    }
    void rearrange(vector<int> &arr, int x) {
            for(int i=0;i<arr.size();i++){
                  arr[i]= (arr[i]-x);
            }
              stable_sort(arr.begin(),arr.end(),cmp);
           for(int i=0;i<arr.size();i++){
              arr[i]= arr[i]+x;
           }
    }
};
