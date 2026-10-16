#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
    std::string literal;
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    static void convert(const std::string& literal);
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& converter);
#endif