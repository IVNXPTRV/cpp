/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:46:28 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/18 01:18:02 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <cstddef>
# include <cstdlib>
# include <string>

#define MAX_SUPPORTED_FILE_SIZE 100

namespace rpl
{
	struct Replacer
	{
		public:
			std::string			prog_;		
			std::string			src_name_;
			std::string			dst_name_;
			std::string			target_;
			std::string			replacement_;
		private:
			std::string			buff_;
		public:
			void				replace(void);
		public:
			Replacer(const std::string& prog, const std::string& file_name, const std::string& target, const std::string& replacement);
	};
}
	
	// public:
	// 	std::string			src_name(void);
	// 	std::string			dst_name(void);
	// 	std::string			target(void);
	// 	std::string			replacement(void);
	
#endif