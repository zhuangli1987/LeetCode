class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> p;
        string t = "";
        for (int i = 0; i <= path.size(); ++i) {
            if (i < path.size() && path[i] == '/' && path[i + 1] == '/') {
                continue;
            }
            if (path[i] == '/' || i == path.size()) {
                if (t == "..") {
                    if (p.size()) {
                        p.pop_back();
                    }
                } else if (t != ".") {
                    p.push_back(t);
                }
                t = "";
            } else {
                t = t + path[i];
            }
        } 
        t = "";
        for (int i = 0; i < p.size(); ++i) {
            t += p[i];
            t += "/";
        }
        for (int j = 1; j < t.size(); ++j) {
            if (t[j] == '/' && t[j - 1] == '/') {
                t[j - 1] = '\0';
            }
        }

        for (int j = t.size() - 1; j >= 0; --j) {
            if (t[j] != '/') {
                break;
            } else {
                t[j] = '\0';
            }
        }
        string ret;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '\0') {
                ret += t[i];
            }
        }
        if (ret == "") {
            return  "/";
        }
        if (ret[0] != '/') {
            ret = "/" + ret;
        }
        return ret;
    }
};