/**
 * Unsolved
 */
#include <bits/stdc++.h>
 
using namespace std;
 
char txt[1000005], pat[1000005];
int mx=0;
 
void LPS(char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;
 
    int i=1;   
    while (i < M)
    {
        if (pat[i] == pat[len])
            len++, lps[i] = len, i++;
        else
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i] = 0, i++;
    }
}
 
void KMP(char *pat, char* txt)
{
    int M = strlen(pat), N = strlen(txt);
   
    int lps[M];
   
    LPS(pat, M, lps);
   
    int i=0, j=0;
    while (i < N)
    {
        if (txt[i] == pat[j])
            i++, j++;
       
        if (j > mx)
            mx = j;
        else if (i < N && pat[j] != txt[i])
            if (j != 0)
                j = lps[j -1];
            else
                i++;
    }
}
 
int main()
{
    int T; 
    scanf("%d", &T);
   
    getchar();
    for (int i=1; i<=T; i++)
    {
        scanf("%[^\n]%*c", txt);
        int lenTxt = strlen(txt);

        reverse_copy(txt, txt+lenTxt, pat);
       
        KMP(pat, txt);
       
        printf("Case %d: %d\n", i, lenTxt+(lenTxt-mx));
       
        mx = 0;
        memset(pat, 0, lenTxt*(sizeof(pat[0])));
        memset(txt, 0, lenTxt*(sizeof(txt[0])));
    }
   
    return 0;
}

/**
 * xxxyxyyxyxxxxxxxyyxxxxxxxyxxxxxxyxxxyxxxxxxxyxxxxx
 **/