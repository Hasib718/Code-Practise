#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Job {
    int id, dealine, profit;

    // bool operator>(Job const& obj) {
    //     return profit > obj.profit;
    // }
};

bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

int main()
{
    int t, n, index, profits, taken;
    
    cin >> n;

    vector<Job> jobs(n+2);
    vector<bool> flag(n+2, false);

    for (int i=0; i<n; i++) {
        cin >> jobs[i].id >> jobs[i].dealine >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), comp);

    for (int i=0; i<n; i++) {
        index = jobs[i].dealine;
        while(index && flag[index])
            index--;

        if (index >= 0) {
            taken++;
            profits += jobs[i].profit;
            flag[index] = true;
        }
    }

    for (int i=0; i<n; i++)
        if (flag[i])
            cout << jobs[i].id << jobs[i].dealine << jobs[i].profit << endl;
}