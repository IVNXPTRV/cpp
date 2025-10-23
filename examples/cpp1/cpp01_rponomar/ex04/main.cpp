/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:01:37 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 22:35:17 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <fcntl.h>
#include <limits>
#include <string>
#include <iostream>
#include <unistd.h>

static int	ft_err(int condition, char *prog, const std::string& msg)
{
	if (!condition)
		return (0);
	std::cerr << '\t' << prog << ": error";
	if (!msg.empty())
		std::cerr << ": " << msg;
	std::cerr << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{	
	if (ft_err(argc != 4, argv[0], "requires 3 args: file_name str_replaced str_replacing"))
		return (1);

	rpl::Replacer	replacer(argv[0], argv[1], argv[2], argv[3]);

	try
	{
		replacer.replace();
	}
	catch(const std::runtime_error& rte)
	{
		std::cerr << rte.what() << '\n';
		return (EXIT_FAILURE);
	}

	return (0);
}


	// std::cout << "\n\tSourse file:\t\t" << replacer.src_name_ << '\n' \
	// 		<< "\tDestination file:\t" << replacer.dst_name_ << '\n' \
	// 		<< "\tTarget str:\t\t" << replacer.target_ << '\n' \
	// 		<< "\tReplacing str:\t\t" << replacer.replacement_ << "\n\n";
	
