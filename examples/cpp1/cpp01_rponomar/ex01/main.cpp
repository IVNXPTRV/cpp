/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:32:36 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:48:45 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>

static void		ft_err_msg(int condition, char *prog)
{
	if (!condition)
		return ;
	std::cerr << '\t' << prog << ": required args: 1st arg positive int<1000 and 2nd arg string\n" << std::endl;
	std::exit(EXIT_FAILURE);	
}

int	main(int argc, char **argv)
{
	ft_err_msg(argc != 3, argv[0]);

	int	n = atoi(argv[1]);
	ft_err_msg(n <= 0 || n >1000, argv[0]);

	ft_err_msg(!argv[2][0], argv[0]);

	zmb::Zombie *z = zmb::zombieHorde(n, argv[2]);

	std::cout << "\n\tN = " << n << "\n\tname: " << argv[2] << std::endl;

	std::cout << "\n\tannouncing:" << std::endl;
	int i = -1;
	while (z && ++i < n)
		z[i].announce();

	std::cout << "\n\tdestructors:" << std::endl;
	delete [] z;
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}
	// #include <string>
	// int	n = std::stoi(argv[1]);