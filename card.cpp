#include "card.h"

using namespace std;

card::card(){}

card::card(GLint _point, GLint _suit,
        GLfloat _midx,GLfloat _midy,GLfloat _midz,GLboolean _neg):
        point(_point),suit(_suit),
        midx(_midx),midy(_midy),midz(_midz),neg(_neg){
            char t[100];
            sprintf(t,"%d",point);
            rp=string(t);
            vis=true;
            sel=false;
}

card::~card(){}

void card::draw(GLint s){
    GLfloat tmidy=s*(-0.5);
    if(sel)
        graphic::DrawBlankCard(midx,tmidy,midz,1);
    else
        graphic::DrawBlankCard(midx,tmidy,midz,0);
    if(vis){
        switch(suit){
            case SPADE:
                graphic::DrawSpade(midx,tmidy,midz,neg);
                break;
            case HEART:
                graphic::DrawHeart(midx,tmidy,midz,neg);
                break;
            case CLUB:
                graphic::DrawClub(midx,tmidy,midz,neg);
                break;
            case DIAMOND:
                graphic::DrawDiamond(midx,tmidy,midz,neg);
                break;
        }
        if(point==1)
            graphic::DrawCardAce(midx,tmidy,midz);
        else if(point==13)
            graphic::DrawCardKing(midx,tmidy,midz);
        else if(point==12)
            graphic::DrawCardQueen(midx,tmidy,midz);
        else if(point==11)
            graphic::DrawCardJack(midx,tmidy,midz);
        else{
            GLfloat dx=1.5;
            glBegin(GL_LINES);
            glColor3f(0,0,0);
            glLineWidth(100);
            for(GLint i=0;i<rp.length();i++){
                graphic::DrawCardNum(rp[i]-'0',midx,tmidy,midz,i*dx);
            }
            glEnd();
        }
    }
}

void card::move_x(GLint d){
    midx = d;
}

void card::move_z(GLint d){
    midz = d;
}

GLboolean card::mouse_on(GLfloat x,GLfloat z){
    GLfloat dx=abs(midx-x);
    GLfloat dz=abs(midz-z);
    if(dx<5&&dz<10)return true;
    return false;
}

void card::svis(){
    vis^=1;
}

void card::ssel(){
    sel^=1;
}