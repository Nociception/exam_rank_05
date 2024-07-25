#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator& src) {*this = src;}

TargetGenerator&	TargetGenerator::operator=(const TargetGenerator& src)
{
	this->_book = src._book;

	return *this;
}

TargetGenerator::TargetGenerator() {}
		
TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string,ATarget*>::iterator it = this->_book.begin() ; it != this->_book.end() ; ++it)
		delete it->second;
	this->_book.clear();
}

void	TargetGenerator::learnTargetType(ATarget* type)
{
	if (type && !(this->_book.count(type->getType())))
		this->_book[type->getType()] = type->clone();
}
		
void	TargetGenerator::forgetTargetType(const std::string& type)
{
	if (this->_book.count(type))
		this->_book.erase(type);
}
		
ATarget*	TargetGenerator::createTarget(const std::string& type)
{
	if (this->_book.count(type))
		return this->_book[type];
	return NULL;
}