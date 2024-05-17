/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 13:06:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &cpy);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();
        
        Fixed &operator=(Fixed const &rhs);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif
