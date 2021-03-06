#include "GL/freeglut.h"
#include <iostream>

/// 위글
/// wglCreateContext() : 랜더링 컨텍스트를 생성한다.
/// wglDeleteContext() : 랜더링 컨텍스트를 삭제한다.
/// wglMakeCurrent() : 현재 랜더링 컨텍스트를 설정한다.
/// wglGetProcAddress() : 확장함수 포인터를 리턴한다.
/// wglUseFontBitmaps() : 현재 선택된 GDI 폰트에 대해 오픈GL 디스플레이 리스트를 만든다.
/// wglUseFontOutlines() : 현재의 외각선 글꼴과 각 글리프들에 대한 디스플레이 리스트를 만든다.
/// 
/// GLUT
/// glutTimerFunc() : 지정된 시간후에 지정된 함수를 한번 호출한다. 다시 호출하려면 다시 이 함수를 호출해야한다.
/// 
/// 픽셀형식
/// ChoosePixelFormat() : 가장 근접한 픽셀형식을 결정한다.
/// SetPixelFormat() : 픽셀형식을 디바이스 컨텍스트에 설정헌다.
/// 
/// 화면출력
/// ChangeDisplaySetting() : 전체화면으로 바꾼다.
/// SwapBuffers() : 후면버펴를 전면버퍼로 바꾼다.
/// glClear() : 화면과 버퍼를 지운다.
/// glClearColor() : 화면 배경 색상을 설정한다.
/// 
/// 그리기
/// glBegin() : 기본도형 그리기를 시작한다.
/// glEnd() : 기본도형 그리기를 마친다.
/// glVertex[2,3,4][d,f,i,s][v]() : 정점을 지정한다.
/// glColor[3,4][b,d,f,i,s,f]() : 색을 지정한다.
/// 
/// 점
/// glPointSize() : 점의 크기를 변경한다.
/// 
/// 선
/// glLineWidth() : 선의 굵기를 변경한다.
/// glLineStipple() : 점선 패턴을 설정한다.
/// 
/// 다각형
/// glPolygonMode() : 전면, 후면의 다각형 그리기 방식(점,선,면 그리기)을 설정한다.
/// glCullFace() : 면을 제거한다.
/// glFrontFace() : 전면을 변경한다.
/// glEdgeFlag() : 변을 숨긴다. 정점 지정 중에 사용한다.
/// glPolygonStipple() : 다각형 패턴설정
/// 
/// 기타 도형 그리기
/// glRectf() : 사각형을 그린다
/// auxSolidCube() : 정육면체를 그린다.
/// auxSolidSphere() : 구를 그린다.
/// auxSolidTorus() : 토러스(원환)을 그린다.
/// 
/// 스테이트머신
/// 
/// 행렬
/// 
/// 스택
/// 
/// 조망변환
/// 
/// 모델링변환
/// 
/// 투영
/// 
/// 셰이딩
/// 
/// 조명
/// 
/// 깊이
/// 
/// 비트맵
/// 
/// 텍스쳐
/// 
/// 다중 텍스쳐링
/// 
/// 디스플레이 리스트
/// 
/// 정점배열


//사용할 라이브러리를 지정해줍니다.
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32s.lib")

using namespace std;


//큐브 위치
float cubeX = 0.0;
float cubeY = 0.0;
float cubeZ = -4.0;

//회전
float pitch = 0.0;
float yaw = 0.0;
float roll = 0.0;


//float current_angle = 0.0;

void drawBitmapText(char* str, float x, float y, float z)
{
    glRasterPos3f(x, y, z); //문자열이 그려질 위치 지정

    while (*str)
    {
        //GLUT_BITMAP_TIMES_ROMAN_24 폰트를 사용하여 문자열을 그린다.
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);

        str++;
    }
}


//큐브의 한 면, 화면 안쪽 방향인 -Z축방향으로 0.5이동하여 정사각형을 그린다.
static void cubebase(void)
{
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glEnd();
}

