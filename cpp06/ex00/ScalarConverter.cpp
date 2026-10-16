#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() : literal("") {};
ScalarConverter::ScalarConverter(const ScalarConverter& other) : literal(other.literal) {};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        this->literal = other.literal;
    }
    return *this;
}
ScalarConverter::~ScalarConverter() {};

void ScalarConverter::convert(const std::string& _literal) {
    // Implementation of the conversion logic goes here
    this->literal = _literal;
    if(_literal.empty()) {
        std::cerr << "Error: Empty literal provided." << std::endl;
        return;
    }
    else if(_literal == "nan" || _literal == "inf" || _literal == "-inf") {
        std::cout << "Special floating-point value: " << _literal << std::endl;
        return;
    }
    else if(_literal.length() == 1 && !isdigit(_literal[0])) {
        std::cout << "Character literal: '" << _literal[0] << "'" << std::endl;
        return;
    }
    else {
        try {
            char* endptr;
            int value = std::strtol(_literal, &endptr, 10);

            if (*endptr != '\0') {
                std::cerr << "Error: Invalid literal provided." << std::endl;
                return;
            }

            std::cout << "Double value: " << value << std::endl;
            // Additional conversion logic can be added here
            float floatValue = static_cast<float>(value);
            std::cout << "Float value: " << floatValue << "f" << std::endl;
            int intValue = static_cast<int>(value);
            std::cout << "Integer value: " << intValue << std::endl;
            char charValue = static_cast<char>(value);
            if (std::isprint(charValue)) {
                std::cout << "Character value: '" << charValue << "'" << std::endl;
            } else {
                std::cout << "Character value: Non-displayable" << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid literal provided." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Literal out of range." << std::endl;
        }
    }
    // For demonstration purposes, we'll just print the literal
    std::cout << "Converting literal: " << _literal << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ScalarConverter& converter) {
    os << converter.literal;
    return os;
}