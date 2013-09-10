class Solution {
public:
    string doit(vector<string> &v, int L) {
        string ret = "";
        int ct = 0;
        for (int i = 0; i < v.size(); ++i) {
            ct += (v[i]).size();
        }
        if (v.size() == 1) {
            ret += v[0];
            while (ret.size() != L) {
                ret += " ";
            }
            return ret;
        }
        int sp = L - ct;
        int i = 0;
        while(sp) {
            int ind = i % v.size();
            ++i;
            if (ind == v.size() - 1) {
                continue;
            }
            v[ind] += ' ';
            --sp;
        }
        for (int i = 0; i < v.size(); ++i) {
            ret += v[i];
        }
        return ret;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;

        vector<string> e;
        vector< vector<string> > v;
        int ct = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (ct + e.size() + words[i].size() > L) {
                v.push_back(e);
                e.clear();
                e.push_back(words[i]);
                ct = words[i].size();
            } else {
                e.push_back(words[i]);
                ct += words[i].size();
            }
        }
        if (e.size()) {
            v.push_back(e);
        }
        for (int i = 0; i < v.size(); ++i) {
            if (i == v.size() - 1) {
                string tp = "";
                for (int j = 0; j < v[i].size(); ++j) {
                    if (j != 0) {
                        tp += " ";
                    }
                    tp += v[i][j];
                }
                v[i].clear();
                v[i].push_back(tp);
            }
            ret.push_back(doit(v[i], L));
        }
        return ret;
    }
};