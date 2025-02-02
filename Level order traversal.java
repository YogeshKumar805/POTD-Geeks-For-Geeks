class Solution {
    public ArrayList<ArrayList<Integer>> levelOrder(Node root) {
        // Your code here
        ArrayList<ArrayList<Integer>>list=new ArrayList<>();
        if(root==null) return list;
        Queue<Node>q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            ArrayList<Integer>ll=new ArrayList<>();
            for(int i=0;i<size;i++){
                Node curr=q.remove();
                ll.add(curr.data);
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);
            }
            list.add(ll);
        }
        return list;
    }
}

