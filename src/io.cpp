#include "io.h"

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
	char buf[MB], _name[MB/2], c = '\0';
	int i = 0;
	memset(buf, 0, MB);

	// Skip over '>'
	while (c != '>') {
		in >> c;
	}

	in.getline(buf, MB);
	// Get unique identifier of sequence, up to first whitespace
	sscanf(buf, "%s", _name);
	// Allocate and copy
	name = std::string(_name);

	i = 0;
	c = '\0';
	while (c != '>') {
		if (notLineEnd(c)) {
			buf[i++] = c;
		}
		in >> c;
	}
	str = std::string(buf);
}
