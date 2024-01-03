#include <iostream>
#include <fstream>

char	*readFile(std::string filename) {
	std::ifstream ifs(filename);
	int length;
	char *buf;

	if (!ifs.is_open())
	{
		std::cout << "ERROR FILESTREAM" << std::endl;
		return (NULL);
	}
	ifs.seekg(0, ifs.end);
	length = ifs.tellg();
	buf = new char[length + 1];
	ifs.seekg(0, ifs.beg);
	ifs.read(buf, length);
	buf[length] = '\0';
	ifs.close();
	return (buf);
}

void	replace(std::string filename, std::string s1, std::string s2)
{
	char *buf;
	size_t pos = 0;
	if (!(buf = readFile(filename))) // READ FILE IN BUFFER
		return ;

	std::string newFilename;
	std::string file(buf); // CAST BUFFER INTO STD::STRING TO DO INSERT AND ERASE
	newFilename = filename.substr(0, filename.find_last_of(".")) + ".replace"; // CREATE FILENAME.REPLACE
  	std::ofstream ofs (newFilename);
	while ((pos = file.find(s1, pos)) != std::string::npos)
	{
		file.erase(pos, s1.size());
		file.insert(pos, s2);
		pos += s2.length();
	}
	ofs << file;
	ofs.close();
	delete [] buf;
}

int main(int ac, char **av) {
	if (ac != 4)
	{
		std::cout << "ERROR ARGUMENT" << std::endl;
		return (1);
	}
	replace(av[1], av[2], av[3]);
	return (0);    
}