/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:50 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:54:19 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>
#include <cstddef>

wpn::HumanB::HumanB(const std::string& name) : 
	name_(name),
	weapon_(NULL)
{}

wpn::HumanB::HumanB(const std::string& name, const Weapon& weapon) : 
	name_(name),
	weapon_(&const_cast<Weapon&>(weapon))
{}

void	wpn::HumanB::setWeapon(const Weapon& weapon)
{
	weapon_ = &const_cast<Weapon&>(weapon);
}

void	wpn::HumanB::attack(void)
{
	if (weapon_)
		std::cout << '\t' << name_ << " attacks with their " << (*weapon_).getType() << std::endl;
	else
		std::cout << '\t' << name_ << " attacks with their bare hands" << std::endl;
}