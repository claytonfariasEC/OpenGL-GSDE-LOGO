//*****************************************************
//
// Nome : Clayton Farias , Hesfaller Silveira
// 
// Logo do GSDE (Grupo de Sistemas Digitais e embracados)-FURG
//*****************************************************

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define CIRC 1
int circle_points = 1000/4;
int i,j;
float angle;
GLfloat win;

#define N_ROUNDING_PIECES 4




// Função callback de redesenho da janela de visualização

float Quadrado(float x , float y ,int r, int g , int b){
     
     glColor3f(r,g,b); //AZUL
       // Desenha um Quadrado no centro da janela
    glBegin(GL_QUADS);
        glVertex3f(-x,0,0);
        glVertex3f(-x,y,0);
        glVertex3f( x,y,0);
        glVertex3f( x,0,0);
    glEnd();


}





float Circulo(float x , float y ,float ponto_xt ,float ponto_yt , int r , int g , int b)
{
 
    //glColor3f(0,0,1);
    glColor3f(r,g,b);
    glLineWidth(3.0f); 

    //Translação 
    glTranslatef(ponto_xt , ponto_yt , 0); // Translação do circulo
   
    glBegin(GL_LINE_LOOP);
    

    float pi2 = PI * 2;
    float px , py ; 

    for (i = 0;i < circle_points+1;i++) {

    
            angle = pi2*i/circle_points;

            px = cos(angle)* 0.05;
            py = sin(angle)* 0.05;
            
            glVertex3f(px,py,0);
            glColor3f(r, g, b);

            glBegin(GL_LINES);
            glVertex3f(px,0,0); // linha 2
            glVertex3f(0,py,0);
           
    
           
    }

  
    
    glEnd();
  
    //Executa os comandos OpenGL 
  
}

float Quarto_de_Circulo(float x , float y ,float aux_x  ,float aux_y , int r , int g , int b)
{
   
    //glColor3f(0,0,1);
    glColor3f(r,g,b);
    glLineWidth(3.0f); 
     
    //Translação 
    glTranslatef(0 , 0 , 0); // Translação do circulo
    
    
   
    glBegin(GL_POLYGON);

    

    float pi2 = PI * 2;
    float px , py ; 

    for (i = 0 ; i < circle_points+1; i++) {

    
            angle = pi2*i/circle_points;

            px = cos(angle)* 0.2;
            py = sin(angle)* 0.2;
                
        
        
        if(px <= 0 && py>=0){   //quarto esquerdo de cima azul
                     
 
            glColor3f(r, g, 1);
            glVertex3f(px-aux_x,py+aux_y,0);
             

            
        }

        if(px <= 0 && py<=0){  //quarto esquerdo de baixo verde
                     

             glColor3f(r, g, b);         
             glVertex3f(px-aux_x,py-aux_y,0);
                   
            
        }


        if(px >=0 && py>=0){  // Quarto direito acima   vermelho
                     
            glVertex3f(px+aux_x,py+aux_y,0);
            glColor3f(r, g, b);
            
        }

        if(px >=0 && py<=0){  // Quarto direito abaixo   preto
                     
            glVertex3f(px+aux_x,py-aux_y,0);
            glColor3f(r, g , b);
            
        }

       

    }



    
    glEnd();
  

  
}

void DesenhaTexto(char *string) 
{   
    glPushMatrix();
      // Posição no universo onde o texto será colocado  
        glColor3f(255, 255, 255);
        
        glRasterPos2f(-0.1,-0.01); 
        


        // Exibe caracter a caracter
        while(*string){
             //glScalef(100 , 100, 0);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++); 
        }

    
    
    glPopMatrix();

    glEnd();

   
}


void Desenha(void)
{
    // Limpa a janela de visualização com a cor branca
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
   
   
    float x , y;
    float ponto_X_t ,  ponto_Y_t;
    int cor = 1;
    int r,g,b;

     x = 0.28;
     y = 0.28;
     //Quadrado(x,y,0,0,1); // Criando Quadrado azul
     //glTranslatef(0 , 0 , 0); // Translação do circulo
     Quarto_de_Circulo (-x , y , x,y, 0, 0 , 1); // Criação do circulo 1

    ponto_X_t = 0.45;
    ponto_Y_t = 0.45;

    char letra[8] = "GSDE";

    ponto_X_t = ponto_Y_t = 0;
    
    DesenhaTexto(letra); 

    glTranslatef(0 , 0 , 0); // Translação do circulo
    
    Circulo(-x , -y , -x , +y, 255, 255 , 255); // Criação do circulo 1
    
    glTranslatef(0 , 0 , 0); // Translação do circulo

    Circulo(x , -y , 2*x , -2*y, 255, 255 , 255); // Criação do circulo 1

    
    printf("X : %f Y :%f\n",x,y);

    ponto_X_t = x;
    ponto_Y_t = y/2.45;

    printf("X : %f Y/numero :%f\n",x,y/3);
    int j;

    for (int j = 0; j <= 3 ; j++)   // Loop que cria as semi-bolinhas direita
    {  
        Circulo (x , y , ponto_X_t , ponto_Y_t , 0 , 0 , 1);
        ponto_X_t = 0;
        ponto_Y_t = 0.15;
      
    }
    
    printf("ponto X : %f ponto Y :%f\n",ponto_X_t, ponto_Y_t);
    ponto_X_t = -4*x;
    ponto_Y_t = 0.0009;
    
    for (int j = 0; j <= 3 ; j++)   // Loop que cria as semi-bolinhas esquerda
    {  
        Circulo (x , y , ponto_X_t , ponto_Y_t , 0 , 0 , 1);
        ponto_X_t = 0;
        ponto_Y_t = -0.16;
      
    }

    float change = 0.01;

    ponto_X_t = 0.35-change;
    ponto_Y_t  = 0.775;

    

    for (int j = 0; j < 3 ; j++)   // Loop que cria as semi-bolinhas cima verde
    {  
        Circulo (x , y , ponto_X_t , ponto_Y_t , 0 , 0 , 1);
        ponto_X_t = 0;
        ponto_Y_t = 0;
        Circulo (x , y , ponto_X_t + 0.15 , ponto_Y_t,0 , 0 , 1);

    }

    ponto_X_t =  -0.45-change;
    ponto_Y_t  = -1.15;

    float u_x , u_y;

    for (int j = 0; j < 3 ; j++)   // Loop que cria as semi-bolinhas baixo
    {  
        Circulo (x , y , ponto_X_t , ponto_Y_t , 0 , 0 , 1);
        ponto_X_t = 0;
        ponto_Y_t = 0;
        Circulo (x , y , ponto_X_t + 0.15 , -ponto_Y_t, 0 , 0 , 1);

    }

    
   
    glFlush();



}   




// Função callback chamada para gerenciar eventos de teclas ESC
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa(void)
{
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.5,1.5,-1.5,1.5);
    glMatrixMode(GL_MODELVIEW);
}





// Programa Principal 
int main(int argc, char** argv)
{

    glutInit(&argc, argv); 
    // Define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 
    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(800,600); 
 
    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Logo GSDE FURG");
 
    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Desenha);


    // Registra a função callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);

    // Chama a função responsável por fazer as inicializações 
    Inicializa();
 
    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();
 
    return 0;
}
