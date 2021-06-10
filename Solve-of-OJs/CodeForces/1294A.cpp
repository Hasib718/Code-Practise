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

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        vector<int> v;
        for(int i=0; i<3; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        int n;
        cin >> n;

        sort(v.begin(), v.end());

        if(v[2] - v[0]+v[2] - v[1] > n)
        {
            cout << "NO" << endl; 
            continue;
        }
        if((v[0]+v[2]+v[1]+n)%3 != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}