#include <bits/stdc++.h>
#include "Department.h"
#include "Professor.h"
#include "Student.h"

using namespace std;

int main() {
    string s;
    cin >> s;

    Department *dept;
    Student student;
    if (s == "S") {
        // same as: Department *dept = new Student();
        // dept = &student;
        dept = new Student();
    } else {
        dept = new Professor();
    }
    dept->getdata();
    return 0;
}