/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:08:36 by mohkhald          #+#    #+#             */
/*   Updated: 2026/04/05 19:08:55 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _fixedPointValue;       
  static const int _fractionalBits = 8;    

public:
	Fixed();

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	int     getRawBits(void) const;
	void    setRawBits(int const raw);
};

#endif
