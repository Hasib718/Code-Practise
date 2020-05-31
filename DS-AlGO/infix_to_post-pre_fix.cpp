#include <bits/stdc++.h>

using namespace std;

string ans[1000];
int q, cnt=0;

void revArray(string arr[], int start, int end)
{
    if (start >= end)
    return;

    string temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    revArray(arr, start + 1, end - 1);
}

int precedence(string c)
{
  if(c == "^") return 3;
  else if(c == "*" || c == "/") return 2;
  else if(c == "+" || c == "-") return 1;
  return -1;
}

void infix_to_postfix(string s[])
{
  stack<string> st;
  st.push("N");

for(int i=0; i<q; i++)
{
    if(s[i] == " ") continue;
    else if(isdigit(s[i][s[i].size()-1]))
    {
      ans[cnt++] = s[i];
    }
    else if(s[i] == "(") st.push("(");
    else if(s[i] == ")")
    {
      while(st.top() != "N" && st.top() != "(")
      {
        string c = st.top();
        st.pop();
        ans[cnt++] = c;
      }
      if(st.top() == "(") st.pop();
    }
    else
    {
      while(st.top() != "N" && precedence(s[i]) <= precedence(st.top()))
      {
        string c = st.top();
        st.pop();
        ans[cnt++] = c;
      }
      st.push(s[i]);
    }
}
  while(st.top() != "N")
  {
    string c = st.top();
    st.pop();
    ans[cnt++] = c;
  }
}

void infix_to_prefix(string s[])
{
  revArray(s, 0, q);

  stack<string> st;
  st.push("N");

for(int i=0; i<=q; i++)
{
    if(s[i] == " ") continue;
    else if(isdigit(s[i][s[i].size()-1]))
    {
      ans[cnt++] = s[i];
    }
    else if(s[i] == ")") st.push(")");
    else if(s[i] == "(")
    {
      while(st.top() != "N" && st.top() != ")")
      {
        string c = st.top();
        st.pop();
        ans[cnt++] = c;
      }
      if(st.top() == ")") st.pop();
    }
    else
    {
      while(st.top() != "N" && precedence(s[i]) <= precedence(st.top()))
      {
        string c = st.top();
        st.pop();
        ans[cnt++] = c;
      }
      st.push(s[i]);
    }
}
  while(st.top() != "N")
  {
    string c = st.top();
    st.pop();
    ans[cnt++] = c;
  }

  revArray(ans, 0, cnt);
}
int main()
{
  string r;
  string s[100];

  while(cin >> r)
  {
    if(r == " ") continue;
    s[q] = r;
    q++;
  }

  // infix_to_prefix(s);
  //
  // for(int i=0; i<=q; i++)
  // cout << ans[i] << " ";
                                        /**
                                          *in order to print a fix, looping is the only way.
                                          *post and pre fin can't be print simustenously as there is only one
                                          *array to store the answer
                                          */

  infix_to_postfix(s);
  for(int i=0; i<=q; i++)
  cout << ans[i] << " ";

  return 0;
}
// -60 + ( 3 * 8 - ( 16 / 2 ^ 3 ) * 6 ) * 5
