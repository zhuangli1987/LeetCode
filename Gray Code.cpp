class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        for (int i = 0; ; ++i) {
            int t = 0;
            for (int j = 0; j < 31; ++j) {
                int a = i & (1 << j);
                int b = i & (1 << (j + 1));
                if (a != 0 && b != 0) {
                    t |= 0;
                } else if (a == 0 && b== 0) {
                    t |= 0;
                } else {
                    t |= (1 << j);
                }
                
            }
            if ( i == (1 << n)) {
                break;
            }
            ret.push_back(t);
        }
        return ret;
        
    }
};