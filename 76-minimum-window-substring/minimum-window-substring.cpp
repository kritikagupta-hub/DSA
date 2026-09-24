class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        int l = 0;
        int c = 0;
        int min_length = INT_MAX;
        int start = 0;
        for (int r = 0; r < s.length(); r++) {
            char ch = s[r];
            if (mp[ch] > 0) {
                c++;
            }
            mp[ch]--;
            while (c == t.length()) {
                if (r - l + 1 < min_length) {
                    min_length = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                mp[leftChar]++;
                if (mp[leftChar] > 0) {
                    c--;
                }
                l++;
            }
        }
        if (min_length == INT_MAX) {
            return "";
        }
        return s.substr(start, min_length);
    }
};