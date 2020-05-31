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
#include <unordered_set>
#include <unordered_map>
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
#include <iomanip>

#define MAX 105
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
        int n;
        cin >> n;

        vector<ipair> v;
        v.push_back({0, 0});
        int a, b;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        string str;
        bool check = false;
        int tmp_x=0, tmp_y=0;

        for(int i=1; i<=n; i++)
        {
            if(v[i-1].second > v[i].second)
            {
                check = true;
                break;
            }
            if(v[i].first > tmp_x)
            {
                int s = v[i].first - tmp_x;
                tmp_x += s;
                for(int j=0; j<s; j++)
                    str.push_back('R');
            }
            if(v[i].second > tmp_y)
            {
                int s = v[i].second - tmp_y;
                tmp_y += s;
                for(int j=0; j<s; j++)
                    str.push_back('U');
            }
        }
        if(check) cout << "NO" << endl;
        else cout << "YES\n" << str << endl;
    }

    return 0;
}