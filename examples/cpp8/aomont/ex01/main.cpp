/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:33:18 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 16:25:42 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

bool checkArgument(const char *string) {
	if (!string || *string == '\0')
		return false;

	while (isspace(*string))
		string++;

	if (*string == '-' || *string == '+')
		string++;

	const char *start = string;

	while (isdigit(*string))
		string++;

	while (isspace(*string))
		string++;

	return (*string == '\0' && string != start);
}

int main(int argc, char **argv) {
	if (argc != 2 || !checkArgument(argv[1])) {
		std::cout << "Usage : ./Span <number of elements>" << std::endl;
		return (1);
	}

	int N = std::atoi(argv[1]);
	std::srand(std::time(0));

	if (N < 0 || static_cast<unsigned long>(N) > static_cast<unsigned long>(INT_MAX)) {
		std::cerr << RED << "Error : number of elements < INT_MAX" << RESET << std::endl;
		return (1);
	}

	std::cout << YELLOW << "### Testing addNumber() method" << RESET << std::endl;
	Span single(N);
	try {
		for (int i = 0; i < N; ++i) {
			single.addNumber(std::rand() % 1000);
		}

		std::cout << "Content			:	";
		const std::vector<int>& elements = single.getStorage();
		for (size_t i = 0; i < elements.size(); ++i) {
			std::cout << elements[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Number of elements (N)	:	" << N << std::endl;
		std::cout << "Shortest Span		:	" << single.shortestSpan() << std::endl;
		std::cout << "Longest Span		:	" << single.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// std::cout << YELLOW << "### Testing addNumber() range" << RESET << std::endl;
	// Span range(N);
	// std::vector<int> random;
	// try {
	// 	for (int i = 0; i < N; ++i) {
	// 		random.push_back(std::rand() % 100);
	// 	}

	// 	std::cout << "Content			:	";
	// 	for (std::vector<int>::iterator it = random.begin(); it != random.end(); ++it) {
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;

	// 	range.addNumber(random.begin(), random.end());

	// 	std::cout << "Number of elements (N)	:	" << N << std::endl;
	// 	std::cout << "Shortest Span		:	" << range.shortestSpan() << std::endl;
	// 	std::cout << "Longest Span		:	" << range.longestSpan() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << RED << "Exception caught : " << e.what() << RESET << std::endl;
	// }
}
