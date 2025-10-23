/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:22 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 21:54:39 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# include <string>


namespace wpn
{
	class HumanA
	{
		private:
			std::string			name_;
			Weapon&				weapon_;
		public:
			void				setWeapon(const Weapon& weapon);
			// void				setWeapon(Weapon& weapon);
			void				attack(void);
		public:
			HumanA(const std::string& name, const Weapon& weapon);			
			HumanA(const std::string& name, Weapon& weapon);
	};
}

#endif