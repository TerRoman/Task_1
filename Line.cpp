#include "main.h"

Line::Line(Position tp1, Position tp2){
    p1=tp1;
    p2=tp2;
    k=(p2.getLatitude()-p1.getLatitude())/(p2.getLongtitude()-p1.getLongtitude());
    b=((p1.getLatitude()-k*p1.getLongtitude())+(p2.getLatitude()-k*p2.getLongtitude()))/2;
    printf("y=5x*%f+%f\n\n", k,b);
}
Position Line::GetP1(){
    return p1;
}
Position Line::GetP2(){
    return p2;
}

void Line::Drow_line(Pixel** Image, Pixel color){
    float x=p1.longtitude;
    float y;
    float d=0.001;
    while(abs(x-p2.longtitude)>d){
        y=k*x+b;
        if ((x-p2.longtitude)<0){
            x=x+d;
        }
        else{
            x=x-d;

    }
        Image[616-(int)y][(int)x].R=0;
        Image[616-(int)y][(int)x].B=0;
        Image[616-(int)y][(int)x].G=0;
    }
}

