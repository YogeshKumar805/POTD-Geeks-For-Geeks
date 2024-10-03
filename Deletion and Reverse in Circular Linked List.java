class Solution {
    // Function to reverse a circular linked list
    Node reverse(Node head) {
        if (head == null || head.next == head) {
            return head;  // List is empty or has only one node
        }

        Node prev = null;
        Node current = head;
        Node next = null;
        Node tail = head;  // We'll track the tail to make it circular again

        // Iterate over the circular linked list
        do {
            next = current.next;  // Save the next node
            current.next = prev;  // Reverse the pointer
            prev = current;  // Move prev forward
            current = next;  // Move current forward
        } while (current != head);

        // At the end, prev is the new head, and current is back to old head
        head.next = prev;  // Make the old head point to the new tail (the previous head)
        head = prev;  // Update head to the new head

        return head;  // Return the new head
    }

    // Function to delete a node from the circular linked list
    Node deleteNode(Node head, int key) {
        if (head == null) {
            return null;  // List is empty
        }

        Node current = head;
        Node prev = null;

        // If the node to be deleted is the head
        if (head.data == key) {
            // Special case: if there's only one node in the list
            if (head.next == head) {
                return null;  // Deleting the only node in the list
            }

            // Find the tail of the list
            Node tail = head;
            while (tail.next != head) {
                tail = tail.next;
            }

            // Move the head to the next node
            head = head.next;
            tail.next = head;  // Maintain circular property by pointing tail to new head

            return head;
        }

        // Otherwise, search for the node with the given key
        do {
            prev = current;
            current = current.next;

            if (current.data == key) {
                prev.next = current.next;  // Remove the node by linking previous to next
                return head;
            }
        } while (current != head);

        return head;  // If the key is not found, return the original head
    }
}
