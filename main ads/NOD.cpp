#include <iostream>
using namespace std;
int Nod(int a, int b)
{
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}
int main()
{
    int a,b;
    cin >> a >> b;

    while (a != 0 && b != 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    cout << a +b;
}