//
//  grade.cpp
//  cw
//
//  Created by Julie B on 24/11/2025.
//

#include "grade.h"

//implements grade class
//constructor initialises members
grade::grade(int sid, int t, const std::string &mod, double mk)
    : student_id(sid), term(t), module_code(mod), module_mark(mk) {}

//implements getter methods
int grade::id() const { return student_id; }
int grade::term_num() const { return term; }
std::string grade::module() const { return module_code; }
double grade::mark() const { return module_mark; }
