#include "tutor.h"

Tutor::Tutor(int number,
            string name,
            Sex sex,
            string school,
            string programme,
            string year,
            string dseResults,
            vector<Grade> studentGrade,
            vector<Subject> subjects,
            vector<Location> locations,
            string aimedSalary):
                number(number),
                name(name),
                sex(sex),
                school(school),
                programme(programme),
                year(year),
                dseResults(dseResults),
                studentGrade(studentGrade),
                subjects(subjects),
                locations(locations),
                aimedSalary(aimedSalary){}