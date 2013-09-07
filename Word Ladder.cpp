struct node {
  string val;
  int dis;
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        node st;
        st.val = start;
        st.dis = 1;
        queue<node> q;
        q.push(st);
        unordered_set<string> s;
        s.insert(start);
 
        while (!q.empty()) {
            node t = q.front();
            q.pop();
            if (t.val == end) {
                return t.dis;
            }
            
            for (int i = 0; i < t.val.size(); ++i) {
                char ch = t.val[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    t.val[i] = j;
                    if (s.find(t.val) == s.end() && dict.find(t.val) != dict.end()) {
                        s.insert(t.val);
                        node nn;
                        nn.val = t.val;
                        nn.dis = t.dis + 1;
                        q.push(nn);
                    }
                }
                t.val[i] = ch;
            }
        }
        return 0;
        
    }
};