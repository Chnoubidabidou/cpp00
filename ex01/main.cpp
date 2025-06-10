/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:13 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/10 19:29:52 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int	main(void)
{
	std::string	command;
	PhoneBook	book;

	while (1)
	{
		std::cout << "Enter a command > ";
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			break;
		}
		if (command == "EXIT" || command == "exit")
			break;
		else if (command == "ADD" || command == "add")
		{
			if (book.add())
				break;
		}
		// else if (command == "SEARCH" || command == "search")
		// 	book.search();
		else
			std::cout << "\033[1;31mInvalid command: Command list: ADD, SEARCH or EXIT\033[0m" << std::endl;
	}
	return (0);
}
