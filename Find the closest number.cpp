class Solution{
    public:
    int findClosest( int n, int k,int a[]) 
    {
        int low =0,high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid]==k)return a[mid];
            if(a[mid]>= k and a[mid-1]<=k){
                if((a[mid]-k)<= k-a[mid-1])return a[mid];
                else return a[mid-1];
            }
            else if(a[mid]<=k and a[mid+1]>=k){
                if((a[mid+1]-k)<= k-a[mid])return a[mid+1];
                else return a[mid];
            }
            else if(a[mid]>k and a[mid-1]>k)high = mid-1;
            else low=mid+1;
        }
        
    } 
};
