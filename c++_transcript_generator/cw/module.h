//
//  module.h
//  cw
//
//  Created by Julie B on 24/11/2025.
//

#ifndef MODULE_H
#define MODULE_H

#include <string>
//create module class holds info on module code, credits and name
class module {
//encapsulation for private members
private:
    std::string code;
    int credits;
    std::string name;

public:
    //constructor initialise module info
    module(const std::string &c = "", int cr = 0, const std::string &n = "");
    //getter methods for module code, credits, name
    std::string module_code() const;
    int module_credits() const;
    std::string module_name() const;
};

#endif
