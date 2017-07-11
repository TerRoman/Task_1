#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class Position{
public:
    float latitude;
    float longtitude;
public:
    Position();
    Position(float t_lat, float t_long);
    float getLatitude();
    float getLongtitude();
    void setLatLongt(float t_lat, float t_longt);
    void GeogrToPixel(Position pmax, Position pmin);
    Position coord_to_pixel(Position Min,Position Max,Position p);
	void Set_Coord(Position tp);
};

struct Pixel{
    int R;
    int B;
    int G;
};
class Line{
    Position p1;
    Position p2;
    float k;
    float b;
public:
    Position GetP1();
    Position GetP2();
    Line (Position tp1, Position tp2);
    void Drow_line(Pixel** image, Pixel color);
};

class House{
    public:
    int num_corners;
	vector <Line> lines;
    Position p[4];
public:
    House();
    void add_Corner(Position p);
	void Draw_House(Pixel** image,Pixel color);
	Position getPos(int t);
	void Add_line(Line tline);
    void print_line();
};

class Map{
    public:
    int  max_x;
    int  max_y;
	Position corner_min;
	Position corner_max;
    Pixel** Image;
    vector <House> Houses;
public:
    Map(int tmax_x, int tmax_y, Position tcorner_min, Position tcorner_max);
    ~Map();
    void Load_image(char* filename);
    void show();
    int  Get_max_x();
    int  Get_max_y();
    void Add_house(House h);
	Position Get_Corner(char *name);
};



