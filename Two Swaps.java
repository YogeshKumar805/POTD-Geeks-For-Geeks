class Solution {
    public boolean checkSorted(List<Integer> arr) {
        int count =0;
        boolean flag = false;
        for(int i=0;i<arr.size();i++)
        {
            if(arr.get(i) != i+1)
            {
                count++;
                if(i+1 == arr.get(arr.get(i)-1))
                {
                    flag = true;
                }
            }
        }
        if( count == 0 || count == 3 || (count == 4 && flag))
        {
            return true;
        }
        return false;
    }
}
