#include <bits/stdc++.h>

using namespace std;

string postfix[1000];
int q, cnt=0;

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
    //check whether the last checrecter of s[i]th string is a digit or not
    else if(isdigit(s[i][s[i].size()-1])) postfix[cnt++] = s[i];
    else if(s[i] == "(") st.push("(");
    else if(s[i] == ")")
    {
      while(st.top() != "N" && st.top() != "(")
      {
        string c = st.top();
        st.pop();
        postfix[cnt++] = c;
      }
      if(st.top() == "(") st.pop();
    }
    else
    {
      while(st.top() != "N" && precedence(s[i]) <= precedence(st.top()))
      {
        string c = st.top();
        st.pop();
        postfix[cnt++] = c;
      }
      st.push(s[i]);
    }
}
  while(st.top() != "N")
  {
    string c = st.top();
    st.pop();
    postfix[cnt++] = c;
  }
}

void evaluate_postfix(string p[])
{
  infix_to_postfix(p);
  postfix[cnt++] = "&";

  for(int i=0; i<=q; i++)
  cout << postfix[i] << " ";
  cout << endl;
  stack<int> st;
  int i;
  // cout << cnt << endl;
  for(i=0; i<=cnt; i++)
  {
    if(postfix[i] == "&")
    {
      cout << "Result = " << st.top() << endl;
      break;
    }
    else if(isdigit(postfix[i][postfix[i].size()-1]))
    {
      int num=0;
        int n;
        sscanf(postfix[i].c_str(), "%d", &n);
        num = num*10 + n;
      st.push(num);
    }
    else
    {
      int val1 = st.top();
      st.pop();
      int val2 = st.top();
      st.pop();

        if(postfix[i] ==  "+") st.push(val2 + val1);
        else if(postfix[i] ==  "-") st.push(val2 - val1);
        else if(postfix[i] ==  "*") st.push(val2 * val1);
        else if(postfix[i] ==  "/") st.push(val2 / val1);
        else if(postfix[i] == "^") st.push((int)(pow(val2, val1) + 0.5));
    }
  }
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

  infix_to_postfix(s);
  for (int i = 0; i < q; i++)
    cout << postfix[i] << " ";

    cout << endl;
  

  return 0;
}
// -60 + ( 3 * 8 - ( 16 / 2 ^ 3 ) * 6 ) * 5
// answer will be 0
