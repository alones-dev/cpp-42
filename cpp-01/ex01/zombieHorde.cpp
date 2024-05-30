/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:31:25 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/30 08:37:55 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0 || N > 500000)
        return (NULL);
    Zombie *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    
    return (horde);
}
