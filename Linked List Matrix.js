class Solution {
    
    convertToLinkedList(row,col,head,n,mat){
                
        if (row < 0 || col < 0 || row === n || col === n) return null
        
        head = new Node(mat[row][col])
        
        let Down = this.convertToLinkedList(row+1,col,head,n,mat)
        let Right = this.convertToLinkedList(row,col+1,head,n,mat)
        
        head.down = Down
        head.right = Right
        
        return head
        
    }
        
    constructLinkedMatrix(mat) {
        
        return this.convertToLinkedList(0,0,null,mat.length,mat)
    }
}
