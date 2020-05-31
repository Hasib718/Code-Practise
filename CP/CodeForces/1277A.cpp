#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#define high 105
#define pb push_back
#define mp make_pair
typedef std::pair<int, int> ipair;

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, cnt=0, tmp;
        cin >> n;

        tmp = 0;
        for(int i=1; i<=9; i++)
        {
            tmp = (tmp*10) + 1;
            for(int j=1; j<=9; j++)
                if(tmp*j <= n)
                    cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}