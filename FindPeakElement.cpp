class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int size = num.size();
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int middle = (low + high)/2;
            if (((0 == middle) || (num[middle] > num[middle-1]))
                    && (((size-1) == middle) || (num[middle] > num[middle+1]))) {
                return middle;
            }

            if ((middle > 0) && (num[middle] < num[middle-1])) {
                high = middle - 1;
            }
            else if (num[middle] < num[middle+1]) {
                low = middle + 1;
            }
            else {
                // never reach
            }
        };  
        return -1; 
    }
};
