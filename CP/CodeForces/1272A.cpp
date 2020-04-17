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

    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int min=INT32_MAX, tmp;
        for(int i=-1; i<2; i++)
            for(int j=-1; j<2; j++)
                for(int k=-1; k<2; k++)
                {
                    tmp = abs((a-i) - (b-j)) + abs((b-j) - (c-k)) + abs((a-i) - (c-k));
                    if(tmp < min) min = tmp;
                }

        cout << min << endl;
    }

    return 0;
}