/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomont <aomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:33:22 by aomont            #+#    #+#             */
/*   Updated: 2025/09/08 14:33:23 by aomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(size_t N) : _maxSize(N) {
	_storage.reserve(N);
}

Span::Span(const Span& source) {
	*this = source;
}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		_maxSize = rhs._maxSize;
		_storage = rhs._storage;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_storage.size() >= _maxSize) {
		throw storageException();
	}
	_storage.push_back(number);
}

// int Span::longestSpan() const {
// 	if (_storage.size() <= 1) {
// 		throw spanException();
// 	}

// 	int min = _storage[0];
// 	int max = _storage[0];

// 	for (size_t i = 1; i < _storage.size(); ++i) {
// 		if (_storage[i] < min) {
// 			min = _storage[i];
// 		}
// 		if (_storage[i] > max) {
// 			max = _storage[i];
// 		}
// 	}
// 	return max - min;
// }

int Span::longestSpan() const {
	if (_storage.size() <= 1) {
		throw spanException();
	}

	int min = *std::min_element(_storage.begin(), _storage.end());
	int max = *std::max_element(_storage.begin(), _storage.end());

	return max - min;
}

int Span::shortestSpan() const {
	if (_storage.size() <= 1) {
		throw spanException();
	}

	std::vector<int> sorted = _storage;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < _storage.size() - 1; i++) {
		int current = sorted[i + 1] - sorted[i];

		if (current < shortest) {
			shortest = current;
		}
	}
	return shortest;
}

const std::vector<int>& Span::getStorage() const {
	return _storage;
}
