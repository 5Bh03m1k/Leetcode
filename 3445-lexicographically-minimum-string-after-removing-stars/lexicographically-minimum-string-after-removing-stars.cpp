class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> charMap; // sorted by default
        vector<bool> deleted(s.size(), false);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                charMap[s[i]].push_back(i);
            } else {
                // Remove index of smallest character
                auto it = charMap.begin();
                int idx = it->second.back();
                deleted[idx] = true;
                it->second.pop_back();
                if (it->second.empty()) {
                    charMap.erase(it);
                }
            }
        }

        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*' && !deleted[i]) {
                result += s[i];
            }
        }

        return result;
    }
};
