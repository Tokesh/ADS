#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y, v;

int color[100]; // color[i] = 0, 1, 2
vector<int> g[100];
bool ok;

void dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (color[y] == 0) {
            dfs(y, 3 - c); // c = 1 => 2, c = 2 => 1
        } else {
            if (color[y] == c)
                ok = false;
        }
    }
}


int main() {
    int cnt = 0;
    cin >> n >> m;
    ok = true;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0) 
            dfs(i, 1);
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
