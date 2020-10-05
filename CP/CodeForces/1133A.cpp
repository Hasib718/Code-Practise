#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    char e, f;

    scanf("%d %c %d", &a, &e, &b);
    scanf("%d %c %d", &c, &f, &d);

    int t = (((c*60)+d) - ((a*60)+b))/2;

    if (b+(t - (((int)t/60)*60)) >= 60)
        cout << setfill('0') << setw(2) << a+1+(int)t/60 << ":" << setfill('0') << setw(2) << (b+(t - (((int)t/60)*60)))-60 << endl;
    else
        cout << setfill('0') << setw(2) << a+(int)t/60 << ":" << setfill('0') << setw(2) << b+(t - (((int)t/60)*60)) << endl;

    return 0;
}