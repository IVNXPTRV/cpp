/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:56:58 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/17 16:30:14 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> 

namespace zmb
{
	class Zombie
	{
		private:
			std::string		name_;
		public:
			void			announce(void);
		public:
			Zombie(std::string name);
			~Zombie();
	};
	
	Zombie			*newZombie(std::string name);
	void			randomChump(std::string name);
}

#endif