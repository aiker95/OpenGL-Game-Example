#include <windows.h>
#include <glut.h>
#include <glaux.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#pragma comment (lib, "Glaux.lib")


using namespace std;



int M=23,N=21;

float amb[]={0.0,0.0,0.0,1.0};

float ambsnake[]={0.3,0.3,0.3,1.0};
float difsnake[]={0.8,0.8,0.8,1.0};
float specsnake[]={0.3,0.3,0.3,1.0};
float shansnake=128*0.2;

float amball[]={0.1,0.1,0.1,1.0};
float difall1[]={0.5,0.5,0.5,1.0};
float difall2[]={1.0,1.0,1.0,1.0};
float specall[]={0.1,0.1,0.1,1.0};
float position[]={11.0,1.0,25.0,1.0};

char Start[50]="League of 3D Snake. Score:";
char Copy[50]="League of 3D Snake. Score:";
char buff[10];

int const L=3;
int const R=10;

int life[L];
int record[R];

int add=2;
int score=0;

AUX_RGBImageRec *image;

class Textures
{
public:
	unsigned int textures[1];
	void LoadTextures()
		{
		 glGenTextures(1, &textures[0]);
		 glBindTexture(GL_TEXTURE_2D, textures[0]);
		 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		 glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
		}
}texture;

class Game
{
public:
	int Answer;
	int lvl;
	int w, h;
	int dir, delay;
	int death;

	void Menu();
	void Change();
	void start(int s,int A);
	void lvlup();
	void detected(int a);
	void Death();

	void drawScene();
	void drawSolid();
}game;

class Snake
{
public:
	int bx;
	int by;
	int bz;
	int num;
	int apple;
	void theCube();
	void Tick();
} cube[500];

class Wall
{
public:
	int wx;
	int wy;
	int wz;
	int lvlWall;

	void DrawWall()
	{
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glColor3f(0.4,0.4,0.4);
		glTexCoord2f(0.0,0.0);glVertex3f(wx,wy,wz);
		glTexCoord2f(0.0,1.0);glVertex3f(wx,wy+1,wz);
		glTexCoord2f(1.0,1.0);glVertex3f(wx+1,wy+1,wz);
		glTexCoord2f(1.0,0.0);glVertex3f(wx+1,wy,wz);
	glNormal3f(0,0,1);
		glTexCoord2f(0.0,0.0);glVertex3f(wx,wy,wz+1);
		glTexCoord2f(0.0,1.0);glVertex3f(wx,wy+1,wz+1);
		glTexCoord2f(1.0,1.0);glVertex3f(wx+1,wy+1,wz+1);
		glTexCoord2f(1.0,0.0);glVertex3f(wx+1,wy,wz+1);
	glNormal3f(1,0,0);
		glTexCoord2f(0.0,0.0);glVertex3f(wx,wy,wz+1);
		glTexCoord2f(0.0,1.0);glVertex3f(wx,wy+1,wz+1);
		glTexCoord2f(1.0,1.0);glVertex3f(wx,wy+1,wz);
		glTexCoord2f(1.0,0.0);glVertex3f(wx,wy,wz);
	glNormal3f(-1,0,0);
		glTexCoord2f(0.0,0.0);glVertex3f(wx+1,wy,wz+1);
		glTexCoord2f(0.0,1.0);glVertex3f(wx+1,wy+1,wz+1);
		glTexCoord2f(1.0,1.0);glVertex3f(wx+1,wy+1,wz);
		glTexCoord2f(1.0,0.0);glVertex3f(wx+1,wy,wz);
	glNormal3f(0,1,0);
		glTexCoord2f(0.0,1.0);glVertex3f(wx,wy+1,wz);
		glTexCoord2f(1.0,1.0);glVertex3f(wx+1,wy+1,wz);
		glTexCoord2f(1.0,0.0);glVertex3f(wx+1,wy+1,wz+1);
		glTexCoord2f(0.0,0.0);glVertex3f(wx,wy+1,wz+1);
	glNormal3f(0,-1,0);
		glTexCoord2f(0.0,0.0);glVertex3f(wx,wy,wz);
		glTexCoord2f(0.0,1.0);glVertex3f(wx+1,wy,wz);
		glTexCoord2f(1.0,1.0);glVertex3f(wx+1,wy,wz+1);
		glTexCoord2f(1.0,0.0);glVertex3f(wx,wy,wz+1);
	glEnd();
	}
}wall[96];

class Fructs
{
public:
	int fx;
	int fy;
	int fz;
	void New()
	{
		fx=rand() % M;
		fy=0;
		fz=rand() % N;
		for(int i=0;i<cube[0].num; i++)
		if(fx==cube[i].bx && fz==cube[i].bz)
			New();
	}
	void DrawApple()
	{
	glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
		glColor3f(1.0,1.0,0);
		glVertex3f(fx,fy,fz);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy,fz);
	glNormal3f(0,0,1);
	    glVertex3f(fx,fy,fz+1);
		glVertex3f(fx,fy+1,fz+1);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx+1,fy,fz+1);
	glNormal3f(1,0,0);
		glVertex3f(fx,fy,fz+1);
		glVertex3f(fx,fy+1,fz+1);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx,fy,fz);
	glNormal3f(-1,0,0);
		glVertex3f(fx+1,fy,fz+1);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy,fz);
	glNormal3f(0,1,0);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx,fy+1,fz+1);
	glNormal3f(0,-1,0);
		glVertex3f(fx,fy,fz);
		glVertex3f(fx+1,fy,fz);
		glVertex3f(fx+1,fy,fz+1);
		glVertex3f(fx,fy,fz+1);
	glEnd();

	glEnable(GL_BLEND);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glColor3f(1.0,1.0,0);
		glVertex3f(fx,fy,fz);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy,fz);
	glNormal3f(0,0,1);
	    glVertex3f(fx,fy,fz+1);
		glVertex3f(fx,fy+1,fz+1);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx+1,fy,fz+1);
	glNormal3f(1,0,0);
		glVertex3f(fx,fy,fz+1);
		glVertex3f(fx,fy+1,fz+1);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx,fy,fz);
	glNormal3f(-1,0,0);
		glVertex3f(fx+1,fy,fz+1);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy,fz);
	glNormal3f(0,1,0);
		glVertex3f(fx,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz);
		glVertex3f(fx+1,fy+1,fz+1);
		glVertex3f(fx,fy+1,fz+1);
	glNormal3f(0,-1,0);
		glVertex3f(fx,fy,fz);
		glVertex3f(fx+1,fy,fz);
		glVertex3f(fx+1,fy,fz+1);
		glVertex3f(fx,fy,fz+1);
	glEnd();
	glDisable(GL_BLEND);
  }
}m[5];
