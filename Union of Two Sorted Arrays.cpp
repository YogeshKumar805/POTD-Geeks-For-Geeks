class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>ans;
        ans.push_back(min(arr1[0],arr2[0]));
        int i=0; 
        int j=0;
        while(i<n && j<m){
            if(arr1[i] != ans.back() && arr2[j] != ans.back()){
                if(arr1[i] < arr2[j]){
                    ans.push_back(arr1[i]);
                    i++;
                }
                else if(arr1[i] > arr2[j]){
                    ans.push_back(arr2[j]);
                    j++;
                }
                else{
                    ans.push_back(arr1[i]);
                    i++;
                    j++;
                }
            }
            else if(arr1[i] == ans.back() && arr2[j] != ans.back()){
                i++;                
            }
            else if(arr1[i] != ans.back() && arr2[j] == ans.back()){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        
        while(i<n){
            if(arr1[i] != ans.back()) ans.push_back(arr1[i]);
            i++;
        }
        
        while(j<m){
            if(arr2[j] != ans.back()) ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
};
