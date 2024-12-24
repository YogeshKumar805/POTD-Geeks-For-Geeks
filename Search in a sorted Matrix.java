class Solution {
    // Function to search a given number in row-column sorted matrix.
    public boolean searchMatrix(int[][] mat, int x) {
        // code here
        int ind=matbin(mat,x);
        if(ind==-1) return false;
        return isin(mat[ind],x);
        
    }
    int matbin(int arr[][],int x){
        int l=0;
        int h=arr.length-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid][arr[mid].length-1]>=x && arr[mid][0]<=x||arr[mid][0]==x || arr[mid][arr[mid].length-1]==x) return mid;
            else if(arr[mid][arr[mid].length-1]>=x) h=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    boolean isin(int arr[],int x){
        int l=0;
        int h=arr.length-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==x) return true;
            else if(arr[mid]>x) h=mid-1;
            else l=mid+1;
        }
        return false;
    }
}

