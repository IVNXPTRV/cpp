/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:10 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:58:32 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#include <cstdlib>

wpn::Weapon::Weapon() : type_("empty") {}

wpn::Weapon::Weapon(std::string type) : type_(type)
{}

const std::string&	wpn::Weapon::getType(void)
{
	const std::string&	type_ref = type_;
	return (type_ref);
}

void	wpn::Weapon::setType(const std::string& val)
{
	type_ = val;
}