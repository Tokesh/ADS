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


class MyStack {
public:
    /** Initialize your data structure here. */
    int cnt;
    Nodes* first;
    Nodes* second;
    MyStack() {
        first=second= NULL;
        cnt = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Nodes* temp = new Nodes(x);
        cnt++;
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            temp->prev = second;
            second = temp;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int j = second->data;
        if(cnt == 1){
            first=second=NULL;
            cnt = 0;
        }else{
            second = second->prev;
            if (second == NULL){
                first = NULL;
                cnt = 0;
            }
            else{
                second->next = NULL;
                cnt--;
            }
        }
        return j;
    }
    
    /** Get the top element. */
    int top() {
        return second->data;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return cnt==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */