#include "main.h"

void Game::Menu()
{
	death=0;
	for(int i=0; i<L;i++)
	{
		life[i]=1;
	}
	system("cls");
	cout<<"----!SNAKE!3D!----"<<endl;
	cout<<endl;
	cout<<"1)Start Game"<<endl;
	cout<<"2)Random lvl Game"<<endl;
	cout<<"3)TOP 10 Best Results"<<endl<<endl;
	cout<<"4)Close Game"<<endl<<endl;
	cout<<"To return in the Menu, press - HOME"<<endl<<endl;
	cout<<"Press Key:"<<endl;
	cin>>game.Answer;
	if(game.Answer>4 || game.Answer<0)
		Menu();	
//---------------main
	switch(game.Answer)
	{
		
		case 1:game.lvl=1;game.start(0,game.lvl);break;
		case 2:game.Change(); break;
		case 3:
		system("cls");
		cout<<"----TOP 10 Best Results----"<<endl<<endl;
		for(int i=0; i<10; i++)
		{
			cout<<i+1<<")"<<"----"<<record[i]<<"----"<<endl;
		}
		cout<<endl;
		cout<<"5)- Back <==="<<endl;
		cout<<"Press Key:"<<endl;
		cin>>game.Answer;
		if(game.Answer==5)
		 Menu(); break;
		case 4:exit(1);break;
	 }
//------------
system("cls");
}

void Game::Change(){
			system("cls");
			cout<<"1)Start Game"<<endl;
			cout<<"2)----Setting----"<<endl<<endl;
			cout<<"3)- Back <==="<<endl<<endl;
			cout<<"Press Key:"<<endl;
			cin>>game.Answer;
			if(game.Answer>3 || game.Answer<0)
				game.Change();
			switch(game.Answer)
			{
				case 1:game.start(0,game.lvl);break;
				case 2:
				system("cls");
					cout<<"----Setting----"<<endl<<endl;
					cout<<"1)-LVL 1"<<endl;
					cout<<"2)-LVL 2"<<endl;
					cout<<"3)-LVL 3"<<endl<<endl;
					cout<<"4)- Back <==="<<endl<<endl;
					cout<<"Press Key:"<<endl;
					cin>>game.Answer;
					if(game.Answer>4 || game.Answer<0)
							game.Change();

					switch(game.Answer)
					{
						case 1: 
						game.lvl=1;
						game.delay=125;
							game.Change(); break;
					case 2:
						game.lvl=2;
						game.delay=100;
						wall[0].lvlWall=46;
							game.Change(); break;
					case 3:
						game.lvl=3;
						game.delay=75;
						wall[0].lvlWall=(N+2)*4;
							game.Change(); break;
					case 4:game.Change();break;
					}break;
				case 3: game.Menu();break; 
			} 
}

