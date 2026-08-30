class Solution {
  public:
    int ceilPos(int num, vector<int> &arr) {
        int ans=0;
        int start=0, end=arr.size()-1;
        while(start<=end) {
            int mid=(start+end)/2;
            if(arr[mid]>=num) {
                ans=mid;
                end=mid-1;
            } else start=mid+1;
        }
        return ans;
    }
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int> ans;
        int n=l.size();
        vector<int> diff(n);
        diff[0]=r[0]-l[0]+1;
        for(int i=1; i<n; i++) diff[i]=diff[i-1]+r[i]-l[i]+1;
        for(int i=0; i<rank.size(); i++) {
            int index=ceilPos(rank[i],diff);
            if(index==0) ans.push_back(l[index]+rank[i]-1);
            else ans.push_back(l[index]+rank[i]-diff[index-1]-1);
        }
        return ans;
    }
};
