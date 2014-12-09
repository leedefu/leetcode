class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }

        if (s.length() <= nRows) {
            return s;
        }

        std::vector<std::string> vec;
        vec.resize(nRows);

        int nRow = 0;           // range: 0 ~ (nRows -1)
        int nextRowStep = 0;    /* 1: forward */ /*-1: backward*/

        for (int i = 0; i < s.length(); ++i) {
            vec[nRow] += s[i];
            // first row
            if (nRow == 0) { 
                nextRowStep = 1; // forward
            }
            // last row
            else if (nRow == (nRows - 1)) {
                nextRowStep = -1; // backward
            }
            else {
                // keeping nextRowStep value
            }
            nRow += nextRowStep;
        }

        std::string result;
        for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
            result.append(*iter);
        }
        return result;
    }
};
