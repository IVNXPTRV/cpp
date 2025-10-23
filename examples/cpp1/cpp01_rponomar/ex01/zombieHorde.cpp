/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:34:39 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:47:22 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string.h>
#include <cstdlib>

zmb::Zombie*	zmb::zombieHorde(int N, std::string name)
{
	Zombie *z = new (std::nothrow) Zombie[N];
	while (z && N--)
		z[N] = Zombie(name);
	return (z);
}
