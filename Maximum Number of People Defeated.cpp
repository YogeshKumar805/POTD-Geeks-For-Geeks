class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int i = 1, cnt = 0;

        while (i*i <= p){
            cnt++;
            p -= i*i;
            i++;
        }

        return cnt;
    }
};
