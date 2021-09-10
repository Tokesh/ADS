#include <iostream>
#include <deque>
using namespace std;

struct Nodes{
    int data;
    Nodes *next;
    Nodes(int data){
        this->data=data;
        this->next=NULL;
    }
};

struct Stack{
    int cnt;
    Nodes *top;
    Stack(){
        cnt = 0;
        top = NULL;
    }
    void push(int data){
        Nodes *temp = new Nodes(data);
        temp->next = top;
        top = temp;
        cnt++;
    }
    void pop(){
        top = top->next;
        cnt--;
    }
    bool empty(){
        return(top ==NULL);
    }
    int size(){
        return cnt;
    }
    int top_d(){
        return top->data;
    }
    void clear(){
        while(top!=NULL){
            top = top->next;
            cnt--;
        }
        cnt = 0;
    }
};



int main(){
    deque<int> main_min_el, second_min_el;
    Stack max_ans, left_ind, right_ind;
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int l=0,r=0,sumi = arr[0],total = arr[0] * arr[0];
    main_min_el.push_front(arr[0]);
    for(int i=1;i<n;i++){
        bool left_stop = false, right_stop = false;
        // Всегда проверяем, чтобы из второй очереди тоже был готов правильный элемент
        if(second_min_el.size() > 0 && second_min_el.front() > second_min_el.back()){
            int temp_x = second_min_el.front();
            int temp_y = second_min_el.back();
            second_min_el.pop_front();
            second_min_el.push_front(temp_y);
            second_min_el.pop_back();
            second_min_el.push_back(temp_x);
        }
        // У нас постоянно будет минимальный элемент
        if(main_min_el.size() == 0 && second_min_el.size() >= 1){
            main_min_el.push_front(second_min_el.front());
        }
        
        // Right add
        int temp_min = min(main_min_el.front(), arr[i]);
        int temp = sumi + arr[i];
        int var=temp*temp_min;
        if(var > total){
            right_stop = true;
            r += 1;
            sumi += arr[i];
            total = var;
            if(main_min_el.front() >= arr[i]) main_min_el.push_front(arr[i]);
            else if(second_min_el.size() != 0 && second_min_el.front() >= arr[i]) second_min_el.push_front(arr[i]);
            else if(second_min_el.size() == 0) second_min_el.push_front(arr[i]);
            
        }
        
        // Left delete
        //Check min_element
        if(arr[l] == main_min_el.front()){
            int mini_num=0;
            int first_num = sumi - arr[l];
            if(main_min_el.size() == 1 && second_min_el.size() != 0 && second_min_el.front() > main_min_el.front()){
                mini_num = second_min_el.front();
                second_min_el.pop_front();
            }else if(second_min_el.size() != 0 || main_min_el.size() > 1){
                mini_num = main_min_el.front();
            }
            int var=first_num*mini_num;
            if(var > total){
                left_stop = true;
                sumi -= arr[l];
                total = var;
                l += 1;
                main_min_el.pop_front();
            }
        }

        if((left_stop == false && right_stop == false) || i == n-1){
            if(max_ans.cnt == 0){
                max_ans.push(total);
                left_ind.push(l);
                right_ind.push(r);
            }
            else if(max_ans.cnt > 0  && max_ans.top->data < total){
                max_ans.push(total);
                left_ind.push(l);
                right_ind.push(r);
            }
            // Мы записали результат если он был первым или рекордным, дальше начинаем с одного элемента по массиву, в надежде на лучшую
            // комбинацию.
            l = i;
            r = i;
            sumi = arr[i];
            total = arr[i] * arr[i];
            main_min_el.clear();
            main_min_el.push_front(arr[i]);
            second_min_el.clear();
        }

        
    }
    cout << max_ans.top->data << endl;
    for(int i=left_ind.top->data;i<right_ind.top->data + 1;i++){
        cout << arr[i] << ' ';
    }
    return 0;


}