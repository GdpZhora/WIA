#ifndef GLEVEL_H
#define GLEVEL_H

class LevelClass
{
public:
	LevelClass();
	bool LoadMap(char* filename);
	char filemap[40];
	char filetrassa[40];
	char fileworld[40];
	char filetexmap[40];
	char filetextrassa[40];
	char foldertexworld[40];

private:
};

#endif
