#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, float> _database;

 public:
  const static std::string _databaseFilepath;

 private:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);

  static void calculate(const std::string& filepath);

  // EXCEPTIONS
  //  Error: could not open file.
  //  Error: not a positive number.
  //  Error: bad input => 2001-42-42
  //  Error: too large a number.
};

#endif
