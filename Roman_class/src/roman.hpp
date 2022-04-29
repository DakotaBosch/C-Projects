/**
 * @class Roman
 * @brief Stores a number as a Roman numeral string.
 */

#ifndef ROMAN_H
#define ROMAN_H

#include <string>

class Roman {
   private:
      std::string romanStr;   /**< Roman numeral string */
   public:
      Roman();
      Roman(std::string);
      Roman(int);
      ~Roman();
      void SetRoman(std::string);
      void SetRoman(int);
      std::string GetRoman() const;
      int GetInt() const;
      void IncreaseWith(const Roman &);
};

#endif

