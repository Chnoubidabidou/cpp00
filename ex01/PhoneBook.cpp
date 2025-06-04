/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:15 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/04 19:41:51 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	std::cout << "\033[1;32mPhonebook created\033[0m" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[1;32mPhonebook destroyed\033[0m" << std::endl;
}
