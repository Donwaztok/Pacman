#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;


float p1x = 0, p1y = 0.05, p1z = 1;
float scale = 0.05;

float pontuacao = 0;
char message[] = "Score:";


GLfloat xf = 50, yf = 50, win = 250;
GLint view_w, view_h;



                    /*     x        y       h      w */
float parede[][4] = {{     1,       1,      1,    35},
                    {     -1,       1,      1,    35},
                    {      1,      -1,     1,     39},
                    {     -1,      -1,      1,    39},
                    {      0,      -1,     40,     1},
                    {      0,       1,     40,     1},
                    //Caixinha onde ele ta
                    {      0,   -0.05,      8,     1},
                    {   0.20,    0.05,      1,     5},
                    {  -0.20,    0.05,      1,     5},
                    {   0.15,    0.15,      3,     1},
                    {  -0.15,    0.15,      3,     1},
                    //T paralelos a caixa (inferior)
                    {      0,   -0.25,      9,     1},
                    {      0,  -0.375,      1,     4},
                    {      0,  -0.625,      9,     0.5}, //Erro?
                    {      0,  -0.725,      1,     4},
                    //T paralelos a caixa (superior)
                    {      0,    0.55,      9,     1},
                    {      0,   0.425,      1,     4},
                    {      0,    0.85,      1,     5},
                    //Quadrante superior esquerdo (retas)
                    {  -0.30,    0.78,      5,     2},
                    {  -0.70,    0.78,      5,     2},
                    {  -0.70,    0.55,      5,     1},
                    //Quadrante superior esquerdo (T, Coluna, Reta)
                    {  -0.40,    0.35,      1,     9},
                    {  -0.28,    0.35,      4,     1},
                    {  -0.40,   -0.15,      1,     5},
                    {  -0.30,   -0.45,      5,     1},
                    //Saida esquerda (Retas)
                    {  -0.80,    0.35,      8,     1},
                    {  -0.80,    0.15,      8,     1},
                    {  -0.80,   -0.05,      8,     1},
                    {  -0.80,   -0.25,      8,     1},
                    //Saida esquerda (Colunas)
                    { -0.595,    0.25,      1,     5},
                    { -0.595,   -0.15,      1,     5},
                    //Quadrante inferior esquerdo
                    {  -0.70,    -0.45,     5,     1},
                    {  -0.88,   -0.625,     4,   0.5}, //Erro?
                    {  -0.60,    -0.53,     1,     4},
                    {  -0.50,    -0.80,    13,     1},
                    {  -0.40,    -0.72,     1,     4},
                    //Quadrante superior direito (retas)
                    {   0.30,    0.78,      5,     2},
                    {   0.70,    0.78,      5,     2},
                    {   0.70,    0.55,      5,     1},
                    //Quadrante superior direito (T, Coluna, Reta)
                    {   0.40,    0.35,      1,     9},
                    {   0.28,    0.35,      4,     1},
                    {   0.40,   -0.15,      1,     5},
                    {   0.30,   -0.45,      5,     1},
                    //Saida direito (Retas)
                    {   0.80,    0.35,      8,     1},
                    {   0.80,    0.15,      8,     1},
                    {   0.80,   -0.05,      8,     1},
                    {   0.80,   -0.25,      8,     1},
                    //Saida direita (Colunas)
                    {  0.595,    0.25,      1,     5},
                    {  0.595,   -0.15,      1,     5},
                    //Quadrante inferior esquerdo
                    {   0.70,    -0.45,     5,     1},
                    {   0.88,   -0.625,     4,   0.5}, //Erro?
                    {   0.60,    -0.53,     1,     4},
                    {   0.50,    -0.80,    13,     1},
                    {   0.40,    -0.72,     1,     4},
                    };

                    /*     x        y   Ativo*/
