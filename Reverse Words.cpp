class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
         vector<string> words;
         string word;
    
    // Split the string into words based on the '.' delimiter
    for (char c : str) {
        if (c == '.') {
            words.push_back(word);
            word = "";  
        } else {
            word += c;
        }
    }
    
    // Push the last word (as it is not followed by '.')
    words.push_back(word);
    
    // Reverse the words
    reverse(words.begin(), words.end());
    
    // Join the words using '.'
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += '.';
        }
    }
    
    return result;
    }
};
