/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:27:56 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 18:58:23 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

namespace wpn
{
	class Weapon
	{
		private:
			std::string 			type_;
		public:
			const std::string&		getType(void);
			void					setType(const std::string& val);
		public:
			Weapon();
			Weapon(std::string type);
	};
}

#endif