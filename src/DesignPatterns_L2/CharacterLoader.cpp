#include "CharacterLoader.h"

#include <fstream>

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;
using namespace l2::sys;

const bool CharacterLoader::LoadL2CharacterImage(Character * character, const string & path)
{
	std::string outBuffer;

	ifstream in;
	in.open(path.c_str());
	if (!in.is_open())
		return false;

	string header("");
	in >> header;
	if (header != "ENEMY_DATA")
		return false;

	in >> header;
	if (header != "COL")
		return false;
	char foregroundAscii;
	in >> foregroundAscii;
	character->model_.SetColor(Colorizer::GetInstance()->GetColorFromChar(foregroundAscii), Colorizer::Black);

	uint16_t w(0), h(0);
	in >> header;
	if (header != "WIDTH")
		return false;
	in >> w;
	in >> header;
	if (header != "HEIGHT")
		return false;
	in >> h;

	string data;
	char * line = new char[w + 1];

	in.seekg(2, ios::cur);
	for (uint16_t i = 0; i < h && !in.eof(); ++i)
	{
		ZeroMemory(line, sizeof(char)*(w + 1));
		in.getline(line, w + 1);
		size_t lineSize = strlen(line);
		memset(&line[lineSize], static_cast<int>(' '), sizeof(char)*(w - lineSize));
		data.append(line);
	}

	character->model_.SetDrawableData(data);
	character->model_.SetDrawableSpace(0, 0, w, h);
	delete line;

	in.close();

	return true;
}
