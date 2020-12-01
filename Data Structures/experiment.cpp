#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    vector<vector<int>> *vec;

    vector<vector<int>> x(9, vector<int>(9, INF));
    int m, n;
    m = n =5;
    vec = x;
    vec[3][2] = 235;
        for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++){ 
            cout<< vec->operator[](i)[j]<< " "; 
        } 
        cout<< "\n"; 
    }
}