#include <bits/stdc++.h>

#define ipair pair<int, int>
#define pb push_back

using namespace std;

int main()
{
    int T, i=1;
    cin >> T;


    // for(int i=0; i<9; i++)
    //     for(int j=0; j<6; j++)
    //         cout << str[i][j];

    while(i <= T)
    {
        int m, n, a, b;
        cin >> m >> n;

        char str[n+1][m+1], tmp;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin >> tmp;
                if(tmp == '@')
                {
                    a = i;
                    b = j;
                }
                else if(tmp == '#')
                {
                    visited[i][j] = true;
                }
                str[i][j] = tmp;
            }

            queue<ipair> q;
            q.push({a, b});
            //cout << a << " " << b << endl;

            visited[a][b] = true;
            int cnt=1, tmp_a, tmp_b;

            while(!q.empty())
            {
                ipair tp = q.front();
                q.pop();

                if(tp.first - 1 >= 0 && !visited[tp.first - 1][tp.second])
                {
                    q.push({tp.first-1, tp.second});
                    visited[tp.first-1][tp.second] = true;
                    cnt++;
                }
                if(tp.first + 1 < n && !visited[tp.first + 1][tp.second])
                {
                    q.push({tp.first+1, tp.second});
                    visited[tp.first+1][tp.second] = true;
                    cnt++;
                }
                if(tp.second - 1 >= 0 && !visited[tp.first][tp.second-1])
                {
                    q.push({tp.first, tp.second-1});
                    visited[tp.first][tp.second-1] = true;
                    cnt++;
                }
                if(tp.second + 1 < m && !visited[tp.first][tp.second+1])
                {
                    q.push({tp.first, tp.second+1});
                    visited[tp.first][tp.second+1] = true;
                    cnt++;
                }

            }

            printf("Case %d: %d\n", i, cnt);

         i++;
         cnt=1;

     }

     return 0;
}