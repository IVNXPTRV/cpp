/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:39:32 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 22:42:04 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstddef>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "\tharlFilter: Error: Requires one arg for 'filter': Chose from: DEBUG, INFO, WARNING, ERROR\n";
		return (1);
	}

	harl::Harl mr_harl(argv[1]);
	std::cout << '\n';
	mr_harl.complain("DEBUG");
	mr_harl.complain("INFO");
	mr_harl.complain("WARNING");
	mr_harl.complain("ERROR");
	mr_harl.complain("wrong level");
	std::cout << '\n';
	mr_harl.complain("wrong level");
	mr_harl.complain("ERROR");
	mr_harl.complain("WARNING");
	mr_harl.complain("INFO");
	mr_harl.complain("DEBUG");
	std::cout << '\n';
	return (0);
}
