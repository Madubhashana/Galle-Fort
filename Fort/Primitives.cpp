#include <math.h>
#include <iostream>
#include "GL\glut.h"
#define PI 3.1428571428571428571428571428571
GLfloat wall_anlge = atan(5);
GLfloat wall_anlge2 = 57.5;

void ground(){
	glColor3f(0.0, 0.0, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(500.0, 0.0, 0.1);
	glVertex3f(500.0, -500.0, 0.1);
	glVertex3f(-500.0, -500.0, 0.1);
	glVertex3f(-500.0, 0.0, 0.1);
	glEnd();

	glColor3f(0.0, 0.4, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(50, 20.0);
	glVertex2f(50, 8.0);
	glVertex2f(57, 0.0);
	glVertex2f(57, -3.0);
	glVertex2f(56, -5.0);
	glVertex2f(59, -8.0);
	glVertex2f(60, -10.6);
	glVertex2f(61.2, -23.6);
	glVertex2f(-32, -23.6);
	glVertex2f(-30, -15);
	glVertex2f(-31, -9.6);
	glVertex2f(-36, 0.0);
	glVertex2f(-32.0, 8.0);
	glVertex2f(-32.0, 20.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-32, -23.6);
	glVertex2f(61.2, -23.6);
	glVertex2f(56.5, -31.7);
	glVertex2f(56.7, -46.4);
	glVertex2f(58, -49.4);
	glVertex2f(60.13, -52.8);
	glVertex2f(-40, -36);
	glVertex2f(-32, -23.6);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(60.13, -52.8);
	glVertex2f(-40, -36);
	glVertex2f(-51, -48);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(60.13, -52.8);
	glVertex2f(-57.6, -51);
	glVertex2f(-51, -48);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(60.13, -52.8);
	glVertex2f(-57.6, -51);
	glVertex2f(-70, -53);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(60.13, -52.8);
	glVertex2f(-70, -53);
	glVertex2f(-87.1, -52);
	glVertex2f(-87.6, -54.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(50.8, -51);
	glVertex2f(48.2, -84.1);
	glVertex2f(-1.4, -132.5);
	glVertex2f(-5.8, -132.5);
	glVertex2f(-36.1, -163.098);
	glVertex2f(-86.6, -147.7);
	glVertex2f(-90.7, -106.2);
	glVertex2f(-92.78, -104.29);
	glVertex2f(-87.6, -54.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-87.6, -54.4);
	glVertex2f(-95.7, -78.8);
	glVertex2f(-92.78, -104.29);
	glEnd();


}
void Wall(float h, float w){
	glBegin(GL_POLYGON);
	glVertex3f(-w / 2, 0, 0);
	glVertex3f(-w / 2, h, 0);
	glVertex3f(w / 2, h, 0);
	glVertex3f(w / 2, 0, 0);
	glEnd();
}
void Wall_special(){
	glPushMatrix();
	glTranslated(-6.0, 0.0, 0.0);
	Wall(2.5, 2.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.0, 1.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.5, 2.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.0, 1.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.5, 2.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.0, 1.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.5, 2.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.0, 1.0);
	glTranslated(1.5, 0.0, 0.0);
	Wall(2.5, 2.0);
	glPopMatrix();
}
void wall_left_angle(float h, GLfloat wall_anlge){
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -h / tan(wall_anlge));
	glVertex3f(-h / tan(wall_anlge), 0, 0);
	glEnd();
}
void wall_right_angle(float h, GLfloat wall_anlge){
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -h / tan(wall_anlge));
	glVertex3f(h / tan(wall_anlge), 0, 0);
	glEnd();
}
void wall_middle(float h, float w){
	glBegin(GL_POLYGON);
	glVertex3f(-w / 2, 0, 0);
	glVertex3f(-w / 2, h, -0.2);
	glVertex3f(w / 2, h, -0.2);
	glVertex3f(w / 2, 0, 0);
	glEnd();
}
void ground_levels(){
	glColor3f(0.0, 0.5, 0.0);

	//L-01
	glBegin(GL_POLYGON);
	glVertex3f(-2.109998, 0.9, -10.640148);
	glVertex3f(-2.289998, 0.9, -12.630194);
	glVertex3f(-11.840176, 0.9, -11.790174);
	glVertex3f(-10.290140, 0.9, -9.940132);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-11.840176, 0.9, -11.790174);
	glVertex3f(-11.490168, 0.9, -7.830084);
	glVertex3f(-9.970133, 0.9, -6.240047);
	glVertex3f(-10.290140, 0.9, -9.940132);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-11.490168, 0.9, -7.830084);
	glVertex3f(-23.290438, 0.9, -3.519997);
	glVertex3f(-23.120434, 0.9, -1.459999);
	glVertex3f(-9.970133, 0.9, -6.240047);
	glEnd();

	//L-02
	glBegin(GL_POLYGON);
	glVertex3f(2.289998, 0.9, -11.020157);
	glVertex3f(12.820198, 0.9, -11.950178);
	glVertex3f(12.670195, 0.9, -13.940224);
	glVertex3f(2.109998, 0.9, -13.020203);
	glEnd();

	//L-03
	glBegin(GL_POLYGON);
	glVertex3f(32.51, 0.9, -13.48);
	glVertex3f(44.05, 0.9, -14.48);
	glVertex3f(43.860, 0.9, -16.67);
	glVertex3f(32.32, 0.9, -15.65);
	glEnd();



	glColor3f(0.0, 0.6, 0.0);
	//L-04
	glBegin(GL_POLYGON);
	glVertex3f(-11.84, 1.9, -11.8);
	glVertex3f(-22.010137, 1.9, -18.09);
	glVertex3f(-25.850225, 1.9, -16.98);
	glVertex3f(-24.630468, 1.9, -3.05);
	glVertex3f(-11.5, 1.9, -7.83);
	glEnd();

	//L-05
	glBegin(GL_POLYGON);
	glVertex3f(32.31, 1.9, -15.66);
	glVertex3f(32.98, 1.9, -8.02);
	glVertex3f(23.079877, 1.9, 1.870259);
	glVertex3f(13.2, 1.9, -8.02);
	glVertex3f(12.67, 1.9, -13.95);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-22.250143, 1.9, -18.93);
	glVertex3f(-22.010137, 1.9, -18.09);
	glVertex3f(-11.84, 1.9, -11.8);
	glVertex3f(43.860162, 1.9, -16.67);
	glVertex3f(54.14, 1.9, -23.82);
	glVertex3f(48.47, 1.9, -25.12);
	glEnd();

	//L-06
	glBegin(GL_POLYGON);
	glVertex3f(43.860162, 1.9, -16.67);
	glVertex3f(44.1, 1.9, -13.98);
	glVertex3f(57.240, 1.9, -9.2);
	glVertex3f(56.010183, 1.9, -23.13);
	glVertex3f(54.14, 1.9, -23.82);
	glEnd();

	//L-07
	glBegin(GL_POLYGON);
	glVertex3f(53.13, 1.9, -52.8);
	glVertex3f(60.13, 1.9, -52.8);
	glVertex3f(57.110015, 1.9, -60.84013);
	glVertex3f(52.88, 1.9, -60.02011);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(48.47, 1.9, -25.12);
	glVertex3f(54.14, 1.9, -23.82);
	glVertex3f(51.8, 1.9, -91.01);
	glVertex3f(46.49, 1.9, -82.1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(51.8, 1.9, -90.99);
	glVertex3f(41.8, 1.9, -90.99);
	glVertex3f(46.57, 1.9, -81.93);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(34.02, 1.9, -98.76);
	glVertex3f(36.32, 1.9, -100.7);
	glVertex3f(34.12, 1.9, -106.27);
	glVertex3f(30.25, 1.9, -102.53);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(46.57, 1.9, -82.0);
	glVertex3f(41.8, 1.9, -90.99);
	glVertex3f(1.96, 1.9, -130.82);
	glVertex3f(-2.3, 1.9, -130.88);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.96, 1.9, -130.82);
	glVertex3f(-2.3, 1.9, -130.88);
	glVertex3f(-7.270117, 1.9, -131.32);
	glVertex3f(-5.430075, 1.9, -133.67);
	glVertex3f(-1.877, 1.9, -137.99);
	glVertex3f(6.2, 1.9, -135.05);
	glEnd();

	//L-08
	glBegin(GL_POLYGON);
	glVertex3f(-7.270117, 1.9, -131.32);
	glVertex3f(-5.430075, 1.9, -133.67);
	glVertex3f(-33.02, 1.9, -162.641);
	glVertex3f(-37.18, 1.9, -160.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-33.02, 1.9, -162.641);
	glVertex3f(-30.85, 1.9, -164.710013);
	glVertex3f(-32.44, 1.9, -168.37);
	glVertex3f(-34.23, 1.9, -169.250116);
	glVertex3f(-37.87, 1.9, -169.440121);
	glVertex3f(-39.65, 1.9, -168.5501);
	glVertex3f(-42.39, 1.9, -165.650034);
	glVertex3f(-41.534, 1.9, -162.78);
	glVertex3f(-37.18, 1.9, -160.2);
	glEnd();

	//L-09
	glBegin(GL_POLYGON);
	glVertex3f(-41.504, 1.9, -162.77);
	glVertex3f(-37.18, 1.9, -160.2);
	glVertex3f(-84.43, 1.9, -147.19);
	glVertex3f(-84.69, 1.9, -149.99);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-84.43, 1.9, -147.19);
	glVertex3f(-84.69, 1.9, -149.99);
	glVertex3f(-87.531, 1.9, -150.941);
	glVertex3f(-89.061, 1.9, -150.491);
	glVertex3f(-89.751014, 1.9, -148.631);
	glVertex3f(-87.791, 1.9, -145.15);
	glEnd();

	//L-10
	glBegin(GL_POLYGON);
	glVertex3f(-84.43, 1.9, -147.19);
	glVertex3f(-87.791, 1.9, -145.15);
	glVertex3f(-91.15, 1.9, -110.34);
	glVertex3f(-89.52, 1.9, -104.49);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-91.13, 1.9, -110.34);
	glVertex3f(-95.27, 1.9, -105.98);
	glVertex3f(-92.78, 1.9, -104.29);
	glVertex3f(-89.52, 1.9, -104.49);
	glEnd();

	//small front
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(9.3, 3.0, -6.1);
	glScaled(0.6, 0.0, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(32.31, 1.9, -15.66);
	glVertex3f(32.98, 1.9, -8.02);
	glVertex3f(23.079877, 1.9, 1.870259);
	glVertex3f(13.2, 1.9, -8.02);
	glVertex3f(12.67, 1.9, -13.95);
	glEnd();
	glPopMatrix();

}
void castsel(){
	glColor3f(0.5, 0.5, 0.5);
	//18
	glPushMatrix();
	glTranslated(-2.0, 0.0, -11.65);
	glRotated(95.0, 0.0, 1.0, 0.0);
	wall_middle(1.0, 2.0);
	glPushMatrix();
	glTranslated(-1.00, 0.0, 0.0);
	wall_left_angle(1.0, wall_anlge);
	glPopMatrix();
	glPopMatrix();


	//19
	glPushMatrix();
	glTranslated(2.0, 0.0, -12.0);
	glRotated(-85.0, 0.0, 1.0, 0.0);
	wall_middle(1.0, 2.0);
	glPushMatrix();
	glTranslated(1.0, 0.0, 0.0);
	wall_right_angle(1.0, wall_anlge);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-2.094, 0.0, -10.44);
	glRotated(5, 0.0, 1.0, 0.0);
	//17
	wall_right_angle(1.0, wall_anlge);
	glTranslated(-4.12, 0.0, 0.0);
	wall_middle(1.0, 8.24);
	//4
	glTranslated(-0.675, 0.0, -2.2);
	Wall(2.0, 9.6);
	//I-1
	glTranslated(-4.8535, 0.0, -8.02);
	Wall(2, 19.4);
	glTranslated(37.65, 0.0, 0.0);
	Wall(2, 47.3);
	glPopMatrix();

	glColor3f(0.5, 0.5, 0.5);


	glPushMatrix();
	glTranslated(2.302, 0.0, -10.824);
	glRotated(5, 0.0, 1.0, 0.0);
	//20
	wall_left_angle(1.0, wall_anlge);
	glTranslated(5.3, 0.0, 0);
	wall_middle(1.0, 10.6);
	//21
	glTranslated(30.8106, 0.0, 0.0);
	Wall(1.0, 11.6);
	//5
	glTranslated(-30.8106, 0.0, -2.2);
	Wall(2.0, 10.6);
	glPopMatrix();

	//6
	glPushMatrix();
	glTranslated(12.93, 0.0, -11.0);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall(2.5, 6.0);
	glPopMatrix();

	//7
	glPushMatrix();
	glTranslated(18.14, 0.0, -3.062);
	glRotated(-45.0, 0.0, 1.0, 0.0);
	Wall_special();
	glPopMatrix();

	//8
	glPushMatrix();
	glTranslated(28.031, 0.0, -3.068);
	glRotated(45.0, 0.0, 1.0, 0.0);
	Wall_special();
	glPopMatrix();

	//9
	glPushMatrix();
	glTranslated(32.645, 0.0, -11.835);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall(2.5, 7.67);
	glPopMatrix();

	//10
	glPushMatrix();
	glTranslated(38.09, 0.0, -16.160);
	glRotated(5, 0.0, 1.0, 0.0);
	Wall(2.0, 11.6);
	glPopMatrix();

	//3
	glPushMatrix();
	glTranslated(-11.67, 0.0, -9.81);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall(2.5, 4.0);
	//16
	glPushMatrix();
	glRotated(180, 0.0, 1.0, 0.0);
	glTranslated(-1.81, 0.0, 1.591);
	wall_middle(1.0, 3.8);
	glTranslated(-1.9, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -0.2);
	glVertex3f(-0.1565, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslated(-18.07, 0.0, -5.43);
	glRotated(20.0, 0.0, 1.0, 0.0);
	Wall_special();

	//15
	glTranslated(0.895, 0.0, 2.218);
	wall_middle(1.0, 14);
	glTranslated(7.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -0.2);
	glVertex3f(0.155, 0, 0);
	glEnd();

	glTranslated(-14.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -0.2);
	glVertex3f(-0.258, 0, 0);
	glEnd();
	glPopMatrix();

	//1
	glPushMatrix();
	glTranslated(-25.25, 0.0, -10.01);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall_special();

	//14
	glPushMatrix();
	glTranslated(7.69, 0.0, -1.18);
	wall_middle(1.0, 2.05);
	glTranslated(1.025, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, -0.2);
	glVertex3f(0.265, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//11
	glPushMatrix();
	glTranslated(43.98, 0.0, -15.32);
	glRotatef(-85.0, 0.0, 1.0, 0.0);
	Wall(2.5, 2.7);
	//13
	glTranslated(0.27, 0.0, -12.68);
	Wall_special();
	glPopMatrix();

	//12
	glPushMatrix();
	glTranslated(50.673, 0.0, -11.58);
	glRotatef(-20.0, 0.0, 1.0, 0.0);
	Wall_special();
	//22
	glTranslated(0.08, 0.0, -12.68);
	Wall(2.5, 2);
	glPopMatrix();

	//23
	glPushMatrix();
	glRotatef(-88.0, 0.0, 1.0, 0.0);
	glTranslated(-36.4, 0.0, -54.945);
	Wall(2.5, 29);
	//27
	glTranslated(-37.232, 0.0, 0.0);
	Wall(2.5, 31);

	//I-2
	glTranslated(21.716, 0.0, 5.628);
	Wall(2, 57);
	glPopMatrix();


	//24
	glPushMatrix();
	glTranslated(56.635, 0.0, -52.785);
	Wall(2.5, 7);
	//26
	glTranslated(-1.636, 0.0, -7.642);
	glRotated(11, 0.0, 1.0, 0.0);
	Wall(2.5, 4.314);
	//28
	glTranslated(-2.215, 0.0, -31.569);
	glRotated(-11, 0.0, 1.0, 0.0);
	Wall(2.5, 10);
	//29
	glRotated(45.0, 0.0, -1.0, 0.0);
	glTranslated(-9.035, 0.0, 3.535);
	Wall(2.5, 11);
	//33
	glTranslated(-30.83, 0.0, 0.01);
	Wall(2.5, 40);
	//I-3
	glTranslated(11.44, 0.0, 2.98);
	Wall(2, 69);
	//I-4
	glTranslated(-36.41, 0.0, 1.6);
	glRotated(140.0, 0.0, -1.0, 0.0);
	Wall(2, 5);
	//I-5
	glTranslated(18.65, 0.0, 13.084);
	glRotated(39, 0.0, -1.0, 0.0);
	Wall(2, 41.6);
	//I-6
	glTranslated(33.26, 0.0, -21.09082);
	glRotated(120.6, 0.0, -1.0, 0.0);
	Wall(2, 49);
	//I-7
	glTranslated(-32.620617, 0.0, 19.9);
	glRotated(112.2, 0.0, -1.0, 0.0);
	Wall(2, 43);
	//I-8
	glTranslated(21.8, 0.0, 1.6);
	glRotated(100.4, 0.0, 1.0, 0.0);
	Wall(2, 3.3);
	glPopMatrix();

	glColor3f(0.5, 0.5, 0.5);


	glColor3f(0.5, 0.5, 0.5);
	//25
	glPushMatrix();
	glRotated(110.55, 0.0, 1.0, 0.0);
	glTranslated(32.618, 0.0, 74.836);
	Wall(2.5, 8.6);
	glPopMatrix();

	//30
	glPushMatrix();
	glTranslated(35.174, 0.0, -99.735);
	glRotated(40, 0.0, 1.0, 0.0);
	Wall(2.5, 3);
	//31
	glTranslated(2.45, 0.0, -2.844);
	glRotated(71.5, 0.0, 1.0, 0.0);
	Wall(2.5, 6);
	//32
	glTranslated(1.967, 0.0, -2.49);
	glRotated(67.5, 0.0, -1.0, 0.0);
	Wall(2.5, 5.39);
	glPopMatrix();


	//34
	glPushMatrix();
	glTranslated(4.085, 0.0, -132.934);
	glRotated(45, 0.0, 1.0, 0.0);
	Wall(2.5, 6);
	//35
	glTranslated(1.183, 0.0, -3.895);
	glRotated(65, 0.0, -1.0, 0.0);
	Wall(2.5, 8.6);
	//36
	glTranslated(-5.230025, 0.0, 2.64);
	glRotated(109.4, 0.0, -1.0, 0.0);
	Wall(2.5, 5.6);
	//37
	glTranslated(0.363, 0.0, 19.849);
	glRotated(83.0, 0.0, 1.0, 0.0);
	Wall(2.5, 40);
	//37.2
	glTranslated(-20.0, 0.0, -1.5);
	glRotated(90.0, 0.0, 1.0, 0.0);
	Wall(2.5, 3);
	//37.4
	glTranslated(2.183, 0.0, -1.88);
	glRotated(110.0, 0.0, -1.0, 0.0);
	Wall(2.5, 4);
	//37.6
	glTranslated(-2.76, 0.0, 0.64);
	glRotated(140.0, 0.0, -1.0, 0.0);
	Wall(2.5, 2);
	//37.8
	glTranslated(2.67, 0.0, -0.73);
	glRotated(156.53, 0.0, -1.0, 0.0);
	Wall(2.5, 3.65);

	glPopMatrix();

	//56
	glPushMatrix();
	glTranslated(-23.938, 0.0, -17.534);
	glRotated(16, 0.0, 1.0, 0.0);
	Wall(2.5, 4);
	//55
	glTranslated(2.0, 0.0, -12.5);
	glRotated(90.0, 0.0, -1.0, 0.0);
	Wall(2.5, 25);
	//54
	glTranslated(-12.5, 0.0, 2.0);
	glRotated(90.0, 0.0, -1.0, 0.0);
	Wall(2.5, 4);
	//53
	glTranslated(2.0, 0.0, 14);
	glRotated(90.0, 0.0, 1.0, 0.0);
	Wall(2.5, 28);
	//52
	glTranslated(-14, 0.0, 24.5);
	glRotated(90.0, 0.0, -1.0, 0.0);
	Wall(2.5, 49);
	//51
	glTranslated(23.698, 0.0, 11.471);
	glRotated(86.0, 0.0, 1.0, 0.0);
	Wall(2.5, 23);
	//50
	glTranslated(-11.26, 0.0, 1.125);
	glRotated(78.0, 0.0, -1.0, 0.0);
	Wall(2.5, 2.3);
	//49
	glTranslated(1.15, 0.0, 1.50);
	glRotated(90.0, 0.0, 1.0, 0.0);
	Wall(2.5, 3);
	//48
	glTranslated(-1.81, 0.0, -1.258);
	glRotated(104.0, 0.0, 1.0, 0.0);
	Wall(2.5, 2.6);
	//47
	glTranslated(9.010111, 0.0, -9.190115);
	glRotated(130.0, 0.0, -1.0, 0.0);
	Wall(2.5, 24);
	//46
	glTranslated(-12.793, 0.0, 1.27);
	glRotated(122.0, 0.0, -1.0, 0.0);
	Wall(2.5, 3);
	//45
	glTranslated(1.005, 0.0, 2.954);
	glRotated(80.5, 0.0, 1.0, 0.0);
	Wall(2.5, 6);
	//44
	glTranslated(-16.780289, 0.0, 10.770151);
	glRotated(142.0, 0.0, -1.0, 0.0);
	Wall(2.5, 35);
	//43
	glTranslated(19.13, 0.0, -1.14);
	glRotated(145, 0.0, -1.0, 0.0);
	Wall(2.5, 4);
	//42
	glTranslated(-2.64, 0.0, -0.765);
	glRotated(50, 0.0, -1.0, 0.0);
	Wall(2.5, 2);
	//41
	glTranslated(-1.477, 0.0, -0.635);
	glRotated(53, 0.0, -1.0, 0.0);
	Wall(2.5, 1.6);
	//40
	glTranslated(-2.025, 0.0, -0.86);
	glRotated(35, 0.0, -1.0, 0.0);
	Wall(2.5, 3);
	//39
	glTranslated(-19.93, 0.0, 12.9);
	glRotated(145, 0.0, -1.0, 0.0);
	Wall(2.5, 45);
	//38
	glTranslated(22.5, 0.0, -1.5);
	glRotated(90, 0.0, -1.0, 0.0);
	Wall(2.5, 3);
	//37.9
	glTranslated(-2.5, 0.0, -1.73);
	glRotated(120, 0.0, 1.0, 0.0);
	Wall(2.5, 4);
	//37.8
	glTranslated(2.94, 0.0, 0.34);
	glRotated(160, 0.0, 1.0, 0.0);
	Wall(2.5, 2);
	glPopMatrix();



	//small front
	glPushMatrix();
	glScaled(0.6, 0.8, 0.6);
	glTranslated(15.5, 2.37, -10.0);
	glPushMatrix();
	glPushMatrix();
	glTranslated(12.93, 0.0, -11.0);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall(2.5, 6.0);
	glPopMatrix();

	//7
	glPushMatrix();
	glTranslated(18.14, 0.0, -3.062);
	glRotated(-45.0, 0.0, 1.0, 0.0);
	Wall_special();
	glPopMatrix();

	//8
	glPushMatrix();
	glTranslated(28.031, 0.0, -3.068);
	glRotated(45.0, 0.0, 1.0, 0.0);
	Wall_special();
	glPopMatrix();

	//9
	glPushMatrix();
	glTranslated(32.645, 0.0, -11.835);
	glRotated(-85, 0.0, 1.0, 0.0);
	Wall(2.5, 7.67);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}