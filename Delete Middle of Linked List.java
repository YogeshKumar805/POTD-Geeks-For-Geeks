class Solution {
    public Node deleteMid(Node head) {
        if (head == null) {
            return null;
        }

        int count = 0;
        Node current = head;

        while (current != null) {
            count++;
            current = current.next;
        }

        if (count == 1) {
            return null;
        }

        Node prev = head;
        for (int i = 0; i < (count / 2) - 1; i++) {
            prev = prev.next;
        }

        Node middle = prev.next;
        prev.next = middle.next;

        return head;
    }
}
