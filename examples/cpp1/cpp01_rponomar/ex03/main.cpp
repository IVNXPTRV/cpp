/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:18:15 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:56:59 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

int	main(void)
{
	{
		wpn::HumanB epi("Epiphany");
		epi.attack();
		const wpn::Weapon club("vonuchy valenok");
		epi.setWeapon(club);
		epi.attack();
	}
	{
		wpn::Weapon club = wpn::Weapon("crude spiked club");
		wpn::HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		wpn::Weapon club = wpn::Weapon("crude spiked club");
		wpn::HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
