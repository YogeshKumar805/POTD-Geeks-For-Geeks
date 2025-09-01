import java.util.*;

class Solution {
    // Helper class to store frequency and value
    static class Pair {
        int freq, value;
        Pair(int freq, int value) {
            this.freq = freq;
            this.value = value;
        }
    }

    public int sumOfModes(int[] arr, int k) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((a, b) -> {
            if (a.freq == b.freq) return Integer.compare(a.value, b.value);
            return Integer.compare(b.freq, a.freq);
        });

        int sum = 0;
        int n = arr.length;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            int val = arr[i];
            freqMap.put(val, freqMap.getOrDefault(val, 0) + 1);
            maxHeap.offer(new Pair(freqMap.get(val), val));
        }

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            // Add mode of current window
            while (freqMap.get(maxHeap.peek().value) != maxHeap.peek().freq) {
                maxHeap.poll(); // Remove outdated frequency
            }
            sum += maxHeap.peek().value;

            // Remove outgoing element
            int outVal = arr[i - k];
            freqMap.put(outVal, freqMap.get(outVal) - 1);

            // Add incoming element
            int inVal = arr[i];
            freqMap.put(inVal, freqMap.getOrDefault(inVal, 0) + 1);
            maxHeap.offer(new Pair(freqMap.get(inVal), inVal));
        }

        // Add mode of the last window
        while (freqMap.get(maxHeap.peek().value) != maxHeap.peek().freq) {
            maxHeap.poll();
        }
        sum += maxHeap.peek().value;

        return sum;
    }
}
