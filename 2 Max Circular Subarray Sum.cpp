class Solution {
  public:
    int max_subarray_sum(vector<int>&arr){
        int n=arr.size();
        int ans=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int prefix[n]={0},suffix[n]={0};
        prefix[0]=arr[0],suffix[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=arr[i]+prefix[i-1];
            suffix[n-i-1]=arr[n-i-1]+suffix[n-i];
        }
        int sum1=max_subarray_sum(arr);
        int sum2=INT_MIN;
        priority_queue<int>pq;
        pq.push(prefix[0]);
        for(int i=1;i<n;i++){
            int top=pq.top();
            if(i+1<n && top+suffix[i+1]>sum2) sum2=top+suffix[i+1];
            pq.push(prefix[i]);
        }
        return max(sum1,sum2);
    }
};
