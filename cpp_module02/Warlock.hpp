#pragma once

#include <string>

#include "SpellBook.hpp"

class	ASpell;
class	ATarget;

class	Warlock
{
	private :
		std::string	_name;
		std::string	_title;
		SpellBook	_spellBook;

		Warlock(const Warlock& src);
		Warlock&	operator=(const Warlock& src);

	public :
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, const ATarget& target);

		const std::string& getName() const;
		const std::string& getTitle() const;
		void	setTitle(const std::string& title);
};