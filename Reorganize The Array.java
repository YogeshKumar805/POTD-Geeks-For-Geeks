class Solution {
    public List<Integer> rearrange(List<Integer> arr) {
        // Code here
        int n = arr.size();
        List<Integer>result = new ArrayList<>();
        for(int i=0;i<n;i++){
            result.add(-1);
        }
        for(int i=0;i<n;i++){
            int element = arr.get(i);
            if(element>-1 && element<n){
                result.set(element,element);
            }
        }
        return result;
    }
}
