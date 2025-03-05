class Solution {

public: int longestStringChain(vector<string>& words)

{

// Sort words by length

sort(words.begin(), words.end(), [](const string &a, const string &b) {

return a.size() < b.size();

});

unordered_map<string, int> dp; // Stores longest chain ending at word

int maxLength = 1;

for (const string &word : words) {

dp[word] = 1; // Initialize chain length as 1

for (int i = 0; i < word.size(); i++) {

string prev = word.substr(0, i) + word.substr(i + 1); // Remove 1 char

if (dp.find(prev) != dp.end()) { dp[word] = max(dp[word], dp[prev] + 1);

}

}

maxLength = max(maxLength, dp[word]);

}

return maxLength;

}

};
