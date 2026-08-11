class Solution {
    int expand(string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

public:
    string longestPalindrome(string s) {
        int start = 0, max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            int len = max(expand(s, i, i),
                          expand(s, i, i + 1));

            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, max_len);
    }
};