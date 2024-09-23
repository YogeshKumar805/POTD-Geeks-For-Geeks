class Solution
{
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    public static String smallestWindow(String s, String p)
    {
        // Edge case when p is larger than s
        if (p.length() > s.length()) {
            return "-1";
        }
        
        // Frequency map for string p
        Map<Character, Integer> pFreq = new HashMap<>();
        for (char ch : p.toCharArray()) {
            pFreq.put(ch, pFreq.getOrDefault(ch, 0) + 1);
        }

        // Frequency map for the current window in s
        Map<Character, Integer> windowFreq = new HashMap<>();
        
        int left = 0, minLen = Integer.MAX_VALUE, minStart = -1;
        int count = 0;  // to track the number of characters matched from p
        
        // Traverse the string s using the right pointer
        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            
            // Add the current character to the window frequency map
            windowFreq.put(ch, windowFreq.getOrDefault(ch, 0) + 1);
            
            // If the current character in window matches the frequency in p, increase the match count
            if (pFreq.containsKey(ch) && windowFreq.get(ch).intValue() <= pFreq.get(ch).intValue()) {
                count++;
            }
            
            // If all characters from p are matched in the current window
            while (count == p.length()) {
                // Check if this is the smallest window so far
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Try to contract the window from the left
                char leftChar = s.charAt(left);
                windowFreq.put(leftChar, windowFreq.get(leftChar) - 1);
                
                // If the character removed from the left causes the window to no longer be valid
                if (pFreq.containsKey(leftChar) && windowFreq.get(leftChar).intValue() < pFreq.get(leftChar).intValue()) {
                    count--;
                }
                
                // Move the left pointer forward
                left++;
            }
        }
        
        // If no valid window was found
        if (minStart == -1) {
            return "-1";
        }
        
        // Return the smallest window
        return s.substring(minStart, minStart + minLen);
    }
}

