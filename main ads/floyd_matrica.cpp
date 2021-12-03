//Нахождение кратчайшего путей между всеми парами вершин
#include <iostream>

using namespace std;
int g[100][100];
int c[100][100];

int main() {
    int n, m, x, y, l;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            g[i][j] = 1000000;
        g[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for(int j=0;j < n ;j++){
            cin >> g[i][j];
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                    c[i][j] = k; // c[i][k] c[k][j]
                }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}
