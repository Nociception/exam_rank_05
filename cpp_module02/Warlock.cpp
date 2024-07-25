#include <iostream>

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const Warlock& src) {*this = src;}

Warlock&	Warlock::operator=(const Warlock& src)
{
	this->_name = src.getName();
	this->_title = src.getTitle();

	return *this;
}

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	this->_spellBook.learnSpell(spell);
}
		
void	Warlock::forgetSpell(std::string spellName)
{
	this->_spellBook.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	if (this->_spellBook.createSpell(spellName)) // very important if protection ; otherwise, the line below leads to a potential segfault
		this->_spellBook.createSpell(spellName)->launch(target);
}

const std::string& Warlock::getName() const {return this->_name;}
const std::string& Warlock::getTitle() const {return this->_title;}
void	Warlock::setTitle(const std::string& title) {this->_title = title;}