/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:35:25 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 16:32:45 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
void printElements(const T& container) {
	typename T::const_iterator it = container.begin();
	typename T::const_iterator ite = container.end();

	std::cout << "Container : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main() {
	MutantStack<int> stack;

	std::cout << BLUE << "### Testing Stack" << RESET << std::endl;
	std::cout << YELLOW << "stack.empty() : " << stack.empty() << RESET << std::endl;
	stack.push(42);
	std::cout << YELLOW << "stack.empty() : " << stack.empty() << RESET << std::endl;

	stack.push(0);
	stack.push(99);
	stack.push(17);
	stack.push(13);
	printElements(stack);
	stack.pop();
	printElements(stack);
	stack.push(50);
	printElements(stack);

	std::cout << YELLOW << "stack.size() : " << stack.size() << RESET << std::endl;
	std::cout << YELLOW << "stack.top() : " << stack.top() << RESET << std::endl;

	// ##############################################################################
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();

	std::cout << "Forward iterator : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// ##############################################################################
	MutantStack<int>::reverse_iterator rit = stack.rbegin();
	MutantStack<int>::reverse_iterator rite = stack.rend();
	std::cout << "Reverse iterator : ";
	while (rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	// ##############################################################################
	const MutantStack<int> constStack = stack;

	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();
	std::cout << "Const Forward iterator : ";
	while (cit != cite) {
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;

	// ##############################################################################
	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = constStack.rend();
	std::cout << "Const Reverse iterator : ";
	while (crit != crite) {
		std::cout << *crit << " ";
		++crit;
	}
	std::cout << std::endl;

	// ##############################################################################
	// ##############################################################################

	std::list<int> list;

	std::cout << BLUE << "\n### Testing List" << RESET << std::endl;
	std::cout << YELLOW << "List.empty() : " << list.empty() << RESET << std::endl;
	list.push_back(42);
	std::cout << YELLOW << "list.empty() : " << list.empty() << RESET << std::endl;

	list.push_back(12);
	list.push_back(13);
	list.push_back(99);
	list.push_back(8);
	printElements(list);
	list.pop_front();
	printElements(list);
	list.push_back(30);
	printElements(list);

	std::cout << YELLOW << "List.size() : " << list.size() << RESET << std::endl;
	std::cout << YELLOW << "List.back() : " << list.back() << RESET << std::endl;

	// ##############################################################################

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	std::cout << "Forward iterator : ";
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int>::reverse_iterator lrit = list.rbegin();
	std::list<int>::reverse_iterator lrite = list.rend();

	std::cout << "Reverse iterator : ";
	while (lrit != lrite) {
		std::cout << *lrit << " ";
		++lrit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int> constList = list;

	std::list<int>::const_iterator lcit = constList.begin();
	std::list<int>::const_iterator lcite = constList.end();

	std::cout << "Const Forward iterator : ";
	while (lcit != lcite) {
		std::cout << *lcit << " ";
		++lcit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int>::const_reverse_iterator lcrit = list.rbegin();
	std::list<int>::const_reverse_iterator lcrite = list.rend();

	std::cout << "Const Reverse iterator : ";
	while (lcrit != lcrite) {
		std::cout << *lcrit << " ";
		++lcrit;
	}
	std::cout << std::endl;

	// ##############################################################################
	// ##############################################################################

	std::vector<int> vector;

	std::cout << BLUE << "\n### Testing Vector" << RESET << std::endl;
	std::cout << YELLOW << "vector.empty() : " << vector.empty() << RESET << std::endl;
	vector.push_back(0);
	std::cout << YELLOW << "vector.empty() : " << vector.empty() << RESET << std::endl;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	printElements(vector);
	vector.push_back(5);
	printElements(vector);

	std::cout << YELLOW << "vector.size() : " << vector.size() << RESET << std::endl;
	std::cout << YELLOW << "vector.front() : " << vector.front() << RESET << std::endl;
	std::cout << YELLOW << "vector.back() : " << vector.back() << RESET << std::endl;

	// ##############################################################################

	std::vector<int>::iterator vit = vector.begin();
	std::vector<int>::iterator vite = vector.end();

	std::cout << "Forward iterator : ";
	while (vit != vite) {
		std::cout << *vit << " ";
		++vit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::reverse_iterator vrit = vector.rbegin();
	std::vector<int>::reverse_iterator vrite = vector.rend();

	std::cout << "Reverse iterator : ";
	while (vrit != vrite) {
		std::cout << *vrit << " ";
		++vrit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::const_iterator vcit = vector.begin();
	std::vector<int>::const_iterator vcite = vector.end();

	std::cout << "Const Forward iterator : ";
	while (vcit != vcite) {
		std::cout << *vcit << " ";
		++vcit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::const_reverse_iterator vcrit = vector.rbegin();
	std::vector<int>::const_reverse_iterator vcrite = vector.rend();

	std::cout << "Const Reverse iterator : ";
	while (vcrit != vcrite) {
		std::cout << *vcrit << " ";
		++vcrit;
	}
	std::cout << std::endl;

	return (0);
}
