// Greedy

// the greedy approach described here does not guarantee the best solution in all cases.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, profit;
};

// Comparator: end time asc, profit desc, start time asc
bool comp(Job &a, Job &b) {
    if (a.end != b.end)
        return a.end < b.end;
    if (a.profit != b.profit)
        return a.profit > b.profit;
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), comp);

    int maxProfit = 0;
    int lastEnd = 0;

    for (auto &job : jobs) {
        if (job.start >= lastEnd) {
            maxProfit += job.profit;
            lastEnd = job.end;
        }
    }

    cout << maxProfit << endl;
    return 0;
}

// Brute Force / Recursive Solution

// optimal solutions
/*
n is small (no large constraints), so we can afford to try all combinations (brute force / backtracking / recursion) to decide whether to take each job or not.

That way, we don’t need to complicate it with DP or greedy—we can explore all subsets and just pick the one with no overlaps and maximum profit.

This is totally valid when n is small (like n ≤ 20 or so).*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, profit;
};

int maxProfit = 0;

// Check if two jobs overlap
bool overlap(Job& a, Job& b) {
    return !(a.end <= b.start || b.end <= a.start);
}

// Check if the current set of jobs is valid (no overlap)
bool isValid(vector<Job>& jobs, vector<int>& selected) {
    for (size_t i = 0; i < selected.size(); i++) {
        for (size_t j = i + 1; j < selected.size(); j++) {
            if (overlap(jobs[selected[i]], jobs[selected[j]]))
                return false;
        }
    }
    return true;
}

// Try all subsets using recursion
void dfs(vector<Job>& jobs, int index, vector<int>& selected, int currentProfit) {
    if (index == jobs.size()) {
        if (isValid(jobs, selected)) {
            maxProfit = max(maxProfit, currentProfit);
        }
        return;
    }

    // Choice 1: include this job
    selected.push_back(index);
    dfs(jobs, index + 1, selected, currentProfit + jobs[index].profit);
    selected.pop_back();

    // Choice 2: don't include this job
    dfs(jobs, index + 1, selected, currentProfit);
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }

    vector<int> selected;
    dfs(jobs, 0, selected, 0);

    cout << maxProfit << endl;
    return 0;
}

*/







// DP

// optimal solution

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, profit;
};

bool comp(Job &a, Job &b) {
    return a.end < b.end;
}

// Binary search to find the last job that doesn't overlap
int latestNonConflict(vector<Job> &jobs, int i) {
    int low = 0, high = i - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[i].start) {
            if (jobs[mid + 1].end <= jobs[i].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), comp);

    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int incl = jobs[i].profit;
        int l = latestNonConflict(jobs, i);
        if (l != -1)
            incl += dp[l];
        dp[i] = max(incl, dp[i - 1]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}

*/