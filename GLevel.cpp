#include"main.h"

LevelClass::LevelClass()
{

};

bool LevelClass::LoadMap(char* filename)
{	
	ifstream infile;
	infile.open(filename);
	if(!infile) return false;
//	char tmp[40];
	infile>>filemap;
//	filemap=tmp;
	infile>>filetrassa;
//	filetrassa=tmp;
	infile>>fileworld;
//	fileworld=tmp;
	infile>>filetexmap;
//	filetexmap=tmp;
	infile>>filetextrassa;
//	filetextrassa=tmp;
	infile>>foldertexworld;
//	foldertexworld=tmp;
	infile.close();
	ofstream OutFile;
	OutFile.open("Debug1.log");
	OutFile<<filemap<<endl<<filetrassa<<endl<<fileworld;
	OutFile.close();
	return true;
};