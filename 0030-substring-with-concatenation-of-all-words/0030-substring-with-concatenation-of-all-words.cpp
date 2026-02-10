class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        // Try all offsets
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};
