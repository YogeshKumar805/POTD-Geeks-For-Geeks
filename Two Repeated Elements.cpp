class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        int cxor = 0;
        for(int i = 0; i <= n; i++)
        {
            cxor = cxor ^ i;
        }
        for(int i = 0; i < n+2; i++)
        {
            cxor = cxor ^ arr[i];
        }
        int m = 0;
        while(cxor)
        {
            if(cxor & 1) break;
            m++;
            cxor = cxor >> 1;
        }
        
        int first = 0;
        int second = 0;
        for(int i = 0; i < n+2; i++)
        {
            if(arr[i] & (1 << m)) first ^= arr[i];
            else second ^= arr[i];
        }
        for(int i = 0; i <= n; i++)
        {
            if(i & (1 << m)) first ^= i;
            else second ^= i;
        }
        
        int firstOccurred = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n+2; i++)
        {
            if(arr[i] == first)
            {
                cnt1++;
                if(cnt1 == 2) 
                {
                    firstOccurred = first;
                    break;
                }
            }
            else if(arr[i] == second)
            {
                cnt2++;
                if(cnt2 == 2)
                {
                    firstOccurred = second;
                    break;
                }
            }
        }
        
        if(firstOccurred == first) return {first, second};
        return {second, first};
    }
};
