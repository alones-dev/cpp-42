/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:51:31 by kdaumont          #+#    #+#             */
/*   Updated: 2024/05/13 23:03:01 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "\033[1;36mAddress of the string: \033[0m" << &str << std::endl;
    std::cout << "\033[1;36mAddress of the stringPTR: \033[0m" << stringPTR << std::endl;
    std::cout << "\033[1;36mAddress of the stringREF: \033[0m" << &stringREF << std::endl;

    std::cout << "\033[1;36mValue of the string: \033[0m" << str << std::endl;
    std::cout << "\033[1;36mValue of the stringPTR: \033[0m" << *stringPTR << std::endl;
    std::cout << "\033[1;36mValue of the stringREF: \033[0m" << stringREF << std::endl;

    return (0);
}