float pontos[][3] = { // LADO DIREITO
                     // Coluna 0
                     {    0.0,    0.25,      1},
                     {    0.0,    0.15,      1},
                     {    0.0,    0.65,      1},
                     {    0.0,   -0.15,      1},
                     {    0.0,   -0.55,      1},
                     {    0.0,   -0.90,      1},
                     // Coluna 1
                     {    0.1,    0.25,      1},
                     {    0.1,    0.35,      1},
                     {    0.1,    0.45,      1},
                     {    0.1,    0.65,      1},
                     {    0.1,    0.78,      1},
                     {    0.1,    0.90,      1},
                     {    0.1,   -0.15,      1},
                     {    0.1,   -0.35,      1},
                     {    0.1,   -0.45,      1},
                     {    0.1,   -0.55,      1},
                     {    0.1,   -0.70,      1},
                     {    0.1,   -0.80,      1},
                     {    0.1,   -0.90,      1},
                     // Coluna 1.5
                     {    0.2,    0.25,      1},
                     {    0.2,    0.45,      1},
                     {    0.2,    0.65,      1},
                     {    0.2,    0.90,      1},
                     {    0.2,   -0.15,      1},
                     {    0.2,   -0.35,      1},
                     {    0.2,   -0.55,      1},
                     {    0.2,   -0.70,      1},
                     {    0.2,   -0.90,      1},
                     // Coluna 2
                     {    0.3,    0.05,      1},
                     {    0.3,    0.15,      1},
                     {    0.3,    0.25,      1},
                     {    0.3,    0.45,      1},
                     {    0.3,    0.55,      1},
                     {    0.3,    0.65,      1},
                     {    0.3,    0.90,      1},
                     {    0.3,   -0.05,      1},
                     {    0.3,   -0.15,      1},
                     {    0.3,   -0.25,      1},
                     {    0.3,   -0.35,      1},
                     {    0.3,   -0.55,      1},
                     {    0.3,  -0.625,      1},
                     {    0.3,   -0.70,      1},
                     {    0.3,   -0.90,      1},
                     // Coluna 2.5
                     {    0.4,    0.05,      1},
                     {    0.4,    0.65,      1},
                     {    0.4,    0.90,      1},
                     {    0.4,   -0.35,      1},
                     {    0.4,   -0.55,      1},
                     {    0.4,   -0.90,      1},
                     // Coluna 3
                     {    0.5,    0.05,      1},
                     {    0.5,    0.15,      1},
                     {    0.5,    0.25,      1},
                     {    0.5,    0.45,      1},
                     {    0.5,    0.35,      1},
                     {    0.5,    0.55,      1},
                     {    0.5,    0.65,      1},
                     {    0.5,    0.78,      1},
                     {    0.5,    0.90,      1},
                     {    0.5,   -0.05,      1},
                     {    0.5,   -0.15,      1},
                     {    0.5,   -0.25,      1},
                     {    0.5,   -0.35,      1},
                     {    0.5,   -0.45,      1},
                     {    0.5,  -0.625,      1},
                     {    0.5,   -0.55,      1},
                     {    0.5,   -0.70,      1},
                     {    0.5,   -0.90,      1},
                     // Coluna 3.5
                     {    0.6,    0.05,      1},
                     {    0.6,    0.45,      1},
                     {    0.6,    0.65,      1},
                     {    0.6,    0.90,      1},
                     {    0.6,   -0.35,      1},
                     {    0.6,   -0.70,      1},
                     {    0.6,   -0.90,      1},
                     // Coluna 4
                     {   0.70,    0.05,      1},
                     {   0.70,    0.45,      1},
                     {   0.70,    0.65,      1},
                     {   0.70,    0.90,      1},
                     {   0.70,   -0.35,      1},
                     {   0.70,   -0.55,      1},
                     {   0.70,  -0.625,      1},
                     {   0.70,   -0.70,      1},
                     {   0.70,   -0.90,      1},
                     // Coluna 4.5
                     {    0.8,    0.05,      1},
                     {    0.8,    0.45,      1},
                     {    0.8,    0.65,      1},
                     {    0.8,    0.90,      1},
                     {    0.8,   -0.35,      1},
                     {    0.8,   -0.55,      1},
                     {    0.8,   -0.70,      1},
                     {    0.8,   -0.90,      1},
                     // Coluna 5
                     {   0.90,    0.05,      1},
                     {   0.90,    0.45,      1},
                     {   0.90,    0.55,      1},
                     {   0.90,    0.65,      1},
                     {   0.90,    0.78,      1},
                     {   0.90,    0.90,      1},
                     {   0.90,   -0.35,      1},
                     {   0.90,   -0.45,      1},
                     {   0.90,   -0.55,      1},
                     {   0.90,   -0.70,      1},
                     {   0.90,   -0.80,      1},
                     {   0.90,   -0.90,      1},

                     // LADO ESQUERDO
                     // Coluna 1
                     {   -0.1,    0.25,      1},
                     {   -0.1,    0.35,      1},
                     {   -0.1,    0.45,      1},
                     {   -0.1,    0.65,      1},
                     {   -0.1,    0.78,      1},
                     {   -0.1,    0.90,      1},
                     {   -0.1,   -0.15,      1},
                     {   -0.1,   -0.35,      1},
                     {   -0.1,   -0.45,      1},
                     {   -0.1,   -0.55,      1},
                     {   -0.1,   -0.70,      1},
                     {   -0.1,   -0.80,      1},
                     {   -0.1,   -0.90,      1},
                     // Coluna 1.5
                     {   -0.2,    0.25,      1},
                     {   -0.2,    0.45,      1},
                     {   -0.2,    0.65,      1},
                     {   -0.2,    0.90,      1},
                     {   -0.2,   -0.15,      1},
                     {   -0.2,   -0.35,      1},
                     {   -0.2,   -0.55,      1},
                     {   -0.2,   -0.70,      1},
                     {   -0.2,   -0.90,      1},
                     // Coluna 2
                     {   -0.3,    0.05,      1},
                     {   -0.3,    0.15,      1},
                     {   -0.3,    0.25,      1},
                     {   -0.3,    0.45,      1},
                     {   -0.3,    0.55,      1},
                     {   -0.3,    0.65,      1},
                     {   -0.3,    0.90,      1},
                     {   -0.3,   -0.05,      1},
                     {   -0.3,   -0.15,      1},
                     {   -0.3,   -0.25,      1},
                     {   -0.3,   -0.35,      1},
                     {   -0.3,   -0.55,      1},
                     {   -0.3,  -0.625,      1},
                     {   -0.3,   -0.70,      1},
                     {   -0.3,   -0.90,      1},
                     // Coluna 2.5
                     {   -0.4,    0.05,      1},
                     {   -0.4,    0.65,      1},
                     {   -0.4,    0.90,      1},
                     {   -0.4,   -0.35,      1},
                     {   -0.4,   -0.55,      1},
                     {   -0.4,   -0.90,      1},
                     // Coluna 3
                     {   -0.5,    0.05,      1},
                     {   -0.5,    0.15,      1},
                     {   -0.5,    0.25,      1},
                     {   -0.5,    0.45,      1},
                     {   -0.5,    0.35,      1},
                     {   -0.5,    0.55,      1},
                     {   -0.5,    0.65,      1},
                     {   -0.5,    0.78,      1},
                     {   -0.5,    0.90,      1},
                     {   -0.5,   -0.05,      1},
                     {   -0.5,   -0.15,      1},
                     {   -0.5,   -0.25,      1},
                     {   -0.5,   -0.35,      1},
                     {   -0.5,   -0.45,      1},
                     {   -0.5,  -0.625,      1},
                     {   -0.5,   -0.55,      1},
                     {   -0.5,   -0.70,      1},
                     {   -0.5,   -0.90,      1},
                     // Coluna 3.5
                     {   -0.6,    0.05,      1},
                     {   -0.6,    0.45,      1},
                     {   -0.6,    0.65,      1},
                     {   -0.6,    0.90,      1},
                     {   -0.6,   -0.35,      1},
                     {   -0.6,   -0.70,      1},
                     {   -0.6,   -0.90,      1},
                     // Coluna 4
                     {  -0.70,    0.05,      1},
                     {  -0.70,    0.45,      1},
                     {  -0.70,    0.65,      1},
                     {  -0.70,    0.90,      1},
                     {  -0.70,   -0.35,      1},
                     {  -0.70,   -0.55,      1},
                     {  -0.70,  -0.625,      1},
                     {  -0.70,   -0.70,      1},
                     {  -0.70,   -0.90,      1},
                     // Coluna 4.5
                     {   -0.8,    0.05,      1},
                     {   -0.8,    0.45,      1},
                     {   -0.8,    0.65,      1},
                     {   -0.8,    0.90,      1},
                     {   -0.8,   -0.35,      1},
                     {   -0.8,   -0.55,      1},
                     {   -0.8,   -0.70,      1},
                     {   -0.8,   -0.90,      1},
                     // Coluna 5
                     {  -0.90,    0.05,      1},
                     {  -0.90,    0.45,      1},
                     {  -0.90,    0.55,      1},
                     {  -0.90,    0.65,      1},
                     {  -0.90,    0.78,      1},
                     {  -0.90,    0.90,      1},
                     {  -0.90,   -0.35,      1},
                     {  -0.90,   -0.45,      1},
                     {  -0.90,   -0.55,      1},
                     {  -0.90,   -0.70,      1},
                     {  -0.90,   -0.80,      1},
                     {  -0.90,   -0.90,      1},
                    };




