// Copied from stack overflow : https://stackoverflow.com/questions/9158150/colored-output-in-c/9158263

#pragma once
#include <iostream>

namespace ansi {
    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& reset(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[0m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_black(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[30m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& fg_red(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[31m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& fg_red_bold(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[1m\033[31m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& fg_green(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[32m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& fg_green_bold(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[1m\033[32m";
    }
    
}

// Use above namespace as:
//std::cout << ansi::foreground_red << "in red" << ansi::reset << std::endl;

/*

Color Codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      // Black
#define RED     "\033[31m"      // Red
#define GREEN   "\033[32m"      // Green
#define YELLOW  "\033[33m"      // Yellow
#define BLUE    "\033[34m"      // Blue
#define MAGENTA "\033[35m"      // Magenta
#define CYAN    "\033[36m"      // Cyan
#define WHITE   "\033[37m"      // White
#define BOLDBLACK   "\033[1m\033[30m"      // Bold Black
#define BOLDRED     "\033[1m\033[31m"      // Bold Red
#define BOLDGREEN   "\033[1m\033[32m"      // Bold Green
#define BOLDYELLOW  "\033[1m\033[33m"      // Bold Yellow
#define BOLDBLUE    "\033[1m\033[34m"      // Bold Blue
#define BOLDMAGENTA "\033[1m\033[35m"      // Bold Magenta
#define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan
#define BOLDWHITE   "\033[1m\033[37m"      // Bold White

*/
