#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
        int number;
        string name;
        Sex sex;
        string school;
        string programme;
        string year;
        string dseResults;
        string studentGrade;
        vector<Subject> subjects;
        vector<Location> locations;
        string aimedSalary;

        

};
