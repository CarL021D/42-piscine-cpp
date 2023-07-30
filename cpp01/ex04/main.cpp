/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:51 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/29 18:55:57 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "4 arguments required!" << std::endl;
		return 1;
	}

	std::ifstream infile(av[1]);
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (!infile.is_open()) {
		std::cerr << "Error: failed to open file!" << std::endl;
		return 1;
	}

	std::ofstream outfile((std::string(av[1]) + ".replace").c_str());
	std::string line;

	 while (std::getline(infile, line)) {
		size_t pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << line << '\n';
	}

	infile.close();
	outfile.close();
	std::cout << "Find and replace operation completed successfully!" << std::endl;
	return 0;
}
