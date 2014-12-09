class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            int size = numbers.size();
            map<int, int> temp;
            for( int index = 0; index < numbers.size(); ++index) {
                map<int, int>::iterator iter = temp.find(target - numbers[index]);
                if (iter != temp.end()) {
                    result.push_back(temp[target - numbers[index]] + 1);
                    result.push_back(index + 1);
                }
                else {
                    temp[numbers[index]] = index;
                }
            }
            return result;
        }
};