void display()
{
  //glClearColor(0.0, 0.0, 0.3, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  //glColor3f(1.0, 1.0, 1.0);
  glLineWidth(2.0);


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 3000, 0, 3500);

  glPushMatrix();
  glTranslatef(050,2100,0); //Translates the character object with its axis of rotation
  //glTranslatef(-700,0,0); //translates the character object
                        //by 700 unit to the -ve x-axis
  for (unsigned int i = 0; i < strlen(message); i++) {
    glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
  }

    glutStrokeCharacter(GLUT_STROKE_ROMAN, (pontuacao + '0'));


  glPopMatrix();
  //glutSwapBuffers();
}

void desenhaPlayer(){
    // Player
    glLoadIdentity();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(p1x, p1y, p1z);
    glScalef(scale,scale,scale);
    glutSolidSphere(1, 10, 10);

    // Pontos de colisão
    /*int qtdCalculos = 12;
    for (int i=0; i < qtdCalculos; i++){
        float angulo = 360 / qtdCalculos;
        float x = p1x+(cos(i*angulo*M_PI/180)*0.1);
        float y = p1y+(sin(i*angulo*M_PI/180)*0.1);

        glLoadIdentity();
        glTranslatef(x, y, p1z);
        glScalef(scale,scale,scale);
        glutWireSphere(0.1, 5, 5);
    }*/
}

