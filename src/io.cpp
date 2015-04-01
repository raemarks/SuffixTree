#include "io.h"

#include <iostream>
#include <cstring>

#define MB 1024*1024

inline bool
notLineEnd(
	char c
	)
{
	return c != '\n' && c != '\r';
}

void
ReadInputFasta(
	std::ifstream &in,
	std::string& str,
	std::string& name
	)
{
	int BUFSIZE = 4 * MB;
	char buf[BUFSIZE], _name[MB/2], c = '\0';
	int i = 0;
	memset(buf, 0, BUFSIZE);

	// Skip over '>'
	while (c != '>' && !in.eof()) {
		in >> c;
	}

	in.getline(buf, BUFSIZE);
	// Get unique identifier of sequence, up to first whitespace
	sscanf(buf, "%s", _name);
	// Allocate and copy
	name = std::string(_name);

	i = 0;
	c = '\0';
	memset(buf, 0, BUFSIZE);

	in >> c;
	while (c != '>' && !in.eof()) {
		if (notLineEnd(c)) {
			buf[i++] = c;
		}
		in >> c;
	}
	str = std::string(buf);
}
