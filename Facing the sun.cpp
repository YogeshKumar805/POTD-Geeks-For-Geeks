class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
         // Abhishek
        int maximum = height[0];
        int count = 1;
        for(auto i:height)
        {
            if(i>maximum){
                maximum = i;
                count++;
            }
        }
        return count;
    }
};