// Desenha
void desenha(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    //exibe texto
    display();
    // Player
    desenhaPlayer();

    // Barras
    for(unsigned int i=0; i < sizeof(parede)/sizeof(parede[0]); i++){
        glLoadIdentity();
        glColor3f(0.35,0.35,1.0);
        glTranslatef(parede[i][0], parede[i][1], 0);
        glScalef(scale,scale,scale);
        glScalef(parede[i][2], parede[i][3], 1);
        glutSolidCube(1);
    }

    // Pontos
    for(unsigned int i=0; i < sizeof(pontos)/sizeof(pontos[0]); i++){
        if (pontos[i][2] == 1){
            glLoadIdentity();
            glColor3f(1.0,1.0,1.0);
            glTranslatef(pontos[i][0], pontos[i][1], 0);
            glScalef(scale,scale,scale);
            glutSolidSphere(0.2, 10, 10);
        }
    }

    glFlush();
}

void ePonto(){
    for(unsigned int i=0; i < sizeof(pontos)/sizeof(pontos[0]); i++){
        float dx = pontos[i][0] - p1x;
        float dy = pontos[i][1] - p1y;
        float distance = sqrt(dx*dx + dy*dy);

        if((distance <= 0.05) && (pontos[i][2] == 1)) {
            pontuacao++;
            pontos[i][2] = 0;
            cout << "Pontos: " << pontuacao << endl;
        }
    }
}

bool eParede(float x, float y){
    for(unsigned int i=0; i < sizeof(parede)/sizeof(parede[0]); i++){
        if (((  x <= parede[i][0]+(parede[i][2]/40)) && (  x >= parede[i][0]-(parede[i][2]/40))) &&
            ((  y <= parede[i][1]+(parede[i][3]/40)) && (  y >= parede[i][1]-(parede[i][3]/40))))
            return true;
    }
    return false;
}

bool colisao(char key){
    int qtdCalculos = 12;

    for (int i=0; i < qtdCalculos; i++){
        float angulo = 360 / qtdCalculos;
        float x = p1x+(cos(i*angulo*M_PI/180)*0.1);
        float y = p1y+(sin(i*angulo*M_PI/180)*0.1);

        switch(key){
            case 'w': if(i*angulo >  45 && i*angulo <= 135) if(eParede(x,y)) return true; break; //  46 - 135º - w
            case 'a': if(i*angulo > 135 && i*angulo <= 225) if(eParede(x,y)) return true; break; // 136 - 225º - a
            case 's': if(i*angulo > 225 && i*angulo <= 315) if(eParede(x,y)) return true; break; // 226 - 315º - s
            case 'd': if(i*angulo > 316 || i*angulo <=  45) if(eParede(x,y)) return true; break; // 316 -  45º - d
        }
    }

    return false;
}
//Teclado
void teclado(unsigned char key, int x, int y){
    switch(key){
        case 'w': if(!colisao(key)) { p1y += 0.05; } break;
        case 'a': if(!colisao(key)) { p1x -= 0.05; } break;
        case 's': if(!colisao(key)) { p1y -= 0.05; } break;
        case 'd': if(!colisao(key)) { p1x += 0.05; } break;

    }
    if(p1x < -1) p1x =  1;
    if(p1x >  1) p1x = -1;
    ePonto();
}
// Teclas especiais
void tecladoEspecial(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT:  teclado('a', x, y); break;
        case GLUT_KEY_UP:    teclado('w', x, y); break;
        case GLUT_KEY_RIGHT: teclado('d', x, y); break;
        case GLUT_KEY_DOWN:  teclado('s', x, y); break;
    }
}
//Callback para Timer
void timer(int p){
    glutPostRedisplay();                // Redesenha a Tela
    glutTimerFunc(10, timer, 0);        // Agenda a Funcao Timer para 30 ms
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,800);
    glutCreateWindow("Pac-Man");
    glutDisplayFunc(desenha);
    glutTimerFunc(0, timer, 0);         // Chama Timer após 0 ms
    //glutMouseFunc(mouse);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}
