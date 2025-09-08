/*
class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node mergeSort(Node head) {
        // code here
        ArrayList<Integer>list = new ArrayList();
        Node curr = head;
        
        while(curr != null)
        {
            list.add(curr.data);
            curr = curr.next;
        }
        Collections.sort(list);
        curr = head;
        int j = 0;
        while(curr != null && j < list.size())
        {
            curr.data = list.get(j++);
            curr = curr.next;
        }
        return head;
    }
}

