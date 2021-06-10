#include <bits/stdc++.h>

using namespace std;


int main()
{

  int n, i=1, j=1;

  scanf("%d", &n);
  while(i <= n)
  {
    int m, q;
    deque<int> deq;
    cin >> m >> q;

    printf("Case %d:\n", i);
    while(j <= q)
    {
      string s;
      int p;
      string pl = "pushLeft", pr = "pushRight", pol = "popLeft", por = "popRight";
      cin >> s;

      if(s == pl || s == pr)
      {
        cin >> p;
        if((s == pl) && (deq.size() < m))
        {
          cout << "Pushed in left: " << p << endl;
          deq.push_front(p);
        }
        else if((s == pr) && (deq.size() < m))
        {

          cout << "Pushed in right: " << p << endl;
          deq.push_back(p);
        }
        else cout << "The queue is full" << endl;
      }
      else
      {
        if(deq.empty()) cout << "The queue is empty" << endl;
        else if(s == pol)
        {
          cout << "Popped from left: " << deq.front() << endl;
          deq.pop_front();
        }
        else if(s == por)
        {
          cout << "Popped from right: " << deq.back() << endl;
          deq.pop_back();
        }
      }
    j++;
    }
    j=1;
    i++;
  }

  return 0;
}
