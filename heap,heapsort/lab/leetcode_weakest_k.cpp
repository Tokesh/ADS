#include <vector>
#include <algorithm>

using namespace std;

struct MinHeap {
    vector< pair<int,int> > a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    pair<int,int> getMin() {
        return {a[0].first, a[0].second};
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)].first > a[i].first) {
            swap(a[parent(i)].first, a[i].first);
            swap(a[parent(i)].second, a[i].second);
            i = parent(i);
        }
    }

    void insert(int cnt,int i) {
        a.push_back(make_pair(cnt,i));
        int k = a.size() - 1;
        siftUp(k);
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);

        
        if (right(i) < a.size() && a[left(i)].first > a[right(i)].first)
            j = right(i);
        if (a[i].first > a[j].first) {
            swap(a[i].first, a[j].first);
            swap(a[i].second, a[j].second);
            heapify(j);
        }
    }

    void extractMin() {
        swap(a[0].first, a[a.size() - 1].first);
        swap(a[0].second, a[a.size() - 1].second);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
    }
    void print_m(){
        for(int i=0;i<a.size();i++){
            cout << a[i].first << ' ' << a[i].second << endl;
        }
    }

};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector< pair<int,int> >zxc;
        vector<int>res;
        MinHeap qq;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1) cnt++;
            }
            qq.insert(cnt,i);
        }
        for(int i=0;i<mat.size();i++){
            zxc.push_back(qq.getMin());
            qq.extractMin();
        }
        sort(zxc.begin(), zxc.end());
        for(int i=0;i<k;i++){
            res.push_back(zxc[i].second);
        }
        return res;
    }
};