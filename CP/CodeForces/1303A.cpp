#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;

        int mx=0, cnt=0, j;
        for (int i=0; i<str.length(); i++)
            if(str[i] == '1') {
                j=i;
                j++;
                while(str[j] == '0') {
                    cnt++;
                    if(j == str.length()-1) cnt=0;
                    j++;
                    if(str[j] == '1') break;
                }
                    mx+=cnt;
                    cnt=0;
            }

        cout << mx << endl;
    }
}