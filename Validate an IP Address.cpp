class Solution {
  public:
    int isValid(string ip) {
        // code here
        stringstream ss(ip);
        string segment;
        vector<int> segments;
        
        while (std::getline(ss, segment, '.')) {
            if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) {
                // Check for empty segments and leading zeros
                return false;
            }
            try {
                int num = std::stoi(segment);
                if (num < 0 || num > 255) {
                    return false;
                }
                segments.push_back(num);
            } catch (...) {
                return false;  // Catch any conversion error
            }
        }
    
        // Check if there are exactly 4 segments
        if (segments.size() != 4) {
            return false;
        }
    
        return true;
    }
};
