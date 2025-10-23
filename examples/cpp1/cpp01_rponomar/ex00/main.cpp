/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:32:36 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:11:33 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	zmb::Zombie* z = zmb::newZombie("new_zombie");
	if (z)
		(*z).announce();
	delete z;

	zmb::randomChump("random_zombie");

}
