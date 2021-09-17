
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>zxc;
        for(int i=0;i<s.size();i++){
            zxc[s[i]] += 1;
        }
        for(int i=0;i<s.size();i++){
            if(zxc[s[i]] == 1) return i;
        }
        return -1;
    }
};