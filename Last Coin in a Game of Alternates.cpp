class Solution {
public:

int coin(vector<int> &arr) {
    int i = 0;
    int j = arr.size() - 1;
    
    while(i < j) {
        if(arr[i] >= arr[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    
    return arr[i];
}

};
class Solution {
    public int coin(int[] arr) {
        int i = 0;
        int j = arr.length - 1;
        
        while(i < j) {
            if(arr[i] >= arr[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return arr[i];
    }
}
