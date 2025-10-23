/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:10:08 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 12:10:09 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <cctype>

# include <iostream>
# include <vector>
# include <list>
# include <deque>

# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

template <typename T>
typename T::const_iterator easyfind(const T &container, int number) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), number);

	if (it == container.end()) {
		throw std::runtime_error("Number not found");
	}
	return it;
}

#endif
