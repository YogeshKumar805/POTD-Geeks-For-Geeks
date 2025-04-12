class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int original = image[sr][sc] ; 
        Queue<Pair> q = new LinkedList<>() ; 
        int[] dx = {-1 , 1 , 0 , 0 } ; 
        int[] dy = {0 , 0 , -1 , 1 } ; 
        int n = image.length ; 
        int m = image[0].length ; 
        int[][] visited = new int[n][m] ; 
        q.offer(new Pair(sr , sc)) ; 
        image[sr][sc] = newColor ; 
        visited[sr][sc] = 1 ; 
        while(!q.isEmpty()){
            Pair p = q.poll() ; 
            int x = p.first ; 
            int y = p.second; 
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i] ; 
                int ny = y + dy[i] ; 
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0  && image[nx][ny] == original){
                    q.offer(new Pair(nx , ny)) ;
                    visited[nx][ny] = 1 ; 
                    image[nx][ny] = newColor ; 
                }
            }
        }
        return image; 
        
    }
}
