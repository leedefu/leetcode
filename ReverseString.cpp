class Solution {
    public:
        string reverseString(string s) {
            int forwardIndex = 0;
            int backIndex = s.size() - 1;
            while (forwardIndex < backIndex) {
                std::swap(s[forwardIndex++], s[backIndex--]);
            }
            return s;
        }
};
