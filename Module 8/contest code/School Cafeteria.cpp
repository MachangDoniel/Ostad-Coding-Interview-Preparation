/*
School Cafeteria

বাং
Problem Statement
Your school cafeteria serves two types of foods sandwitchs and burgers. Each student has a preference. Cafeteria has one booth where food is served. It has some rules, at the start of the day the booth has no food and the student queue is empty. There types of event can happen:

Event 1: A new student comes and stands at the end of the student queue.
Event 2: A new food has arrived and put on the top of all foods.
Event 3: The student in the front of the queue asks for food. If student's prefered food is on the top of the food stack then he is satisfied and leaves the queue with the food. If the food stack is empty of the top of the stack doesn't contain student's prefered food then the student goes to the end of the queue.
The food is stored as a stack where the latest arrived food stays at the top. And students wait in a queue where first arrived student stays at the front. Your task is to count the number of satisfied students who got his preferred food.

Input
First line of the input contains an integer 
T
T, number of days observed.
Next is the description of 
T
T days. Each day starts with an integer 
N
N number of events happened that day. Next 
N
N line describes the events:

Event 1 is described as 
1
1 
S
S. Which means a new student with prefered food 
S
S came. 
S
S can be ether "sandwich" or "burger".
Event 2 is described as 
2
2 
S
S. Which means a new food 
S
S has arrived. 
S
S can be ether "sandwich" or "burger".
Event 3 is described as 
3
3. Which means the student in the front of the queue asks for food.
Output
For each day print the day number and number of satisfied students that day. See sample output for better understanding.

Constraints
1
1 
≤
≤ 
T
T 
≤
≤ 
100
100
1
1 
≤
≤ 
N
N 
≤
≤ 
10000
10000
S
S 
∈
∈ {"sandwich", "burger"}
Example 1:
Input:
2
3
1 sandwich
2 burger
3
3
1 burger
2 burger
3
Output:
Day 1: 0
Day 2: 1
Example 2:
Input:
2
7
1 sandwich
2 sandwich
2 burger
1 burger
3
3
3
6
1 sandwich
2 sandwich
2 burger
1 burger
3
3
Output:
Day 1: 2
Day 2: 1
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    stack<string>food;
    queue<string>stud;
    int satisfied=0;
    for(int i=0;i<n;i++){
        int event; cin>>event;
        if(event==1){
            string newFood; cin>>newFood;
            food.push(newFood);
        }
        else if(event==2){
            string preferFood; cin>>preferFood;
            stud.push(preferFood);
        }
        else{
            if(food.top()==stud.front()){
                satisfied++;
                food.pop();
                stud.pop();
            }
            else{
                string preferFood=stud.front();
                stud.pop();
                stud.push(preferFood);
            }
        }
    }
    cout<<satisfied<<endl;
}
     
int main() {
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cout<<"Day "<<t<<": ";
        solve();
    }

    return 0;
}