/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:33:20 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 14:33:21 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <ctime>
# include <climits>

# include <vector>
# include <iterator> // insert, begin, end
# include <algorithm> // distance, min_element, max_element

# define BLUE	"\033[1;34m"
# define YELLOW	"\033[1;33m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

class Span {

	private :

		std::vector<int>	_storage;
		size_t		_maxSize;

	public :

		Span();
		Span(const Span &source);
		Span &operator=(const Span &rhs);
		~Span();

		Span(size_t N);

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		const std::vector<int>& getStorage() const;

		class storageException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Invalid Storage.";
				}
		};

		class spanException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Not enough elements to calculate span.";
				}
		};

		template <typename I>
		void addNumber(I begin, I end) {
			if (_storage.size() + std::distance(begin, end) > _maxSize) {
				throw storageException();
			}
			_storage.insert(_storage.end(), begin, end);
		}
};

#endif
