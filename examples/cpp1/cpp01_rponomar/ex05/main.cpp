/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:39:32 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 22:41:53 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstddef>
#include <string>

int	main(void)
{
	harl::Harl mr_harl;
	mr_harl.complain("DEBUG");
	mr_harl.complain("ERROR");
	mr_harl.complain("INFO");		
	mr_harl.complain("WARNING");
	mr_harl.complain("wrong level");	
	return (0);
}
