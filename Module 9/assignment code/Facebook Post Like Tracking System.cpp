/*
Task 2: Facebook Post Like Tracking System

Facebook keeps track of the number of likes on each post. You are given n posts, each having an initial number of likes. Over time, users can like posts, and your task is to efficiently process these updates and determine which post has the highest number of likes after each update.
Task
Read two integers:
n: Number of Facebook posts.
m: Number of queries.
Read an array of n integers, where a[i] represents the initial number of likes on the i-th post.
Process m queries of the form:
post_no like_increase
This means the post_no-th post receives like_increase more likes.
After each query, print the post number (1-based index) with the highest likes and its like count. If multiple posts have the same highest likes, return the smallest index.
Input
	5 3
	10 20 30 40 50
	3 25
2 35
5 10
Output 
3 55
2 55
5 60

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> likes(n);
    for (int i = 0; i < n; i++) 
        cin >> likes[i];

    set<pair<int, int>> posts; // {likes, -index} (neg index ensures smallest index in case of tie)

    for (int i = 0; i < n; i++)
        posts.insert({likes[i], -i}); // Insert initial likes

    while (m--) {
        int post_no, increase;
        cin >> post_no >> increase;
        post_no--; // Convert 1-based index to 0-based

        posts.erase({likes[post_no], -post_no}); // Remove old value
        likes[post_no] += increase;
        posts.insert({likes[post_no], -post_no}); // Insert updated value

        auto max_post = *posts.rbegin(); // Get the post with max likes
        cout << -max_post.second + 1 << " " << max_post.first << endl; // Convert back to 1-based index
    }

    return 0;
}