#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){
    double r1right = R1->x + R1->w;
    double r1bot = R1->y - R1->h;
    double r2right = R2->x + R2->w;
    double r2bot = R2->y - R2->h;
    double right,left,bot,top;
    
    if(r1right > r2right){right = r2right;}
    else {right = r1right;}
    if(R1->x > R2->x){left = R1->x;}
    else {left = R2->x;}
    
    if(R1->y > R2->y){top = R2->y;}
    else {top = R1->y;}
    if(r1bot > r2bot){bot = r1bot;}
    else {bot = r2bot;}

    double w = abs(right-left);
    double h = abs(top-bot);
    if(right < left || top < bot){
		w = 0;
		h = 0;
	}

    return w*h;
}