class Solution{
public:
vector<int> constructLowerArray(vector<int>arr) {
    // code here
   vector<int> ans;
    int n= arr.size();
    vector<int> temp;
    
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++){
            //using binary search for finding the index of ith element of original array
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(index);
            //removing the element, so that the right-side for any ith element doesn't exist
            temp.erase(temp.begin()+index);
        }
        return ans;
 
}
};
