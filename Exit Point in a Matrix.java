class Solution {
    public int[] FindExitPoint(int n, int m, int[][] matrix) {
        int i = 0,  j = 0, dir = 0;
        
        while(i < n && j < m && i >= 0 && j >= 0) {
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                dir++;
            }
            
            dir %= 4;
            switch(dir) {
                case 0: j++; 
                        break;
                
                case 1: i++;
                        break;
                
                case 2: j--;
                        break;
                
                case 3: i--;
                        break;
            }
        }
        
        int res[] = new int[2];
        switch(dir) {
            case 1: res[0] = i - 1;
                    res[1] = j;
                    break;
                    
            case 2: res[0] = i;
                    res[1] = j + 1;
                    break;
                    
            case 3: res[0] = i + 1;
                    res[1] = j;
                    break;
        }
        
        if(dir == 0) {
            res[0] = i;
            res[1] = j - 1;
        }
        
        return res;
    }
}
