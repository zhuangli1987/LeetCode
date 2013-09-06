class Solution {
public:
    vector<int> getRow(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        ret.push_back(1);
        for (int i = 1; i <= numRows; ++i) {
            vector<int> tp;
            tp.push_back(1);
            for (int j = 1; j < i; ++j) {
                tp.push_back(ret[j - 1] + ret[j]);
            }
            tp.push_back(1);
            ret.clear();
            ret = tp;
        }
        return ret;
    }
};