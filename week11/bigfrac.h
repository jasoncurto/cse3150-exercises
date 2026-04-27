#ifndef BIGFRAC_H
#define BIGFRAC_H

#include <utility>
#include <string>

class bigint;

typedef std::pair<bigint, bigint> BigFraction;

BigFraction multFracs(BigFraction f1, BigFraction f2);
BigFraction sumFracs(BigFraction f1, BigFraction f2);
std::string fracToString(BigFraction f);

#endif