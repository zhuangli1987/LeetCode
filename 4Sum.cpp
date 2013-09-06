class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        struct node {
            int i, j;
        };
        map<int, vector<node> > m;
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                node n;
                n.i = i;
                n.j = j;
                m[num[i] + num[j]].push_back(n);
            }
        }
        set< vector<int> > s;
        for (map< int, vector<node> >::iterator it = m.begin(); it != m.end(); ++it) {
            int val = target - (it -> first);
            if (m.find(val) != m.end()) {
                for (int i = 0; i < it->second.size(); ++i) {
                    for (int j = 0; j < m[val].size(); ++j) {
                        vector<int> t;
                        t.push_back((it->second)[i].i);
                        t.push_back((it->second)[i].j);
                        t.push_back(m[val][j].i);
                        t.push_back(m[val][j].j);
                        sort(t.begin(), t.end());
                        int flag = 0;
                        for (int k = 1; k < t.size(); ++k) {
                            if (t[k] == t[k - 1]) {
                                flag = 1;
                                break;
                            }
                        }
                        for (int k = 0; k < t.size(); ++k) {
                            t[k] = num[t[k]];
                        }
                        if (flag == 0) {
                            s.insert(t);
                        }
                    }
                }
            }
        }
        vector< vector<int> > ret;
        for (set< vector<int> >::iterator it = s.begin(); it != s.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};