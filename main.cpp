#include "vmain.h"


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-11,5,-40);
	glRotatef(40,1,0,0);
	game.drawSolid();
	game.drawScene();
	glPushMatrix();
	for(int i=0;i<5;i++)
		m[i].DrawApple();
	for(int i=0;i<cube[0].num;i++)
		cube[i].theCube();
	glPopMatrix();
	if(game.lvl!=1)
	{	
		glPushMatrix();
		image=auxDIBImageLoadA("small.bmp");
		texture.LoadTextures();
		for(int i=0;i<wall[0].lvlWall;i++)
		{
		if(wall[i].wz==N)
		{
			glEnable(GL_BLEND);
		}
		wall[i].DrawWall();
		glDisable(GL_BLEND);
		}
		glPopMatrix();
		glutPostRedisplay();
	}
	glutSwapBuffers();
}

void inite()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55,1.5f, 1.0f, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);    
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0,0,0,1);
	glTranslatef(0.375,0.375,0.0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
		glLightfv(GL_LIGHT0,GL_AMBIENT,amball);	
		glLightfv(GL_LIGHT0,GL_DIFFUSE,difall1);
		glLightfv(GL_LIGHT0,GL_SPECULAR,specall);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE); 
}

void Skeyboard(int key, int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_UP: if(game.dir!=3){ game.dir=0; Sleep(game.delay); }break; 
		case GLUT_KEY_RIGHT: if(game.dir!=1)	{  game.dir=2; Sleep(game.delay);} break; 
		case GLUT_KEY_LEFT: if(game.dir!=2) {  game.dir=1; Sleep(game.delay);} break; 
		case GLUT_KEY_DOWN:	if(game.dir!=0) { game.dir=3; Sleep(game.delay);}break; 
		
		case GLUT_KEY_HOME: game.death=L;game.Death(); break;
	}
}

void timer(int = 0 )
{
	display();
	cube[0].Tick();
	game.lvlup();
	glutTimerFunc(game.delay,timer,0);
}

int main(int argc, char** argv)
{
	game.w=1024;
	game.h=512;
	game.lvl=1;
	game.delay=125;
	for(int n=0; n<96;n++)
	{
		wall[n].wx=-1;
		wall[n].wy=0;
		wall[n].wz=-1;
	}
	for(int i=0; i<R;i++)
	{
		record[i]=0;
	}
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);//статика- GLUT_SINGLE, динамика- GLUT_DOUBLE(2 БУФЕРА)
	glutInitWindowSize(game.w, game.h);
	system("pause");
	cout<<endl;
	cout<<"Welcome to the League of"<<endl<<endl;
	system("pause");
	game.Menu();
	glutCreateWindow("!League of 3D Snake!");	
	score=0;
	glEnable(GL_TEXTURE_2D);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amb);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);	
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	//Перспективное представление
	inite();
	glutDisplayFunc(display);	
	glutSpecialFunc(Skeyboard);
	glutTimerFunc(game.delay,timer,0);
	glGetError();
	glutMainLoop();
}
