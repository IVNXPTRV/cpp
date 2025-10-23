/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:12 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/19 20:26:00 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <cstddef>
# include <cstdlib>
# include <string>
# include <fstream>

# define COMPLAIN_LEVELS(CL)	\
	CL(WRONG_LEVEL_),			\
	CL(DEBUG_),					\
	CL(INFO_),					\
	CL(WARNING_),				\
	CL(ERROR_),					\
	CL(INSIGNIFICANT_)

#define CL(f) f
enum ComplainLevels {COMPLAIN_LEVELS(CL), NUM_COMPLAIN_LEVELS};
#undef CL

#define DEFAULT_FILTER_ DEBUG_

namespace harl
{
	
	class Harl
	{
		private:
			int					min_level_;
		public:
			void				complain(const std::string& level);
		private:
			typedef void		(harl::Harl::*	HarlComplainPtr)(void);	
		private:
			void				wrong_level(void);
			void				debug(void);
			void				info(void);
			void				warning(void);
			void				error(void);
			void				insignificant(void);
		public:
			Harl();
			Harl(const std::string& filter);
	};
}

#endif