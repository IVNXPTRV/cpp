/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:32:38 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:53:19 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "\tMemory address of the string:\t" << std::setbase(16) << &brain << std::endl;
	std::cout << "\tMemory address by stringPTR:\t" << std::setbase(16) << stringPTR << std::endl;
	std::cout << "\tMemory address by stringREF:\t" << std::setbase(16) << &stringREF << std::endl;

	std::cout << "\n\tValue of the string:\t\t" <<  brain << std::endl;
	std::cout << "\tValue pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "\tValue pointed to by stringREF:\t" << stringREF << std::endl;

	return (0);
}
