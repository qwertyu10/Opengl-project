#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>

void ellipse(float h,float k,float height,float width,float red,float green,float blue)
{
	float x,y;
	float hh=height*height;
	float ww=width*width;
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glColor3f(red,green,blue);
	for(y=-height;y<=height;y++)
		for(x=-width;x<=width;x++)
			if((x*x*hh)+(y*y*ww)<=hh*ww)glVertex2f(x+h,y+k);
	glEnd();
	
}

void circle(float h,float k,float radius,float red,float green,float blue)
{
	float x,y;
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glColor3f(red,green,blue);
	for(x=-radius;x<=radius;x++)
	   for(y=-radius;y<=radius;y++)
			if((x*x)+(y*y)<=(radius*radius))glVertex2f(x+h,y+k);
	glEnd();
}


void drawGrass(int x,int y)
{
	glColor3f(0.1,0.6324,0.1);
	glBegin(GL_TRIANGLES);
	 glVertex2f(x,y);
	 glVertex2f(x+50,y);
	 glVertex2f(x-25,y+200);
	 glVertex2f(x+25,y);
	 glVertex2f(x+50,y);
	 glVertex2f(x+25,y+100);

	 glVertex2f(x+50,y);
	 glVertex2f(x+70,y);
	 glVertex2f(x+50,y+200);
	glEnd();
}

void pot()
{
	glLineWidth(4.5);
	glColor3f(0.6,0.0,0.0);

	float cx=300,cy=373;    
	float num_segments=30.0;
	float theta = 2 * 3.1415926 / num_segments; 
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;
	int i;
    float x = 80;//x=r,we start at angle = 0 
    float y = 0; 

	
    glBegin(GL_LINE_LOOP);                             //ROUND PART OF POT
    for(i = 0; i < num_segments; i++) 
    { 
        glVertex2f(x + cx, y + cy);//output vertex 

        t = x;//apply the rotation matrix
        x = c * x - s * y;
        y = s * t + c * y;
    } 
    glEnd(); 
	glBegin(GL_LINES);                            //OTHER PART OF POT
	   glVertex2i(255,441);
	   glVertex2i(255,471);
	   glVertex2i(340,443);
	   glVertex2i(340,473);
	   glVertex2i(242,472);
	   glVertex2i(354,472);
	glEnd();
}

