/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:52:50 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:02 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    std::cout << "Triangle with integer coordinates" << std::endl;
	if (bsp(Point(0, 0), Point(50, 100), Point(100, 0), Point(50, 50))) {
        std::cout << "Point is in the triangle" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
    }
    std::cout << "Triangle with float coordinates" << std::endl;
    if (bsp(Point(0.5f, 0.5f), Point(1.5f, 1.0f), Point(2.0f, 0.5f), Point(1.0f, 0.75f))) {
        std::cout << "Point is in the triangle" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
    }
    std::cout << "Triangle with combination of integer and float coordinates" << std::endl;
    if (bsp(Point(0.5f, 0), Point(46.0f, 100), Point(97.89f, 0), Point(35.0f, 48.5f))) {
        std::cout << "Point is in the triangle" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
    }
    return (0);
}
