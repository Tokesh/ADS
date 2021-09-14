#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Nodes{
    string data;
    Nodes* next;
    Nodes(string d){
        this->data = d;
        this->next = NULL;
    }
};

struct linked{
    Nodes* first;
    Nodes* second;
    linked(){
        first = second = NULL;
    }
    void add(string x){
        Nodes* temp = new Nodes(x);
        if(first == NULL){
            first=second=temp;
        }else{
            second->next = temp;
            second = temp;
        }
    }
};

bool sortByVal(const pair<string, int> &a, const pair<string, int> &b) {
    if(a.second == b.second) return a.first < b.first; // this is the "secondary" comparison, used if the frequencies are equal
    return a.second > b.second; 
} 

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    map<string,int>zxc;
    linked ll;
    string s;
    while(cin >> s){
        string j="";
        for(int i =0;i<s.size();i++){
            if(s[i] >= 97 && s[i] <= 122) j+=s[i];
            else if(s[i] >=65 && s[i] <= 90) j+= (s[i]+32);
        }
        zxc[j] += 1;
    }/* 
    map<string,int>::iterator it;
    for(it = zxc.begin();it!=zxc.end();it++){
        cout << it->first << ' ' << it->second << endl;
    } */
    vector<pair<string, int> > vec;
    map<string, int> :: iterator it2;
    for (it2=zxc.begin(); it2!=zxc.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }
    sort(vec.begin(), vec.end(), sortByVal); 
    for (int i = 0; i < vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}

}