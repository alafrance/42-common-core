//
// Created by Alexis Lafrance on 26/09/2021.
//

#include "ShrubberyCreationForm.hpp"
#include <fstream>
/* CANONICAL FORM */
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("unknown", 0, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 0, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src) {
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &inst) {
	(void) inst;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	testExecute(executor.getGrade());
	std::cout << "create file\n";
	std::ofstream file(getName() + "_shrubbery");
	file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
	file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "              (_)  \\.-'.-/" << std::endl;
	file << "          __...--- |'-.-'| --...__" << std::endl;
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	file << " -\"    ' .  . '    |.'-._| '  . .  '   alaf" << std::endl;
	file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	file << "          ' ..     |'-_.-|" << std::endl;
	file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	file << "              .'   |'- .-|   '." << std::endl;
	file << "  ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl;
	file << "   .-' '        '-._______.-'     '  ." << std::endl;
	file << "        .      ~," << std::endl;
	file << "    .       .   |\\   .    ' '-." << std::endl;
	file << "    ___________/  \\____________" << std::endl;
	file << "   /  Why is it, when you want \\" << std::endl;
	file << "  |  something, it is so damn   |" << std::endl;
	file << "  |    much work to get it?     |" << std::endl;
	file << "   \\___________________________/" << std::endl;
}
/* ACCESSORS */

/* MAIN */