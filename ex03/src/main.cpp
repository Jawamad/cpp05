/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:32 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 13:25:40 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int	main()
{
	srand(time(0));
	std::cout << std::endl << "----########-test exec special form-########----"<< std::endl << std::endl;
	Bureaucrat director("Bernard", 1);
	Bureaucrat peon("Regis", 138);
	Bureaucrat randomGuy("bob", 45);
	Intern raymond;
	AForm *newform;
	try
	{
		newform = raymond.makeForm("bad name", "Robert");
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		newform = raymond.makeForm("shrubbery", "Robert");
		peon.signForm(*newform);
		std::cout << *newform << std::endl;
		director.executeForm(*newform);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	delete newform;
	return 0;
}