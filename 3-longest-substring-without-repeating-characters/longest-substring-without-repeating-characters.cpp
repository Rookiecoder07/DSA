class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        for (int i = 0; i < 256; i++)
            pos[i] = -1;

        int max_len = 0;
        int l = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            l = max(l, pos[ch] + 1);
            pos[ch] = i;

            max_len = max(max_len, i - l + 1);
        }

        return max_len;
    }
};