void Game::start(int s,int A)
{
 if(s==0){
	if(A==1)
	{
		glLightfv(GL_LIGHT0,GL_DIFFUSE,difall1);
		glDisable(GL_TEXTURE_2D);
		add=2;
		cube[0].bx=0;
		cube[0].by=0;
		cube[0].bz=0;
		cube[0].apple=0;
		game.dir=2;
		game.death=0;
		game.delay=125;
			cube[0].num=5;
		for(int i=0;i<5;i++)
			m[i].New();
		

	}
	if(A==2)
	{
		
		glLightfv(GL_LIGHT0,GL_DIFFUSE,difall2);
		glEnable(GL_TEXTURE_2D);
		add=3;
		cube[0].bx=0;
		cube[0].by=0;
		cube[0].bz=0;
		cube[0].apple=0;
		game.dir=2;
		game.death=0;
		cube[0].num=5;
		game.delay=100;
		for(int i=0; i<L;i++)
		{
			life[i]=1;
		}
		for(int i=0;i<5;i++)
			m[i].New();
		for(int i=0,j=0; i<wall[0].lvlWall;i++)
		{
			if(i<12)
			{
				wall[i].wx=-1;
				wall[i].wy=0;
				wall[i].wz=-1+2*i;
			}
			if(i>=12 && i<24)
			{
				wall[i].wx=M;
				wall[i].wy=0;
				wall[i].wz=-1+2*i-12*2;
			}
			if(i>=24 && i<35)
			{
				wall[i].wx=1+2*j;
				wall[i].wy=0;
				wall[i].wz=-1;
				j++;
			}
			if(i>=35 && i<wall[0].lvlWall)
			{
				wall[i].wx=1+2*j-11*2;;
				wall[i].wy=0;
				wall[i].wz=N;
				j++;
			}
		}
	}
	if(A==3)
	{
		glLightfv(GL_LIGHT0,GL_DIFFUSE,difall2);
		glEnable(GL_TEXTURE_2D);
		add=4;
		cube[0].bx=0;
		cube[0].by=0;
		cube[0].bz=0;
		cube[0].apple=0;
		game.dir=2;
		game.death=0;
		cube[0].num=5;
		game.delay=75;
		for(int i=0; i<L;i++)
		{
			life[i]=1;
		}
		for(int i=0;i<5;i++)
			m[i].New();
		for(int i=0,j=0; i<wall[0].lvlWall;i++)
		{
			if(i<N+2)
			{
				wall[i].wx=-1;
				wall[i].wy=0;
				wall[i].wz=-1+i;
			}
			if(i>=N+2 && i<(N+2)*2)
			{
				wall[i].wx=M;
				wall[i].wy=0;
				wall[i].wz=i-N-3;
			}
			if(i>=(N+2)*2 && i<(N+2)*3)
			{
				wall[i].wx=j;
				wall[i].wy=0;
				wall[i].wz=-1;
				j++;
			}
			if(i>=(N+2)*3 && i<wall[0].lvlWall)
			{
				wall[i].wx=j-N-2;;
				wall[i].wy=0;
				wall[i].wz=N;
				j++;
			}
		}
	}
	cout<<"Next Round. Started:"<<A<<endl;
		for(int i=3; i>0; i--)
		{
			cout<<i<<endl;
			Sleep(1000);
		}
 }
 else
 {
	if(A==1)
		game.start(0,game.lvl);	
	else
	    Menu();
  }
}

void Game::detected(int a)
{
	if(a==1){
	for(int i=0; i<wall[0].lvlWall;i++)
		{
			if(cube[0].bx==wall[i].wx && cube[0].bz==wall[i].wz ) 
			{
				if(cube[0].bx>M-1)
				{
					cube[0].bx-=(M);//dir=1;
				}
				if(cube[0].bx<0)
				{
					cube[0].bx+=M;//dir=2;
				}
				if(cube[0].bz>N-1)
				{
					cube[0].bz-=(N);//dir=0;
				}
				if(cube[0].bz<0)
				{
					cube[0].bz+=N;//dir=3;
				}
					if(cube[0].num%2==0)
				{
					score=score-(cube[0].num/2)*add/2;
					cube[0].num=cube[0].num/2;
					if(cube[0].num<5)
						cube[0].num=5;
				}
				if(cube[0].num%2==1)
				{
					score=score-(cube[0].num/2-1)*add/2;
					cube[0].num=cube[0].num/2-1;
					if(cube[0].num<5)
						cube[0].num=5;
				}
				if(score<0)
					score=0;

				game.death++;
			}
		}
	}
	else
	{
		if(cube[0].bx>M-1)
		{
			cube[0].bx-=(M);//dir=1;
		}
		if(cube[0].bx<0)
		{
			cube[0].bx+=M;//dir=2;
		}
		if(cube[0].bz>N-1)
		{
			cube[0].bz-=(N);//dir=0;
		}
		if(cube[0].bz<0)
		{
			cube[0].bz+=N;//dir=3;
		}
	}
}

void Game::lvlup(){
	if(game.lvl==1 && cube[0].apple>50)
	{
		game.lvl=2;
		game.delay=100;
		wall[0].lvlWall=46;
		system("cls");
		cout<<"----!SNAKE!3D!----"<<endl;
		cout<<endl;
		cout<<"LvL 1 - Complitely"<<endl;
		cout<<endl;
		cout<<"Next LvL 2.Gotov? "<<endl;
		system("pause");
		game.start(0,game.lvl);
	}
	else
	{
		if(game.lvl==2 && cube[0].apple>50)
	 {
		game.lvl=3;
		game.delay=75;
		wall[0].lvlWall=(N+2)*4;
		system("cls");
		cout<<"----!SNAKE!3D!----"<<endl;
		cout<<endl;
		cout<<"LvL 2 - Complitely"<<endl;
		cout<<endl;
		cout<<"Next LvL 3. Gotov? "<<endl;
		system("pause");
		game.start(0,game.lvl);
	 }
   }
}

void Game::Death()
{
	int lastscore=score;
		for(int i=0; i<game.death; i++)
		{
			life[i]=0;
			if(game.death==L)
			{
				for(int j=0; j<R; j++)
				{
					int update=0;	
					int max;
					if(update==1)
					{
						if(j<9)
						{
							max=record[j];
							record[j]=score;
							score=max;
						}
					}
					else
					{
						int max=record[j];
						if(max<score)
						{
							record[j]=score;
							score=max;
							update=1;
						}
					}
				}
				//Обратно в консоль
				system("cls");
				score=0;
				cout<<"Your score:"<<lastscore<<endl<<endl;
				cout<<"----TOP 10 Best Results----"<<endl;
				for(int i=0; i<R; i++)
				{
					cout<<i+1<<")"<<"----"<<record[i]<<"----"<<endl;
				}
				system ("pause");
				cout<<"Next Round?(1-Y/2-N):"<<endl;
//Новая Жизнь------------------
				cin>>game.Answer;
				game.start(1,game.Answer);
//-------------------------
			}		
	  }
}


void Game::drawScene()
{
	glPushMatrix();
	for(int i=0;i<M;i++)
	{
		if(i%2!=0)
	{
		for(int j=0;j<N;j++)
		{
			if(j%2!=0)
			{
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
				glColor3f(0,0.2,0);
				glVertex3f(i,-0.02,j+1);//нижняя грань
				glVertex3f(i,-0.02,j);
				glVertex3f(i+1,-0.02,j);
				glVertex3f(i+1,-0.02,j+1);
			glEnd();
			}
			else
			{
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
				glColor3f(0,0.5,0);
				glVertex3f(i,-0.02,j+1);//нижняя грань
				glVertex3f(i,-0.02,j);
				glVertex3f(i+1,-0.02,j);
				glVertex3f(i+1,-0.02,j+1);
			glEnd();
			}
		}
	}
	else
	 {
		for(int j=0;j<N;j++)
		{
			if(j%2==0)
			{
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
				glColor3f(0,0.2,0);
				glVertex3f(i,-0.02,j+1);//нижняя грань
				glVertex3f(i,-0.02,j);
				glVertex3f(i+1,-0.02,j);
				glVertex3f(i+1,-0.02,j+1);
			glEnd();
			}
			else
			{
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
				glColor3f(0,0.7,0);
				glVertex3f(i,-0.02,j+1);//нижняя грань
				glVertex3f(i,-0.02,j);
				glVertex3f(i+1,-0.02,j);
				glVertex3f(i+1,-0.02,j+1);
			glEnd();
			}
		}
	  }
	}
	glColor3f(1,1,1);
	glRotatef(90,1,0,0);
	glBegin(GL_LINES);
	for(int i=0;i<=M;i++)
	{
		glVertex3f(i,0,0);
		glVertex3f(i,N,0);
	}
	for(int j=0;j<=N;j++)
	{
		glVertex3f(0,j,0);
		glVertex3f(M,j,0);
	}
	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}

void Game::drawSolid()
{	
	for(int i=0;i<L;i++){
		glPushMatrix();
		if(life[i]==1)
		{
			glColor3f(1,0,0);
				glTranslatef(M+i, 10, 0);
				glutSolidSphere(0.5, 20, 20);
		}
		else
		{
			glColor3f(0.2,0,0);
				glTranslatef(M+i, 10, 0);
				glutSolidSphere(0.5, 20, 20);
		}
		strcpy(Start,Copy);
		glutSetWindowTitle(strcat(Start,_itoa(score,buff,10)));
		glPopMatrix();
	}
}

void Snake::theCube()
{
//Голова
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambsnake);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,difsnake);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specsnake);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shansnake);
	glBegin(GL_QUADS);
    glColor3f(0,0,0);
	glNormal3f(0,0,-1);
		if(game.dir==0)
			glColor3f(1,0,0);
		else
			glColor3f(0,0,0);
	    glVertex3f(cube[0].bx,0,cube[0].bz);//зад
		glVertex3f(cube[0].bx,1,cube[0].bz);
		glVertex3f(cube[0].bx+1,1,cube[0].bz);
		glVertex3f(cube[0].bx+1,0,cube[0].bz);
	glNormal3f(0,0,1);
		if(game.dir==3)
			glColor3f(1,0,0);
		else
			glColor3f(0,0,0);
	    glVertex3f(cube[0].bx,0,cube[0].bz+1);//перед
		glVertex3f(cube[0].bx,1,cube[0].bz+1);
		glVertex3f(cube[0].bx+1,1,cube[0].bz+1);
		glVertex3f(cube[0].bx+1,0,cube[0].bz+1);
	glNormal3f(-1,0,0);
		if(game.dir==1)
			glColor3f(1,0,0);
		else
			glColor3f(0,0,0);
		glVertex3f(cube[0].bx,0,cube[0].bz+1);//левая
		glVertex3f(cube[0].bx,1,cube[0].bz+1);
		glVertex3f(cube[0].bx,1,cube[0].bz);
		glVertex3f(cube[0].bx,0,cube[0].bz);
	glNormal3f(1,0,0);
		if(game.dir==2)
			glColor3f(1,0,0);
		else
			glColor3f(0,0,0);
		glVertex3f(cube[0].bx+1,0,cube[0].bz+1);//правая
		glVertex3f(cube[0].bx+1,1,cube[0].bz+1);
		glVertex3f(cube[0].bx+1,1,cube[0].bz);
		glVertex3f(cube[0].bx+1,0,cube[0].bz);
	glNormal3f(0,1,0);
	glColor3f(0,0,0);
		glVertex3f(cube[0].bx,1,cube[0].bz);//верх
		glVertex3f(cube[0].bx+1,1,cube[0].bz);
		glVertex3f(cube[0].bx+1,1,cube[0].bz+1);
		glVertex3f(cube[0].bx,1,cube[0].bz+1);
	glNormal3f(0,-1,0);
		glVertex3f(cube[0].bx,0,cube[0].bz);//низ
		glVertex3f(cube[0].bx+1,0,cube[0].bz);
		glVertex3f(cube[0].bx+1,0,cube[0].bz+1);
		glVertex3f(cube[0].bx,0,cube[0].bz+1);
	glEnd();
	
