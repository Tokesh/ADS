#include <vector>
struct heapi{
    vector<int>a;
    int sz;
    heapi(){
        sz=0;
    }

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    void insert(int k){
        a.push_back(k);
        sz++;
        int i = a.size()-1;
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        if(left(i) > sz-1) return;
        int j = left(i);
        if(right(i) < sz && a[right(i)] > a[j]) j = right(i);
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
        return;
    }
    void extract_max(){
        swap(a[0], a[a.size()-1]);
        sz--;
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
    }
    int get_max(){
        return a[0];
    }

    void DecrKey(int i, int num){
        a[i] = a[i] - num;
        heapify(i);
    }
    void extract_max_full(int k){
        int temp1 = a.size();
        for(int i=0;i<temp1 && k > 0;i++){
            k--;
            extract_max();
        }
    }
    void print_m(){
        for(int i=0;i<sz;i++){
            cout << a[i] << ' ';
        }
    }

};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        heapi qq;
        for(int i=0;i<nums.size();i++){
            qq.insert(nums[i]);
        }
        int temp1= qq.get_max();
        qq.extract_max();
        int temp2= qq.get_max();
        return (temp1-1)*(temp2-1);
    }
};