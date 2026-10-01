/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:31:29 by mohkhald          #+#    #+#             */
/*   Updated: 2026/04/06 18:31:29 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
}

Fixed::Fixed(const int value) {
    this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_rawBits = other._rawBits;
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_rawBits + other._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_rawBits - other._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = static_cast<long long>(this->_rawBits) * static_cast<long long>(other._rawBits);
    result.setRawBits(static_cast<int>(temp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long temp = (static_cast<long long>(this->_rawBits) << _fractionalBits) / other._rawBits;
    result.setRawBits(static_cast<int>(temp));
    return result;
}

Fixed& Fixed::operator++() {
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_rawBits++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_rawBits--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
