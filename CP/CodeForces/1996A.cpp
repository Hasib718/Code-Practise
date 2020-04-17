#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        int odd=0, e;
        e = n;
        while(n--){
            int a;
            cin >> a;
            if(a%2) odd++;
        }
        
        if (!odd or (odd==e and !(odd%2))) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}