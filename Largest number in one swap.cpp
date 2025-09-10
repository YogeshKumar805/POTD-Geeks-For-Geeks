class Solution {
  public:
    string largestSwap(string &s) {
        // code here
       
          int n = s.size();
        if (n <= 1) return s;

        // Step 1: Store the index of the maximum character from right to left
        vector<int> maxIndex(n);
        maxIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[maxIndex[i + 1]])
                maxIndex[i] = i;
            else
                maxIndex[i] = maxIndex[i + 1];
        }

        // Step 2: Find the first position where swap can increase lexicographic order
        for (int i = 0; i < n; i++) {
            if (s[i] < s[maxIndex[i]]) {
                // Swap with the rightmost maximum character
                swap(s[i], s[maxIndex[i]]);
                break;
            }
        }
        return s;
    
    }
};

 
