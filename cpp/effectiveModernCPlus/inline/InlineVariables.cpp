/**
 *
 * Inline Variabels is a new concept introduced in C++ 17
 * So Basically originally if we have bunch of constants then we do
 *
 * 1. Define a Header
 * 2. Create a namespace
 * 3. Make Variables 
 *
 * example IRS.h
 *
 * namespace CRL::CONST
 * {
 *  constexpr int TOTAL_TRACKS {100};
 *  constexpr int TOTAL_TRAINS {10};
 * };
 *
 * Now the drawback is whenever we included the header the compiler will have to copy all the constant
 *
 * as by default global const has internal linkage that means across different transalation unit
 * they are not visible. if we declared pragma guards they just save from copying from same unit not
 * cross
 *
 * So with
 * inline constexpr int TOTAL_TRACKS{100} this is included once
 *
 */
#include <iostream>
inline constexpr int TOTAL_TRACKS {100};

int main()
{
    std::cout << TOTAL_TRACKS << "\n";
}
