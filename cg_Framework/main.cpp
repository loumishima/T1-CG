#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
    //drawLine(20,20,512,20,255,255,255,255,0,0);
    drawLine(50,300/*v2*/,300,300/*v3*/,0,0,255/*c1*/,255,0,0/*c2*/);
    drawTriangle(50, 50 /*v1*/,0,300/*v2*/,300,300/*v3*/,0,0,255/*c1*/,255,0,0/*c2*/,0,255,0/*c3*/);


}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

