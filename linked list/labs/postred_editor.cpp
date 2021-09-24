#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct Nodes{
    int data;
    Nodes *next;
    int cnt;
    string arr[500];
    Nodes(int d){
        this->cnt = 0;
        this->data = d;
        this->next = NULL;
    }
};

struct LinkedList{
    int size_cnt;
    Nodes* first;
    Nodes* second;
    LinkedList(){
        size_cnt = 0;
        first=second=NULL;
    }
    bool push_back(int d, string zxc){
        Nodes* temp = new Nodes(d);
        
        if(first == NULL){
            size_cnt++;
            first=second=temp;
            temp->arr->append(zxc);
            temp->cnt++;
            return false;
        }else{
            temp = first;
            while(temp != NULL && temp->data != d){
                temp = temp->next;
            }
            if(temp == NULL){
                size_cnt++;
                Nodes* look = new Nodes(d);
                second->next = look;
                second = look;
                look->arr->append(zxc);
                look->cnt++;
                return false;
            }else{
                temp->arr[temp->cnt] = zxc;
                temp->cnt++;
                return true;
            }
        }
        
    }
    bool change_l(int n, string zxc){
        
        Nodes* temp = first;
        while(temp != NULL && temp->data != n){
            temp = temp->next;
        }
        if(temp->cnt == 0){
            return false;
        }else{
            temp->arr[temp->cnt - 1] = zxc;
            return true;
        }
    }
    bool del_me(int n){
        Nodes* temp = first;
        while(temp != NULL && temp->data != n){
            temp = temp->next;
        }
        if(temp->cnt == 0){
            return false;
        }else{
            temp->arr[0] = "";
            temp->cnt = 0;
            return true;
        }
    }
    void print_m(){
        Nodes* temp = first;
        bool empty_or = false;
        bool ok =false;
        while(temp != NULL){
            for(int i=temp->cnt-1;i>=0;i--){
                if(ok == false && temp->arr[i] != ""){
                    cout << temp->arr[i];
                    ok = true;
                    empty_or = true;
                }else{
                    if(temp->arr[i] != ""){
                        cout << endl << temp->arr[i];
                    }
                }
            }

            temp = temp->next;
        }
        if(empty_or == false) cout << "EMPTY";
    }
};


int main(){
    bool ok = false;
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    LinkedList qq;
    string s;
    while(cin >> s && ok == false){
        if(s[0] == '+'){
            int temp = 0;
            string j;
            for(int i=1;i<s.size();i++){
                j += s[i];
            }
            temp = stoi(j);
            if(temp > qq.size_cnt+1){
                ok = true;
                cout << "ERROR";
                return 0;
            }
            j = "";
            string k;
            while(cin >> k){
                j += k;
                if(k[k.size()-1] == '.'){
                    break;
                }
                j += ' ';
            }
            qq.push_back(temp,j);
        }

        if(s[0] == '*'){
            int temp = 0;
            string j;
            for(int i=1;i<s.size();i++){
                j += s[i];
            }
            temp = stoi(j);
            if(temp > qq.size_cnt+1){
                ok = true;
                cout << "ERROR";
                return 0;
            }
            j = "";
            string k;
            while(cin >> k){
                j += k;
                if(k[k.size()-1] == '.'){
                    break;
                }
                j += ' ';
            }
            if(qq.change_l(temp, j) == false){
                cout << "ERROR";
                return 0;
            }
        }
        if(s[0] == '-'){
            int temp = 0;
            string j;
            for(int i=1;i<s.size();i++){
                j += s[i];
            }
            temp = stoi(j);
            if(temp > qq.size_cnt+1){
                ok = true;
                cout << "ERROR";
                return 0;
            }
            j = "";
            if(qq.del_me(temp)==false){
                ok = true;
                cout << "ERROR";
                return 0;
            }
        }
    }
    qq.print_m();
    return 0;
}