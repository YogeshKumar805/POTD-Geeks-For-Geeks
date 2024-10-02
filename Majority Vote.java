class Solution {
    // Function to find the majority elements in the array
    public List<Integer> findMajority(List<Integer> nums) {
        // Your code goes here.
        int n = nums.size();
        List<Integer> ans = new ArrayList<>();
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = -1, el2 = -1;
        // Boyer Moore's Voting Algo to find the candidates which might have n/3 votes
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums.get(i) != el2) {
                el1 = nums.get(i);
                cnt1 = 1;
            } else if(cnt2 == 0 && nums.get(i) != el1) {
                el2 = nums.get(i);
                cnt2 = 1;
            } else if(nums.get(i) == el1) cnt1++;
            else if(nums.get(i) == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        // Verifying the votes if the possible candidates have more than n/3 votes.
        for(int i = 0; i < n; i++) {
            if(nums.get(i) == el1) cnt1++;
            if(nums.get(i) == el2) cnt2++;
        }
        if(cnt1 > n / 3) ans.add(el1);
        if(cnt2 > n / 3) ans.add(el2);
        if(ans.isEmpty()) ans.add(-1);
        return ans;
    }
}
