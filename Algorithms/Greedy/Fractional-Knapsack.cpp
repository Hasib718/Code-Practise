#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    return ((double)a.value/a.weight) > ((double)b.value/b.weight);
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<Item> items(n+2);
    for (int i=0; i<n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    int curWeight=0;
    double finalvalue = 0.0;
    for (int i=0; i<n; i++)
        if (curWeight + items[i].weight <= W)
        {
            curWeight += items[i].weight;
            finalvalue += items[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += items[i].value * ((double) remain / items[i].weight);
            break;
        }

    cout << finalvalue << endl;
}