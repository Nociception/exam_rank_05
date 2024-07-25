#pragma once

#include <map>
#include <string>

class ATarget;

class	TargetGenerator
{
	private :
		std::map<std::string,ATarget*>	_book;

		TargetGenerator(const TargetGenerator& src);
		TargetGenerator&	operator=(const TargetGenerator& src);

	public :
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget* spell);
		void	forgetTargetType(const std::string& type);
		ATarget*	createTarget(const std::string& type);
};