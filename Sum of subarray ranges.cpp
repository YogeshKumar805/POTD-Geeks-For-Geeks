class Solution {
  public:
    virtual vector<int> getPSE(vector<int> &arr){
      int n=arr.size();
      vector<int> pse(n);
      stack<int> st;
      
      for(int i=0; i<n; i++){
        while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();
        
        pse[i] = (st.empty())? -1: st.top();
        st.push(i);
      }
      
      return pse;
    }
    virtual vector<int> getNSE(vector<int> &arr){
      int n=arr.size();
      vector<int> nse(n);
      stack<int> st;
      
      for(int i=n-1; i>=0; i--){
        while(!st.empty() && (arr[st.top()] > arr[i])) st.pop();
        
        nse[i] = (st.empty())? n: st.top();
        st.push(i);
      }
      
      return nse;
    }
    virtual vector<int> getNGE(vector<int> &arr){
      int n=arr.size();
      vector<int> nge(n);
      stack<int> st;
      
      for(int i=n-1; i>=0; i--){
        while(!st.empty() && (arr[st.top()] < arr[i])) st.pop();
        
        nge[i] = (st.empty())? n: st.top();
        st.push(i);
      }
      
      return nge;
    }
    
    virtual vector<int> getPGE(vector<int> &arr){
      int n=arr.size();
      vector<int> pge(n);
      stack<int> st;
      
      for(int i=0; i<n; i++){
        while(!st.empty() && (arr[st.top()] <= arr[i])) st.pop();
        
        pge[i] = (st.empty())? -1: st.top();
        st.push(i);
      }
      
      return pge;
    }    
    
    virtual vector<int> miniContribute(vector<int> &arr){
      int n=arr.size();
      vector<int> miniContributeArr(n);
      
      vector<int> pseArr = getPSE(arr);
      vector<int> nseArr = getNSE(arr);
      
      for(int i=0; i<n; i++){
        miniContributeArr[i] = (i-pseArr[i])*(nseArr[i]-i);  
      }
      return miniContributeArr;
    }
    virtual vector<int> maxiContribute(vector<int> &arr){
      int n=arr.size();
      vector<int> maxiContributeArr(n);
      
      vector<int> pgeArr = getPGE(arr);
      vector<int> ngeArr = getNGE(arr);
      
      for(int i=0; i<n; i++){
        maxiContributeArr[i] = (i-pgeArr[i])*(ngeArr[i]-i);  
      }
      return maxiContributeArr;
    }
    
    
    virtual int subarrayRanges(vector<int>& arr){
      int n=arr.size();
      vector<int> maxiContributeArr(n), miniContributeArr(n);
      maxiContributeArr = maxiContribute(arr);
      miniContributeArr = miniContribute(arr);
      
      int sum=0;
      for(int i=0; i<n; i++){
        sum += (arr[i] * (maxiContributeArr[i] - miniContributeArr[i]));      
      }
      return sum;
    }
};
