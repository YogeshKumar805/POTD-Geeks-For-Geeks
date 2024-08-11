class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       vector<int>ans;
       sort(arr,arr+n,[&](Job a,Job b){
           return (a.profit == b.profit)?a.dead < b.dead:a.profit > b.profit;
       });
       int ct = 0;
       int profit = 0;
       vector<int>timeline(n+1,0);
       for(int i=0;i<n;i++){
           int st = arr[i].dead-1;
           if(st < 0)continue;
           while(timeline[st]==1){
               st--;
           }
           if(st < 0)continue;
           timeline[st] = 1;
           ct++;
           profit += arr[i].profit;
       }
       ans.push_back(ct);
       ans.push_back(profit);
       return ans;
    } 
};
