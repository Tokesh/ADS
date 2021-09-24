#include <iostream>
using namespace std;
struct Nodes{
    string data;
    Nodes *next;
    int cnt;
    Nodes(string d){
        this->cnt = 1;
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
    void push_back(string d){
        Nodes* temp = new Nodes(d);
        Nodes* last = first;
        size_cnt++;
        if(first == NULL){
            first=second=temp;
            return;
        }
        while(last->next != NULL && last->data != d){
            last = last->next;
        }
        if(last->data == d){
            last->cnt++;
            return;
        }
        last->next = temp;
        second = temp;
    }
    void push_front(string d){
        Nodes* temp = new Nodes(d);
        size_cnt++;
        if(first == NULL){
            first = second=temp;
        }else{
            temp->next = first;
            first = temp;
        }
    }
    void pop_back(){
        if(first == NULL) return;
        if(first == second){
            first=second=NULL;
            size_cnt=0;
        }else{
            size_cnt--;
            Nodes* temp = first;
            while(temp->next != second){
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    void print_m(){
        Nodes* temp = first;
        int maxi = -100000;
        string arr[1000];
        int ind_c=0;
        while(temp != NULL){
            if(temp->cnt > maxi) maxi = temp->cnt;
            temp = temp->next;
        }
        if(first == NULL) cout << "NO DATA!";
        else if(maxi == 1) cout << "UNIQUE!";
        else{
            temp = first;
            while(temp != NULL){
                if(temp->cnt == maxi){
                    arr[ind_c] = temp->data;
                    ind_c += 1;
                }
                temp = temp->next;
            }
            for(int i=0;i<ind_c;i++){
                cout << arr[i];
                if(i!=ind_c-1) cout << ",";
            }
        }

    }
};
int main(){
    /* freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout); */
    LinkedList zxc;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s1,s2,s3,s4;
        cin >> s1 >> s2 >> s3;
        if(s3 != "w" && s3 != "m"){
            cin >> s4;
            if(s4 == "w"){
                zxc.push_back(s2);
            }
        }else{
            if(s3 == "w"){
                zxc.push_back(s2);
            }
        }
    }
    zxc.print_m();
    return 0;
}