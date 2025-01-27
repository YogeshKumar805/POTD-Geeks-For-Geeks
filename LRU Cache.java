class LRUCache 
{
    private static class Node 
    {
        int key, value;
        Node prev, next;

        Node(int key, int value) 
        {
            this.key = key;
            this.value = value;
        }
    }
    private final int capacity;
    private final Map<Integer, Node> cache;
    private final Node head, tail;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) 
    {
        this.capacity = cap;
        this.cache = new HashMap<>();
        this.head = new Node(-1, -1); // Dummy head
        this.tail = new Node(-1, -1); // Dummy tail
        head.next = tail;
        tail.prev = head;
    }
    // Function to return value corresponding to the key.
    public int get(int key) 
    {
        if (!cache.containsKey(key)) {
            return -1;
        }
        Node node = cache.get(key);
        moveToHead(node);
        return node.value;
    }
    // Function for storing key-value pair.
    public void put(int key, int value) 
    {
        if (cache.containsKey(key)) 
        {
            Node node = cache.get(key);
            node.value = value; // Update the value
            moveToHead(node);  // Mark as recently used
        } else 
        {
            if (cache.size() == capacity) 
            {
                removeLeastRecentlyUsed();
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            addToHead(newNode);
        }
    }
    // Helper function to move a node to the head.
    private void moveToHead(Node node) 
    {
        removeNode(node);
        addToHead(node);
    }
    // Helper function to remove a node.
    private void removeNode(Node node) 
    {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    // Helper function to add a node to the head.
    private void addToHead(Node node) 
    {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
    // Helper function to remove the least recently used node.
    private void removeLeastRecentlyUsed() 
    {
        Node lru = tail.prev;
        removeNode(lru);
        cache.remove(lru.key);
    }
}
