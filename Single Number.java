class Solution {
    int getSingle(int arr[]) {
        int num = arr[0];
        // as we knoe xor of even element will become 0;
        // also we know only one element is there whose odd times repeating
        for(int i =1;i<arr.length;i++){
            // xor eliminate even numbered element
            num ^= arr[i];
        }
        // in num only odd element left
        return num;
    }
}
