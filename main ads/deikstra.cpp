#include <iostream>
#include <vector>
#define MAX_INT 1e7

using namespace std;
int n, m, x, y, l;
int g[100][100];
int u[100];
int c[100];
vector<int> d(100, MAX_INT);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--; y--;
        g[x][y] = l;
        g[y][x] = l;
    }

    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) 
            if (!u[j] && (v == -1 || d[v] > d[j]))
                v = j;
        // cout << v + 1 << endl;
        u[v] = true;
        // v -> j
        for (int j = 0; j < n; j++) {
            if (!u[j] && g[v][j] > 0) {
                if (d[j] > d[v] + g[v][j]) {
                    d[j] = d[v] + g[v][j];
                    c[j] = v;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) 
        cout << c[i] << " ";

    return 0;
}
