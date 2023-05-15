/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:20 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:21 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str; 

    std::cout << &str << std::endl;
    std::cout << strPTR << std::endl;
    std::cout << &strREF << std::endl;

    std::cout << str << std::endl;
    std::cout << *strPTR << std::endl;
    std::cout << strREF << std::endl;
}
