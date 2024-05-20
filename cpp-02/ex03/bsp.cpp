/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:24 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/20 13:21:23 by kdaumont         ###   ########.fr       */
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
	
}
