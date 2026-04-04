/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 01:13:52 by mohkhald          #+#    #+#             */
/*   Updated: 2026/04/04 01:13:52 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "\n";
	harl.complain("DEBUG");
	
	std::cout << "\n";
	harl.complain("INFO");
	
	std::cout << "\n";
	harl.complain("WARNING");
	
	std::cout << "\n";
	harl.complain("ERROR");

	std::cout << "\n";
	harl.complain("INVALID");
	
	return 0;
}
