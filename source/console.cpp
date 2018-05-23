
#include <windows.h>

#include "console.hpp"

using namespace std;

static HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
static HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);

void set_title(string title)
{
    TCHAR *tit = new TCHAR[title.size() + 1];
    tit[title.size()] = 0;
    copy(title.begin(), title.end(), tit);

    SetConsoleTitle(tit);

    delete tit;
}

void set_buffer(coord buffer)
{
    _COORD buf = {(SHORT)buffer.x, (SHORT)buffer.y};
    SMALL_RECT rect = {0, 0, 1, 1};
    SetConsoleWindowInfo(handle_out, true, &rect);
    SetConsoleScreenBufferSize(handle_out, buf);
}

void set_size(coord size)
{
    SMALL_RECT rect = {0, 0, (SHORT)size.x, (SHORT)size.y};
    SetConsoleWindowInfo(handle_out, true, &rect);
}

void set_font(wstring type, coord size)
{
    CONSOLE_FONT_INFOEX info;
    info.cbSize = sizeof info;
    info.nFont = 0;
    info.dwFontSize.X = (SHORT)size.x;
    info.dwFontSize.Y = (SHORT)size.y;
    info.FontFamily = FF_DONTCARE;
    info.FontWeight = FW_NORMAL;
    
    wcscpy_s(info.FaceName, type.c_str());
    SetCurrentConsoleFontEx(handle_out, FALSE, &info);
}

void set_cursor(coord position)
{
    COORD pos = {(SHORT)position.x, (SHORT)position.y};
    SetConsoleCursorPosition(handle_out, pos);
}
