class Solution {
  public:
    int maxLength(string str) {
        // arr stores maximum valid string according to depth
        // ( - increase depth
        // ) - decrease depth
        int n = str.size();
        vector<int> arr(n, 0);
        // () (() = 2
        int maxl = 0;
        int depth = 0;
        for(char ch : str)
        {
            // count the depth of open parenthesis
            if(ch == '(')
            {
                depth++;
            }
            // in case of close parenthesis, check that depth >0
            if(ch == ')')
            {
                if(depth > 0)
                {
                    // decrease depth
                    depth--;
                    // increase count by 2 and add count of deeper point
                    arr[depth] += 2 + arr[depth+1];
                    // clear deeper point, in case it might be used again
                    arr[depth+1] = 0;
                    maxl = max(maxl, arr[depth]);
                }
                else
                {
                    // when depth reaches minimum, clear last count
                    arr[0] = 0;
                }
            }
        }
        return maxl;
    }
};
