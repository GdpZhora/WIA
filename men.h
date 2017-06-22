/*#ifndef MEN_H
#define MEN_H



class men
{
public:
	D3DXMESHCONTAINER_EX *Mesh;//меш человека
	ID3DXMesh *pMeshToDraw //меш человека для визуализации
	D3DXFRAME_EX *Hierarhy;//иерархия костей человека
	D3DXVECTOR3 Pos;//позиция
	int Anime;//вид текущей анимации
	int TimeAnime;//время анимации
	int RepeatNeed;//количество необходимых повторов
	int RepeatFact;//сколько повторов сделано
	float Ugol;//угол поворота
	void Draw();//функция для вывода человека
	BOOL Load(char *path);//функция загрузки человека
	BOOL ReBuild(int ttime);//функция перестройки человека

} 

#endif*/