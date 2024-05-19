/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:43:53 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/19 22:28:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(Point const &cpy);
		~Point();

		Point &operator=(Point const &rhs);

		Fixed getX() const;
		Fixed getY() const;
		float getXFloat() const;
		float getYFloat() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
