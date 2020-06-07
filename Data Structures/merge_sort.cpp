#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int left, int mid, int right)
{
  int index_a, index_left, index_right, size_left, size_right;

  size_left = mid - left + 1;
  size_right = right - mid;

  vector<int> left_array, right_array;

  for(int i=0; i<size_left; i++)
    left_array.push_back(a[left + i]);
  for(int i=0; i<size_right; i++)
    right_array.push_back(a[mid + i+1]);

  index_left = 0;
  index_right = 0;

  for(index_a = left; (index_left < size_left) && (index_right < size_right); index_a++)
    if(left_array[index_left] < right_array[index_right])
    {
      a[index_a] = left_array[index_left];
      index_left++;
    }
    else
    {
      a[index_a] = right_array[index_right];
      index_right++;
    }

  while(index_left < size_left)
  {
    a[index_a] = left_array[index_left];
    index_left++;
    index_a++;
  }
  while(index_right < size_right)
  {
    a[index_a] = right_array[index_right];
    index_right++;
    index_a++;
  }
  left_array.clear();
  right_array.clear();
}

void merge_sort(vector<int> &a, int left, int right)
{
  if(left >= right) return;

  int mid = left + ((right - left)/2);

  merge_sort(a, left, mid);
  merge_sort(a, mid+1, right);

  merge(a, left, mid, right);
}

int main()
{
  int n;
  cin >> n;

  vector<int> v;
  for(int i=0; i<=n; i++)
  {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }

  merge_sort(v, 0, n);

  for(int i=0; i<=n; i++)
    cout << v[i] << " ";

    return 0;
}

/*
8
9 5 6 3 5 8 7 2 1
*/
