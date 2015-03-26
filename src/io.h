#ifndef IO_H
#define IO_H

#include <cstdio>
#include <fstream>
#include <string>

void
ReadInputFasta(
	std::ifstream &in,
	std::string& str,
	std::string& name
	);

#endif
