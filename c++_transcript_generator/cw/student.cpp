//
//  student.cpp
//  cw
//
//  Created by Julie B on 24/11/2025.
//

#include "student.h"
#include <numeric>

//constructor initialise student object
student::student() : id("") {}
student::student(const std::string &student_id)
    : id(student_id) {}
//adds grade object
void student::student_grade(const grade &g) {
    grades.push_back(g);
}
//getter methods
std::string student::student_id() const {
    return id;
}
const std::vector<grade>& student::getGrades() const {
    return grades;
}
//getter for private members
//groups grades by term
std::map<int, std::vector<grade>> student::term_grade() const {
    std::map<int, std::vector<grade>> termMap;
    for (const auto &g : grades) {
        termMap[g.term_num()].push_back(g);
    }
    return termMap;
}
//calculate term average
double student::term_average(int term) const {
    double sum = 0;
    int count = 0;
    //iterates through grades
    for (const auto &g : grades) {
        if (g.term_num() == term) {
            sum += g.mark();
            count++;
        }
    }
    if (count == 0) return 0.0;
    return sum / count;
}
//calculate overall average
double student::overall_average() const {
    if (grades.empty()) return 0.0;
    double sum = 0;
    for (const auto &g : grades) {
        sum += g.mark();
    }
    return sum / grades.size();
}


