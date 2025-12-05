#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
 public:
  static std::map<std::string, std::string> database;

 private:
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  BitcoinExchange();
  ~BitcoinExchange();

 public:
  static void calculate(const std::string& filepath);
};

#endif
