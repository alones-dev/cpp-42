/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:24 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/21 21:02:33 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool isOnTop(Point const a, Point const b, Point const c, Point const point)
{
	if (a.getX() == point.getX() && a.getY() == point.getY())
		return (true);
	if (b.getX() == point.getX() && b.getY() == point.getY())
		return (true);
	if (c.getX() == point.getX() && c.getY() == point.getY())
		return (true);
	return (false);
}

Fixed abs(Fixed const a)
{
	return (a < 0 ? (a * -1) : a);
}

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area = abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isOnTop(a, b, c, point))
		return (false);

	Fixed abc = abs(area(a, b, c));
	Fixed abp = abs(area(a, b, point));
	Fixed acp = abs(area(a, c, point));
	Fixed bcp = abs(area(b, c, point));

	if (abc == abp + acp + bcp)
		return (true);
	return (false);
}
