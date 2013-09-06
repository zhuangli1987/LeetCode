class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[num[i]];
        }
        set<vector<int> > s;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            --it->second;
            for (map<int, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
                if (it2 -> second == 0) {
                    continue;
                }
                int sum = it -> first + it2 -> first;
                --it2->second;
                if (m.find(-sum) != m.end() && m[-sum]) {
                    vector<int> ss;
                    ss.push_back(it->first);
                    ss.push_back(it2->first);
                    ss.push_back(-sum);
                    sort(ss.begin(), ss.end());
                    s.insert(ss);
                }
                ++it2->second;
            }
            ++it->second;
        }
        vector<vector<int> > ret;
        for (set<vector<int> >::iterator it = s.begin();it != s.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};