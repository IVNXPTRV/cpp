/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:15 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 20:47:50 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>

harl::Harl::Harl() : min_level_(DEFAULT_FILTER_) {}

harl::Harl::Harl(const std::string& filter) 
{
	min_level_ = 0;
	min_level_ += (filter == "DEBUG") * DEBUG_ + \
					(filter == "INFO") * INFO_ + \
					(filter == "WARNING") * WARNING_ + \
					(filter == "ERROR") * ERROR_;

	if (!min_level_)
	{
		std::cerr << "\tharlFilter: Warning: Wrong input for 'filter': Default filter will be used\n";
		min_level_ = DEFAULT_FILTER_;
	}
}

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


void	harl::Harl::insignificant(void)
{
	std::cerr << "\tINSIGNIFICANT message" << std::endl;
}

void	harl::Harl::complain(const std::string& level)
{
	int valid_input = (level == "DEBUG" ||
					level == "INFO" || \
					level == "WARNING" || \
					level == "ERROR");

	int idx = INSIGNIFICANT_;
	switch (min_level_)
	{
		case DEBUG_:
			idx += (level == "DEBUG") * (DEBUG_ - INSIGNIFICANT_);
		case INFO_:
			idx += (level == "INFO") * (INFO_ - INSIGNIFICANT_);
		case WARNING_:
			idx += (level == "WARNING") * (WARNING_ - INSIGNIFICANT_);
		case ERROR_:		
			idx += (level == "ERROR") * (ERROR_ - INSIGNIFICANT_);
		default :
			idx *= valid_input;
	}

	HarlComplainPtr harl_complainers[NUM_COMPLAIN_LEVELS] = \
	{
		&harl::Harl::wrong_level,
		&harl::Harl::debug,
		&harl::Harl::info,
		&harl::Harl::warning,
		&harl::Harl::error,
		&harl::Harl::insignificant
	};

	(this->*harl_complainers[idx])();
}

//