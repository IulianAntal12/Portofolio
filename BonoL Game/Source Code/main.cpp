#include <iostream>
#include <stdlib.h>
#include <winbgim.h>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
using namespace std;
typedef struct {
                int Player1;
                int Player2;
} Bonol;
Bonol Game;
int Array[6][6],different,corect,First_Cell,Player,x,y,Choice,ok,coord2[100][6],coord_player[100][6],pc,okey,NewVector[3],color, coord[3],NeutralPiece,CorectCircle;
int Left=500,Side=100,Up=140;
void ChooseColor()
{
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    {

        if(x>130&&x<260&&y>190&&y<300)
        {
            okey=1;
            Game.Player1=1;
            setfillstyle(SOLID_FILL,BLUE);
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//blue
        if(x>280&&x<410&&y>190&&y<300)
        {
            okey=1;
            Game.Player1=4;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//red
        if(x>430&&x<560&&y>190&&y<300)
        {
            okey=1;
            Game.Player1=5;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//magenta
        if(x>130&&x<260&&y>350&&y<460)
        {
            okey=1;
            Game.Player1=2;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//green
        if(x>280&&x<410&&y>350&&y<460)
        {
            okey=1;
            Game.Player1=6;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//brown
        if(x>430&&x<560&&y>350&&y<460)
        {
            okey=1;
            Game.Player1=13;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//lightmagenta

        if(x>930&&x<1060&&y>190&&y<300)//930,190,1060,300
        {
            okey=1;
            Game.Player2=1;
            pc=1;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//blue
        if(x>1080&&x<1210&&y>190&&y<300)
        {
            okey=1;
            Game.Player2=4;
            pc=4;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//red
        if(x>1230&&x<1360&&y>190&&y<300)
        {
            okey=1;
            Game.Player2=5;
            pc=5;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//magenta
        if(x>930&&x<1060&&y>350&&y<460)
        {
            okey=1;
            Game.Player2=2;
            pc=2;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//green
        if(x>1080&&x<1210&&y>350&&y<460)
        {
            okey=1;
            Game.Player2=6;
            pc=6;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }//brown
        if(x>1230&&x<1360&&y>350&&y<460)
        {
            okey=1;
            Game.Player2=13;
            pc=13;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }
    }
}
void ChooseColorNeutralPiece()
{
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    {
        if(x>720 && x<770 && y>220 && y<270)
        {
            CorectCircle=1;
            NeutralPiece=9;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }
        if(x>720 && x<770 && y>290 && y<340)
        {
            CorectCircle=1;
            NeutralPiece=10;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }
        if(x>720 && x<770 && y>360 && y<410)
        {
            CorectCircle=1;
            NeutralPiece=14;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }
        if(x>720 && x<770 && y>430 && y<480)
        {
            CorectCircle=1;
            NeutralPiece=12;
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        }

    }
}
void InitialTable(int Array[6][6])
{
    if(okey==0)
        Game.Player1=4,Game.Player2=1,pc=1;
    if(Game.Player1==Game.Player2)
        Game.Player2=11,pc=11; //lightcyan
    if(CorectCircle==0)
        NeutralPiece=14;

    Array[6][6]= {0};
    for(int lin=0;lin<=5;lin++)
    {
        Array[lin][0]=-1;
        Array[lin][5]=-1;
    }
    for(int col=0;col<=5;col++)
    {
        Array[0][col]=-1;
        Array[5][col]=-1;
    }
    Array[1][1]=NeutralPiece;
    Array[1][2]=Game.Player1;
    Array[1][3]=Game.Player1;
    Array[1][4]=0;
    Array[2][1]=0;
    Array[2][2]=Game.Player2;
    Array[2][3]=Game.Player1;
    Array[2][4]=0;
    Array[3][1]=0;
    Array[3][2]=Game.Player2;
    Array[3][3]=Game.Player1;
    Array[3][4]=0;
    Array[4][1]=0;
    Array[4][2]=Game.Player2;
    Array[4][3]=Game.Player2;
    Array[4][4]=NeutralPiece;

    for(int lin=1; lin<=4; lin++)
        for(int col=1; col<=4; col++)
        {
            if(Array[lin][col]==NeutralPiece)//sterge cerc
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
            }
            else
            {
                 setcolor(WHITE);
                 rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                 setfillstyle(SOLID_FILL,Array[lin][col]);
                 floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);

            }//daca nu are culoarea respectiva , o seteaza
        }

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,NeutralPiece);
    circle(Left+50,Up+50,40);          //pune piesa neutra din stanga sus in pozitia initiala
    floodfill(Left+50,Up+50,DARKGRAY);

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,NeutralPiece);
    circle(Left+350,Up+350,40);         //pune piesa neutra din dreapta jos in pozitia initiala
    floodfill(Left+350,Up+350,DARKGRAY);

    settextstyle(9, HORIZ_DIR,3);
    outtextxy(500,590,"First player:");
    outtextxy(500,690,"Second player:");

    setfillstyle(SOLID_FILL,Game.Player1);
    rectangle(690,570,740,620);
    bar(690,570,740,620);

    setfillstyle(SOLID_FILL,Game.Player2);
    rectangle(710,670,760,720);
    bar(710,670,760,720);
}
void L_Position(int coord[], int color)
{
    int lin,col,count=0;
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
                coord[count++]=lin*10+col;
}
void L_Remake(int coord[], int color)
{
    int lin,col,i;
    //sterge L-ul desenat
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=0;
            }
    //reface L-ul initial folosind coordonatele din vector
    for(i=0;i<=3;i++)
    {
        col=coord[i]%10;
        lin=coord[i]/10;
        setcolor(WHITE);
        rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
        setfillstyle(SOLID_FILL, color);
        floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
        Array[lin][col]=color;
    }
}
void L_Change(int color)
{   int i, lin,col;
    //sterge L-ul initial
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=0;
            }
    //coloreaza L-ul desenat din gri in culoarea jucatorului
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==8)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,color);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=color;
            }
}
int L_corect(int color,int NewVector[])
{
    int count=0;
    for(int lin=1; lin<=4; lin++)
        for(int col=1; col<=4; col++)
            if(Array[lin][col]==color)
                NewVector[count++]=lin*10+col;
    int k=0;
    if(different==0)
        return 0;
    for(int lin=1; lin<=4; lin++)
        for(int col=1; col<=4; col++)
            if(Array[lin][col]==color)
                k++;
    if(k==4 && NewVector[0]==NewVector[1]-1 && NewVector[2]==NewVector[3]-10)
        return 1;
    else
        if(k==4 && NewVector[0]==NewVector[1]-10 && NewVector[2]==NewVector[3]-1)
            return 1;
        else
            if(k==4 && NewVector[0]%10==NewVector[3]%10 && NewVector[2]/10==NewVector[3]/10 && NewVector[1]/10==NewVector[2]/10 && NewVector[2]/10==NewVector[3]/10)
                return 1;
            else
                if(k==4 && NewVector[0]==NewVector[1]-10 && NewVector[1]/10==NewVector[2]/10 && NewVector[2]/10==NewVector[3]/10 && NewVector[0]%10==NewVector[1]%10)
                    return 1;
                else
                    if(k==4 && NewVector[0]/10==NewVector[1]/10 && NewVector[1]/10==NewVector[2]/10 && NewVector[0]%10==NewVector[3]%10 && NewVector[0]==NewVector[3]-10)
                        return 1;
                    else
                        if(k==4 && NewVector[0]/10==NewVector[1]/10 && NewVector[1]/10==NewVector[2]/10 && NewVector[2]==NewVector[3]-10 && NewVector[2]%10==NewVector[3]%10)
                            return 1;
                        else
                            if(k==4 && NewVector[0]%10==NewVector[4]%10 && NewVector[1]/10==NewVector[2]/10)
                                return 1;
                            else
                                if(k==4 && NewVector[0]==NewVector[1]-1 && NewVector[1]==NewVector[2]-1 && NewVector[0]==NewVector[3]+10)
                                    return 1;
                                else
                                    return 0;
}
void Draw_L(int color, int coord[])
{
    int Initial_Line,Initial_Column,Next_Line,Next_Column,count=0;
    different=0; //verific daca L-ul initial e diferit de cel urmator
    if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            Initial_Line= (mousey()-140)/100+1;
            Initial_Column= (mousex()-500)/100+1;
            while(!ismouseclick(WM_LBUTTONUP) && count<3)
            {
                if(ismouseclick(WM_MOUSEMOVE))
                {
                    x = mousex();
                    y = mousey();
                    Next_Line=(y-140)/100+1;
                    Next_Column=(x-500)/100+1;
                    if((x>500&&x<900&&y>140&&y<540) && (Array[Next_Line][Next_Column]==color || Array[Next_Line][Next_Column]==0))//putem construi L ul peste cel mult 3 dintre patratelele colorate
                    {
                        if(Array[Initial_Line][Initial_Column]==0)
                            different=1;
                        setcolor(WHITE);
                        rectangle(Left+Side*(Next_Column-1),Up+Side*(Next_Line-1),Left+Side*Next_Column,Up+Side*Next_Line);
                        setfillstyle(SOLID_FILL,8);
                        floodfill(Left+Side*(Next_Column-1)+1,Up+Side*(Next_Line-1)+1,WHITE);
                        if(Next_Column!=Initial_Column || Next_Line!=Initial_Line)
                        {
                            count++;
                            Array[Initial_Line][Initial_Column]=8;
                            Initial_Column=Next_Column; Initial_Line=Next_Line;
                        }
                    }
                }
            }
            if(Array[Initial_Line][Initial_Column]==0)
                different=1;
            if((x>500&&x<900&&y>140&&y<540) && (Array[Initial_Line][Initial_Column]==color || Array[Initial_Line][Initial_Column]==0))
                Array[Initial_Line][Initial_Column]=8;
            L_Change(color);
            if(L_corect(color,NewVector)==0)
                L_Remake(coord, color);
            else
                ok=0;
        }
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_MOUSEMOVE);
}
void Move_L(int color)
{
    int coord[3];
    L_Position(coord,color);
    ok=1;
    do{
        Draw_L(color, coord);
    }while(ok);

}
void Draw_Circle()
{
    int Initial_Line,Initial_Column,Next_Line,Next_Column;//linie,coloana initiala; linie, coloana urmatoare
    while(!(ismouseclick(WM_LBUTTONDOWN)));
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        Initial_Column=(x-500)/100+1;
        Initial_Line=(y-140)/100+1;
        if(Array[Initial_Line][Initial_Column]==NeutralPiece)
        {
            corect=1;
            setcolor(DARKGRAY);
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            circle(Left+Side*(Initial_Column-1)+50,Up+Side*(Initial_Line-1)+50,40);
            floodfill(Left+Side*(Initial_Column-1)+50,Up+Side*(Initial_Line-1)+50,DARKGRAY);
            while(!(ismouseclick(WM_LBUTTONDOWN)));
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            Next_Column=(x-500)/100+1;
            Next_Line=(y-140)/100+1;
            if((corect==1) && Array[Next_Line][Next_Column]==0 && (x>500 && x<900 && y>140 && y<540))
            {
                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL,NeutralPiece);
                circle(Left+Side*(Next_Column-1)+50,Up+Side*(Next_Line-1)+50,40);
                floodfill(Left+Side*(Next_Column-1)+50,Up+Side*(Next_Line-1)+50,DARKGRAY);
                Array[Initial_Line][Initial_Column]=0;
                Array[Next_Line][Next_Column]=NeutralPiece;
                setcolor(WHITE);
                rectangle(Left+Side*(Initial_Column-1),Up+Side*(Initial_Line-1),Left+Side*Initial_Column,Up+Side*Initial_Line);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(Left+Side*(Initial_Column-1)+1,Up+Side*(Initial_Line-1)+1,WHITE);
            }
            else
                if(Array[Next_Line][Next_Column]!=0 && (x>500&&x<900&&y>140&&y<540))
                {
                    setcolor(DARKGRAY);
                    setfillstyle(SOLID_FILL,NeutralPiece);
                    circle(Left+Side*(Initial_Column-1)+50,Up+Side*(Initial_Line-1)+50,40);
                    floodfill(Left+Side*(Initial_Column-1)+50,Up+Side*(Initial_Line-1)+50,DARKGRAY);
                }
        }
}
void Move_Circle()
{
    corect=0;
    do{
        Draw_Circle();
    }while(corect==0);
}
int Can_Move(int Player)
{
    int count=0;
    for(int j=1;j<=4;j++)
        for(int i=1;i<=4;)
        {
            count=0;
            if((Array[i][j])==0||(Array[i][j]==Player))
            {
                First_Cell=i;
                while((Array[i][j]==0)||(Array[i][j]==Player))
                {
                    count++;
                    i++;
                }
            }
            if((count==3)&&((Array[First_Cell][j+1]==0)||(Array[First_Cell][j-1]==0)||(Array[i-1][j-1]==0)||(Array[i-1][j+1]==0)||(Array[First_Cell][j+1]==Player)||(Array[First_Cell][j-1]==Player)||(Array[i-1][j-1]==Player)||(Array[i-1][j+1]==Player)))
                if((Array[i-1][j]==0)||(Array[i-2][j]==0)||(Array[i-3][j]==0)||(Array[First_Cell][j+1]==0)||(Array[First_Cell][j-1]==0)||(Array[i-1][j-1]==0)||(Array[i-1][j+1]==0))
                   return 1;
            if(count==4)
            {
                if((Array[First_Cell][j+1]==0)||(Array[First_Cell][j-1]==0)||(Array[i-2][j-1]==0)||(Array[i-2][j+1]==0)||(Array[First_Cell][j+1]==Player)||(Array[First_Cell][j-1]==Player)||(Array[i-2][j-1]==Player)||(Array[i-2][j+1]==Player))
                    if((Array[i-2][j]==0)||(Array[i-3][j]==0)||(Array[i-4][j]==0)||(Array[First_Cell][j-1]==0)||(Array[First_Cell][j+1]==0)||(Array[i-2][j-1]==0)||(Array[i-2][j+1]==0))
                        return 1;
                if((Array[First_Cell+1][j+1]==0)||(Array[First_Cell+1][j-1]==0)||(Array[i-1][j-1]==0)||(Array[i-1][j+1]==0)||(Array[First_Cell+1][j+1]==Player)||(Array[First_Cell+1][j-1]==Player)||(Array[i-1][j-1]==Player)||(Array[i-1][j+1]==Player))
                    if((Array[i-1][j]==0)||(Array[i-2][j]==0)||(Array[i-3][j]==0)||(Array[First_Cell+1][j+1]==0)||(Array[First_Cell+1][j-1]==0)||(Array[i-1][j-1]==0)||(Array[i-1][j+1]==0))
                        return 1;
            }
            i++;
        }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;)
        {
            count=0;
            if((Array[i][j])==0 || (Array[i][j]==Player))
            {
                First_Cell=j;
                while((Array[i][j]==0)||(Array[i][j]==Player))
                {
                    count++;
                    j++;
                }
            }
            if((count==3)&&((Array[i+1][First_Cell]==0)||(Array[i-1][First_Cell]==0)||(Array[i+1][First_Cell]==0)||(Array[i-1][j-1]==0)||(Array[i+1][First_Cell]==Player)||(Array[i-1][First_Cell]==Player)||(Array[i+1][j-1]==Player)||(Array[i-1][j-1]==Player)))
                if((Array[i][j-1]==0)||(Array[i][j-2]==0)||(Array[i][j-3]==0)||(Array[i+1][First_Cell]==0)||(Array[i-1][First_Cell]==0)||(Array[i+1][j-1]==0)||(Array[i-1][j-1]==0))
                   return 1;
            if(count==4)
            {
                if((Array[i+1][First_Cell]==0)||(Array[i-1][First_Cell]==0)||(Array[i+1][j-2]==0)||(Array[i-1][j-2]==0)||(Array[i+1][First_Cell]==Player)||(Array[i-1][First_Cell]==Player)||(Array[i+1][j-2]==Player)||(Array[i-1][j-2]==Player))
                    if((Array[i][j-2]==0)||(Array[i][j-3]==0)||(Array[i][j-4]==0)||(Array[i+1][First_Cell]==0)||(Array[i-1][First_Cell]==0)||(Array[i+1][j-2]==0)||(Array[i-1][j-2]==0))
                        return 1;
                if((Array[i+1][First_Cell+1]==0)||(Array[i-1][First_Cell+1]==0)||(Array[i+1][j-1]==0)||(Array[i-1][j-1]==0)||(Array[i+1][First_Cell+1]==Player)||(Array[i-1][First_Cell+1]==Player)||(Array[i+1][j-1]==Player)||(Array[i-1][j-1]==Player))
                    if((Array[i][j-1]==0)||(Array[i][j-2]==0)||(Array[i][j-3]==0)||(Array[i+1][First_Cell+1]==0)||(Array[i-1][First_Cell+1]==0)||(Array[i+1][j-1]==0)||(Array[i-1][j-1]==0))
                        return 1;
            }
            j++;
        }
    return 0;
}
void Coord_Next_Move_PC (int coord2[][6], int color, int &moves, int Matrix[6][6])
{
    int initial_position[4];
    L_Position(initial_position,pc);
    moves=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            if (Matrix[i][j]==0 || Matrix[i][j]==color)
            {
                if (i<=2 && j<=2) //patrat stanga sus
                {
                    if( (Matrix[i+1][j]==0 || Matrix[i+1][j]==color) && (Matrix[i+2][j]==0 || Matrix[i+2][j]==color))
                        if(Matrix[i+2][j-1]==0 || Matrix[i+2][j-1]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=(i+1)*10+j;
                            coord2[moves][3]=(i+2)*10+j;
                            coord2[moves][4]=(i+2)*10+j-1;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i+2][j+1]==0 || Matrix[i+2][j+1]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=(i+1)*10+j;
                                coord2[moves][3]=(i+2)*10+j;
                                coord2[moves][4]=(i+2)*10+j+1;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                    if( (Matrix[i][j+1]==0 || Matrix[i][j+1]==color) && (Matrix[i][j+2]==0 || Matrix[i][j+2]==color))
                        if(Matrix[i+1][j+2]==0 || Matrix[i+1][j+2]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=i*10+j+1;
                            coord2[moves][3]=i*10+j+2;
                            coord2[moves][4]=(i+1)*10+j+2;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-1][j+2]==0 || Matrix[i-1][j+2]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=i*10+j+1;
                                coord2[moves][3]=i*10+j+2;
                                coord2[moves][4]=(i-1)*10+j+2;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                }
                if (i<=2 && j>=3) //patrat dreapta sus
                {
                    if( (Matrix[i+1][j]==0 || Matrix[i+1][j]==color) && (Matrix[i+2][j]==0 || Matrix[i+2][j]==color))
                       if(Matrix[i+2][j-1]==0 || Matrix[i+2][j-1]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=(i+1)*10+j;
                            coord2[moves][3]=(i+2)*10+j;
                            coord2[moves][4]=(i+2)*10+j-1;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i+2][j+1]==0 || Matrix[i+2][j+1]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=(i+1)*10+j;
                                coord2[moves][3]=(i+2)*10+j;
                                coord2[moves][4]=(i+2)*10+j+1;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                    if( (Matrix[i][j-1]==0 || Matrix[i][j-1]==color) && (Matrix[i][j-2]==0 || Matrix[i][j-2]==color))
                        if(Matrix[i+1][j-2]==0 || Matrix[i+1][j-2]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=i*10+j-1;
                            coord2[moves][3]=i*10+j-2;
                            coord2[moves][4]=(i+1)*10+j-2;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-1][j-2]==0 || Matrix[i-1][j-2]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=i*10+j-1;
                                coord2[moves][3]=i*10+j-2;
                                coord2[moves][4]=(i-1)*10+j-2;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                }
                if(i>=3 && j<=2) //patrat stanga jos
                {
                    if( (Matrix[i][j+1]==0 || Matrix[i][j+1]==color) && (Matrix[i][j+2]==0 || Matrix[i][j+2]==color))
                        if(Matrix[i+1][j+2]==0 || Matrix[i+1][j+2]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=i*10+j+1;
                            coord2[moves][3]=i*10+j+2;
                            coord2[moves][4]=(i+1)*10+j+2;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-1][j+2]==0 || Matrix[i-1][j+2]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=i*10+j+1;
                                coord2[moves][3]=i*10+j+2;
                                coord2[moves][4]=(i-1)*10+j+2;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                    if( (Matrix[i-1][j]==0 || Matrix[i-1][j]==color) && (Matrix[i-2][j]==0 || Matrix[i-2][j]==color))
                        if(Matrix[i-2][j-1]==0 || Matrix[i-2][j-1]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=(i-1)*10+j;
                            coord2[moves][3]=(i-2)*10+j;
                            coord2[moves][4]=(i-2)*10+j-1;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-2][j+1]==0 || Matrix[i-2][j+1]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=(i-1)*10+j;
                                coord2[moves][3]=(i-2)*10+j;
                                coord2[moves][4]=(i-2)*10+j+1;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                }
                if(i>=3 && j>=3) //patrat dreapta jos
                {
                    if( (Matrix[i-1][j]==0 || Matrix[i-1][j]==color) && (Matrix[i-2][j]==0 || Matrix[i-2][j]==color))
                        if(Matrix[i-2][j-1]==0 || Matrix[i-2][j-1]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=(i-1)*10+j;
                            coord2[moves][3]=(i-2)*10+j;
                            coord2[moves][4]=(i-2)*10+j-1;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-2][j+1]==0 || Matrix[i-2][j+1]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=(i-1)*10+j;
                                coord2[moves][3]=(i-2)*10+j;
                                coord2[moves][4]=(i-2)*10+j+1;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                    if( (Matrix[i][j-1]==0 || Matrix[i][j-1]==color) && (Matrix[i][j-2]==0 || Matrix[i][j-2]==color))
                        if(Matrix[i+1][j-2]==0 || Matrix[i+1][j-2]==color)
                        {
                            coord2[++moves][1]=i*10+j;
                            coord2[moves][2]=i*10+j-1;
                            coord2[moves][3]=i*10+j-2;
                            coord2[moves][4]=(i+1)*10+j-2;
                            if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                moves--;
                        }
                        else
                            if(Matrix[i-1][j-2]==0 || Matrix[i-1][j-2]==color)
                            {
                                coord2[++moves][1]=i*10+j;
                                coord2[moves][2]=i*10+j-1;
                                coord2[moves][3]=i*10+j-2;
                                coord2[moves][4]=(i-1)*10+j-2;
                                if(coord2[moves][1]==initial_position[0] && coord2[moves][2]==initial_position[1] && coord2[moves][3]==initial_position[2] && coord2[moves][4]==initial_position[3])
                                    moves--;
                            }
                }

            }
}
void Move_PC_easy1(int coord2[][6], int color,int position)
{
    int moves=0;
    Coord_Next_Move_PC(coord2,color,moves,Array);
    int lin, col, i;
    //sterge L-ul initial
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=0;
            }
    for(i=1;i<=4;i++)
    {
        col=coord2[position][i]%10;
        lin=coord2[position][i]/10;
        setcolor(WHITE);
        rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
        setfillstyle(SOLID_FILL, color);
        floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
        Array[lin][col]=color;
    }
}
void Move_PC_easy2(int coord2[][6], int color,int position)
{
    int moves=0;
    Coord_Next_Move_PC(coord2,color,moves,Array);
    int lin, col, i;
    //sterge L-ul initial
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=0;
            }
    for(i=1;i<=4;i++)
    {
        col=coord2[position][i]%10;
        lin=coord2[position][i]/10;
        setcolor(WHITE);
        rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
        setfillstyle(SOLID_FILL, color);
        floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
        Array[lin][col]=color;
    }

}
void pc_circle_Erase()
{
    int lin,col;
    for(lin=1;lin<=4;lin++)
    {
        for(col=1;col<=4;col++)
        {
            if(Array[lin][col]==NeutralPiece)
            {
                delay(100);
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+50,Up+Side*(lin-1)+50,BLACK);
                Array[lin][col]=0;
                delay(300);
                return ;
            }
        }
    }
}
void pc_circle_Draw1() 
{
    int stop=1,line,column;
    for(line=1;line<=4 && stop!=0;line++)
    {
        for(column=1;column<=4 && stop!=0;column++)
        {
            if (Array[line][column]==0)
            {
                delay(100);
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,NeutralPiece);
                circle(Left+Side*(column-1)+50,Up+Side*(line-1)+50,40);
                floodfill(Left+Side*(column-1)+50,Up+Side*(line-1)+50,WHITE);
                Array[line][column]=NeutralPiece;
                stop=0;
                delay(300);
            }
        }
    }
}
void pc_circle_Draw2()
{
    int line,column,stop=1;
    for(line=4;line>=1 && stop!=0;line--)
    {
        for(column=4;column>=1 && stop!=0;column--)
        {
            if (Array[line][column]==0)
            {
                delay(100);
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,NeutralPiece);
                circle(Left+Side*(column-1)+50,Up+Side*(line-1)+50,40);
                floodfill(Left+Side*(column-1)+50,Up+Side*(line-1)+50,WHITE);
                Array[line][column]=NeutralPiece;
                stop=0;
                delay(300);
            }

        }
    }
}
void pc_circle_Draw3()
{
    int line,column,stop=0;
    do
    {
        line=rand()%4+1;
        column=rand()%4+1;
        if (Array[line][column]==0)

        {
            delay(100);
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,NeutralPiece);
            circle(Left+Side*(column-1)+50,Up+Side*(line-1)+50,40);
            floodfill(Left+Side*(column-1)+50,Up+Side*(line-1)+50,WHITE);
            Array[line][column]=NeutralPiece;
            stop=1;
            delay(300);
        }
    } while (stop==0);
}
void Move_PC_medium (int coord2[][6], int color)
{
    int moves=0;
    Coord_Next_Move_PC(coord2,color,moves,Array);
    int lin, col, i;
    //sterge L-ul initial
    for(lin=1; lin<=4; lin++)
        for(col=1; col<=4; col++)
            if(Array[lin][col]==color)
            {
                setcolor(WHITE);
                rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
                setfillstyle(SOLID_FILL,0);
                floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
                Array[lin][col]=0;
            }
    //deseneaza noul L folosind coordonatele din vector
    int random=rand()%moves+1;
    for(i=1;i<=4;i++)
    {
        col=coord2[random][i]%10;
        lin=coord2[random][i]/10;
        setcolor(WHITE);
        rectangle(Left+Side*(col-1),Up+Side*(lin-1),Left+Side*col,Up+Side*lin);
        setfillstyle(SOLID_FILL, color);
        floodfill(Left+Side*(col-1)+1,Up+Side*(lin-1)+1,WHITE);
        Array[lin][col]=color;
    }

}
void Help();
void Settings();
void Start();
void Start2();
void Start3();
void LGame()
{
    readimagefile("bonol6.jpg",0,0,1600,800);
    setcolor(LIGHTCYAN);
    setlinestyle(SOLID_LINE,0,9);//pt grosimea liniei
    line(400,250,1100,250);
    line(400,400,1100,400);
    line(400,550,1100,550);
    line(750,100,750,250);

    line(750,150,1100,150);

    line(925,150,925,250);

    settextstyle(9,HORIZ_DIR,7);
    outtextxy(600,600,"Exit");
    settextstyle(9,HORIZ_DIR,6);
    outtextxy(600,450,"Help");
    outtextxy(600,300,"Settings");

    settextstyle(9,HORIZ_DIR,4);

    outtextxy(770,180,"Easy");
    outtextxy(945,180,"Medium");

    outtextxy(430,150,"Player VS Player");//p vs p
    outtextxy(800,115,"Player VS PC");//p vs pc
    //am facut un singur patrat si am trasat linii
    rectangle(400,100,1100,700);

    setcolor(LIGHTGRAY);
    rectangle(350,50,1150,750);

    setcolor(LIGHTBLUE);
    rectangle(375,75,1125,725);

    setcolor(YELLOW);
    rectangle(362,62,1137,737);

    setcolor(LIGHTRED);
    rectangle(387,87,1113,713);

    while(!(ismouseclick(WM_LBUTTONDOWN)));
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(x>400&&x<1100&&y>400&&y<550)
    {
        Help();
        Choice=1;
    }
    else
        if(x>400&&x<1100&&y>250&&y<400)
        {
            Settings();
            Choice=2;
        }
        else
            if(x>400&&x<750&&y>100&&y<250)
            {
                Start();
                Choice=3;
            }
            else
                if(x>750&&x<925&&y>100&&y<250)
                {
                    Start2();//pt PC
                    Choice=4;
                }
                else
                    if(x>925&&x<1100&&y>100&&y<250)
                    {
                        Start3();
                        Choice=5;
                    }
                    else
                        if(x>400&&x<1100&&y>550&&y<700)
                        {
                            Beep(750,300);
                            exit(0);
                            Choice=6;
                        }
}
void Help()
{
    Beep(750,300);
    readimagefile("mov.jpg",0,0,1600,800);//mov
    setcolor(LIGHTMAGENTA);
    settextstyle(9,HORIZ_DIR,1);
    rectangle(100,100,1450,700);
    setcolor(LIGHTBLUE);
    rectangle(110,110,1440,690);
    setcolor(YELLOW);
    rectangle(120,120,1430,680);
    setfillstyle(SOLID_FILL,BLACK);
    bar(130,130,1420,670);
    setcolor(LIGHTCYAN);
    outtextxy(150,150,"DESCRIPTION:");
    outtextxy(150,180,"->The L game is a two-player game played on a board of 4x4 squares.");
    outtextxy(150,210,"->Each player has a 3x2 L-shaped piece, and there are two 1x1 neutral pieces.");
    outtextxy(150,240,"RULES:");
    outtextxy(150,270,"->On each turn, a player must first move their L piece, and then may optionally move one of the neutral pieces.");
    outtextxy(150,300,"->The game is won by leaving the opponent unable to move their L piece to a new position.");
    outtextxy(150,330,"->Pieces may not overlap or cover other pieces.");
    outtextxy(150,360,"->On moving the L,the only rule is that it must end in a different position from the position it started.");
    outtextxy(150,390,"The INITIAL TABLE is as follows:");
    readimagefile("table.jpg",150,420,380,620);

    settextstyle(9,HORIZ_DIR,4);
    outtextxy(130,730,"PRESS ESC TO RETURN TO MENU");
    int buton;
    buton=getch();
    if(buton==27)//esc
    {
        LGame();
    }
}
void Settings()
{
    Beep(750,300);
    readimagefile("roz.jpg",0,0,1600,800);
    settextstyle(9,HORIZ_DIR,3);
    setcolor(LIGHTMAGENTA);
    outtextxy(100,100,"Choose the color of the first player:");
    outtextxy(900,100,"Choose the color of the second player:");
    outtextxy(650,140,"Choose the color");
    outtextxy(650,170,"for neutral piece:");

    rectangle(720,220,770,270);
    setfillstyle(SOLID_FILL,LIGHTBLUE);//9
    bar(720,220,770,270);

    rectangle(720,290,770,340);
    setfillstyle(SOLID_FILL,LIGHTGREEN);//10
    bar(720,290,770,340);

    rectangle(720,360,770,410);
    setfillstyle(SOLID_FILL,YELLOW);//14
    bar(720,360,770,410);

    rectangle(720,430,770,480);
    setfillstyle(SOLID_FILL,LIGHTRED);//12
    bar(720,430,770,480);
    setlinestyle(SOLID_LINE,0,8);

    rectangle(100,150,600,540);

    rectangle(900,150,1400,540);

    rectangle(130,190,260,300);

    setlinestyle(SOLID_LINE,0,6);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    bar(130,190,260,300);

    rectangle(280,190,410,300);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    bar(280,190,410,300);

    rectangle(430,190,560,300);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL,MAGENTA);
    bar(430,190,560,300);

    rectangle(130,350,260,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    bar(130,350,260,460);

    rectangle(280,350,410,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(BROWN);
    setfillstyle(SOLID_FILL,BROWN);
    bar(280,350,410,460);

    rectangle(430,350,560,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(LIGHTMAGENTA);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(430,350,560,460);

    rectangle(930,190,1060,300);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    bar(930,190,1060,300);

    rectangle(1080,190,1210,300);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    bar(1080,190,1210,300);

    rectangle(1230,190,1360,300);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL,MAGENTA);
    bar(1230,190,1360,300);

    rectangle(930,350,1060,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    bar(930,350,1060,460);

    rectangle(1080,350,1210,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(BROWN);
    setfillstyle(SOLID_FILL,BROWN);
    bar(1080,350,1210,460);

    rectangle(1230,350,1360,460);
    setlinestyle(SOLID_LINE,0,6);
    setcolor(LIGHTMAGENTA);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(1230,350,1360,460);
    settextstyle(9, HORIZ_DIR,3);

    outtextxy(930,600,"BACK");
    rectangle(900,580,1060,650);

    outtextxy(100,600,"Choose the song number");
    outtextxy(100,700,"If you don't want to choose any song, choose 4");

    rectangle(130,640,170,680);
    outtextxy(140,650,"1");

    rectangle(210,640,250,680);
    outtextxy(220,650,"2");

    rectangle(290,640,330,680);
    outtextxy(300,650,"3");

    rectangle(370,640,410,680);
    outtextxy(380,650,"4");
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        ChooseColor();
    }
     while(!(ismouseclick(WM_LBUTTONDOWN)));
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        ChooseColorNeutralPiece();
        if(x>130 && x<170 && y>640 && y<680)
        {
             bool played1=PlaySound(TEXT("song1.wav"),NULL, SND_ASYNC);
        }
        if(x>210 && x<250 && y>640 && y<680)
        {
             bool played2=PlaySound(TEXT("song2.wav"),NULL, SND_ASYNC);
        }
        if(x>290 && x<330 && y>640 && y<680)
        {
             bool played3=PlaySound(TEXT("song3.wav"),NULL, SND_ASYNC);
        }
        if(x>370 && x<410 && y>640 && y<680)
        {

        }
    }
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(x>900 && x<1060 && y>580 && y<650)//back
        {
            Beep(750,300);
            LGame();
        }

    }
}
void Start()
{
    Beep(750,300);
    graphdefaults();
    readimagefile("bonol600.jpg",0,0,1600,800);
    InitialTable(Array);

    while(!(ismouseclick(WM_LBUTTONDOWN)));
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(x>450&&x<540&&y>600&&y<620)
    {
        LGame();
        InitialTable(Array);
        LGame();
    }
    else
    {
        while((Can_Move(Game.Player1)==1) && (Can_Move(Game.Player2)==1) && x>500&&x<900&&y>140&&y<540 )
        {
            Move_L(Game.Player1);
            Move_Circle();
            Move_L(Game.Player2);
            Move_Circle();
        }
        if((Can_Move(Game.Player1)==1) && (Can_Move(Game.Player2)==0))
        {
            readimagefile("go.jpg",0,0,1600,800);
            settextstyle(9,HORIZ_DIR,5);
            setcolor(LIGHTMAGENTA);
            outtextxy(500,600,"First player won!");
            delay(1000);
            Beep(750,300);
            LGame();
            cout<<"First player won";
        }
        else
           if((Can_Move(Game.Player1)==0) && (Can_Move(Game.Player2)==1))
           {
                readimagefile("go.jpg",0,0,1600,800);
                settextstyle(9,HORIZ_DIR,5);
                setcolor(LIGHTMAGENTA);
                outtextxy(500,600,"Second player won!");
                delay(1000);
                Beep(750,300);
                LGame();
                cout<<"Second player won";
           }
    }
 }
