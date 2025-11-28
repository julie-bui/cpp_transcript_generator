//
//  stats.cpp
//  cw
//
//  Created by Julie B on 19/11/2025.
//

#include "stats.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

//median of the values in a vector
double median(vector<double> v) {
    const auto n = v.size();
    //checks if vector empty
    if (n == 0)
        throw domain_error("median of an empty vector");
    //sorts vector
    sort(v.begin(), v.end());
    //finds median
    const auto middle = n/2;
    if (n%2 == 1)
        //size is odd
        return v[middle];
    else //size even
        return (v[middle-1] + v[middle])/2;
}

//calculates average values in a vector
double average(const vector<double> &v) {
    const auto n = v.size();
    if (n == 0)
        throw domain_error("average of an empty vector");
    double sum = 0;
        //iterates through each value in vector and add to sum
        for (double x : v)
        sum += x;
    return sum / n;
}
