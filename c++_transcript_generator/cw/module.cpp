//
//  module.cpp
//  cw
//
//  Created by Julie B on 24/11/2025.
//

#include "module.h"
//implementation of the module class
module::module(const std::string &c, int cr, const std::string &n)
    : code(c), credits(cr), name(n) {}
//getter methods for controlled access to private members
std::string module::module_code() const { return code; }
int module::module_credits() const { return credits; }
std::string module::module_name() const { return name; }