void crow(int state,int x,int y)
{
	
	glLineWidth(4.0);
	switch(state)
	{
	case 0:
		  glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 0:CROW LEFT FLY WING UP
		     glVertex2i(x,y);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y-10);
		   glEnd();
           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-41);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-41);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-41);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+100,y-90);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+96,y-86);
			  glVertex2i(x+110,y-96);
			  glVertex2i(x+110,y-96);
			  glVertex2i(x+106,y-104);
		   glEnd();

		   ellipse(x+93,y-20,30.0,25.0,0.0,0.0,0.0); //WING UP
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+45);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+25);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+14);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+4);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   break;

	case 1:glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 1:CROW LEFT FLY WING DOWN
		     glVertex2i(x,y);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y-10);
		   glEnd();
           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-41);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-41);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-41);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+100,y-90);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

		   ellipse(x+93,y-60,30.0,25.0,0.0,0.0,0.0); //WING DOWN
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x+80,y-60);
			  glVertex2i(x+113,y-60);
			  glVertex2i(x+93,y-120);
			   glVertex2i(x+93,y-60);
			   glVertex2i(x+67,y-60);
			   glVertex2i(x+80,y-120);
			    glVertex2i(x+93,y-60);
			    glVertex2i(x+133,y-60);
			    glVertex2i(x+103,y-114);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

	case 2:
			glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 2:CROW AT REST face left
		     glVertex2i(x,y);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y-10);
		   glEnd();
           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

		   ellipse(x+83,y-40,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x+100,y-25);
			  glVertex2i(x+100,y-60);
			  glVertex2i(x+155,y-40);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

	case 3:
			glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 3:CROW AT REST face right
		     glVertex2i(x,y);                       
			 glVertex2i(x-19,y+10);
			 glVertex2i(x-19,y);
			 glVertex2i(x-19,y-10);
		   glEnd();
           circle(x-34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x-42,y+13);
			  glVertex2i(x-80,y-25);
			  glVertex2i(x-48,y-43);
			  glVertex2i(x-39,y-15);
		   glEnd();
		   ellipse(x-90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-37);
			  glVertex2i(x-185,y-30);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-200,y-40);
			  glVertex2i(x-200,y-70);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-69);
			  glVertex2i(x-185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x-70,y-68);           //LEG PART
			  glVertex2i(x-90,y-68);
			  glVertex2i(x-84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x-84,y-92);
			  glVertex2i(x-84,y-110);
			  glVertex2i(x-75,y-110);
			  glVertex2i(x-89,y-110);
		   glEnd();

		   ellipse(x-83,y-40,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x-100,y-25);
			  glVertex2i(x-100,y-60);
			  glVertex2i(x-155,y-40);
		   glEnd();

		   circle(x-27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x-25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

		

	 case 4:
			glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 4:CROW FLY right WING UP
		     glVertex2i(x,y);                       
			 glVertex2i(x-19,y+10);
			 glVertex2i(x-19,y);
			 glVertex2i(x-19,y-10);
		   glEnd();
           circle(x-34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x-42,y+13);
			  glVertex2i(x-80,y-25);
			  glVertex2i(x-48,y-43);
			  glVertex2i(x-39,y-15);
		   glEnd();
		   ellipse(x-90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-37);
			  glVertex2i(x-185,y-30);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-200,y-40);
			  glVertex2i(x-200,y-70);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-69);
			  glVertex2i(x-185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x-70,y-68);           //LEG PART
			  glVertex2i(x-90,y-68);
			  glVertex2i(x-84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x-84,y-92);
			  glVertex2i(x-84,y-110);
			  glVertex2i(x-75,y-110);
			  glVertex2i(x-89,y-110);
		   glEnd();

		     ellipse(x-93,y-20,30.0,25.0,0.0,0.0,0.0); //WING UP
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x-80,y+10);
			  glVertex2i(x-100,y-57);
			  glVertex2i(x-160,y+45);
			  glVertex2i(x-80,y+10);
			  glVertex2i(x-100,y-57);
			  glVertex2i(x-160,y+25);
			  glVertex2i(x-80,y+10);
			  glVertex2i(x-100,y-57);
			  glVertex2i(x-160,y+14);
			  glVertex2i(x-80,y+10);
			  glVertex2i(x-100,y-57);
			  glVertex2i(x-160,y+4);
		   glEnd();

		   circle(x-27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x-25,y+4,0.0,0.0,0.0,0.0);
		   break;

	case 5:
			glBegin(GL_TRIANGLE_FAN);                //MOUTH                         CASE 5:CROW FLY right WING DOWN
		     glVertex2i(x,y);                       
			 glVertex2i(x-19,y+10);
			 glVertex2i(x-19,y);
			 glVertex2i(x-19,y-10);
		   glEnd();
           circle(x-34,y,15,0.2,0.2,0.2);          // HEAD         
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x-42,y+13);
			  glVertex2i(x-80,y-25);
			  glVertex2i(x-48,y-43);
			  glVertex2i(x-39,y-15);
		   glEnd();
		   ellipse(x-90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-37);
			  glVertex2i(x-185,y-30);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-200,y-40);
			  glVertex2i(x-200,y-70);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-69);
			  glVertex2i(x-185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x-70,y-68);           //LEG PART
			  glVertex2i(x-90,y-68);
			  glVertex2i(x-84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x-84,y-92);
			  glVertex2i(x-84,y-110);
			  glVertex2i(x-75,y-110);
			  glVertex2i(x-89,y-110);
		   glEnd();

		   ellipse(x-93,y-60,30.0,25.0,0.0,0.0,0.0); //WING DOWN
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x-80,y-60);
			  glVertex2i(x-113,y-60);
			  glVertex2i(x-93,y-120);
			   glVertex2i(x-93,y-60);
			   glVertex2i(x-67,y-60);
			   glVertex2i(x-80,y-120);
			    glVertex2i(x-93,y-60);
			    glVertex2i(x-133,y-60);
			    glVertex2i(x-103,y-114);
		   glEnd();

		   circle(x-27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x-25,y+4,0.0,0.0,0.0,0.0);
		   break;
	
	 case 6:
           glBegin(GL_TRIANGLES);                //MOUTH               CASE 2:CROW LOOK DOWN face left         
		     glVertex2i(x+25,y-102);
			 glVertex2i(x+10,y-124);
			 glVertex2i(x+14,y-92);
			 glVertex2i(x+14,y-92);
			 glVertex2i(x+26,y-128);
			 glVertex2i(x+35,y-95);
		   glEnd();
		   
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);       //NECK
			  glVertex2i(x+34,y-85);
		      glVertex2i(x+16,y-76);
		      glVertex2i(x+50,y-45);    
			  glVertex2i(x+64,y-75);
		  glEnd();
		  
		   ellipse(x+90,y-60,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

		   ellipse(x+90,y-44,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x+100,y-25);
			  glVertex2i(x+100,y-60);
			  glVertex2i(x+155,y-40);
		   glEnd();
		   circle(x+25,y-94,15,0.2,0.2,0.2);     //HEAD
		    
		   circle(x+16,y-96,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+15,y-96,0.0,0.0,0.0,0.0);
		   break;

	 case 7:
		    glBegin(GL_TRIANGLES);                //MOUTH               CASE 2:CROW LOOK DOWN face right         
		     glVertex2i(x-25,y-102);
			 glVertex2i(x-10,y-124);
			 glVertex2i(x-14,y-92);
			 glVertex2i(x-14,y-92);
			 glVertex2i(x-26,y-128);
			 glVertex2i(x-35,y-95);
		   glEnd();
		   
		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);       //NECK
			  glVertex2i(x-34,y-85);
		      glVertex2i(x-16,y-76);
		      glVertex2i(x-50,y-45);    
			  glVertex2i(x-64,y-75);
		  glEnd();
		  
		   ellipse(x-90,y-60,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-37);
			  glVertex2i(x-185,y-30);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-200,y-40);
			  glVertex2i(x-200,y-70);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-69);
			  glVertex2i(x-185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x-70,y-68);           //LEG PART
			  glVertex2i(x-90,y-68);
			  glVertex2i(x-84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x-84,y-92);
			  glVertex2i(x-84,y-110);
			  glVertex2i(x-75,y-110);
			  glVertex2i(x-89,y-110);
		   glEnd();

		   ellipse(x-90,y-44,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x-100,y-25);
			  glVertex2i(x-100,y-60);
			  glVertex2i(x-155,y-40);
		   glEnd();
		   circle(x-25,y-94,15,0.2,0.2,0.2);     //HEAD
		    
		   circle(x-16,y-96,2.0,1.0,1.0,1.0);    //EYE
		   circle(x-15,y-96,0.0,0.0,0.0,0.0);
		   break;

	 case 8:
			glBegin(GL_TRIANGLES);                //MOUTH                         CASE 8:CROW AT REST face left stone in mouth
		     glVertex2i(x,y+10);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y);
			 glVertex2i(x,y-10);
			 glVertex2i(x+19,y-10);
		   glEnd();

		   ellipse((float)x-14,(float)y,5.0,15.0,0.0,0.0,0.0);

           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD  

		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

		   ellipse(x+83,y-40,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x+100,y-25);
			  glVertex2i(x+100,y-60);
			  glVertex2i(x+155,y-40);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

	 case 9:
			glBegin(GL_TRIANGLES);                //MOUTH                         CASE 9:CROW AT REST face right stone in mouth
		     glVertex2i(x,y+10);                       
			 glVertex2i(x-19,y+10);
			 glVertex2i(x-19,y);
			 glVertex2i(x-19,y);
			 glVertex2i(x,y-10);
			 glVertex2i(x-19,y-10);
		   glEnd();

		   ellipse((float)x+14,(float)y,5.0,15.0,0.0,0.0,0.0);

           circle(x-34,y,15,0.2,0.2,0.2);          // HEAD  

		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x-42,y+13);
			  glVertex2i(x-80,y-25);
			  glVertex2i(x-48,y-43);
			  glVertex2i(x-39,y-15);
		   glEnd();
		   ellipse(x-90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-37);
			  glVertex2i(x-185,y-30);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-200,y-40);
			  glVertex2i(x-200,y-70);
			  glVertex2i(x-130,y-50);
			  glVertex2i(x-185,y-69);
			  glVertex2i(x-185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x-70,y-68);           //LEG PART
			  glVertex2i(x-90,y-68);
			  glVertex2i(x-84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x-84,y-92);
			  glVertex2i(x-84,y-110);
			  glVertex2i(x-75,y-110);
			  glVertex2i(x-89,y-110);
		   glEnd();

		   ellipse(x-83,y-40,15.0,35.0,0.0,0.0,0.0); //WING
		   glBegin(GL_TRIANGLES);
		      glVertex2i(x-100,y-25);
			  glVertex2i(x-100,y-60);
			  glVertex2i(x-155,y-40);
		   glEnd();

		   circle(x-27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x-25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

	 case 10:
			glBegin(GL_TRIANGLES);                //MOUTH                         CASE 10:CROW fly, face left, stone in mouth,WING up
		     glVertex2i(x,y+10);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y);
			 glVertex2i(x,y-10);
			 glVertex2i(x+19,y-10);
		   glEnd();

		   ellipse((float)x-14,(float)y,5.0,15.0,0.0,0.0,0.0);

           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD  

		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

		    ellipse(x+93,y-20,30.0,25.0,0.0,0.0,0.0); //WING UP
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+45);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+25);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+14);
			  glVertex2i(x+80,y+10);
			  glVertex2i(x+100,y-57);
			  glVertex2i(x+160,y+4);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;

	 case 11:
			glBegin(GL_TRIANGLES);                //MOUTH                         CASE 10:CROW fly, face left, stone in mouth, WING down
		     glVertex2i(x,y+10);                       
			 glVertex2i(x+19,y+10);
			 glVertex2i(x+19,y);
			 glVertex2i(x+19,y);
			 glVertex2i(x,y-10);
			 glVertex2i(x+19,y-10);
		   glEnd();

		   ellipse((float)x-14,(float)y,5.0,15.0,0.0,0.0,0.0);

           circle(x+34,y,15,0.2,0.2,0.2);          // HEAD  

		   glColor3f(0.2,0.2,0.2);
		   glBegin(GL_QUADS);                      // NECK
		      glVertex2i(x+42,y+13);
			  glVertex2i(x+80,y-25);
			  glVertex2i(x+48,y-43);
			  glVertex2i(x+39,y-15);
		   glEnd();
		   ellipse(x+90,y-50,20.0,40.0,0.2,0.2,0.2);   //BODY

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_TRIANGLES);                      //TAIL FEATHER
		      glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-37);
			  glVertex2i(x+185,y-30);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+200,y-40);
			  glVertex2i(x+200,y-70);
			  glVertex2i(x+130,y-50);
			  glVertex2i(x+185,y-69);
			  glVertex2i(x+185,y-79);
			  glColor3f(0.2,0.2,0.2);
			  glVertex2i(x+70,y-68);           //LEG PART
			  glVertex2i(x+90,y-68);
			  glVertex2i(x+84,y-95);
		   glEnd();
		   glLineWidth(2.0);

		   glColor3f(0.0,0.0,0.0);
		   glBegin(GL_LINES);                 //LEG
		      glVertex2i(x+84,y-92);
			  glVertex2i(x+84,y-110);
			  glVertex2i(x+75,y-110);
			  glVertex2i(x+89,y-110);
		   glEnd();

          ellipse(x+93,y-60,30.0,25.0,0.0,0.0,0.0); //WING DOWN
		  glBegin(GL_TRIANGLES);
		      glVertex2i(x+80,y-60);
			  glVertex2i(x+113,y-60);
			  glVertex2i(x+93,y-120);
			   glVertex2i(x+93,y-60);
			   glVertex2i(x+67,y-60);
			   glVertex2i(x+80,y-120);
			    glVertex2i(x+93,y-60);
			    glVertex2i(x+133,y-60);
			    glVertex2i(x+103,y-114);
		   glEnd();

		   circle(x+27,y+4,2.0,1.0,1.0,1.0);    //EYE
		   circle(x+25,y+4,0.0,0.0,0.0,0.0);
		   
		         break;
   }
 glLineWidth(4.5);
	
}

