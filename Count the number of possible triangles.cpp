class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int ans =0;
        int n = arr.size();
        for(int i = 0 ; i < n-2 ;i++ ){
            
            for(int j = i+1 ; j < n-1 ; j++){
                
                for(int k = j+1; k < n ; k++){
                    
                    if(arr[i]+arr[j] > arr[k]){
                        ans++;
                    } else break;
                }
            }
        }
        return ans;
    }
};
