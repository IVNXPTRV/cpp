/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:44 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:50:24 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

# include <string>

namespace wpn
{
	class HumanB
	{
		private:
			const std::string	name_;
			Weapon*				weapon_;
		public:
			void				setWeapon(const Weapon& weapon);
			// void				setWeapon(Weapon& weapon);
			void				attack(void);
		public:
			HumanB(const std::string& name);		
			HumanB(const std::string& name, const Weapon& weapon);			
			// HumanB(const std::string& name, Weapon& weapon);
	};
}

#endif