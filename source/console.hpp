
#include <string>

#include "coord.hpp"

void set_title(std::string title);
void set_buffer(coord buffer);
void set_size(coord size);
void set_font(std::wstring type, coord size);

void set_cursor(coord position = {0, 0});
