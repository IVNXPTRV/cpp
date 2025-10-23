/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:33 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:47:48 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>
#include <cstddef>

wpn::HumanA::HumanA(const std::string& name, Weapon& weapon) : 
	name_(name),
	weapon_(weapon)
{}

wpn::HumanA::HumanA(const std::string& name, const Weapon& weapon) : 
	name_(name),
	weapon_(const_cast<Weapon&>(weapon))
{}

void	wpn::HumanA::setWeapon(const Weapon& weapon)
{
	weapon_ = const_cast<Weapon&>(weapon);
}

// void	wpn::HumanA::setWeapon(Weapon& weapon)
// {
// 	weapon_ = weapon;
// }

void	wpn::HumanA::attack(void)
{
	std::cout << '\t' << name_ << " attacks with their " << weapon_.getType() << std::endl;
}