void Start2()
{
    int position_order=1,moves;
    Beep(750,300);
    graphdefaults();
    readimagefile("bonol600.jpg",0,0,1600,800);
    InitialTable(Array);
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(x>450&&x<540&&y>600&&y<620)
    {
        LGame();
        InitialTable(Array);
        LGame();
    }
    else
    {
        while((Can_Move(Game.Player1)==1) && x>500&&x<900&&y>140&&y<540)
        {
            Move_L(Game.Player1);
            Move_Circle();
            moves=0;
            Coord_Next_Move_PC(coord2,pc,moves,Array);
            if (position_order==1)
            {
                Move_PC_easy1(coord2,pc,1);
                pc_circle_Erase();
                pc_circle_Draw1();
            }
            else
                if (position_order==-1)
                {
                    Move_PC_easy2(coord2,pc,moves);
                    pc_circle_Erase();
                    pc_circle_Draw2();
                }
            position_order*=-1;
        }
        if((Can_Move(Game.Player1)==1) && (Can_Move(pc)==0))
        {
            readimagefile("go.jpg",0,0,1600,800);
            settextstyle(9,HORIZ_DIR,5);
            setcolor(LIGHTMAGENTA);
            outtextxy(500,600,"First player won!");
            delay(1000);
            Beep(750,300);
            LGame();
            cout<<"First player won";
        }
        else
           if((Can_Move(Game.Player1)==0) && (Can_Move(pc)==1))
           {
                readimagefile("go.jpg",0,0,1600,800);
                settextstyle(9,HORIZ_DIR,5);
                setcolor(LIGHTMAGENTA);
                outtextxy(500,600,"Second player won!");
                delay(1000);
                Beep(750,300);
                LGame();
                 cout<<"Computer won";
           }
    }
}
void Start3()
{
    int moves;
    Beep(750,300);
    graphdefaults();
    readimagefile("Pc.jpg",0,0,1600,800);
    InitialTable(Array);
    while(!(ismouseclick(WM_LBUTTONDOWN)));
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(x>450&&x<540&&y>600&&y<620)
    {
        LGame();
        InitialTable(Array);
        LGame();
    }
    else
    {
        while((Can_Move(Game.Player1)==1) && x>500&&x<900&&y>140&&y<540)
        {
            Move_L(Game.Player1);
            Move_Circle();
            moves=0;
            Coord_Next_Move_PC(coord2,pc,moves,Array);
            Move_PC_medium(coord2,pc);
            pc_circle_Erase();
            pc_circle_Draw3();
        }
        if((Can_Move(Game.Player1)==1) && (Can_Move(pc)==0))
        {
            readimagefile("go.jpg",0,0,1600,800);
            settextstyle(9,HORIZ_DIR,5);
            setcolor(LIGHTMAGENTA);
            outtextxy(500,600,"First player won!");
            delay(1000);
            Beep(750,300);
            LGame();
            cout<<"First player won";
        }
        else
           if((Can_Move(Game.Player1)==0) && (Can_Move(pc)==1))
            {
                readimagefile("go.jpg",0,0,1600,800);
                settextstyle(9,HORIZ_DIR,5);
                setcolor(LIGHTMAGENTA);
                outtextxy(500,600,"Computer won!");
                delay(1000);
                Beep(750,300);
                LGame();
                cout<<"Computer won";
            }
    }
}
int main()
{
    initwindow(1600,800);
    Choice=10;
    while(1)
    {
        if(Choice==10)
            LGame();//meniul propriu zis
        else
            if(Choice==1)
                Help();
            else
                if(Choice==2)
                    Settings();
                else
                    if(Choice==3)
                        Start();
                    else
                        if(Choice==4)
                            Start2();
                        else
                            if(Choice=5)
                                Start3();

    }
    getch();
    closegraph();
    return 0;
}
