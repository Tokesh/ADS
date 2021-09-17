struct Nodes{
    char data;
    Nodes* next;
    Nodes(char d){
        this->data = d;
        this->next = NULL;
    }
};

struct stackz{
    int cnt;
    Nodes* top;
    stackz(){
        cnt=0;
        top=NULL;
    }
    void push(char d){
        Nodes* temp = new Nodes(d);
        temp->next = top;
        top=temp;
        cnt++;
    }
    void pop(){
        top = top->next;
        cnt--;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stackz b1;
        stackz b2;
        string j1="",j2="";
        for(int i=0;i<s.size();i++){
            if(s[i] != '#'){
                b1.push(s[i]);
            }
            else if(b1.cnt != 0){
                b1.pop();
            }
        }
        while(b1.top != NULL){
            j1 += b1.top->data;
            b1.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i] != '#') b2.push(t[i]);
            else if(b2.cnt != 0) b2.pop();
        }
        while(b2.top != NULL){
            j2 += b2.top->data;
            b2.pop();
        }
        if(j1 == j2) return true;
        return false;
    }
};