//
//  grade.h
//  cw
//
//  Created by Julie B on 24/11/2025.
//

#ifndef GRADE_H
#define GRADE_H

#include <string>

//create class grade which has data of student id, term, module code, module mark
class grade {
//encapsulation - data members hidden from outside class
private:
    int student_id;
    int term;
    std::string module_code;
    double module_mark;

public:
    //constructor - initialises grade object with the data
    grade(int student_id = 0, int term = 0, const std::string &module_code = "", double module_mark = 0);
    //getter methods with const at end so method doesn't change object
    int id() const;
    int term_num() const;
    std::string module() const;
    double mark() const;
};

#endif

