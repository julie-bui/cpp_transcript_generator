//
//  student.h
//  cw
//
//  Created by Julie B on 24/11/2025.
//


#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <map>
#include "grade.h"

//creates class student
class student {
//private members -encapsulation
private:
    std::string id;
    std::vector<grade> grades;

public:
    //default constructor
    student();
    //constructor with student id
    student(const std::string &student_id);
    void student_grade(const grade &g);
    std::string student_id() const;
    const std::vector<grade>& getGrades() const;
    //map where each key is term number, each value is vector
    std::map<int, std::vector<grade>> term_grade() const;
    //average for one terms
    double term_average(int term) const;
    //overall average
    double overall_average() const;
};

#endif 



