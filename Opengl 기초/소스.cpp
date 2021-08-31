#include "GL/freeglut.h"
#include <iostream>

/// ����
/// wglCreateContext() : ������ ���ؽ�Ʈ�� �����Ѵ�.
/// wglDeleteContext() : ������ ���ؽ�Ʈ�� �����Ѵ�.
/// wglMakeCurrent() : ���� ������ ���ؽ�Ʈ�� �����Ѵ�.
/// wglGetProcAddress() : Ȯ���Լ� �����͸� �����Ѵ�.
/// wglUseFontBitmaps() : ���� ���õ� GDI ��Ʈ�� ���� ����GL ���÷��� ����Ʈ�� �����.
/// wglUseFontOutlines() : ������ �ܰ��� �۲ð� �� �۸����鿡 ���� ���÷��� ����Ʈ�� �����.
/// 
/// GLUT
/// glutTimerFunc() : ������ �ð��Ŀ� ������ �Լ��� �ѹ� ȣ���Ѵ�. �ٽ� ȣ���Ϸ��� �ٽ� �� �Լ��� ȣ���ؾ��Ѵ�.
/// 
/// �ȼ�����
/// ChoosePixelFormat() : ���� ������ �ȼ������� �����Ѵ�.
/// SetPixelFormat() : �ȼ������� ����̽� ���ؽ�Ʈ�� �������.
/// 
/// ȭ�����
/// ChangeDisplaySetting() : ��üȭ������ �ٲ۴�.
/// SwapBuffers() : �ĸ���츦 ������۷� �ٲ۴�.
/// glClear() : ȭ��� ���۸� �����.
/// glClearColor() : ȭ�� ��� ������ �����Ѵ�.
/// 
/// �׸���
/// glBegin() : �⺻���� �׸��⸦ �����Ѵ�.
/// glEnd() : �⺻���� �׸��⸦ ��ģ��.
/// glVertex[2,3,4][d,f,i,s][v]() : ������ �����Ѵ�.
/// glColor[3,4][b,d,f,i,s,f]() : ���� �����Ѵ�.
/// 
/// ��
/// glPointSize() : ���� ũ�⸦ �����Ѵ�.
/// 
/// ��
/// glLineWidth() : ���� ���⸦ �����Ѵ�.
/// glLineStipple() : ���� ������ �����Ѵ�.
/// 
/// �ٰ���
/// glPolygonMode() : ����, �ĸ��� �ٰ��� �׸��� ���(��,��,�� �׸���)�� �����Ѵ�.
/// glCullFace() : ���� �����Ѵ�.
/// glFrontFace() : ������ �����Ѵ�.
/// glEdgeFlag() : ���� �����. ���� ���� �߿� ����Ѵ�.
/// glPolygonStipple() : �ٰ��� ���ϼ���
/// 
/// ��Ÿ ���� �׸���
/// glRectf() : �簢���� �׸���
/// auxSolidCube() : ������ü�� �׸���.
/// auxSolidSphere() : ���� �׸���.
/// auxSolidTorus() : �䷯��(��ȯ)�� �׸���.
/// 
/// ������Ʈ�ӽ�
/// 
/// ���
/// 
/// ����
/// 
/// ������ȯ
/// 
/// �𵨸���ȯ
/// 
/// ����
/// 
/// ���̵�
/// 
/// ����
/// 
/// ����
/// 
/// ��Ʈ��
/// 
/// �ؽ���
/// 
/// ���� �ؽ��ĸ�
/// 
/// ���÷��� ����Ʈ
/// 
/// �����迭


//����� ���̺귯���� �������ݴϴ�.
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32s.lib")

using namespace std;


//ť�� ��ġ
float cubeX = 0.0;
float cubeY = 0.0;
float cubeZ = -4.0;

//ȸ��
float pitch = 0.0;
float yaw = 0.0;
float roll = 0.0;


//float current_angle = 0.0;

void drawBitmapText(char* str, float x, float y, float z)
{
    glRasterPos3f(x, y, z); //���ڿ��� �׷��� ��ġ ����

    while (*str)
    {
        //GLUT_BITMAP_TIMES_ROMAN_24 ��Ʈ�� ����Ͽ� ���ڿ��� �׸���.
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);

        str++;
    }
}


//ť���� �� ��, ȭ�� ���� ������ -Z��������� 0.5�̵��Ͽ� ���簢���� �׸���.
static void cubebase(void)
{
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glEnd();
}

//cubebase�Լ����� �׸� �簢���� ȸ�� �� �̵�����
//ť�긦 �ϼ���Ų��.
void draw_cube()
{
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix(); // �� �Լ��� �Ҹ��� ���� ��ȯ ��ǥ�� ����


    glColor3f(0.0f, 1.0f, 0.0f);     // Green, -Z�� ����
    cubebase();

    glPushMatrix();
    /*construct side on +x axis*/
    glTranslated(1.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue, +X�� ����
    cubebase();
    glPopMatrix(); // glPushMatrix() ������ ��ǥ ���¸� �ٽ� ȣ���ϴ� �Լ�

    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange, -X�� ����
    cubebase();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 1.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red, +Y�� ����
    cubebase();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, -1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow, -Y�� ����
    cubebase();
    glPopMatrix();

    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta, +Z�� ����
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, 0.5, 0.5);
    glVertex3d(-0.5, 0.5, 0.5);
    glEnd();


    glPopMatrix();

    glFlush(); // gl ��ɾ �޴� ��� ��ɾ� �ϳ��ϳ��� ��� ó���� �ܿ� GPU�� �Ź� ���������� ���μ����� �����ؾ��ϱ� ������ �ð��� ���ذ� �߻��ϳ�. ������ ������ �з��� ��ɾ �׾Ƶξ��ٰ� �ѹ��� ���������� ���μ����� �����Ѵ�. �̸� ��ٸ��� ��ġ ���� �� glFlush �Լ��� ȣ���ϸ� �ȴ�
}

