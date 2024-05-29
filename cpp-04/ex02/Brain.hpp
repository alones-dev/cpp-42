/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:15 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/29 09:11:37 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const &cpy);
		virtual ~Brain();
		
		Brain &operator=(Brain const &rhs);

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
	private:
		std::string _ideas[100];	
};

#endif
