class Solution {
    ArrayList<Integer> findMissing(int a[], int b[], int n, int m) {
        HashSet<Integer> set = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i=0; i<b.length; i++){
            set.add(b[i]);
        }

        for (int i=0; i<a.length; i++){
            if (!set.contains(a[i])){
                ans.add(a[i]);
            }
        }
        return ans;
    }
}
