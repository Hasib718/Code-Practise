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

    string p, h;
    while(T--)
    {
        cin >> p;
        cin >> h;

        bool ans = false;
        vector<int> cntp(26);
        for(int i = 0; i<p.size(); i++)
            cntp[p[i] - 'a']++;

        for(int i = 0; i<h.size(); i++)
        {
            vector<int> cnth(26);
            for(int j = i; j<h.size(); j++)
            {
                cnth[h[j] - 'a']++;

                if(cntp == cnth)
                {
                    ans = true;
                    break;
                }
            }
        }
        
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}