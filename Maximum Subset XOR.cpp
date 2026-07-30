class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> basis(23);
        for(int i=0; i<n; i++)
        {
            int el = arr[i];
            for(int bit = 22; bit >= 0; bit--)
            {
                
                if(el & (1<<bit))
                {
                    if(basis[bit] & (1<<bit))
                    {
                        el ^= basis[bit];
                    }
                    else
                    {
                        basis[bit] = el;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=22; i>=0; i--)
        {
             if(basis[i] & (1<<i))
             {
                 if(!(ans & (1<<i))) ans ^= basis[i];
             }
        }
        return ans;
    }
};

