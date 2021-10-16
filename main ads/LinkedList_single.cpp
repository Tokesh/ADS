#include <iostream>
using namespace std;
struct Nodes{
    int data;
    Nodes *next;
    int cnt;
    Nodes(int d){
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
    void push_back(int d){
        Nodes* temp = new Nodes(d);
        size_cnt++;
        if(first == NULL){
            first=second=temp;
            return;
        }else{
            second->next = temp;
            second = temp;
        }
        
    }
    void push_front(int d){
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
    void pop_front(){
        if(first == NULL) return;
        if(first == second){
            first = second= NULL;
            size_cnt = 0;
        }else{
            size_cnt--;
            first = first->next;
        }
    }
    void sort_sel(){
        Nodes* current = first;
        while(current != NULL){
            Nodes* end = current->next;
            while(end != NULL){
                if(current->data > end->data){
                    int temp = current->data;
                    current->data = end->data;
                    end->data = temp;
                }
                end = end->next;
            }
            current = current->next;
        }
    }
    void print_m(){
        Nodes* temp = first;
        while(temp != NULL){
            cout << temp->data;
            if(temp->next != NULL) cout << endl;
            temp = temp->next;
        }
    }

    Nodes* joinll(Nodes* h1 ,Nodes* h2){
        if(h1==NULL){
            return h2;
        }
    
        if(h2 == NULL){
            return h1;
        }
        Nodes* head;
        Nodes* tail;
        
        if(h1->data <= h2->data){
            head = h1;
            tail = h1;
            h1=h1->next;
        }else{
            head = h2;
            tail = h2;
            h2=h2->next;
        }
        while(h1!=NULL && h2!=NULL){
            if(h1->data <= h2->data){
                tail->next = h1;
                tail = h1;
                h1=h1->next;             
            }else{
                tail->next = h2;
                tail = h2;
                h2=h2->next;
            }
        }
        if(h1==NULL){
            tail->next = h2 ;
        }
        else{
            tail->next = h1 ; 
        }
        return head;
    }
    Nodes* mergeSort(Nodes *head) {
    
        if(head==NULL || head->next==NULL){
            return head ;
        }
        
        Nodes* slow = head ;
        Nodes* fast = head->next ;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next ;
            fast =fast->next->next ;
        }
        Nodes*h2 = slow->next ;
        slow->next =NULL ;
        
        head = mergeSort(head) ;
        h2 = mergeSort(h2) ; 
        
        return joinll(head , h2) ;
    }
};


int main(){
    /* freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout); */
    LinkedList qq;
    qq.push_back(5);
    qq.push_back(1);
    qq.push_back(3);
    qq.first = qq.mergeSort(qq.first);
    qq.print_m();
    return 0;
}