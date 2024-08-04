class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        int count=1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int last=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>last){
                count++;
                last=v[i].first;
            }
        }
       
        
    return count;
    }
};