void static_background()
{   
	
	 glBegin(GL_POLYGON); 
	   glColor3f(0.0,0.0,1.0);          //SKY
		glVertex2i(0,300);
	    glVertex2i(1300,300);
		glVertex2i(1300,1300);
		glVertex2i(0,1300);
	 glEnd();
	circle(200,1000,100,1.0,0.5,0.0);    //SUN
	circle(300,373,76,1.0,1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	  glVertex2i(257,443);
	  glVertex2i(257,468);
	  glVertex2i(338,443);
	  glVertex2i(338,469);
	glEnd();
    glBegin(GL_POLYGON);            //GROUND
	    glColor3f(0.0,0.9,0.0);
		glVertex2i(0,300);
	    glVertex2i(1300,300);
		glVertex2i(1300,0);
		glVertex2i(0,0);
	glEnd();	
	glBegin(GL_QUADS);            //POLE
	    glColor3f(0.4,0.0,0.0);
		glVertex2i(850,300);      
		glVertex2i(880,300);
		glVertex2i(880,900);
		glVertex2i(850,900);
	glEnd();
	glBegin(GL_POLYGON);       //POLE BOARDS
	    glColor3f(0.6,0.0,0.0);
		glVertex2i(900,800);      
		glVertex2i(800,800);
		glVertex2i(775,775);
		glVertex2i(800,750);
		glVertex2i(900,750);
		glVertex2i(930,750);
		glVertex2i(980,750);
		glVertex2i(980,800);
		glVertex2i(930,800);
		glVertex2i(900,800);
	glEnd();
	glBegin(GL_POLYGON);
	  glVertex2i(850,700);
	  glVertex2i(800,700);
	  glVertex2i(800,650);
	  glVertex2i(880,650);
	  glVertex2i(980,650);
	  glVertex2i(1005,675);
	  glVertex2i(980,700);
	  glVertex2i(880,700);
	glEnd();   
	
	drawGrass(50,300);             //GRASS
	drawGrass(70,300);
	drawGrass(700,300);
	drawGrass(950,300);
	drawGrass(970,300);
	drawGrass(990,300);

	pot();                         //POT BEFORE ADDING STONE
	
	ellipse(370.0,300.0,5.0,10.0,0.0,0.0,0.0);	   
	ellipse(390.0,280.0,5.0,10.0,0.0,0.0,0.0);    	
	ellipse(440.0,300.0,5.0,10.0,0.0,0.0,0.0);	
	ellipse(800.0,260.0,5.0,25.0,0.0,0.0,0.0);	
}


void display()
{    
  int i=0;
 
 for(i=0;i<300;i++)                 //crow at rest on pole
  {   
	  static_background();
	  crow(2,792,1010);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
     glEnd();
	 ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	 ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
   }

   int xloc=792,yloc=1010;            //pole location
   int j;                              //to crow state
  for(i=0;i<600;i++)                                  //crow flies from pole to pot
   {   
	   j=i%2;
	   static_background();
       crow(j,xloc,yloc);
	   if(xloc>267)xloc--;           //move until pot location
	   if(yloc>583)yloc--;
	   glColor3f(0.0,0.0,0.8);
	    glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
       glEnd();
	   ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	   ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	    glFlush();
	   glClear(GL_COLOR_BUFFER_BIT);
   }
	
   for(i=0;i<300;i++)               //crow rest on pot
  {   
	  static_background();
	  crow(2,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);		
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
   }

    for(i=0;i<300;i++)               //crow look down on pot.    get to know low water level
  {   
	  static_background();
	  crow(6,266,582);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
   }
  
	 for(i=0;i<300;i++)               //crow rest on pot right side face.     turn to right and saw stones
   {   
	  static_background();
	  crow(3,426,582);
	   glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
   }


     xloc=426;
	 yloc=582;
	 j=4;
	  for(i=0;i<500;i++)                 //crow flies from  pot to 1 stone
     {   
	   static_background();
       crow(j,xloc,yloc);
	   if(j==4)j=5;
	   else j=4;
	   if(xloc<660)xloc++;           //move until stone 1 location
	   if(yloc>410)yloc--;
	   glColor3f(0.0,0.0,0.8);
	    glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
       glEnd();
	   ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	   ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);		
	    glFlush();
	   glClear(GL_COLOR_BUFFER_BIT);
     }

	   for(i=0;i<200;i++)               //crow rest right side face.     at stones
   {   
	  static_background();
	  crow(3,660,410);
	   glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(650.0,292.0,5.0,15.0,0.0,0.0,0.0);	
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
   }

	  for(i=0;i<300;i++)               //crow look down to pick stone 1
    {   
	  static_background();
	  ellipse(650.0,286.0,5.0,15.0,0.0,0.0,0.0);	
	  crow(7,660,410);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

    for(i=0;i<300;i++)                          //crow picks stone
    {   
	  static_background();	
	  crow(9,660,410);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

    for(i=0;i<200;i++)                                //crow with stone turn left
    {   
	  static_background();	
	  crow(8,500,410);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);		
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

    
     xloc=500;
	 yloc=410;
	 j=10;
	  for(i=0;i<500;i++)                           //crow flies from  1 stone to pot
     {   
	   static_background();
       crow(j,xloc,yloc);
	   if(j==10)j=11;
	   else j=10;
	   if(xloc>267)xloc--;           //move until stone 1 location
	   if(yloc<583)yloc++;
	   glColor3f(0.0,0.0,0.8);
	    glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
       glEnd();
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);		
	    glFlush();
	   glClear(GL_COLOR_BUFFER_BIT);
     }

	   for(i=0;i<200;i++)                                   //crow rest on pot
    {   
	  static_background();
	  crow(8,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(223,380);
		glVertex2i(380,380);
      glEnd();
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

	 for(i=0;i<300;i++)                                    //crow rest put stone into water
    {   
	  static_background();
	  crow(6,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL rises
	    glVertex2i(235,420);
		glVertex2i(367,420);
      glEnd();
    ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);	
	ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	ellipse(800.0,260.0,5.0,25.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }
   
	for(i=0;i<300;i++)                                          //crow turn right for another stone
    {   
	  static_background();
	  crow(3,426,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(235,420);
		glVertex2i(367,420);
      glEnd();
    ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);	
	ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	ellipse(800.0,260.0,5.0,25.0,0.0,0.0,0.0);	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }
   
	xloc=426;
	 yloc=582;
	 j=4;
	  for(i=0;i<600;i++)                                          //crow flies from  pot to 1 stone
     {   
	   static_background();
       crow(j,xloc,yloc);
	   if(j==4)j=5;
	   else j=4;
	   if(xloc<760)xloc++;           //move until stone 1 location
	   if(yloc>398)yloc--;
	   glColor3f(0.0,0.0,0.8);
	    glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(235,420);
		glVertex2i(367,420);
       glEnd();
	  ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);	
	  ellipse(750.0,280.0,5.0,15.0,0.0,0.0,0.0);	
	    glFlush();
	   glClear(GL_COLOR_BUFFER_BIT);
     }

	 for(i=0;i<300;i++)                                                //crow look down to pick stone 2
    {   
	  static_background();
	  ellipse(750.0,275.0,5.0,15.0,0.0,0.0,0.0);	//stone 2
	  crow(7,760,400);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	   glVertex2i(235,420);
	   glVertex2i(367,420);
      glEnd();
	  ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone already in water
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
     }

     for(i=0;i<300;i++)                                                 //crow picks stone
    {   
	  static_background();	
	  crow(9,760,400);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(235,420);
		glVertex2i(367,420);
      glEnd();
	  ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

	 for(i=0;i<200;i++)                                                 //crow with stone2 turn left
    {   
	  static_background();	
	  crow(8,590,400);
	   glColor3f(0.0,0.0,0.8);
	  glBegin(GL_LINES);                          //WATER LEVEL
	    glVertex2i(235,420);
		glVertex2i(367,420);
      glEnd();
	  ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

	 xloc=590;
	 yloc=410;
	 j=10;
	  for(i=0;i<500;i++)                                                 //crow flies from  stone 2 to pot
     {   
	   static_background();
       crow(j,xloc,yloc);
	   if(j==10)j=11;
	   else j=10;
	   if(xloc>267)xloc--;           //move until pot location
	   if(yloc<583)yloc++;
	   glColor3f(0.0,0.0,0.8);
	    glBegin(GL_LINES);                          //WATER LEVEL
	      glVertex2i(235,420);
		  glVertex2i(367,420);
       glEnd();
	   ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water	
	   glFlush();
	   glClear(GL_COLOR_BUFFER_BIT);
     }

	   for(i=0;i<200;i++)                                                   //crow rest on pot
    {   
	  static_background();
	  crow(8,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	      glVertex2i(235,420);
		  glVertex2i(367,420);
      glEnd();
      ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water	
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

	 for(i=0;i<300;i++)                                                    //crow  put stone 2 into water
    {   
	  static_background();
	  crow(6,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL rises
	    glVertex2i(255,460);
		glVertex2i(340,460);
      glEnd();
    ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);	//stone 1 already in water
	ellipse(287.0,322.0,5.0,15.0,0.0,0.0,0.0);
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }
  
	 for(i=0;i<200;i++)                                                    //crow rest on pot
    {   
	  static_background();
	  crow(2,266,582);
	  glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	      glVertex2i(255,460);
		  glVertex2i(340,460);
      glEnd();
      ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water
	  ellipse(287.0,322.0,5.0,15.0,0.0,0.0,0.0);
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }

    for(i=0;i<500;i++)               //crow look down on pot.    get to know low water level
    {   
	  static_background();
	  crow(6,266,582);
	   glColor3f(0.0,0.0,0.8);
	   glBegin(GL_LINES);                          //WATER LEVEL
	      glVertex2i(255,460);
		  glVertex2i(340,460);
      glEnd();
      ellipse(280.0,312.0,5.0,15.0,0.0,0.0,0.0);  //stone 1 already in water
	  ellipse(287.0,322.0,5.0,15.0,0.0,0.0,0.0);
	  glFlush();
      glClear(GL_COLOR_BUFFER_BIT);
    }
	
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);      
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,2022);
	glutCreateWindow("thirsty crow");
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1300.0,0.0,1300.0);
	glutDisplayFunc(display);
	glutMainLoop();
}