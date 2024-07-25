#pragma once

#include <map>
#include <string>

class ASpell;

class	SpellBook
{
	private :
		std::map<std::string,ASpell*>	_book;

		SpellBook(const SpellBook& src);
		SpellBook&	operator=(const SpellBook& src);

	public :
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spellName);
		ASpell*	createSpell(const std::string& spellName);
};