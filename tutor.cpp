#include "tutor.h"

Tutor::Tutor(string number,
            string name,
            string sex,
            string school,
            string programme,
            string year,
            string dseResults,
            string studentGrade,
            string subjects,
            string locations,
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



void Tutor::print()const{
    cout<<number<<'\t'
        <<name<<'\t'
        <<sex<<'\t'
        <<school<<'\t'
        <<programme<<'\t'
        <<year<<'\t'
        <<dseResults<<'\t'
        <<studentGrade<<'\t'
        <<subjects<<'\t'
        <<locations<<'\t'
        <<aimedSalary<<endl;
}