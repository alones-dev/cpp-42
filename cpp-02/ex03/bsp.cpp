/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:24 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/17 14:43:59 by kdaumont         ###   ########.fr       */
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

bool isOnLine(Point const a, Point const b, Point const point)
{
	
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// si point est sur un sommet -> false  OK
	// si point est entre deux sommets -> false
	// calcul de l'aire du triangle ABC
	// calcul de l'aire des triangles ABP, ACP, BCP
	// si la somme des aires des triangles ABP, ACP, BCP est égale à l'aire du triangle ABC -> true
	
	if (isOnTop(a, b, c, point))
		return (false);
	if (isOnLine(a, b, point))
		return (false);
		
	return (true);		
}
