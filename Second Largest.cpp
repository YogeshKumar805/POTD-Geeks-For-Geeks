class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        //use set to remove the multiple instances of the element
        set<int> st(arr.begin(),arr.end());
        //put the values of the set to a vector
        vector<int> ans(st.begin(),st.end());
        //sort the vector
        sort(ans.begin(),ans.end());
        //return -1 if only 1 element is in the array        
        if(ans.size()==1){
            return -1;
        }
        else
        //return the second last emement for the 2nd largest element 
        return ans[ans.size()-2];
        
    }
};
