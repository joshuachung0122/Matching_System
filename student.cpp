#include "student.h"

Student::Student(string number,
        string name,
        string sex,
        string targetTutorSex,
        string grade,
        string subjects,
        string locations,
        string fee):
            number(number),
            name(name),
            sex(sex),
            targetTutorSex(targetTutorSex),
            grade(grade),
            subjects(subjects),
            locations(locations),
            fee(fee){}

void Student::print() const{
    cout<<number<<'\t'
        <<name<<'\t'
        <<sex<<'\t'
        <<targetTutorSex<<'\t'
        <<grade<<'\t'
        <<subjects<<'\t'
        <<locations<<'\t'
        <<fee<<endl;
}

bool Student::operator<(const Student& other)const{
    return stoi(number)<stoi(other.number);
}