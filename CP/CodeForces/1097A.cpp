#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    cin >> in;

    bool ans = false;
    for (int i=0; i<5; i++)
    {
        string s;
        cin >> s;

        if(in[0] == s[0] or in[1] == s[1]) ans = true;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}