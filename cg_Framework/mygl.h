#ifndef _MYGL_H_
#define _MYGL_H_
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int coordX, int coordY, unsigned char pixelColorRed,unsigned char pixelColorGreen,unsigned char pixelColorBlue){

//Pixel properties : coordX, coordY , pixelColor NOT ACTIVE FOR NOW
    FBptr[coordX*4 + coordY*IMAGE_WIDTH*4 + 0] = pixelColorRed; //Componente R
    FBptr[coordX*4 + coordY*IMAGE_WIDTH*4 + 1] = pixelColorGreen; //Componente G
    FBptr[coordX*4 + coordY*IMAGE_WIDTH*4 + 2] = pixelColorBlue; //componente B
    FBptr[coordX*4 + coordY*IMAGE_WIDTH*4 + 3] = 255;//componente A
}

void drawLine(int coordX1, int coordY1, int coordX2, int coordY2,unsigned char Red1,unsigned char Green1,unsigned char Blue1,unsigned char Red2,unsigned char Green2,unsigned char Blue2){
//Bresenham vem aqui!
//Line properties: Pixel initialPixel, Pixel finalPixel NOT ACTIVE FOR NOW
   bool steep = (fabs(coordY2-coordY1) > fabs(coordX2 - coordX1)); //verify if deltaY is higher than deltaX

    if(steep){ //if deltaY is higher than deltaX then we have to swap the coordinates (this actually removes the bug from the Bresemham algorithm)
        std::swap(coordX1,coordY1);
        std::swap(coordX2,coordY2);
    }
    if(coordX1 > coordX2){
        std::swap(coordX1,coordX2);
        std::swap(coordY1,coordY2);
        std::swap(Red2, Red1);
        std::swap(Blue2, Blue1);
        std::swap(Green2, Green1);
    }

    float dx = coordX2 - coordX1;
    float dy = fabs(coordY2 - coordY1);
    float dx_color;
    if(dx > 255){
        dx_color = 255;
    }
    else{
        dx_color = dx;
    }
    float error = dx/2.0f;
    int ystep = (coordY1 < coordY2) ? 1: -1; //if true -1, else 1;
    int y = (int) coordY1;

    //Color variation
    float dr = (Red2 - Red1)/abs(dx_color);
    float dg = (Green2 - Green1)/abs(dx_color);
    float db = (Blue2 - Blue1)/abs(dx_color);
    //Initial point
    int redAtual = (int) Red1;
    int greenAtual =(int) Green1;
    int blueAtual = (int) Blue1;
    int maxX = (int) coordX2;

    for(int x = (int)coordX1; x< maxX ; x++){

        if(steep){
            putPixel(y,x,(unsigned char)redAtual,(unsigned char)greenAtual,(unsigned char)blueAtual);//We swapped this case before, so we need to plot 'swapped'
            redAtual += dr;
            greenAtual += dg;
            blueAtual += db;
        }
        else{
            putPixel(x,y,(unsigned char)redAtual,(unsigned char)greenAtual,(unsigned char)blueAtual);//Normal plot
            redAtual += dr;
            greenAtual += dg;
            blueAtual += db;
        }

        error -= dy;
        if(error < 0){
            y += ystep;
            error += dx;
        }
    }


}

void drawTriangle(int coordX1, int coordY1,int coordX2, int coordY2, int coordX3,int coordY3, unsigned char Red1,unsigned char Green1,unsigned char Blue1,unsigned char Red2,unsigned char Green2,unsigned char Blue2,unsigned char Red3,unsigned char Green3,unsigned char Blue3){

//Triangle properties: Pixel edge1, Pixel edge2 , Pixel edge3 NOT ACTIVE FOR NOW
//Draw of the lines

drawLine(coordX1, coordY1, coordX2, coordY2, Red1, Green1, Blue1, Red2, Green2, Blue2);
drawLine(coordX1, coordY1, coordX3, coordY3, Red1, Green1, Blue1, Red3, Green3, Blue3);
drawLine(coordX3, coordY3, coordX2, coordY2, Red3, Green3, Blue3, Red2, Green2, Blue2 );


}



#endif // _MYGL_H_

