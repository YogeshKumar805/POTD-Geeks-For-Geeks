class Solution {
  public:
    int noConseBits(int n) {
        // code here
        vector<int> bits(32, 0);
        for(int i=0;i<32;i++)   {
            // building bit array
            if((1 << i) & n)    bits[i] = 1;
        }
        
        for(int i=31;i>=2;i--)  {
            // checking if 3 consecutives bit are set or not
            if(bits[i] && bits[i-1] && bits[i-2])   bits[i-2] = 0;
        }
        
        int res = 0;
        for(int i=0;i<32;i++)   {
            // adding bit to answer if bit is set
            if(bits[i]) res |= (1 << i);
        }
        return res;
    }
    // Time Complexity :- O(1)
    // Space Complexity :- O(1)
};
