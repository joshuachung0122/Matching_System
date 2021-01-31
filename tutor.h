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
        int number;
        string name;
        Sex sex;
        string school;
        string programme;
        string year;
        string dseResults;
        vector<Grade> studentGrade;
        vector<Subject> subjects;
        vector<Location> locations;
        string aimedSalary;

    public:
        Tutor(int number,
            string name,
            Sex sex,
            string school,
            string programme,
            string year,
            string dseResults,
            vector<Grade> studentGrade,
            vector<Subject> subjects,
            vector<Location> locations,
            string aimedSalary);
        

};