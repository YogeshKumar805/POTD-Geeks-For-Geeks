class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int a=arr[0];
        int d=arr[1]-arr[0];
        int i=2,n=arr.size(),j=2;
        int ans=-1;
        while(i<n){
            if(a+(j)*d==arr[i]){
                i++;
            }
            else{
                ans=a+j*d;
                break;
            }
          j++;
        }
        return ans==-1?a+n*d:ans;
    }
};
