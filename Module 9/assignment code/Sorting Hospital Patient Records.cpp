/*
Task 1: Sorting Hospital Patient Records

A hospital maintains a record of patients with details such as Patient ID, Name, Age, Severity Score (higher severity means more critical). The hospital wants to efficiently manage patient treatment, ensuring that patients with higher severity are attended to first.
 Write a program that:
Reads an integer n (number of patients).
Reads n lines containing Patient ID (integer), Name (string), Age (integer), and Severity Score (integer).
Sorts the records primarily by Severity Score (descending). If two patients have the same severity, sort them by Age (ascending).
Outputs the sorted patient list.

Input Example:
5  
101 Alice 30 5  
102 Bob 25 8  
103 Charlie 40 8  
104 David 35 6  
105 Eve 28 5 



Output
102 Bob 25 8  
103 Charlie 40 8  
104 David 35 6  
105 Eve 28 5  
101 Alice 30 5

*/

#include <bits/stdc++.h>
using namespace std;

struct Patient {
    int id, age, severity;
    string name;
};

bool compare(const Patient &a, const Patient &b) {
    if (a.severity != b.severity)
        return a.severity > b.severity;
    return a.age < b.age;
}

int main() {
    int n;
    cin >> n;
    vector<Patient> patients(n);
    
    for (int i = 0; i < n; i++)
        cin >> patients[i].id >> patients[i].name >> patients[i].age >> patients[i].severity;
    
    sort(patients.begin(), patients.end(), compare);
    
    for (const auto &p : patients)
        cout << p.id << " " << p.name << " " << p.age << " " << p.severity << endl;

    return 0;
}
