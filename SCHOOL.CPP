#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<fstream.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>
class student
{
	char stuname[20];
	int stuno;
	float eng;
	float hin;
	float mat;
	float sci;
	float soc;
	float stuper;
	int stucls;
	char stusec;

	public:
	void input();
	void output();
	void showdetails();
	char getstusec()
	{
		return stusec;
	}
	int getstucls()
	{
		return stucls;
	}
	float geteng()
	{
		return eng;
	}
	float gethin()
	{
		return hin;
	}
	float getmat()
	{
		return mat;
	}
	float getsci()
	{
		return sci;
	}
	float getsoc()
	{
		return soc;
	}
	float getstuper()
	{
		return stuper;
	}
	char* getstuname()
	{
		return stuname;
	}
	int getstuno()
	{
		return stuno;
	}
	student()
	{
		strcpy(stuname,'\0');
		stuno=0;
		stuper=0;
		stucls=0;
		stusec='0';
		eng=hin=mat=sci=soc=0;
	}
};
void student::showdetails()
{
	int k1;
	k1=strlen(stuname);
	cout<<stuname;
	k1=19-k1;
	for(int i=0;i<k1;i++)
		cout<<" ";
	cout<<stuno;
	for(int j=0;j<13;j++)
		cout<<" ";
	cout<<stucls;
	for(int k=0;k<8;k++)
		cout<<" ";
	cout<<stusec;
	for(int l=0;l<8;l++)
		cout<<" ";
	cout<<stuper<<"%"<<endl;
}
int i,j,k,a,b,stucomp,choi5;
char choi,ans,choi2;
float total;
void student::input()
{
	cout<<endl<<"enter the student name: ";
	gets(stuname);
	cout<<"enter the student number: ";
	cin>>stuno;
	cout<<"enter the student class: ";
	cin>>stucls;
	cout<<"enter the student section: ";
	cin>>stusec;
	cout<<"enter the marks of the student"<<endl;
	cout<<"english: ";
	cin>>eng;
	cout<<"hindi: ";
	cin>>hin;
	cout<<"maths: ";
	cin>>mat;
	cout<<"science: ";
	cin>>sci;
	cout<<"social studies: ";
	cin>>soc;
	stuper=(eng+hin+mat+sci+soc)/5;
}
void student::output()
{
	cout<<"Student name is: "<<stuname<<endl;
	cout<<"Student no is: "<<stuno<<endl;
	cout<<"Student class is: "<<stucls<<endl;
	cout<<"Student section is: "<<stusec<<endl;
	cout<<"Student marks are.."<<endl;
	cout<<"english: "<<eng<<endl;
	cout<<"hindi: "<<hin<<endl;
	cout<<"maths: "<<mat<<endl;
	cout<<"science: "<<sci<<endl;
	cout<<"social science: "<<soc<<endl;
	cout<<"Student percentage is: "<<stuper<<" %"<<endl;
}
void addstudent()
{
	fstream f1;
	student S;
	f1.open("student.dat",ios::out|ios::app|ios::binary);
	do
	{
		clrscr();
		cout<<"\t\t*************** ADD STUDENT ***************"<<endl;
		cout<<endl;
		S.input();
		cout<<endl<<"Student added.."<<endl;
		f1.write((char*)&S,sizeof(S));
		cout<<endl<<"Want to add more?";
		cin>>choi;
	}while(choi=='y'||choi=='Y');
	f1.close();
}
void searchstudent()
{
	D:
	int flag=0;
	int ch;
	fstream f1;
	cout<<"\t\t*************** SEARCH STUDENT ***************"<<endl;
	cout<<endl;
	student S;
	cout<<endl<<"Enter the student number u want to search: ";
	cin>>ch;
	f1.open("student.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(ch==S.getstuno())
		{
			cout<<endl<<"\t\t\tStudent found..."<<endl;
			cout<<endl;
			S.output();
			flag=1;

		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
	if(flag==0)
	cout<<"Student not found!!!!!"<<endl;
	cout<<endl<<"Want to search for about more students: ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto D;
	}
}
void deletestudent()
{
	E:
	int flag=0;
	int ch;
	fstream f1,f2;
	student S;
	cout<<"\t\t*************** DELETE STUDENT ***************"<<endl;
	cout<<endl<<"Enter the student number you want to delete: ";
	cin>>ch;
	f1.open("student.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(ch!=S.getstuno())
		{
			flag=1;
			f2.write((char*)&S,sizeof(S));
		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
	f2.close();
	if(flag==1)
	cout<<"Student deleted"<<endl;
	if(flag==0)
	cout<<"This student is not in your school :( "<<endl;
	remove("student.dat");
	rename("temp.dat","student.dat");
	cout<<endl<<"Want to delete records of more students ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto E;
	}
}
void updatestudent()
{
	F:
	fstream f1,f2;
	int flag=0;
	cout<<"\t\t*************** UPDATE STUDENT ***************"<<endl;
	f1.open("student.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	int updateno;
	cout<<endl<<"Enter the number of the student you want to update: ";
	cin>>updateno;
	student S;
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(updateno==S.getstuno())
		{
			clrscr();
			cout<<"\t\t\tEnter new updated information of student: "<<endl;
			cout<<endl;
			S.input();
			f2.write((char*)&S,sizeof(S));
			flag=1;
		}
		else
		f2.write((char*)&S,sizeof(S));
	f1.read((char*)&S,sizeof(S));
	}
	f1.close();
	f2.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
	if(flag==1)
	cout<<"Student record updated..."<<endl;
	else
	cout<<"This student doen't in your school!!!!"<<endl;
	cout<<"Want to update records of more student? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto F;
	}
}
class teacher
{
	char teaname[20];
	int teano;
	char teasub[20];
	float teasal;
	public:
	void input();
	void output();
	void showdetail();
	char* getteasub()
	{
		return teasub;
	}
	float getteasal()
	{
		return teasal;
	}
	char* getteaname()
	{
		return teaname;
	}
	int getteano()
	{
		return teano;
	}
	teacher()
	{
		strcpy(teaname,'\0');
		teano=0;
		teasal=0;
		strcpy(teasub,'\0');
	}
};
void teacher::input()
{
	cout<<endl<<"enter the teacher name: ";
	gets(teaname);
	cout<<endl<<"enter the teacher number: ";
	cin>>teano;
	cout<<endl<<"enter the teacher subject: ";
	gets(teasub);
	cout<<endl<<"enter the teacher salary: ";
	cin>>teasal;
}
void teacher::output()
{
	cout<<"Teacher name is: "<<teaname<<endl;
	cout<<"Teacher no is: "<<teano<<endl;
	cout<<"Teacher subject is: "<<teasub<<endl;
	cout<<"Teacher salary is: "<<teasal<<endl;
}
void addteacher()
{
	fstream f1;
	teacher T;
	f1.open("teacher.dat",ios::out|ios::app|ios::binary);
	do
	{
		clrscr();
		cout<<"\t\t*************** ADD TEACHER ***************"<<endl;
		cout<<endl;
		T.input();
		cout<<endl<<"Teacher added.."<<endl;
		f1.write((char*)&T,sizeof(T));
		cout<<endl<<"Want to add more?";
		cin>>choi;
	}while(choi=='y'||choi=='Y');
	f1.close();
}
void searchteacher()
{
	D:
	int flag=0;
	int ch;
	fstream f1;
	cout<<"\t\t*************** SEARCH TEACHER ***************"<<endl;
	cout<<endl;
	teacher T;
	cout<<endl<<"Enter the teacher number u want to search: ";
	cin>>ch;
	f1.open("teacher.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&T,sizeof(T));
	while(!f1.eof())
	{
		if(ch==T.getteano())
		{
			cout<<endl<<"\t\t\tTeacher found..."<<endl;
			cout<<endl;
			T.output();
			flag=1;

		}
		f1.read((char*)&T,sizeof(T));
	}
	f1.close();
	if(flag==0)
	cout<<"Teacher info not found!!!!!"<<endl;
	cout<<endl<<"Want to search for about more teacher ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto D;
	}
}
void deleteteacher()
{
	E:
	int flag=0;
	int ch;
	fstream f1,f2;
	teacher T;
	cout<<"\t\t*************** DELETE TEACHER ***************"<<endl;
	cout<<endl<<"Enter the teacher number you want to delete: ";
	cin>>ch;
	f1.open("teacher.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	f1.read((char*)&T,sizeof(T));
	while(!f1.eof())
	{
		if(ch!=T.getteano())
		{
			flag=1;
			f2.write((char*)&T,sizeof(T));
		}
		f1.read((char*)&T,sizeof(T));
	}
	f1.close();
	f2.close();
	if(flag==1)
	cout<<"Teacher deleted"<<endl;
	if(flag==0)
	cout<<"This teacher is not in your school :( "<<endl;
	remove("teacher.dat");
	rename("temp.dat","teacher.dat");
	cout<<endl<<"Want to delete records of more teachers ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto E;
	}
}
void updateteacher()
{
	F:
	fstream f1,f2;
	int flag=0;
	cout<<"\t\t*************** UPDATE TEACHER ***************"<<endl;
	f1.open("teacher.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	int updateno;
	cout<<endl<<"Enter the name of the teacher you want to update: ";
	cin>>updateno;
	student T;
	f1.read((char*)&T,sizeof(T));
	while(!f1.eof())
	{
		if(updateno==T.getstuno())
		{
			clrscr();
			cout<<"\t\t\tEnter new updated information of teacher: "<<endl;
			cout<<endl;
			T.input();
			f2.write((char*)&T,sizeof(T));
			flag=1;
		}
		else
		f2.write((char*)&T,sizeof(T));
	f1.read((char*)&T,sizeof(T));
	}
	f1.close();
	f2.close();
	remove("teacher.dat");
	rename("temp.dat","teacher.dat");
	if(flag==1)
	cout<<"Teacher record updated..."<<endl;
	else
	cout<<"This teacher doen't in your school!!!!"<<endl;
	cout<<"Want to update records of more teachers? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto F;
	}
}
int compname(int a)
{
	fstream f1;
	int f=0;
	cout<<endl;
	student S;
	f1.open("student.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(a==S.getstuno())
		{
			clrscr();
			cout<<"\t\t*************** WELCOME "<<S.getstuname()<<" ***************";
			f=1;
		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
	return f;
}
void stumarks(int b)
{
	fstream f1;
	cout<<endl;
	student S;
	f1.open("student.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(b==S.getstuno())
		{
			clrscr();
			cout<<"\t\t*************** WELCOME "<<S.getstuname()<<" ***************";
			cout<<endl<<endl;
			cout<<"\tstudent marks are:"<<endl;
			cout<<"\tenglish: "<<S.geteng()<<endl;
			cout<<"\thindi: "<<S.gethin()<<endl;
			cout<<"\tmaths: "<<S.getmat()<<endl;
			cout<<"\tscience: "<<S.getsci()<<endl;
			cout<<"\tsocial science: "<<S.getsoc()<<endl;
			getch();
		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
}
void stuinfo(int c)
{
	fstream f1;
	cout<<endl;
	student S;
	f1.open("student.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(c==S.getstuno())
		{
			clrscr();
			cout<<"\t\t*************** WELCOME "<<S.getstuname()<<" ***************";
			cout<<endl<<endl<<"Your details are here:"<<endl<<endl;
			S.output();
			getch();
		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
}
int choi1,choi3,choi4;
int rec,result;
void showstu(int b,char c)
{
	fstream f1;
	cout<<endl;
	student S;
	cout<<"NAME               NUMBER          CLASS     SEC       PERCENTAGE"<<endl;
	f1.open("student.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&S,sizeof(S));
	while(!f1.eof())
	{
		if(b==S.getstucls() && c==S.getstusec())
		{
			S.showdetails();
		}
		f1.read((char*)&S,sizeof(S));
	}
	f1.close();
	getch();
}
void schoolbus()
{
	int i, gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	for (i = 0; i <= 420; i = i + 5)
	{
		setcolor(YELLOW);
		line(0+i, 270, 210 + i, 270);
		line(0 + i, 330, 0 + i, 270);
		line(30+i,295,30+i,270);
		line(60+i,295,60+i,270);
		line(90+i,295,90+i,270);
		line(120+i,295,120+i,270);
		line(150+i,295,150+i,270);
		line(180+i,295,180+i,270);
		line(0+i,295,210+i,295);
		line(210 + i, 330, 210 + i, 270);

		setcolor(LIGHTBLUE);
		outtextxy(65+i,305,"SCHOOL BUS");

		setcolor(DARKGRAY);
		circle(65 + i, 330, 15);
		circle(65 + i, 330, 2);
		circle(145 + i, 330, 15);
		circle(145 + i, 330, 2);

		setcolor(BROWN);
		line(-2000,345,2000,345);

		setcolor(YELLOW);
		line(0 + i, 330, 50 + i, 330);
		line(80 + i, 330, 130 + i, 330);
		line(210 + i, 330, 160 + i, 330);
		setcolor(RED);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(50,50,40);
		floodfill(50,50,RED);
		delay(100);

		setcolor(BLACK);
		line(0+i, 270, 210 + i, 270);
		line(0 + i, 330, 0 + i, 270);
		line(30+i,295,30+i,270);
		line(0+i,295,210+i,295);
		line(60+i,295,60+i,270);
		line(90+i,295,90+i,270);
		line(120+i,295,120+i,270);
		line(150+i,295,150+i,270);
		line(180+i,295,180+i,270);
		line(210 + i, 330, 210 + i, 270);
		outtextxy(65+i,305,"SCHOOL BUS");

		circle(65 + i, 330, 15);
		circle(65 + i, 330, 2);
		circle(145 + i, 330, 15);
		circle(145 + i, 330, 2);

		line(0 + i, 330, 50 + i, 330);
		line(80 + i, 330, 130 + i, 330);
		line(210 + i, 330, 160 + i, 330);
		setfillstyle(SOLID_FILL,BLACK);
		circle(50,50,40);
		floodfill(50,50,BLACK);
	}
	closegraph();
}
int choi7;
void main()
{
	schoolbus();
	int choi4;
	cout<<"X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X"<<endl;
	cout<<"X *           *  * * * * *  *           * * *     * *     *     *   * * * * * X"<<endl;
	cout<<"X  *         *   *          *          *         *   *    * * * *   *         X"<<endl;
	cout<<"X   *   *   *    * * *      *         *         *     *   *  *  *   * * *     X"<<endl;
	cout<<"X    * * * *     *          *          *         *   *    *     *   *         X"<<endl;
	cout<<"X     *   *      * * * * *  * * * * *   * * *     * *     *     *   * * * * * X"<<endl;
	cout<<"X                                                                             X"<<endl;
	cout<<"X                                                                             X"<<endl;
	cout<<"X                             * * * * *    * *                                X"<<endl;
	cout<<"X                                 *       *   *                               X"<<endl;
	cout<<"X                                 *      *     *                              X"<<endl;
	cout<<"X                                 *       *   *                               X"<<endl;
	cout<<"X                                 *        * *                                X"<<endl;
	cout<<"X                                                                             X"<<endl;
	cout<<"X                                                                             X"<<endl;
	cout<<"X *       *    * * *        * *            * * *    * * *   *      *   *   *  X"<<endl;
	cout<<"X  *     *     *     *    *                *    *   *       *      *   *   *  X"<<endl;
	cout<<"X   *   *      * * *        **             *     *  * *     *      * * *   *  X"<<endl;
	cout<<"X    * *       *               *           *    *   *       *      *   *   *  X"<<endl;
	cout<<"X     *     *  *      *    * *   *   *     * * *    * * *   * * *  *   *   *  X"<<endl;
	cout<<"X                                    *                                        X"<<endl;
	cout<<"X                                               --- MADE BY HARSH GUPTA....   X"<<endl;
	cout<<"X                                                                             X"<<endl;
	cout<<"X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X"<<endl;
	delay(3500);
	clrscr();
	lb:
	cout<<"\t       *************** WELCOME TO OUR SCHOOL ***************"<<endl;
	A:
	for(a=0;a<8;a++)
	cout<<endl;
	cout<<"\t\t\tENTER:"<<endl;
	cout<<"\t\t\t1. LOGIN..."<<endl;
	cout<<"\t\t\t2. I AM A STUDENT..."<<endl;
	cout<<"\t\t\t3. EXIT..."<<endl;
	cout<<endl<<"\t\t\tENTER YOUR CHOICE: ";
	cin>>k;
	clrscr();
	char arr[10];
	switch(k)
	{
		case 1:
		a:
		cout<<"\t"<<endl;
		cout<<"ENTER PASSWORD: "<<endl;
		for(int i=0;i<10;i++)
		{
			arr[i]=getch();
			cout<<"*";
		}
		if(strcmp(arr,"harshgupta")==0)
		{
			clrscr();
			cout<<"LOGGING IN";
			for(a=0;a<5;a++)
			{
				cout<<".";
				delay(250);
			}
			b:
			clrscr();
			cout<<"\t\t*************** ADMIN FILE IS READY ***************";
			for(a=0;a<8;a++)
			cout<<endl;
			cout<<"\t\t\tWHAT DO YOU WANT TO DO?"<<endl;
			cout<<endl<<"\t\t\t1. FACULTY.."<<endl;
			cout<<"\t\t\t2. STUDENT.."<<endl;
			cout<<"\t\t\t3. SHOW ALL STUDENTS.."<<endl;
			cout<<"\t\t\t4. LOGOUT.."<<endl;
			cout<<"\t\t\tEnter your choice: ";
			cin>>rec;
			switch(rec)
			{
				case 1:
					re:
					clrscr();
					cout<<"\t\t*************** TEACHER FILE IS READY ***************";
					for(a=0;a<8;a++)
						cout<<endl;
					cout<<"\t\t\t1. Add Faculty.."<<endl;
					cout<<"\t\t\t2. Search Faculty.."<<endl;
					cout<<"\t\t\t3. Delete Faculty.."<<endl;
					cout<<"\t\t\t4. Update Faculty.."<<endl;
					cout<<"\t\t\t5. Exit.."<<endl;
					cout<<endl<<"\t\t\Enter your choice: ";
					cin>>choi7;
					switch(choi7)
					{
						case 1:
							clrscr();
							addteacher();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 2:
							clrscr();
							searchteacher();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 3:
							clrscr();
							deleteteacher();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 4:
							clrscr();
							updateteacher();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 5:
							clrscr();
							cout<<"COMING OUT";
							for(a=0;a<5;a++)
							{
								cout<<".";
								delay(250);
							}
							clrscr();
							goto b;

						default:
						cout<<"Wrong choice want to enter more?"<<endl;
						cin>>choi;
						if(choi=='y'||choi=='Y')
						goto b;
						else
						break;
					}
					break;
				case 2:
					rece:
					clrscr();
					cout<<"\t\t*************** STUDENT FILE IS READY ***************";
					for(a=0;a<8;a++)
						cout<<endl;
					cout<<endl<<"\t\t\t1. Add students.."<<endl;
					cout<<"\t\t\t2. Search student.."<<endl;
					cout<<"\t\t\t3. Delete student.."<<endl;
					cout<<"\t\t\t4. Update student.."<<endl;
					cout<<"\t\t\t5. Logout.."<<endl;
					cout<<endl<<"\t\t\Enter your choice: ";
					cin>>a;
					switch(a)
					{
						case 1:
							clrscr();
							addstudent();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 2:
							clrscr();
							searchstudent();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 3:
							clrscr();
							deletestudent();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 4:
							clrscr();
							updatestudent();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 5:
							clrscr();
							cout<<"YOU ARE LOGGSNG OUT";
							for(a=0;a<5;a++)
							{
								cout<<".";
								delay(250);
							}
							clrscr();
							goto b;

						default:
						cout<<"Wrong choice want to enter more?"<<endl;
						cin>>choi;
						if(choi=='y'||choi=='Y')
						goto b;
						else
						break;
					}
					break;
				case 3:
					stu:
					clrscr();
					cout<<endl<<endl<<"\t\t\tEnter class of the student"<<endl<<endl;
					cout<<"\t\t\t1. First.."<<endl;
					cout<<"\t\t\t2. Second.."<<endl;
					cout<<"\t\t\t3. Third.."<<endl;
					cout<<"\t\t\t4. Fourth.."<<endl;
					cout<<"\t\t\t5. Fifth.."<<endl;
					cout<<"\t\t\t6. Sixth.."<<endl;
					cout<<"\t\t\t7. Seventh.."<<endl;
					cout<<"\t\t\t8. Eight.."<<endl;
					cout<<"\t\t\t9. Back"<<endl;
					cout<<"\t\t\tEnter your choice: ";
					cin>>choi1;
					switch(choi1)
					{
						case 1:
							sect:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(1,'A');
									clrscr();
									goto sect;
								case 2:
									clrscr();
									showstu(1,'B');
									clrscr();
									goto sect;
								case 3:
									clrscr();
									showstu(1,'C');
									clrscr();
									goto sect;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sect;
							}
						case 2:
							sec1:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(2,'A');
									clrscr();
									goto sec1;
								case 2:
									clrscr();
									showstu(2,'B');
									clrscr();
									goto sec1;
								case 3:
									clrscr();
									showstu(2,'C');
									clrscr();
									goto sec1;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec1;
							}
						case 3:
							sec2:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(3,'A');
									clrscr();
									goto sec2;
								case 2:
									clrscr();
									showstu(3,'B');
									clrscr();
									goto sec2;
								case 3:
									clrscr();
									showstu(3,'C');
									clrscr();
									goto sec2;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec2;
							}
						case 4:
							sec3:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(4,'A');
									clrscr();
									goto sec3;
								case 2:
									clrscr();
									showstu(4,'B');
									clrscr();
									goto sec3;
								case 3:
									clrscr();
									showstu(4,'C');
									clrscr();
									goto sec3;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec3;
							}
						case 5:
							sec4:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(5,'A');
									clrscr();
									goto sec4;
								case 2:
									clrscr();
									showstu(5,'B');
									clrscr();
									goto sec4;
								case 3:
									clrscr();
									showstu(5,'C');
									clrscr();
									goto sec4;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec4;
							}
						case 6:
							sec5:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(6,'A');
									clrscr();
									goto sec5;
								case 2:
									clrscr();
									showstu(6,'B');
									clrscr();
									goto sec5;
								case 3:
									clrscr();
									showstu(6,'C');
									clrscr();
									goto sec5;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec5;
							}
						case 7:
							sec6:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(7,'A');
									clrscr();
									goto sec6;
								case 2:
									clrscr();
									showstu(7,'B');
									clrscr();
									goto sec6;
								case 3:
									clrscr();
									showstu(7,'C');
									clrscr();
									goto sec6;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec6;
							}
						case 8:
							sec7:
							clrscr();
							cout<<"\tEnter the Section:"<<endl<<endl;
							cout<<"\t1. Section A"<<endl;
							cout<<"\t2. Section B"<<endl;
							cout<<"\t3. Section C"<<endl;
							cout<<"\t4. Back"<<endl;
							cout<<"\t Enter your Choice: ";
							cin>>choi5;
							switch(choi5)
							{
								case 1:
									clrscr();
									showstu(8,'A');
									clrscr();
									goto sec7;
								case 2:
									clrscr();
									showstu(8,'B');
									clrscr();
									goto sec7;
								case 3:
									clrscr();
									showstu(8,'C');
									clrscr();
									goto sec7;
								case 4:
									clrscr();
									goto stu;
								default:
									clrscr();
									cout<<"wrong choice enter again.."<<endl;
									delay(200);
									goto sec7;
							}
						case 9:
							clrscr();
							goto b;
						default:
							clrscr();
							cout<<"wrong choice enter again..";
							delay(500);
							goto stu;
					}
				case 4:
					clrscr();
					cout<<"\t\t\tLOGGING OUT";
					for(a=0;a<5;a++)
					{
						cout<<".";
						delay(250);
					}
					clrscr();
					goto A;

				default:
				cout<<"Wrong choice want to enter more?"<<endl;
				cin>>choi;
				if(choi=='y'||choi=='Y')
				goto b;
			}
		}
		else
		{
			cout<<endl<<"Wrong password"<<endl;
			cout<<endl<<"Want to try again?: ";
			cin>>choi;
			if(choi=='y'||choi=='Y')
			{
				clrscr();
				goto a;
			}
			else
			{
				clrscr();
				goto lb;
			}
		}
		break;
		case 2:
			st:
			clrscr();
			cout<<"\t\t*#*#*#*#*#*#*#* WELCOME TO STUDENT PORTAL *#*#*#*#*#*#*#*";
			for(a=0;a<8;a++)
				cout<<endl;
			cout<<"enter your student number: ";
			cin>>stucomp;
			result=compname(stucomp);
			if(result==1)
			{
				we:
				clrscr();
				for(a=0;a<8;a++)
				cout<<endl;
				cout<<"\t\t\t1. CHECK MARKS.."<<endl;
				cout<<"\t\t\t2. STUDENT INFORMATION.."<<endl;
				cout<<"\t\t\t3. EXIT.."<<endl;
				cout<<"\t\t\t ENTER YOUR CHOICE: ";
				cin>>choi3;
				switch(choi3)
				{
					case 1:
						clrscr();
						stumarks(stucomp);
						clrscr();
						cout<<"now enter again..";
						goto we;
					case 2:
						clrscr();
						stuinfo(stucomp);
						clrscr();
						cout<<"now enter again..";
						goto we;
					case 3:
						clrscr();
						cout<<"LOGGING OUT";
						for(a=0;a<5;a++)
						{
							cout<<".";
							delay(250);
						}
						goto A;
					default:
						clrscr();
						cout<<"Wrong choice....\n"<<"Want to enter more ? ";
						cin>>choi2;

						if(choi2=='y'||choi2=='Y')
						goto we;
				}
			}
			else
			{
				clrscr();
				cout<<"\t\tSORRY!!!!!"<<endl;
				cout<<endl<<"you are not a student of out group"<<endl;
				cout<<"enter again...";
				delay(500);
				goto st;
			}
		case 3:
			break;
		default:
			clrscr();
			cout<<"Wrong choice enter again..."<<endl;
			delay(700);
			goto A;
	}
}
