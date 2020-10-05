#include <bits/stdc++.h>

using namespace std;

int KMP(char *str, vector<char> &pat, int *lps, int k)
{
    int cnt = 0;

    int M = pat.size(), N = strlen(str);

    int i = 0, j = 0;
    while (i < N)
    {
        if (pat[j] == str[i])
            j++, i++;

        if (j == M)
            cnt++, j = 0;
        else if (i < N && pat[j] != str[i])
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
    }

    return cnt;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        getchar();

        vector<char> pat(k + 1, (char)48);
        char str[n + 5];
        int lps[k + 1];
        cin.get(str, n + 5);

        int len = strlen(str);
        if (len <= k)
        {
            int p=0;
            for (int i=0; i<len; i++)
                if (str[i] == (char)48)
                    p++;
            
            if (p == len)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else
        {
            for (int i = 0; i < k + 1; i++)
                lps[i] = i;

            int cnt = KMP(str, pat, lps, k);

            cout << cnt << endl;
        }
    }

    return 0;
}