void draw_line()
{
    glPushMatrix();

    glPushMatrix(); //X�� ������
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(5.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, 0.0);
    glEnd();
    drawBitmapText("+X", 0.8, 0.0, 0.0);
    drawBitmapText("-X", -0.8, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix(); //Y�� ���
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 5.0, 0.0);
    glVertex3f(0.0, -5.0, 0.0);
    glEnd();
    drawBitmapText("+Y", 0.0, 0.8, 0.0);
    drawBitmapText("-Y", 0.0, -0.8, 0.0);
    glPopMatrix();

    glPushMatrix(); //Z�� �Ķ���
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 5.0);
    glVertex3f(0.0, 0.0, -5.0);
    glEnd();
    drawBitmapText("+Z", 0.0, 0.0, 0.8);
    drawBitmapText("-Z", 0.0, 0.0, -0.8);
    glPopMatrix();

    glPopMatrix();

    glFlush();
}

void display()
{
    //ȭ���� �����. (�÷����ۿ� ���̹���)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //���� ������ ModelView Matirx�� ������ �ش�. ��ü ����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // �̵��� ȸ���� ����
    glTranslatef(cubeX, cubeY, cubeZ);
    glRotatef(pitch, 1.0, 0.0, 0.0); //x�࿡ ���� ȸ��
    glRotatef(yaw, 0.0, 1.0, 0.0); //y�࿡ ���� ȸ��
    glRotatef(roll, 0.0, 0.0, 1.0); //z�࿡ ���� ȸ��

    //ť�긦 �׸�
    draw_cube();

    //��ǥ���� �׸�
    draw_line();

    glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); //������ ũ��� ������Ʈ ���� 

    glMatrixMode(GL_PROJECTION); //���� ������ Projection Matrix�� ������ �ش�. ī�޶�� ���̴� ��� ������ ���� 
    glLoadIdentity();

    //Field of view angle(���� degrees), �������� aspect ratio, Near�� Far Plane����
    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW); //���� ������ ModelView Matirx�� ������ �ش�. ��ü ����
}


void timer(int value) {
    //current_angle += 0.5;
    //if (current_angle > 360) current_angle -= 360;

    glutPostRedisplay();      //�����츦 �ٽ� �׸����� ��û
    glutTimerFunc(30, timer, 0); //���� Ÿ�̸� �̺�Ʈ�� 30�и�����Ʈ ��  ȣ���.
}



void init()
{
    /* Set clear color */
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearDepth(1.0);

    /* Enable the depth buffer */
    glEnable(GL_DEPTH_TEST);
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        pitch += 1.0;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        pitch -= 1.0;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        yaw += 1.0;
    }
    else if (key == GLUT_KEY_LEFT)
    {
        yaw -= 1.0;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    //cout << "���� Ű�� ���������ϴ�. \"" << key << "\" ASCII: " << (int)key << endl;

    //ESC Ű�� �������ٸ� ���α׷� ����
    if (key == 27)
    {
        exit(0);
    }
    else if (key == 43) // +Ű
    {
        roll += 1.0;
    }
    else if (key == 45) //-Ű
    {
        roll -= 1.0;
    }
    else if (key == 113) //q
    {
        cubeZ += 0.1;
    }
    else if (key == 119) //w
    {
        cubeZ -= 0.1;
    }
    else if (key == 97) //a
    {
        cubeY += 0.1;
    }
    else if (key == 115) //s
    {
        cubeY -= 0.1;
    }
    else if (key == 122) //z
    {
        cubeX += 0.1;
    }
    else if (key == 120) //x
    {
        cubeX -= 0.1;
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);  //GLUT �ʱ�ȭ

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //���� ���ۿ� ���� ���۸� ����ϵ��� ����, GLUT_RGB=0x00��
    glutInitWindowSize(500, 500);   //�������� width�� height
    glutInitWindowPosition(100, 100); //�������� ��ġ (x,y)
    glutCreateWindow("OpenGL Example"); //������ ����


    init();

    //���÷��� �ݹ� �Լ� ���, display�Լ��� ������ ó�� ������ ���� ȭ�� �ٽ� �׸� �ʿ� ������ ȣ��ȴ�. 
    glutDisplayFunc(display);

    //Ű���� �ݹ� �Լ� ���, Ű���尡 �������� ȣ��ȴ�. 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);

    //reshape �ݹ� �Լ� ���, reshape�Լ��� ������ ó�� ������ ���� ������ ũ�� ����� ȣ��ȴ�.
    glutReshapeFunc(reshape);
    //Ÿ�̸� �ݹ� �Լ� ���, ó������ �ٷ� ȣ���.
    glutTimerFunc(0, timer, 0);

    //GLUT event processing loop�� �����Ѵ�.
    //�� �Լ��� ���ϵ��� �ʱ� ������ �����ٿ� �ִ� �ڵ尡 ������� �ʴ´�. 
    glutMainLoop();

    return 0;
}

