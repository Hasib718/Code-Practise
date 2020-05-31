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
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int cnt=0, mx=0;
        while(n--) {
            if(str[n] == 'P') cnt++;
            else { mx = max(cnt, mx); cnt=0; }
        }
        cout << mx << endl;
    }
}