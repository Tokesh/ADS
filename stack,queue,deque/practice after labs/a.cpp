#include <iostream>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes(string d){
        this->data = d;
        this->next = NULL;
    }
};

struct que{
    int cnt;
    Nodes* first;
    Nodes* second;
    que(){
        cnt =0;
        first=NULL;
        second=NULL;
    }
    void push(string s){
        Nodes* temp = new Nodes(s);
        if(first == NULL){
            first=temp;
            second = temp;
            cnt++;
        }else{
            second->next = temp;
            second = temp;
            cnt++;
        }
    }
    void pop(){
        first = first->next;
        cnt--;
    }
};

int main(){
    que zxc;
    string s,j;
    getline(cin,s);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            j += s[i];
        }
        else{
            zxc.push(j);
            j="";
        }
        if(i == s.size()-1 && j!=""){
            zxc.push(j);
        }
    }
    int num=0;
    while(num != k){
        zxc.push(zxc.first->data);
        zxc.pop();
        num++;
    }
    while(zxc.first != NULL){
        cout << zxc.first->data << " ";
        zxc.pop();
    }
    return 0;
}