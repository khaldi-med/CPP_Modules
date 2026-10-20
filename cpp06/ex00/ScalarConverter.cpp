#include "ScalarConverter.hpp"
#include <cerrno>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

static bool isNan(double value)
{
    return value != value;
}

static bool isInfinite(double value)
{
    return value == std::numeric_limits<double>::infinity()
        || value == -std::numeric_limits<double>::infinity();
}

static bool parseInteger(const std::string& literal, long& value)
{
    char* endptr;

    errno = 0;
    value = std::strtol(literal.c_str(), &endptr, 10);
    return endptr != literal.c_str() && *endptr == '\0' && errno != ERANGE;
}

static bool parseDecimal(const std::string& literal, double& value)
{
    char* endptr;

    errno = 0;
    value = std::strtod(literal.c_str(), &endptr);
    return endptr != literal.c_str() && *endptr == '\0' && errno != ERANGE;
}

static void printChar(double value)
{
    if (isNan(value) || isInfinite(value)
        || value < std::numeric_limits<char>::min()
        || value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char converted = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(converted)))
        std::cout << "char: '" << converted << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value)
{
    if (isNan(value) || isInfinite(value)
        || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    if (isNan(value))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (value == std::numeric_limits<double>::infinity())
    {
        std::cout << "float: +inff" << std::endl;
        return;
    }
    if (value == -std::numeric_limits<double>::infinity())
    {
        std::cout << "float: -inff" << std::endl;
        return;
    }
    if (value < -std::numeric_limits<float>::max()
        || value > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
    if (isNan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (value == std::numeric_limits<double>::infinity())
    {
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (value == -std::numeric_limits<double>::infinity())
    {
        std::cout << "double: -inf" << std::endl;
        return;
    }

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << value << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    double value;
    long integerValue;

    if (literal == "nan" || literal == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf" || literal == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        value = static_cast<unsigned char>(literal[1]);
    else if (parseInteger(literal, integerValue))
        value = static_cast<double>(integerValue);
    else if (literal.length() > 1 && literal[literal.length() - 1] == 'f'
        && parseDecimal(literal.substr(0, literal.length() - 1), value))
    {
    }
    else if (literal.find('.') != std::string::npos
        || literal.find('e') != std::string::npos
        || literal.find('E') != std::string::npos)
    {
        if (!parseDecimal(literal, value))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}