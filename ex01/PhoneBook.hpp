/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:16 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/10 19:31:20 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int 	contact_index;
		int		contact_count;

		int _is_valid_number(const std::string &str) const;
		int _is_valid_name(const std::string &str) const;
		int _get_next_index() const;
		int _ask(std::string question, Contact &contact, int index);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		add();
		void	search();
};

#endif