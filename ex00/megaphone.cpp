/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:01:17 by lgrisel           #+#    #+#             */
/*   Updated: 2025/05/28 17:01:18 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int i = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[++i])
		{
			int j = -1;
			while (av[i][++j])
			{
				if (std::isalpha(av[i][j]))
					std::cout << (char)std::toupper(av[i][j]);
				else
					std::cout << av[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
