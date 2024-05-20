/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:24 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/20 19:33:40 by kdaumont         ###   ########.fr       */
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

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isOnTop(a, b, c, point))
		return (false);

	float ax = a.getX().toFloat(), ay = a.getY().toFloat();
	float bx = b.getX().toFloat(), by = b.getY().toFloat();
	float cx = c.getX().toFloat(), cy = c.getY().toFloat();
	float x = point.getX().toFloat(), y = point.getY().toFloat();
	
	float areaABP = ((ax - x) * (by - y) - (ay - y) * (bx - x));
    float areaBCP = ((bx - x) * (cy - y) - (by - y) * (cx - x));
    float areaCAP = ((cx - x) * (ay - y) - (cy - y) * (ax - x));

	if (areaABP == 0 || areaBCP == 0 || areaCAP == 0)
		return (false);

	return ((areaABP > 0 && areaBCP > 0 && areaCAP > 0) || (areaABP < 0 && areaBCP < 0 && areaCAP < 0));
}
