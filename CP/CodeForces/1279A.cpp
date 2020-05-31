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
    int t;
    cin >> t;

    int r, g, b;
    while(t--)
    {
        cin >> r >> g >> b;
        if((r>g+b+1) or (g>r+b+1) or (b>r+g+1)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}