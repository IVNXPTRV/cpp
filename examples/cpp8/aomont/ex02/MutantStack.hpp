/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:35:35 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 14:35:36 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <vector>
# include <iostream>
# include <iterator>

# define BLUE	"\033[1;34m"
# define YELLOW	"\033[1;33m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

template <typename T>

class MutantStack : public std::stack<T> {
	public :

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack &source);
		MutantStack& operator=(const MutantStack &rhs);
		~MutantStack();

		iterator		begin();
		iterator		end();

		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
