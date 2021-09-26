#include <vector>
#include <map>
struct heapi{
    int sz;
    vector<int>a;
    heapi(){
        sz=0;
    }
    
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    
    void shiftUp(int i){
        while(i > 0 && a[parent(i)] > a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    
    void insert(int n){
        a.push_back(n);
        sz++;
        int i = sz-1;
        shiftUp(i);
    }
    
    int getMin(){
        return a[0];
    }
    
    void heapify(int i){
        if(left(i) > sz-1) return;
        int j = left(i);
        if(right(i) <= sz-1 && a[right(i)] < a[j]) j = right(i);
        
        if(a[i] > a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    
    void extract_min(){
        swap(a[0], a[sz-1]);
        sz--;
        a.pop_back();
        if(sz > 0) heapify(0);
    }
    
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        heapi qq;
        map<int,int>qwe;
        vector< pair<int,string> >zxc;
        vector<string> resultz;
        for(int i=0;i<score.size();i++){
            qq.insert(score[i]);
        }
        int cnt = score.size();
        for(int i=0;i<score.size();i++){
            int z = qq.getMin();
            qq.extract_min();
            //cout << z << ' ' << cnt << endl;
            if(cnt > 3) qwe[z] = cnt;
            else if(cnt == 3) zxc.push_back(make_pair(z,"Bronze Medal"));
            else if(cnt == 2) zxc.push_back(make_pair(z,"Silver Medal"));
            else if(cnt == 1) zxc.push_back(make_pair(z, "Gold Medal"));
            cnt--;
        }
        //cout << zxc[0].first << ' ' << zxc[1].first << ' ' << zxc[2].first << endl;
        for(int i=0;i<score.size();i++){
            if(qwe[score[i]]==0){
                if(zxc[0].first == score[i]) resultz.push_back(zxc[0].second);
                else if(zxc[1].first == score[i]) resultz.push_back(zxc[1].second);
                else if(zxc[2].first == score[i]) resultz.push_back(zxc[2].second);
            }else{
                resultz.push_back(to_string(qwe[score[i]]));
            }
        }
        return resultz;
    }
};