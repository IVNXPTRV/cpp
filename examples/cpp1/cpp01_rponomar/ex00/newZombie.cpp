/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:57:11 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:28:14 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <exception>
#include <new>
#include <string>
#include <cstdlib>

zmb::Zombie	*zmb::newZombie(std::string name)
{
	Zombie *z;
	try
	{
		z = new Zombie(name);
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "\tzmb::newZombie: Error: " << ba.what() << std::endl;
		delete z;
		z = NULL;
	}

	return (z);
}

