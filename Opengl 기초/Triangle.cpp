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


#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32s.lib")

using namespace std;
    /// glFlush : gl ��ɾ �޴� ��� ��ɾ� �ϳ��ϳ��� ��� ó���� ��� GPU�� �Ź� ���������� ���μ����� �����ؾ� �ϱ� ������ �ð��� ���� �߻�.
    ///           ������ ������ �з��� ��ɾ �׾Ƶξ��ٰ� �� ���� ���������� ���μ����� �����Ѵ�. 
    ///           �̸� ��ٸ��� ��ġ ���� �� glFlush �Լ��� ȣ���ϸ� �ȴ�.

    /// glViewport(x,y,width,hight) : viewport�� �����ϴ� �Լ��̴�. GL�� ����ϴ� ȭ�� ��ǥ��� �������� ���ϴ��� �������� �ϴ� ���� �����ؾ��Ѵ�.

GLfloat current_angle = 0.0f; // �ﰢ���� ����ȸ������

void Keyboard(unsigned char key, int x, int y) {
    cout << "���� Ű�� ���������ϴ�. W" << key << "W ASCII:" << int(key) << endl;

    // ESC Ű�� �������ٸ� ���α׷� ����
    if (key == 27) {
        exit(0);
    }
    // key�� ���� ��ȣ�� ���� ��ȣ�� �޶����� �� ����.
    /// ����Ű
    /// ���� : 37
    /// ���� : 38
    /// ������ : 39
    /// �Ʒ��� : 40
}

