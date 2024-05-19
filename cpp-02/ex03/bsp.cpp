/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:44:24 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/19 22:30:10 by kdaumont         ###   ########.fr       */
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
	float deltaX = b.getX().toFloat() - a.getX().toFloat();
    float deltaY = b.getY().toFloat() - a.getY().toFloat();
    
    if (deltaX == 0 && deltaY == 0) 
        return point.getX().toFloat() == a.getX().toFloat() && point.getY().toFloat() == a.getY().toFloat();
    
    float tX = (point.getX().toFloat() - a.getX().toFloat()) / deltaX;
    float tY = (point.getY().toFloat() - a.getY().toFloat()) / deltaY;

    return (tX == tY) && (tX >= 0 && tX <= 1);
}

float	areaTriangle(Point const a, Point const b, Point const c)
{
	float area = 0;
	area = (a.getXFloat() * (b.getXFloat() - c.getXFloat()) + b.getXFloat() * (c.getXFloat() - a.getXFloat()) + c.getXFloat() * (a.getXFloat() - b.getXFloat())) / 2;
	return (area);
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

	float ABC = areaTriangle(a, b, c);
	float ABP = areaTriangle(a, b, point);
	float ACP = areaTriangle(a, c, point);
	float BCP = areaTriangle(b, c, point);
		
	return (ABC == (ABP + ACP + BCP));		
}
