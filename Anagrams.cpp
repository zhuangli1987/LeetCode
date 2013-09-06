class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string val = strs[i];
            string now = strs[i];
            sort(val.begin(), val.end());
            m[val].push_back(now);
        } 
        for (map<string, vector<string> >::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); ++i) {
                    ret.push_back(it->second[i]);
                }
            }
        }
        return ret;
    }
};