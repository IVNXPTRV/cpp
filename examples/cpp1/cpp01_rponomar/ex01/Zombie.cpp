/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:57:02 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:47:49 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

zmb::Zombie::Zombie()
{
	std::cout << '\t'  << "Ctor Default Zombie: " << name_ << std::endl;
}

zmb::Zombie::~Zombie()
{
	std::cout << '\t'  << "Dtor Zombie: " << name_ << std::endl;
}

zmb::Zombie::Zombie(std::string name) : name_(name) 
{}

void	zmb::Zombie::announce(void)
{
	std::cout << '\t' << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}