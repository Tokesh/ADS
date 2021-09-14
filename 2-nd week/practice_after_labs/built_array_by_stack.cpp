class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>zxc;
        int cnt =1;
        int j=0;
        while(j < target.size()){
            if(target[j] != cnt){
                zxc.push_back("Push");
                zxc.push_back("Pop");
            }else if(target[j] == cnt){
                zxc.push_back("Push");
                j++;
            }
            cnt++;
            
        }
        return zxc;
        
    }
};