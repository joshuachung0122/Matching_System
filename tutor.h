#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Sex;
enum class Grade;
enum class Location;
enum class Subject;

class Tutor{
    private:
        string number;
        string name;
        string sex;
        string school;
        string programme;
        string year;
        string dseResults;
        string studentGrade;
        string subjects;
        string locations;
        string aimedSalary;

    public:
        Tutor(string number,
            string name,
            string sex,
            string school,
            string programme,
            string year,
            string dseResults,
            string studentGrade,
            string subjects,
            string locations,
            string aimedSalary);
        
        void print()const;
};