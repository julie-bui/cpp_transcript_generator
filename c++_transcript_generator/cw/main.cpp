//
//  main.cpp
//  cw
//
//  Created by Julie B on 27/11/2025.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include "student.h"
#include "module.h"
#include "grade.h"

using namespace std;

int main() {
    //loads,read modules txt file
    //maps module codes to module objects
    map<string,module> modules;
    ifstream module_file("modules.txt");
    string code, name;
    int credits;
    while (module_file >> code >> credits >> name) {
        //iterates and replaces underscores to spaces in names
        //creates module object and stores in map
        for (char &c : name) if (c=='_') c=' ';
        modules[code] = module(code, credits, name);
    }

    //loads,read grades txt file
    map<string, student> students;
    ifstream grade_file("grades.txt");
    string grade_id, grade_module;
    int grade_term;
    double grade_mark;
    //creates grades objects adds to student
    while (grade_file >> grade_id >> grade_term >> grade_module >> grade_mark) {
        if(!students.count(grade_id)) students[grade_id] = student(grade_id);
        grade g(0,grade_term,grade_module,grade_mark);
        students[grade_id].student_grade(g);
    }

    //loads requests file
    ifstream requests_file("requests.txt");
    //vector stores all requests
    vector<pair<string,int>> requests;
    string line;
    while(getline(requests_file, line)) {
        //skips blank lines
        if(line.empty()) continue;
        istringstream ss(line);
        string student_name_id;
        int term = -1;
        ss >> student_name_id;
        //saves the student id and term to requests vector
        if(ss >> term) {
            requests.push_back({student_name_id, term});
        //if no term exists
        } else {
            requests.push_back({student_name_id, -1});
        }
    }

    //iterates student objects
    //outputs student id, terms, grades
    for(auto &p : requests) {
        string student_name_id = p.first;
        int term_request = p.second;
        if(!students.count(student_name_id)) continue;
        student &s = students[student_name_id];
        cout << "Student ID: " << student_name_id << "\n";
        auto term_map = s.term_grade();
        //iterates through each term
        if(term_request==-1){
            double overall_weighted=0;
            int overall_credits=0;
            for(auto &tm:term_map){
                int t = tm.first;
                auto &grades = tm.second;
                cout << "  Term " << t << ":\n";
                double term_weighted=0;
                int term_credits=0;
                //iterates through grades in each term
                for(auto &g:grades){
                    module m = modules[g.module()];
                    //output module and mark info
                    cout << "    " << m.module_code() << " "
                         << m.module_name() << " ("
                         << m.module_credits() << " credits): "
                         << g.mark() << "\n";
                    term_weighted += g.mark()*m.module_credits();
                    term_credits += m.module_credits();
                }
                //output term average 2 decimal places
                cout << fixed << setprecision(2);
                cout << "  Term Average: " << (term_credits?term_weighted/term_credits:0) << "\n";
                overall_weighted += term_weighted;
                overall_credits += term_credits;
            }
            //output overall average 2 decimal places
            cout << "  Overall Average: " << (overall_credits?overall_weighted/overall_credits:0) << "\n\n";
        } else {
            //checks if requested term doesn't exist for student
            if(!term_map.count(term_request)) continue;
            auto &grades = term_map[term_request];
            //gets vector of grade object for the term
            cout << "  Term " << term_request << ":\n";
            double term_weighted=0;
            int term_credits=0;
            //iterates through each grade object in term
            for(auto &g:grades){
                module m = modules[g.module()];
                //outputs module code, name, credits, mark
                cout << "    " << m.module_code() << " "
                     << m.module_name() << " ("
                     << m.module_credits() << " credits): "
                     << g.mark() << "\n";
                term_weighted += g.mark()*m.module_credits();
                term_credits += m.module_credits();
            }
            cout << fixed << setprecision(2);
            cout << "  Term Average: " << (term_credits?term_weighted/term_credits:0) << "\n\n";
        }
    }
    return 0;
}


