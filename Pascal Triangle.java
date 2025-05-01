class Solution {
    ArrayList<Integer> nthRowOfPascalTriangle(int n) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        for (int i = 1; i < n; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(1);
            for (int j = 1; j < arr.size(); j++) {
                temp.add(arr.get(j - 1) + arr.get(j));
            }
            temp.add(1);
            arr = temp;
        }
        return arr;
    }
}
