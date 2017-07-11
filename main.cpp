#include "main.h"

int main(){
	int house_number = -1;
    setlocale(LC_ALL, "");
    std::ifstream file("test.txt");
    string line;
    const char* temp;
    char *str1;
    int k = 0;
    std::vector<float> parametrs;
    if (file.is_open())
  {
    while ( file.good() )
    {
    house_number++;
    getline (file,line);
    temp = line.c_str();
    str1 = (char*)temp;
    char* pch = strtok (str1," ");
    while (pch != NULL)
    {
    parametrs.push_back(atof(pch));
      pch = strtok (NULL, " ");
      k++;
    }
    }
    file.close();
  }
  else cout << "Unable to open file";
	Map *Image;
	Position Min(parametrs[2],parametrs[3]);
    Position Max(parametrs[4],parametrs[5]);
	Image = new Map(parametrs[0], parametrs[1],  Min,  Max);
	House House1;
    Position temp_pos;
    Position pos[4];
    for(int i = 0; i < house_number*4; i++)
    {
        temp_pos.setLatLongt(parametrs[2*i+6],parametrs[2*i+7]);
        House1.add_Corner(temp_pos);
        pos[i] = temp_pos;
    }
    FILE* carta=fopen("mai.pnm","r");
    Image->Load_image("mai.pnm");
	Position p1 = House1.getPos(0);
	Position p2= House1.getPos(1);
	Position p3= House1.getPos(2);
	Position p4= House1.getPos(3);
    p1 = p1.coord_to_pixel(Min, Max,p1);
    p2 = p2.coord_to_pixel(Min, Max,p2);
    p3 = p3.coord_to_pixel(Min, Max,p3);
    p4 = p4.coord_to_pixel(Min, Max,p4);
    House1.Add_line(Line(p1,p2));
    House1.Add_line(Line(p2,p3));
    House1.Add_line(Line(p3,p4));
    House1.Add_line(Line(p4,p1));
    House1.print_line();
    Image->Add_house(House1);
    Image->show();
    fclose(carta);
	free(Image);
    return 0;
}
