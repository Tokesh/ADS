struct Nodes{
    int data;
    Nodes* next;
    Nodes* prev;
    Nodes(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct linked{
    int cnt;
    Nodes* first;
    Nodes* second;
    linked(){
        cnt=0;
        first=second=NULL;
    }
    void add(int x){
        cnt++;
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            temp->prev = second;
            second = temp;
        }
    }
};

class RecentCounter {
public:
    linked zxc;
    int cnt;
    RecentCounter() {
        cnt =0;
    }
    
    int ping(int t) {
        cnt = 0;
        zxc.add(t);
        int l=t-3000;
        int r=t;
        Nodes* temp = zxc.first;
        while(temp != NULL){
            if(temp->data >= l && temp->data <= r) cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */