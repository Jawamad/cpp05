/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:32 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/30 17:10:35 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int	main()
{
	srand(time(0));
	std::cout << std::endl << "----########-test exec special form-########----"<< std::endl << std::endl;
	Bureaucrat director("Bernard", 1);
	Bureaucrat peon("Regis", 138);
	Bureaucrat randomGuy("bob", 45);
	try
	{
		std::cout << std::endl << "########-test exec shrubbery director with bureaucrat exec form members function-########"<< std::endl << std::endl;
		ShrubberyCreationForm shrubbery("special_field");
		std::cout << director << std::endl;
		std::cout << shrubbery << std::endl;
		director.signForm(shrubbery);
		director.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test exec shrubbery director-########"<< std::endl << std::endl;
		ShrubberyCreationForm shrubbery("field");
		std::cout << director << std::endl;
		std::cout << shrubbery << std::endl;
		director.signForm(shrubbery);
		shrubbery.execute(director);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test exec shrubbery peon-########"<< std::endl << std::endl;
		ShrubberyCreationForm shrubbery("field");
		std::cout << peon << std::endl;
		std::cout << shrubbery << std::endl;
		peon.signForm(shrubbery);
		shrubbery.execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test exec shrubbery random guy-########"<< std::endl << std::endl;
		ShrubberyCreationForm shrubbery("field");
		std::cout << randomGuy << std::endl;
		std::cout << shrubbery << std::endl;
		randomGuy.signForm(shrubbery);
		shrubbery.execute(randomGuy);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test director exec presidential pardon-########"<< std::endl << std::endl;
		std::cout << director << std::endl;
		PresidentialPardonForm pardon("regis");
		std::cout << pardon << std::endl;
		director.signForm(pardon);
		pardon.execute(director);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test peon exec presidential pardon with exec form member -########"<< std::endl << std::endl;
		std::cout << peon << std::endl;
		PresidentialPardonForm pardon("regis");
		std::cout << pardon << std::endl;
		director.signForm(pardon);
		peon.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test peon exec presidential pardon-########"<< std::endl << std::endl;
		std::cout << peon << std::endl;
		PresidentialPardonForm pardon("regis");
		std::cout << pardon << std::endl;
		peon.signForm(pardon);
		pardon.execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test random guy exec presidential pardon-########"<< std::endl << std::endl;
		std::cout << randomGuy << std::endl;
		PresidentialPardonForm pardon("regis");
		std::cout << pardon << std::endl;
		randomGuy.signForm(pardon);
		pardon.execute(randomGuy);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test director exec robotomy-########"<< std::endl << std::endl;
		std::cout << director << std::endl;
		RobotomyRequestForm random("Russian roulette");
		std::cout << random << std::endl;
		director.signForm(random);
		random.execute(director);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test peon exec robotomy-########"<< std::endl << std::endl;
		std::cout << peon << std::endl;
		RobotomyRequestForm random("Russian roulette");
		std::cout << random << std::endl;
		peon.signForm(random);
		random.execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test random guy exec robotomy-########"<< std::endl << std::endl;
		std::cout << randomGuy << std::endl;
		RobotomyRequestForm random("Russian roulette");
		std::cout << random << std::endl;
		randomGuy.signForm(random);
		random.execute(randomGuy);
	}
	catch(const std::exception& e)
	{
		std::cerr << "⚠️   Error: " << e.what() << '\n';
	}
	return 0;
}