/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:10:10 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 15:59:42 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename C>
void handleContainer(const C& container, int target) {
	try {
		easyfind(container, target);
		std::cout << GREEN << "Found " << target << " in container." << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught : " << e.what() << RESET << std::endl;
	}
}

template <typename C>
void printElements(const C& container) {
	std::cout << "Elements : ";
	typename C::const_iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool checkArgument(const char *string) {
	if (!string || *string == '\0')
		return false;

	while (isspace(*string))
		string++;

	if (*string == '-' || *string == '+')
		string++;

	if (!isdigit(*string))
		return false;

	while (isdigit(*string))
		string++;

	while (isspace(*string))
		string++;

	return (*string == '\0');
}

int main(int argc, char **argv) {
	if (argc != 2 || !checkArgument(argv[1])) {
		std::cout << "Usage : ./easyfind <integer>" << std::endl;
		return (1);
	}

	int target = atoi(argv[1]);
	std::srand(std::time(0));

	std::cout << YELLOW << "### Testing Vector" << RESET << std::endl;
	std::vector<int> numbersVector(10);
	for (std::vector<int>::iterator it = numbersVector.begin(); it != numbersVector.end(); ++it) {
		*it = std::rand() % 21 - 10;
	}
	printElements(numbersVector);
	handleContainer(numbersVector, target);

	std::cout << YELLOW << "\n### Testing List" << RESET << std::endl;
	std::list<int> numbersList(10);
	for (std::list<int>::iterator it = numbersList.begin(); it != numbersList.end(); ++it) {
		*it = std::rand() % 11;
	}
	printElements(numbersList);
	handleContainer(numbersList, target);

	std::cout << YELLOW << "\n### Testing Deque" << RESET << std::endl;
	std::deque<int> numbersDeque(10);
	for (std::deque<int>::iterator it = numbersDeque.begin(); it != numbersDeque.end(); ++it) {
		*it = std::rand() % 11;
	}
	printElements(numbersDeque);
	handleContainer(numbersDeque, target);

	return (0);
}
