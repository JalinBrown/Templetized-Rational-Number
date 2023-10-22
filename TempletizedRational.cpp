/******************************************************************************
* \filename    TempletizedRational.cpp
* \author      Jalin Brown
* \email       jalinbrownworks@gmail.com

Brief Description:
Templetize class Rational from the previous assignment.
Assume that class T (the template parameter) can do all required arithmetic:
addition, subtraction, division, and multiplication.

******************************************************************************/

#include "TempletizedRational.h"
#include <iomanip>  // setw
#include <cstdlib>  // abs

namespace Rational {

  /*
   * @brief Rational Width Constructor - CTOR
   *
   * Initializes the static member 'width' to 0, which indicates no padding
   * by default for output formatting.
   */
  template < typename T>
  int Rational<T>::width = 0; // no padding by default

  //---------------------------------------------------------------------------
  
  /*
   * @brief Default constructor for Rational
   *
   * Creates a Rational object with default values (0/1).
   */
  template < typename T>
  Rational<T>::Rational() : n(0), d(1) {}

  //---------------------------------------------------------------------------

  /*
   * @brief Rational with an integer value - CTOR
   *
   * Creates a Rational object with the provided integer value
   * and a denominator of 1.
   *
   * @param i - Integer value for the numerator
   */
  template < typename T>
  Rational<T>::Rational(T i) : n(i), d(1) {}
  
  //---------------------------------------------------------------------------

  /*
   * @brief Rational with a numerator and denominator - CTOR
   *
   * Creates a Rational object with the provided numerator and denominator
   * values.It also checks and adjusts the sign and simplifies the fraction.
   *
   * @param _n - Numerator
   * @param _d - Denominator
   */
  template < typename T>
  Rational<T>::Rational(T _n, T _d) : n(_n), d(_d) { CheckSign(); CheckGCD(); }

  //---------------------------------------------------------------------------

  /*
   * @brief CheckSign
   * 
   * Check and adjust the sign of the Rational object
   * If the denominator is negative, it changes the sign of both the numerator
   * and denominator.
   */
  template < typename T>
  void Rational<T>::CheckSign()
  {
    if (d < 0)
    {
      n *= -1;
      d *= -1;
    }
  }

  //---------------------------------------------------------------------------

  /*
   * @brief CheckGCD
   * 
   * Simplify the Rational object by finding the greatest common divisor (GCD)
   * Reduces the Rational object to its simplest form by dividing both
   * the numerator and denominator by their GCD.
   */
  template < typename T>
  void Rational<T>::CheckGCD()
  {
    int gcd = GCD();
    n = n / gcd;
    d = d / gcd;
  }

  //---------------------------------------------------------------------------

  /*
   * @brief GCD
   * 
   * Calculate the greatest common divisor (GCD)
   * Finds the greatest common divisor of the numerator and denominator
   * using Euclidean algorithm.
   *
   * @return GCD of the numerator and denominator
   */
  template < typename T>
  int Rational<T>::GCD() const
  {
    int a = std::abs(n), b = std::abs(d);
    while (a && b)
    {
      if (a < b)
      {
        b = b % a;
      }
      else
      {
        a = a % b;
      }
    }
    if (a == 0)
    {
      return b;
    }
    else
    {
      return a;
    }
  }

  //---------------------------------------------------------------------------

  /*
   * @brief Implementations of operator overloads in the following functions
   *
   * =
   * -
   * +=
   * +
   * -=
   * -
   * *
   * *=
   * /=
   * /
   * ==
   * >
   * <
   * !=
   * >=
   * <=
   * numerator()
   * denomenator()
   *
   * @return The appropriate value corresponding to the operation.
   */

   /////////////////////////////////////////////////////////////////////////////
   // =
   /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T>& Rational<T>::operator=(Rational<T> const& rhs)
  {
    this->n = rhs.n; // same thing as next line
    this->d = rhs.d;    //n = rhs.n; 

    return *this;
  }

  /////////////////////////////////////////////////////////////////////////////
  // -
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T> Rational<T>::operator-() const
  {
    return Rational(-n, d);
  }

  /////////////////////////////////////////////////////////////////////////////
  // +=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T>& Rational<T>::operator+=(Rational<T> const& rhs)
  {
    this->n = ((this->n) * rhs.d) + ((this->d) * (rhs.n));
    this->d = this->d * rhs.d;

    CheckGCD();
    CheckSign();

    return *this;
  }

  /////////////////////////////////////////////////////////////////////////////
  // +
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T> Rational<T>::operator+(Rational<T> const& rhs) const
  {
    Rational<T> temp = *this;

    temp += rhs;

    return temp;
  }

  /////////////////////////////////////////////////////////////////////////////
  // -=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T>& Rational<T>::operator-=(Rational<T> const& rhs)
  {
    return *this += -rhs;
  }

  /////////////////////////////////////////////////////////////////////////////
  // -
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T> Rational<T>::operator-(Rational<T> const& rhs) const
  {
    Rational<T> temp = *this;

    temp -= rhs;

    return temp;
  }

  /////////////////////////////////////////////////////////////////////////////
  // *
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T>& Rational<T>::operator*=(Rational<T> const& rhs)
  {
    this->n = this->n * rhs.n;
    this->d = this->d * rhs.d;
    CheckGCD();

    return *this;
  }

  /////////////////////////////////////////////////////////////////////////////
  // *=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T> Rational<T>::operator*(Rational<T> const& rhs) const
  {
    Rational<T> temp = *this;

    temp *= rhs;

    return temp;
  }

  /////////////////////////////////////////////////////////////////////////////
  // /=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T>& Rational<T>::operator/=(Rational<T> const& rhs)
  {
    this->n = this->n * rhs.d;
    this->d = this->d * rhs.n;

    CheckGCD();

    return *this;
  }

  /////////////////////////////////////////////////////////////////////////////
  // /
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  Rational<T> Rational<T>::operator/(Rational<T> const& rhs) const
  {
    Rational<T> temp = *this;

    temp /= rhs;

    return temp;
  }

  /////////////////////////////////////////////////////////////////////////////
  // ==
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator==(Rational<T> const& rhs) const
  {
    return((this->n == rhs.n) && (this->d == rhs.d));
  }

  /////////////////////////////////////////////////////////////////////////////
  // >
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator>(Rational<T> const& rhs) const
  {
    return(this->n * rhs.d > rhs.n * this->d);
  }

  /////////////////////////////////////////////////////////////////////////////
  // <
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator<(Rational<T> const& rhs) const
  {
    return(this->n * rhs.d < rhs.n * this->d);
  }

  /////////////////////////////////////////////////////////////////////////////
  // !=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator!=(Rational<T> const& rhs) const
  {
    return !(rhs == *this);
  }

  /////////////////////////////////////////////////////////////////////////////
  // >=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator>=(Rational<T> const& rhs) const
  {
    return(*this > rhs || *this == rhs);
  }

  /////////////////////////////////////////////////////////////////////////////
  // <=
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  bool Rational<T>::operator<=(Rational<T> const& rhs) const
  {
    return(*this < rhs || *this == rhs);
  }

  /////////////////////////////////////////////////////////////////////////////
  // numerator()
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  T Rational<T>::numerator() const
  {
    return this->n;
  }

  /////////////////////////////////////////////////////////////////////////////
  // denominator()
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  T Rational<T>::denominator() const
  {
    return this->d;
  }

}
