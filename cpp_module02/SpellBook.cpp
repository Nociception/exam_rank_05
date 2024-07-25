#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook(const SpellBook& src) {*this = src;}

SpellBook&	SpellBook::operator=(const SpellBook& src)
{
	this->_book = src._book;

	return *this;
}

SpellBook::SpellBook() {}
		
SpellBook::~SpellBook()
{
	for (std::map<std::string,ASpell*>::iterator it = this->_book.begin() ; it != this->_book.end() ; ++it)
		delete it->second;
	this->_book.clear();
}

void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell && !(this->_book.count(spell->getName())))
		this->_book[spell->getName()] = spell->clone();
}
		
void	SpellBook::forgetSpell(const std::string& spellName)
{
	if (this->_book.count(spellName))
		this->_book.erase(spellName);
}
		
ASpell*	SpellBook::createSpell(const std::string& spellName)
{
	if (this->_book.count(spellName))
		return this->_book[spellName];
	return NULL;
}