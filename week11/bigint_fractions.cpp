#include "bigfrac.h"
#include <sstream>
#include "bigint.h"

using namespace std;

BigFraction multFracs(BigFraction f1, BigFraction f2) {
    bigint num = f1.first * f2.first;
    bigint den = f1.second * f2.second;
    return make_pair(num, den);
}

BigFraction sumFracs(BigFraction f1, BigFraction f2) {
    bigint ad = f1.first * f2.second;
    bigint bc = f2.first * f1.second;
    
    bigint num = ad + bc;
    bigint den = f1.second * f2.second;
    
    return make_pair(num, den);
}

string fracToString(BigFraction f) {
    stringstream ss;
    ss << f.first << "/" << f.second;
    return ss.str();
}