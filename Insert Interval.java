class Solution {
    static ArrayList<int[]> insertInterval(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> res=new ArrayList<>();
        boolean merged=false;
        int start=newInterval[0],end=newInterval[1];
        for(int x[]:intervals){
            if(x[1]<newInterval[0]) res.add(x);
            else if(x[0]>newInterval[1]){
                if(!merged){
                    int temp[]=new int[2];
                    temp[0]=start;
                    temp[1]=end;
                    res.add(temp);
                    merged=true;
                }
                res.add(x);
            }
            else{
                start=Math.min(x[0],start);
                end=Math.max(x[1],end); 
            }
        }
        if(!merged){
            int temp[]=new int[2];
            temp[0]=start;
            temp[1]=end;
            res.add(temp);
        }
        return res;
    }
}

