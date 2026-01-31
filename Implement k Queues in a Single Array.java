class kQueues {
    ArrayList<Integer>[] Q;
    int n;
    int currSize;
    kQueues(int n, int k) {
        
        // member initialization
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] temp = new ArrayList[k];
        Q = temp;
        
        this.n = n; // total max size
        currSize = 0; // currently filled with
        for(int i=0; i<k; i++){
            Q[i] = new ArrayList<>();
        }
    }

    void enqueue(int x, int i) {
        if(currSize==n) return; // already full
        
        Q[i].add(x);
        currSize++; // update size
    }

    int dequeue(int i) {
        if(Q[i].isEmpty()) return -1; // q is empty
        
        currSize--;
        return Q[i].remove(0);
    }

    boolean isEmpty(int i) {
        return Q[i].size()==0;
    }

    boolean isFull() {
        return n==currSize; // curr size == max capacity
    }
}
