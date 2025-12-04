#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
 public:
  static std::map<std::string, std::string> database;
  static std::map<std::string, std::string> input;

 private:
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  BitcoinExchange();
  ~BitcoinExchange();

 public:
  static void calculate(const std::string& filepath);

  // EXCEPTIONS
  //  Error: could not open file.
  //  Error: not a positive number.
  //  Error: bad input => 2001-42-42
  //  Error: too large a number.
};

#endif
