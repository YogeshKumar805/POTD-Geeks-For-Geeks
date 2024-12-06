class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int s=citations.size();
        int t;
        int i=s-1;
        
      sort(citations.begin(),citations.end());
      
      for(i=citations.size()-1;i>=0;i--)
      {
          if(citations[i]==s-i)
          {
              return citations[i];
          }
          
          else if(citations[i]<s-i)
          {
              t=s-i;
              break;
          }
      }
      
      if(i==-1)
      return t;
      
      return t-1;
    
      
    }
};

