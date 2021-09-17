#include <deque>
#include <stack>
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0=0,cnt1=0;
        deque<int>zxc;
        for(int i=0;i<students.size();i++){
            zxc.push_back(students[i]);
            if(students[i] == 1) cnt1++;
            else cnt0++;
        }
        stack<int>sand;
        for(int i=students.size()-1;i>=0;i--){
            sand.push(sandwiches[i]);
        }
        while(zxc.size() != 0){
            if(sand.top() == 0 && cnt0 ==0) return zxc.size();
            else if(sand.top() == 1 && cnt1 ==0) return zxc.size();
            
            if(zxc.front()==sand.top()){
                if(zxc.front()==1) cnt1--;
                else cnt0--;
                sand.pop();
                zxc.pop_front();
            }else{
                zxc.push_back(zxc.front());
                zxc.pop_front();
            }
        }
        return 0;
        
    }
};