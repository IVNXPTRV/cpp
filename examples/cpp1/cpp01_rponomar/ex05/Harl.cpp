/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:15 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 22:40:28 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>

void	harl::Harl::debug(void)
{
	std::cout << "\tDEBUG message" << std::endl;
}

void	harl::Harl::info(void)
{
	std::cout << "\tINFO message" << std::endl;
}

void	harl::Harl::warning(void)
{
	std::cerr << "\tWARNING message" << std::endl;
}

void	harl::Harl::error(void)
{
	std::cerr << "\tERROR message" << std::endl;
}

void	harl::Harl::wrong_level(void)
{
	std::cerr << "\tWrong level: Chose from: DEBUG, INFO, WARNING, ERROR\n";
}

void	harl::Harl::complain(const std::string& level)
{
	int idx = 0;
	idx += (level == "DEBUG") * DEBUG_ + (level == "INFO") * INFO_ + (level == "WARNING") * WARNING_ + (level == "ERROR") * ERROR_;

	HarlComplainPtr harl_complainers[NUM_COMPLAIN_LEVELS] = \
	{
		&harl::Harl::wrong_level,
		&harl::Harl::debug,
		&harl::Harl::info,
		&harl::Harl::warning,
		&harl::Harl::error
	};

	(this->*harl_complainers[idx])();
}