//Хвост
for(int i = 1; i<cube[0].num ;i++)
   {
 glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambsnake);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,difsnake);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specsnake);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shansnake);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glColor3f(1,0,0);
	    glVertex3f(cube[i].bx,0,cube[i].bz);//зад
		glVertex3f(cube[i].bx,1,cube[i].bz);
		glVertex3f(cube[i].bx+1,1,cube[i].bz);
		glVertex3f(cube[i].bx+1,0,cube[i].bz);
	glNormal3f(0,0,1);	
	    glVertex3f(cube[i].bx,0,cube[i].bz+1);//перед
		glVertex3f(cube[i].bx,1,cube[i].bz+1);
		glVertex3f(cube[i].bx+1,1,cube[i].bz+1);
		glVertex3f(cube[i].bx+1,0,cube[i].bz+1);
	glNormal3f(-1,0,0);
		glVertex3f(cube[i].bx,0,cube[i].bz+1);//левая
		glVertex3f(cube[i].bx,1,cube[i].bz+1);
		glVertex3f(cube[i].bx,1,cube[i].bz);
		glVertex3f(cube[i].bx,0,cube[i].bz);
	glNormal3f(1,0,0);
		glVertex3f(cube[i].bx+1,0,cube[i].bz+1);//правая
		glVertex3f(cube[i].bx+1,1,cube[i].bz+1);
		glVertex3f(cube[i].bx+1,1,cube[i].bz);
		glVertex3f(cube[i].bx+1,0,cube[i].bz);
	glNormal3f(0,1,0);
		glVertex3f(cube[i].bx,1,cube[i].bz);//верх
		glVertex3f(cube[i].bx+1,1,cube[i].bz);
		glVertex3f(cube[i].bx+1,1,cube[i].bz+1);
		glVertex3f(cube[i].bx,1,cube[i].bz+1);
	glNormal3f(0,-1,0);
		glVertex3f(cube[i].bx,0,cube[i].bz);//низ
		glVertex3f(cube[i].bx+1,0,cube[i].bz);
		glVertex3f(cube[i].bx+1,0,cube[i].bz+1);
		glVertex3f(cube[i].bx,0,cube[i].bz+1);
	glEnd();
  } 
}

void Snake::Tick()
{
//Движение
	for(int i = cube[0].num; i>0; --i)
	{
		cube[i].bx=cube[i-1].bx;
		cube[i].bz=cube[i-1].bz;
	}
	if(game.dir==0)
		cube[0].bz-=1;
	if(game.dir==1)
		cube[0].bx-=1;
	if(game.dir==2) 
		cube[0].bx+=1;
	if(game.dir==3) 
		cube[0].bz+=1;
//Еда+++
	for(int i = 0;i<5;i++)
	{
			if((game.dir==0) && (cube[0].bx==m[i].fx)  && (cube[0].bz==m[i].fz-1))
		{	
			cube[0].num++;
			m[i].New();
			score+=add;
			cube[0].apple+=1;
		}
			if((game.dir==1) && (cube[0].bx==m[i].fx-1)  && (cube[0].bz==m[i].fz))
		{	
			cube[0].num++;
			m[i].New();
			score+=add;
			cube[0].apple+=1;
		}
			if((game.dir==2) && (cube[0].bx==m[i].fx+1)  && (cube[0].bz==m[i].fz))
		{	
			cube[0].num++;
			m[i].New();
			score+=add;
			cube[0].apple+=1;
		}

		if((game.dir==3) && (cube[0].bx==m[i].fx)  && (cube[0].bz==m[i].fz+1))
		{	
			cube[0].num++;
			m[i].New();
			score+=add;
			cube[0].apple+=1;
		}
	}
//++++++++
//Границы====
	if(game.lvl==1)
	{
		game.detected(0);
	}
	if(game.lvl==2)
	{	
		game.detected(1);
		game.detected(0);
	}	
	if(game.lvl==3)
	{	
		game.detected(1);
	}	
//============
//Есть самого себя
		for(int i=1;i<cube[0].num;i++)
		{
			if((cube[0].bx==cube[i].bx) && cube[0].bz==cube[i].bz) 
			{
				if((cube[0].num-i)%2==0)
				{
					score=score-(cube[0].num-i)*add/2;
				}
				else
				{
					score=score-(cube[0].num-(i+1))*add/2;
				}
				if(score<0)
					score=0;

				cube[0].num=i;
				game.death++;
			}
		}
//Смерть-------
		game.Death();
//-------
}