void drawBitmapText(char* str, float x, float y, float z) {
    glRasterPos3f(x, y, z); // ���ڿ��� �׷��� ��ġ����

    while (*str) {
        //GLUT_BITMAP_TIEMS_ROMAN_24 ��Ʈ�� ����Ͽ� ���ڿ��� �׸���.
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
        str++;
    }
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // GlClear���� �÷� ���� ������ �����츦 ä�� ���� ����>> ������ ������
    glClear(GL_COLOR_BUFFER_BIT); // �÷� ���۸� �����.

    glMatrixMode(GL_MODELVIEW); // ���� ����� modelview matrix�� ������ �ְ� �ȴ�
    // glMatrixMode() : 
    /////////////// GL_MODELVIEW :  ȭ�鿡 ������ �׸��� GL_MODELVIEW ����� ���ؼ� ������ ��ġ�� ���Ѵ�.
    ///////////////                 �̴� glTanslatef, glRotatef, glScalef ���� ���� ��ü ��ġ�� ��ȯ�ϴ� ���̸�, '�𵨸� ��ȯ'�̶� �θ���.
    /////////////// GL_PROJECTION : ȭ�鿡 ��� ��Ÿ���� �� �������� �����Ѵ�.

    glLoadIdentity(); // modelview matrix�� �ʱ�ȭ

    // Z���� �߽Ò׷� ������ current_angle�� ȸ���Ѵ�.
    glRotatef(current_angle, 0.0f, 0.0f, 1.0f);
    // glRotatef() : ������ �࿡ ���ؼ� angle��ŭ�� ȸ������� ���Ѵ�.
    /////////////// current_angle : GLfloat angle : ȸ������
    /////////////// �ڿ� ��ǥ�� : GLfloat x,y,z : ȸ���� 


    //�߾��� ������ ������ �Ѻ��� ���̰� 1�� ������ ���簢���� �׸���.
    glColor3f(1.0f, 0.0f, 0.0f); //������ ����
    glBegin(GL_TRIANGLES); // 4���� �ϳ��� �簢���� �����Ѵ�. �ݽð� �������� 4���� vertex�� ����������Ѵ�.
    // glBegin() : �׸��⸦ �����ϴ� �Լ�
    /////////////// GL_POINT : ���� �׸���.
    /////////////// GL_LINES : ���� �׸���.
    /////////////// GL_POLYGON : �ٰ����� �׸���.
    /////////////// GL_TRIANGLES : �ﰢ���� �׸���.
    /////////////// GL_QUADS : �簢���� �׸���.
    /////////////// GL_LINE_STRIP : ��ģ ���� �׸���.
    /////////////// GL_LINE_LOOP : ��ġ�� �ʰ� ����� ���� �׸���.
    /////////////// GL_TRIANGLE_STRIP : �ﰢ���� ����� ������ �׸���.
    /////////////// GL_TRIANGEL_FAN : ������ �ܽ����� �ﰢ���� ����� ������ �׸���.
    /////////////// GL_QUA_STRIP : �簢���� �̾��� ������ �׸���.
    glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
    glVertex3f(-0.5f, -0.5f,0.0f); // ���� �Ʒ� vertex 
    glColor3f(0.0f, 1.0f, 0.0f); // ��� ����
    glVertex3f(0.5f, -0.5f,0.0f); // ������ �Ʒ� vertex
    glColor3f(0.0f, 0.0f, 1.0f); // �Ķ��� ����
    glVertex3f(0.5f, 0.5f,0.0f); // ���� vertex
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // ��� ����
    drawBitmapText("- 0.5, -0.5", -0.5f, -0.5f, 0.0f);// ������ ��ǥ�� ���ڿ� ���
    drawBitmapText("0.5,-0.5", 0.5f, -0.5f, 0.0f);
    drawBitmapText("0.0,0.5", 0.5f, 0.5f, 0.0f);

    // display �Լ� ȣ��� ������ ȸ������ ������Ŵ
    current_angle += 0.5;
    cout << current_angle << endl;

    // ���� ���۸��� �ϰ� �ִٸ�, ����Ʈ ���ۿ� ����� 2���� ���ȴ�. ���� ȭ�鿡 �������� ���� ����Ʈ ���ۿ� �ִ� �����̴�.
    // �� ���۴� ���� ����� ���� �������� �ϰ� �ִ� ���̴�. �������� �������� �Ϸ�Ǹ� �� ���� ���۸� ��ȯ(swap)�Ѵ�.
    // ȭ�鿡 ������Ʈ�� ����Ʈ ���ۿ� �ִ� ������ ��µȴ�.

    // �̱� ���۶�� ���ۿ� �ִ� ���� ȭ�鿡 ����Ѵ�.
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) { // 0���� ������ ���� ����
        height = 1;
    }

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // ����� ������ ũ��� viewport�� �����Ѵ�.
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION); // �ڿ� ���� ������ Projection matrix�� ������ �ֵ��� ����
    glLoadIdentity(); //projection matrix �ʱ�ȭ
    if (width >= height) {
        // aspect >=1 �̸�, height�� [-1,1]�� �����ϰ� width�� [-1*aspect,1*spect]�� �����Ѵ�.
        // left,right,top,bottom
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else {
        // aspect <1 �̸�, width�� [-1,1]�� �����ϰ� heigth�� [-1/aspect,1/aspect]�� �����Ѵ�.
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

    // �ڿ� ���� ������ Modelview Matrix�� ������ �ֵ��� �����Ѵ�.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Modelview Matrix �ʱ�ȭ
}

void timer(int value) {
    glutPostRedisplay(); // �����츦 �ٽ� �׸����� ��û
    glutTimerFunc(30, timer, 0); // ���� Ÿ�̸� �̺�Ʈ�� 30�и�����Ʈ �� ȣ���.
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // GLUT �ʱ�ȭ

    glutInitDisplayMode(GLUT_DOUBLE); // ���� ���۸� ����ϵ��� ����
    glutInitWindowSize(500, 500); // �������� width�� height ����
    glutInitWindowPosition(100, 100); // �������� ��ġ (x,y)
    glutCreateWindow("OpenGl Example"); // ������ ����

    // ���÷��� �ݹ� �Լ� ���, display �Լ��� ������ ó�� ������ ���� ȭ�� �ٽ� �׸� �ʿ� ���� �� ȣ��ȴ�.
    glutDisplayFunc(display);
    // Ű���� �ݹ� �Լ� ���, Ű���尡 �������� ȣ��ȴ�.
    glutKeyboardFunc(Keyboard);
    // reshape �ݹ� �Լ� ���, reshape�Լ��� ������ ó�� ������ ���� ������ ũ�� ����� ȣ��ȴ�.
    glutReshapeFunc(reshape);
    // Ÿ�̸� �ݹ� �Լ� ���, ó������ �ٷ� ȣ���
    glutTimerFunc(0, timer, 0);

    // Glut event proceeing loop�� �����Ѵ�.
    // �� �Լ��� ���ϵ��� �ʱ� ������ �����ٿ� �մ� �ڵ尡 ������� �۴´�.
    glutMainLoop();

    return 0;
}