//cubebase함수에서 그린 사각형을 회전 및 이동시켜
//큐브를 완성시킨다.
void draw_cube()
{
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix(); // 이 함수가 불리기 전의 변환 좌표를 저장


    glColor3f(0.0f, 1.0f, 0.0f);     // Green, -Z축 방향
    cubebase();

    glPushMatrix();
    /*construct side on +x axis*/
    glTranslated(1.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue, +X축 방향
    cubebase();
    glPopMatrix(); // glPushMatrix() 이전의 좌표 상태를 다시 호출하는 함수

    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange, -X축 방향
    cubebase();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 1.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red, +Y축 방향
    cubebase();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, -1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow, -Y축 방향
    cubebase();
    glPopMatrix();

    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta, +Z축 방향
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, 0.5, 0.5);
    glVertex3d(-0.5, 0.5, 0.5);
    glEnd();


    glPopMatrix();

    glFlush(); // gl 명령어를 받는 즉시 명령어 하나하나를 즉시 처리할 겨우 GPU는 매번 파이프라인 프로세서와 교신해야하기 때문에 시간적 손해가 발생하낟. 때문에 일정한 분량의 명령어를 쌓아두었다가 한번에 파이프라인 프로세서에 전달한다. 이를 기다리길 원치 않을 때 glFlush 함수를 호출하면 된다
}

void draw_line()
{
    glPushMatrix();

    glPushMatrix(); //X축 붉은색
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(5.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, 0.0);
    glEnd();
    drawBitmapText("+X", 0.8, 0.0, 0.0);
    drawBitmapText("-X", -0.8, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix(); //Y축 녹색
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 5.0, 0.0);
    glVertex3f(0.0, -5.0, 0.0);
    glEnd();
    drawBitmapText("+Y", 0.0, 0.8, 0.0);
    drawBitmapText("-Y", 0.0, -0.8, 0.0);
    glPopMatrix();

    glPushMatrix(); //Z축 파란색
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
    //화면을 지운다. (컬러버퍼와 깊이버퍼)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //이후 연산은 ModelView Matirx에 영향을 준다. 객체 조작
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 이동과 회전을 적용
    glTranslatef(cubeX, cubeY, cubeZ);
    glRotatef(pitch, 1.0, 0.0, 0.0); //x축에 대해 회전
    glRotatef(yaw, 0.0, 1.0, 0.0); //y축에 대해 회전
    glRotatef(roll, 0.0, 0.0, 1.0); //z축에 대해 회전

    //큐브를 그림
    draw_cube();

    //좌표축을 그림
    draw_line();

    glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); //윈도우 크기로 뷰포인트 설정 

    glMatrixMode(GL_PROJECTION); //이후 연산은 Projection Matrix에 영향을 준다. 카메라로 보이는 장면 같은거 설정 
    glLoadIdentity();

    //Field of view angle(단위 degrees), 윈도우의 aspect ratio, Near와 Far Plane설정
    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW); //이후 연산은 ModelView Matirx에 영향을 준다. 객체 조작
}


void timer(int value) {
    //current_angle += 0.5;
    //if (current_angle > 360) current_angle -= 360;

    glutPostRedisplay();      //윈도우를 다시 그리도록 요청
    glutTimerFunc(30, timer, 0); //다음 타이머 이벤트는 30밀리세컨트 후  호출됨.
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
    //cout << "다음 키가 눌러졌습니다. \"" << key << "\" ASCII: " << (int)key << endl;

    //ESC 키가 눌러졌다면 프로그램 종료
    if (key == 27)
    {
        exit(0);
    }
    else if (key == 43) // +키
    {
        roll += 1.0;
    }
    else if (key == 45) //-키
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
    glutInit(&argc, argv);  //GLUT 초기화

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //더블 버퍼와 깊이 버퍼를 사용하도록 설정, GLUT_RGB=0x00임
    glutInitWindowSize(500, 500);   //윈도우의 width와 height
    glutInitWindowPosition(100, 100); //윈도우의 위치 (x,y)
    glutCreateWindow("OpenGL Example"); //윈도우 생성


    init();

    //디스플레이 콜백 함수 등록, display함수는 윈도우 처음 생성할 때와 화면 다시 그릴 필요 있을때 호출된다. 
    glutDisplayFunc(display);

    //키보드 콜백 함수 등록, 키보드가 눌러지면 호출된다. 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);

    //reshape 콜백 함수 등록, reshape함수는 윈도우 처음 생성할 때와 윈도우 크기 변경시 호출된다.
    glutReshapeFunc(reshape);
    //타이머 콜백 함수 등록, 처음에는 바로 호출됨.
    glutTimerFunc(0, timer, 0);

    //GLUT event processing loop에 진입한다.
    //이 함수는 리턴되지 않기 때문에 다음줄에 있는 코드가 실행되지 않는다. 
    glutMainLoop();

    return 0;
}

