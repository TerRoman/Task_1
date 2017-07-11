#include "main.h"

Position::Position(){
    latitude = 0;
    longtitude = 0;
}

Position::Position(float t_lat, float t_longt){
    latitude = t_lat;
    longtitude = t_longt;
}


float Position::getLatitude(){
    return latitude;
}

float Position::getLongtitude(){
    return longtitude;
}

void Position::setLatLongt(float t_lat, float t_longt){
    latitude = t_lat;
    longtitude = t_longt;
}

Position Position::coord_to_pixel(Position Min, Position Max, Position p){
    p.setLatLongt(((616/(Max.getLatitude()-Min.getLatitude()))*(p.getLatitude()-Min.getLatitude())), ((950/(Max.getLongtitude()-Min.getLongtitude()))*(p.getLongtitude()-Min.getLongtitude())));
    return p;
}

void Position::Set_Coord(Position tp){
	latitude = tp.getLatitude();
	longtitude = tp.getLongtitude();
}
