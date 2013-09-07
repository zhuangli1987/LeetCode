class Solution {
public:
    void dfs(vector<vector<string> > &ret, vector<string> &v, unordered_map<string, vector<string> > &m, string &now) {
        vector<string> p = m[now];
        if (p.size() == 0) {
            v.push_back(now);
            reverse(v.begin(), v.end());
            ret.push_back(v);
            reverse(v.begin(), v.end());
            v.pop_back();
            return;
        }
        
        v.push_back(now);
        for (int i = 0; i < p.size(); ++i) {
            dfs(ret, v, m, p[i]);
        }
        v.pop_back();
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, vector<string> > m;
        vector<vector<string> > ret;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            m[*it] = vector<string>();
        }
        vector< unordered_set<string> > q(2);
        int now = 1;
        q[0].insert(start);
        while (true) {
            int cur = now;
            int pre = now^1;

            for (unordered_set<string>::iterator it = q[pre].begin(); it != q[pre].end(); ++it) {
                dict.erase(*it);
            }
            q[cur].clear();

            for (unordered_set<string>::iterator it = q[pre].begin(); it != q[pre].end(); ++it) {
                string org = *it;
                string chd = *it;
                for (int j = 0; j < chd.size(); ++j) {
                    char ch = chd[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chd[j] = k;
                        if (dict.find(chd) == dict.end()) {
                            continue;
                        }
                        m[chd].push_back(org);
                        q[cur].insert(chd);
                    } 
                    chd[j] = ch;
                }
            }
            if (q[cur].size() == 0){
                return ret;
            }
            if (q[cur].find(end) != q[cur].end()) {
                break;
            } 
            now = now^1;
        }
        vector<string> v;
        dfs(ret, v, m, end);
        return ret;
    }
};