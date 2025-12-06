#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define UNUSED -1

#include <algorithm>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

void generateJacobsthalSequence(std::vector<size_t>& vec);
void swap(int& a, int& b);
// #define A 0 // Index for the smaller element (Loser in the next step)
// #define B 1 // Index for the larger element (Winner for recursion)

template <template <typename> class Container, typename T>
void print(const Container<T>& nums) {
  for (typename Container<T>::const_iterator it = nums.begin(); it < nums.end();
       it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <template <typename> class Container, typename T>
static void parse(Container<T>& nums, const char** argv) {
  std::stringstream stream;
  std::string merged;
  int num;

  for (int i = 0; argv[i] != NULL; i++) merged = merged + argv[i] + " ";
  stream << merged;
  while (stream >> num) {
    if (num < 0) throw "Error: negative number";
    if (std::find(nums.begin(), nums.end(), num) != nums.end())
      throw "Error: duplicate";
    nums.push_back(num);
  }
  if (!stream.eof()) throw "Error: not a number";
}

template <template <typename> class Container, typename T>
static void createPairs(Container<T>& nums,
                        Container<std::pair<T, T> >& pairs) {
  size_t numPairs = std::ceil(nums.size() / 2.0);
  int loser = 0;
  int winner = 0;
  for (size_t i = 0; i < numPairs; i++) {
    if ((2 * i + 1) == nums.size()) {
      loser = UNUSED;
      winner = nums[2 * i];
    } else {
      loser = nums[2 * i];
      winner = nums[2 * i + 1];
    }
    loser > winner ? swap(loser, winner) : (void)NULL;
    pairs.push_back(std::pair<T, T>(loser, winner));
  }
}

template <template <typename> class Container, typename T>
static void binarySearchInsert(Container<T>& S, const int number) {
  int start, middle, end;

  start = 0;
  end = S.size() - 1;
  while (start <= end) {
    middle = start + (end - start) / 2;
    if (number > S[middle])
      start = middle + 1;
    else
      end = middle - 1;
  }
  S.insert(S.begin() + start, number);
}

template <template <typename> class Container, typename T>
static void sortLosers(Container<T>& S, const size_t& n,
                       Container<std::pair<T, T> >& pairs) {
  std::vector<size_t> jacobSequence(pairs.size());

  generateJacobsthalSequence(jacobSequence);

  // insert L1 seprately
  if (pairs.size() > 0 && pairs[0].first != UNUSED)
    binarySearchInsert(S, pairs[0].first);
  for (size_t i = 1; i < jacobSequence.size(); i++) {
    size_t end = jacobSequence[i] - 1;
    size_t start = jacobSequence[i - 1];

    if (end >= pairs.size()) end = pairs.size() - 1;

    for (size_t k = end; k >= start; k--) {
      if (k >= pairs.size()) continue;

      if (pairs[k].first == UNUSED) continue;
      binarySearchInsert(S, pairs[k].first);
      if (S.size() == n) return;
    }
  }
}

template <template <typename> class Container, typename T>
static void mergeInsertionSort(Container<T>& nums) {
  size_t n = nums.size();
  if (n <= 1) return;  // base case

  // create Local Pairs
  Container<std::pair<T, T> > pairs;
  createPairs(nums, pairs);

  // add elements to Local Main Chain Winners
  Container<T> W;
  for (typename Container<std::pair<T, T> >::iterator it = pairs.begin();
       it < pairs.end(); it++) {
    if (it->first != UNUSED) W.push_back(it->second);
  }
  // recursion
  mergeInsertionSort(W);  // W becomes new nums

  // handle odd element
  int oddElement = UNUSED;
  if (n % 2 != 0) oddElement = pairs.back().second;
  if (oddElement != UNUSED) {
    binarySearchInsert(W, oddElement);
  }
  // handle Local Losers
  sortLosers(W, n, pairs);

  // assign to previous coil to W current W
  nums = W;
}

template <typename T>
struct ContainerType {
  static const char* name() { return "Unknown"; }
};

template <typename T>
struct ContainerType<std::vector<T> > {
  static const char* name() { return "std::vector"; }
};

template <typename T>
struct ContainerType<std::deque<T> > {
  static const char* name() { return "std::deque"; }
};

template <template <typename> class Container, typename T>
void sort(const char** argv, bool printOneTime) {
  Container<T> nums;
  std::clock_t start, end;

  parse(nums, argv);
  if (printOneTime) std::cout << "Before: ", print(nums);
  start = std::clock();
  mergeInsertionSort(nums);
  end = std::clock();
  if (printOneTime) std::cout << "After: ", print(nums), printOneTime = true;
  std::cout << "Time to process a range of " << nums.size() << " elements with "
            << ContainerType<Container<T> >::name() << ": "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC * 10e6 << " us"
            << std::endl;
}
#endif
