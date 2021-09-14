
#include<string>
struct Nodes{
    int data;
    Nodes* next;
    Nodes* prev;
    Nodes(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};

struct deq{
    int cnt;
    int sum;
    Nodes* first;
    Nodes* second;
    deq(){
        first=second=NULL;
        cnt = 0;
        sum = 0;
    }
    void push_back(int d){
        sum += d;
        Nodes* temp = new Nodes(d);
        cnt++;
        if(first == NULL){
            first = second = temp;
        }else{
            temp->prev = second;
            second->next = temp;
            second = temp;
        }
    }
    void pop_back(){
        if(cnt == 1){
            first=second=NULL;
            cnt = 0;
            sum = 0;
        }else{
            sum -= second->data;
            second = second->prev;
            if(second == NULL){
                first=second=NULL;
                cnt=0;
                sum = 0;
            }else{
                second->next = NULL;
                cnt--;
            }
        }
    }
};
class Solution {
public:
    int calPoints(vector<string>& ops) {
        deq linked;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int temp = (linked.second->data) + (linked.second->prev->data);
                linked.push_back(temp);
            }else if(ops[i]=="D"){
                int temp = (linked.second->data) * 2;
                linked.push_back(temp);
            }else if(ops[i] == "C"){
                linked.pop_back();
            }else{
                linked.push_back(stoi(ops[i]));
            }
        }
        return linked.sum;
    }
};