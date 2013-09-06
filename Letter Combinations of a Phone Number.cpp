vector<string> res;
class Solution {
public:
    void dfs(string &d, map<string, string> &h, int pos, string now) {
        if (pos == d.size()) {
            res.push_back(now);
            return;
        }
            
        string ind = "";
        ind += d[pos];
        if (h.find(ind) != h.end()) {
            string x = "";
            x += d[pos];
            x = h[x];
            for (int i = 0; i < x.size(); ++i) {
                dfs(d, h, pos + 1, now + x[i]);
            }
        } else {
            dfs(d, h, pos + 1, now + d[pos]);
        }
    
    }
    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, string> hs;
        hs["0"] = " ";
        hs["2"] = "abc";
        hs["3"] = "def";
        hs["4"] = "ghi";
        hs["5"] = "jkl";
        hs["6"] = "mno";
        hs["7"] = "pqrs";
        hs["8"] = "tuv";
        hs["9"] = "wxyz";
        res.clear();
        dfs(digits, hs, 0, "");
        return res;
    }
};