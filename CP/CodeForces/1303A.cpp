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
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;

        int mx=99999999, cnt=0, j;
        for (int i=0; i<str.length(); i++) {
            if(str[i] == '1') {
                j=i;
                j++;
                while(str[j] == '0') {
                    cnt++;
                    j++;
                    if(str[j] == '0' and j == str.length()-1) {
                        cnt=0;
                        break;
                    }
                }
                    if (cnt !=0 and cnt < mx) mx = cnt;
                    cnt=0;
            }
        }
        if(mx == 99999999) cout << "0" << endl;
        else cout << mx << endl;
    }
}