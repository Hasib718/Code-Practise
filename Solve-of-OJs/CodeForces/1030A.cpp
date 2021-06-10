#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool x = false;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(a == 1) x = true;
    }

    if(x) cout << "HARD" << endl;
    else cout << "EASY" << endl;
}