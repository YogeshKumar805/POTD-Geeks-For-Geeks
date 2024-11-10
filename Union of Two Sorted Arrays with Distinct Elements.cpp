class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> unionArray;
        int i=0,j=0;
        int na=a.size();
        int nb=b.size();
        
        
        while(i<na && j<nb){
            if(a[i]<b[j]){
                unionArray.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                unionArray.push_back(b[j]);
                j++;
                
            }
            else{
                unionArray.push_back(a[i]);
                i++;
                j++;
            }
            
        }
        
        while(i<na){
            unionArray.push_back(a[i]);
            i++;
        }
        while(j<nb){
            unionArray.push_back(b[j]);
            j++;
            
        }
        
        return unionArray;
        
    }
};
