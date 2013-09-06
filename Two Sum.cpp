class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i) {
            m[numbers[i]]++;
        }
        vector<int> ret;
        int find = -1;
        for (int i = 0; i < numbers.size(); ++i) {
            int now = target - numbers[i];
            if (now != numbers[i] && m[now] > 0) {
                find = now;
                ret.push_back(i + 1);
                break;
            } else if (now == numbers[i] && m[now] > 1) {
                find = now;
                ret.push_back(i + 1);
                break;
            }
        }

        for (int i = 0; ret.size() == 1 && i < numbers.size(); ++i) {
            if (numbers[i] == find && i + 1 != ret[0]) {
                ret.push_back(i + 1);
                break;
            }
        }
        if (ret.size() == 2) {
            return ret;
        } else {
            ret.clear();
            return ret;
        }
    }
};