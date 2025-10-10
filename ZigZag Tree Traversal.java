class Solution {
    ArrayList<Integer> zigZagTraversal(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
         Queue<Node> q = new LinkedList<>();
         q.offer(root);
         int lvl = 0;
         
         while(!q.isEmpty()){
             int size = q.size();
             ArrayList<Integer> list = new ArrayList<>();
             for(int i=0; i<size; i++){
                 Node curr = q.poll();
                 list.add(curr.data);
                 
                 if(curr.left != null){
                     q.offer(curr.left);
                 }
                 
                 if(curr.right != null){
                     q.offer(curr.right);
                 }
             }
             if(lvl%2 == 0){
                 res.addAll(list);
             }else{
                 Collections.reverse(list);
                 res.addAll(list);
             }
             lvl++;
             
         }
         return res;
    }
}

