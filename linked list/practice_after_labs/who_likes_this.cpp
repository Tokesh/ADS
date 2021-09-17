#include <iostream>
#include <vector>
#include <string> 
using namespace std;

string likes(const std::vector<std::string> &names)
{   
    int cnt=(names.size()-2);
    string j=to_string(cnt);

    if(names.size() == 0) return "no one likes this";
    else if(names.size()==1) return names[0]+" likes this";
    else if(names.size()==2) return names[0]+" and "+names[1] + " likes this";
    else if(names.size()==3) return names[0]+", "+names[1]+" and " +names[2] + " like this";
    else return names[0]+", "+names[1]+" and "+j+" others like this";
}

int main(){
    vector<string>zxc;
    zxc.push_back("Jacob");
    zxc.push_back("Alex");
    zxc.push_back("Max");
    zxc.push_back("Mark");
    cout << likes(zxc);
}