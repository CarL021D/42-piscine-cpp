/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:41:44 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:41:45 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		for (unsigned int j = 0; av[i][j]; j++)
		{
			if (islower(av[i][j]))
				std::cout << (char)toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
}