class Solution {
public:
    int atoi(const char *str) {
        if ((NULL == str) || (strlen(str) == 0)) {
            return 0;
        }

        const char* p = str;
        while (' ' == *p) {
            ++p;
        }

        int negative = 1;
        if ('-' == *p) {
            negative = -1;
            ++p;
        }
        else if ('+' == *p){
            negative = 1;
            ++p;
        }
        else if ((*p < '0') || (*p > '9')) {
            return 0;
        }
        else {
        }

        int result = 0;
        while (*p != '\0') {
            if ((*p) < '0' || (*p) > '9') {
                break;
            }
            if ((*p) != ' ') {
                int bit = (*p) - '0';
                if (1 == negative) {
                    int maxInt = std::numeric_limits<int>::max();
                    if (result > (maxInt-bit)/10) {
                        return maxInt;
                    }
                }
                else {
                    int minInt = std::numeric_limits<int>::min();
                    if (-result < (minInt+bit)/10) {
                        return minInt;
                    }
                }
                result = result*10 + bit;
            }
            ++p;
        }
        return result * negative;
    }
};
