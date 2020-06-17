#include <bits/stdc++.h>

using namespace std;

char txt[1000005], pat[1000005];
int n;

void LPS(char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;

    int i=1;
    while(i < M)
    {
        if (pat[i] == pat[len])
            len++, lps[i] = len, i++;
        else
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i]=0, i++;
    }
}

void KMP(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    LPS(pat, M, lps);

    int i=0, j=0;
    while (i < N)
    {
        if (pat[j] == txt[i])
            j++, i++;

        if (j == M)
            n++, j = lps[j-1];
        else if (i < N && pat[j] != txt[i])
            if (j != 0)
                j = lps[j-1];
            else
                i++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    getchar();
    for(int i=1; i<=T; i++)
    {
        scanf("%[^\n]%*c", txt);
        scanf("%[^\n]%*c", pat);

        int r = strlen(txt), t = strlen(pat);
        
        KMP(pat, txt);

        printf("Case %d: %d\n", i, n);
        n=0;
        memset(txt, 0, r*(sizeof(txt[0])));
        memset(pat, 0, t*(sizeof(pat[0])));
    }

    return 0;
}