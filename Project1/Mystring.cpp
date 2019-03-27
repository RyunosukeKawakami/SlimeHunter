#include "Mystring.h"

Mystring::Mystring(Point temp, const char* temp_str, int temp_color, const char* temp_font, int thick)
{
	p = temp;
	str = temp_str;
	color = temp_color;
	font = CreateFontToHandle(temp_font, thick, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

};

Mystring::~Mystring() { DeleteFontToHandle(font); };

void Mystring::Draw() {
	DrawStringToHandle(p.x, p.y,str,color,font);
};

Point Mystring::SetPoint(){return p;}