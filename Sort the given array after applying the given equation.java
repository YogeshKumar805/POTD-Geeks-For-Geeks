class Solution {
    public ArrayList<Integer> sortArray(int[] arr, int A, int B, int C) {
        // Code here
        ArrayList<Integer> al=new ArrayList<>();
        for(int i:arr) al.add(A*(int)Math.pow(i,2)+B*i+C);
        Collections.sort(al);
        return al;
    }
}
