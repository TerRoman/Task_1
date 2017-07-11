#include "main.h"


Map::Map(int tmax_x,int tmax_y, Position tcorner_min, Position tcorner_max){
    max_x=tmax_x;
    max_y=tmax_y;
	corner_min = tcorner_min;
	corner_max = tcorner_max;
    Pixel color;
    color.R=255;
    color.G=255;
    color.B=255;
    Image=new Pixel*[max_x];
    for(int i=0;i<max_x;i++){
        Image[i]=new Pixel[max_y];
        for(int j=0;j<max_y;j++){
            Image[i][j]=color;
        }
    }
}

Map::~Map(){
    for(int i=0;i<max_x;i++){
        delete Image[i];
    }
    delete Image;
}

int Map::Get_max_x(){
    return max_x;
}
int Map::Get_max_y(){
    return max_y;
}

void Map::show(){
    Pixel color;
    color.R=0;
	color.G=0;
	color.B=0;
    for(int i=0;i<Houses.size();i++){
        Houses[i].Draw_House(Image,color);
    }

    FILE* fp=fopen("image.pnm","w");
    fprintf(fp,"P3\n");
    fprintf(fp,"%d %d\n",max_x, max_y);
    fprintf(fp,"255\n");
    for(int i=0;i<max_x;i++){
        for(int j=0;j<max_y;j++){
            fprintf(fp,"%d %d %d\n",Image[i][j].R,Image[i][j].G,Image[i][j].B);
        }
    }
    fclose(fp);
}
void Map::Add_house(House h){
    Houses.push_back(h);
}


void Map::Load_image(char* filename){
	int k=1;
	char buf [10];
    FILE* fp=fopen(filename,"r");
    for (int i=0;i<18;i++){
        fscanf(fp, "%c", &buf);
    }
    for(int i=0;i<max_x;i++){
        for(int j=0;j<max_y;j++){
					fscanf(fp, "%d", &Image[i][j].G);
					fscanf(fp, "%d", &Image[i][j].B);
					fscanf(fp, "%d", &Image[i][j].R);
        }
    }
    fclose(fp);
}

Position Map::Get_Corner(char *name){
	if (name == "min")
		return corner_min;
	else
		return corner_max;

}
