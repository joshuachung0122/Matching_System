#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
        string number;
        string name;
        string sex;
        string grade;
        string subjects;
        string locations;
        string fee;

    public:
        Student(string number,
            string name,
            string sex,
            string grade,
            string subjects,
            string locations,
            string fee);
};
