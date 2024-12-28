class Solution {
    public List<List<Integer>> findTriplets(int[] arr) {
        // Your code here
         List<List<Integer>> triplet = new ArrayList<>();
        for(int i=0; i<arr.length; i++){
            for(int j=i+1; j<arr.length; j++){
                for(int k=j+1; k<arr.length; k++){
                    if(arr[i]+arr[j]+arr[k]==0){
                        ArrayList<Integer> list = new ArrayList<>();
                        list.add(i);
                        list.add(j);
                        list.add(k);
                        
                        triplet.add(list);
                    }
                }
            }
        }
        return triplet;
    }
}
