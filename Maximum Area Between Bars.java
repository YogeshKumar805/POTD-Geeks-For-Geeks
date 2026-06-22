class Solution {
    public int maxArea(List<Integer> height) {
        // code here
        int res = Integer.MIN_VALUE;
        int n = height.size();
        int i = 0, j = n-1;
        while(i < j){
            res = Math.max(res, Math.min(height.get(i), height.get(j)) * (j-i-1));
            if(height.get(i) >= height.get(j)){
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
}
