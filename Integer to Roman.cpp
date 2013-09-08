class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        map<int, string> hash;
        hash[1] = "I";
        hash[2] = "II";
        hash[3] = "III";
        hash[4] = "IV";
        hash[5] = "V";
        hash[6] = "VI";
        hash[7] = "VII";
        hash[8] = "VIII";
        hash[9] = "IX";
        hash[10] = "X";
        hash[20] = "XX";
        hash[30] = "XXX";
        hash[40] = "XL";
        hash[50] = "L";
        hash[60] = "LX";
        hash[70] = "LXX";
        hash[80] = "LXXX";
        hash[90] = "XC";
        hash[100] = "C";
        hash[200] = "CC";
        hash[300] = "CCC";
        hash[400] = "CD";
        hash[500] = "D";
        hash[600] = "DC";
        hash[700] = "DCC";
        hash[800] = "DCCC";
        hash[900] = "CM";
        hash[1000] = "M";
        hash[2000] = "MM";
        hash[3000] = "MMM";
        
        string ret = "";
        
        while (num) {
            for (map<int, string>::reverse_iterator it = hash.rbegin(); it != hash.rend(); ++it) {
                while (num >= it -> first) {
                    num -= it -> first;
                    ret += it -> second;
                }
            }
        }
        return ret;
    }
};