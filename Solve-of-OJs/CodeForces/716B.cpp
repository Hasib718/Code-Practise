#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if(s.length() <26)  { cout << "-1" << endl; return 0; }
    else
    {
        vector<int> v(26, 0), emp, chr;
        int cnt=0;
        for(int i=25; i<s.length(); i++)
        {
            v.clear(), v.assign(26, 0), emp.clear(), cnt=0;
            for(int j=i; j>= i-25; j--)
                if(s[j]!= '?' and v[s[j] - 'A'] == 0)
                    v[s[j] - 'A']++, cnt++;
                else if(s[j] == '?') cnt++, emp.push_back(j);
                else 
                {
                    v.clear(), v.assign(26, 0), emp.clear(), cnt=0;
                    break;
                }

            if(cnt==26)
            {
                for(int j=0; j<v.size(); j++)
                    if(v[j] == 0) chr.push_back(j);

                for(int p=0; p<emp.size(); p++)
                    s[emp[p]] = (char)(chr[p] + 'A');

                for(int k=0; k<s.length(); k++)
                    if(s[k] == '?') s[k] = 'A';

                cout << s << endl;

                return 0;
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}