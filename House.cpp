#include "main.h"

House::House(){
    num_corners = 0;
    for(int i = 0; i<4; i++)
    {
        p[i].setLatLongt(0,0);

    }

}

void House::add_Corner(Position t_p){
    p[num_corners] = t_p;
    num_corners++;
}

Position House::getPos(int t){
	return p[t];
}

void House::Add_line(Line tline){
    lines.push_back(tline);

}


void House::Draw_House(Pixel** image,Pixel color){
    for(int i=0;i<lines.size();i++){
        lines[i].Drow_line(image,color);
    }
}

void House::print_line(){
    for(int i=0;i<lines.size();i++){
        printf("x1=%f y1=%f ....... x2=%f y2=%f\n",lines[i].GetP1().getLongtitude(),lines[i].GetP1().getLatitude(),lines[i].GetP2().getLongtitude(),lines[i].GetP2().getLatitude());
    }
}
