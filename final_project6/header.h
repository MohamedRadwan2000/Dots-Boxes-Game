
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define MAX_SIZE 100
#define STR_LEN 50
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
int check_score(int complete_square)
{
    int score;
    if (complete_square==2||complete_square==4)
    {
        score=2;
    }
    else if(complete_square==0)
    {
        score=0;
    }
    else{
        score=1;
    }
    return score;
}



int check_array(int dim,int a[dim][dim],int i,int j,int x)
{
    int b;
    if(x==0)
    {
        b=65;
    }
    else{(b=66);}
    int complete=0;
   if(i==0||i==2||i==4||i==6||i==8||i==10)
   {
        if(((a[i-1][j-1]==124)&&(a[i-2][j]==95)&&(a[i-1][j+1]==124))&&((a[i+1][j-1]==124)&&(a[i+2][j]==95)&&(a[i+1][j+1]==124)))
        {
           complete=2;
            a[i+1][j]=b;
            a[i-1][j]=b;
        }
       else if(((a[i-1][j-1]==124)&&(a[i-2][j]==95)&&(a[i-1][j+1]==124))||((a[i+1][j-1]==124)&&(a[i+2][j]==95)&&(a[i+1][j+1]==124)))
       {

           if((a[i+1][j-1]==124)&&(a[i+2][j]==95)&&(a[i+1][j+1]==124))
            {
            complete=1;
             a[i+1][j]=b;
           }
           if((a[i-1][j-1]==124)&&(a[i-2][j]==95)&&(a[i-1][j+1]==124))
           {
               complete=-1;
            a[i-1][j]=b;
           }

       }
    }
    if(i==1||i==3||i==5||i==7||i==9)
    {
         if(((a[i][j-2]==124)&&(a[i-1][j-1]==95)&&(a[i+1][j-1]==95))&&((a[i-1][j+1]==95)&&(a[i][j+2]==124)&&(a[i+1][j+1]==95)))
        {
           complete=4;
            a[i][j+1]=b;
            a[i][j-1]=b;
        }
       else if(((a[i][j-2]==124)&&(a[i-1][j-1]==95)&&(a[i+1][j-1]==95))||((a[i-1][j+1]==95)&&(a[i][j+2]==124)&&(a[i+1][j+1]==95)))
       {
           if((a[i][j-2]==124)&&(a[i-1][j-1]==95)&&(a[i+1][j-1]==95))
            {
            complete=3;
            a[i][j-1]=b;
           }
           if((a[i-1][j+1]==95)&&(a[i][j+2]==124)&&(a[i+1][j+1]==95))
           {
               complete=-3;
               a[i][j+1]=b;
           }

       }
    }
    return complete ;
}
int take_turns(int x,int b)
{
    if(b==0)
    {
        if(x==0)
        {
            x=1;
        }
        else if(x==1)
        {
            x=0;
        }
    }
    else{x=x;}
    return x;
}


//--------------------------------------------^^^^------------

void print_array_2 (int *i,int *j,int dim,int a[dim][dim],int*b,int color_type){
    int r,k;
    if(dim==11){
    printf("  0 1 2 3 4 5 6 7 8 9 10\n");
    }
    if(dim==5){printf("  0 1 2 3 4 \n");
    }
    int w=0;
    if (*b==2)
    {
    for (r=0;r<dim;r++){
        printf("%d ",w);
        w++;
        for (k=0;k<dim;k++){
         if (((r==*i || r==*i+1 || r==*i-1 || r==*i-2 || r==*i+2)&& k==*j)||((r==*i+1 || r==*i-1)&& k==*j+1)||((r==*i+1 || r==*i-1)&& k==*j-1))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else if (*b==-1)
    {
     for (r=0;r<dim;r++){
      printf("%d ",w);
      w++;
        for (k=0;k<dim;k++){
         if (((r==*i || r==*i-1 || r==*i-2)&& k==*j)||(r==*i-1 &&(k==*j+1 || k==*j-1)))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else if (*b==1)
    {
     for (r=0;r<dim;r++){
        printf("%d ",w);
        w++;
        for (k=0;k<dim;k++){
         if (((r==*i || r==*i+1 || r==*i+2)&& k==*j)||(r==*i+1 &&(k==*j+1 || k==*j-1)))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else if (*b==3)
    {
      for (r=0;r<dim;r++){
        printf("%d ",w);
        w++;
        for (k=0;k<dim;k++){
         if ((r==*i &&(k==*j || k==*j-1 || k==*j-2))||((r==*i-1 || r==*i+1)&& k==*j-1))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else if (*b==-3)
    {
      for (r=0;r<dim;r++){
        printf("%d ",w);
        w++;
        for (k=0;k<dim;k++){
         if ((r==*i &&(k==*j || k==*j+1 || k==*j+2))||((r==*i-1 || r==*i+1)&& k==*j+1))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else if (*b==4){
       for (r=0;r<dim;r++){
       printf("%d ",w);
       w++;
        for (k=0;k<dim;k++){
         if ((r==*i &&(k==*j || k==*j+1 || k==*j-1 || k==*j-2 || k==*j+2)||((r==*i+1 || r==*i-1)&& k==*j+1)||((r==*i+1 || r==*i-1)&& k==*j-1)))
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
    else
    {
     for (r=0;r<dim;r++){
        printf("%d ",w);
        w++;
        for (k=0;k<dim;k++){
         if (r==*i && k==*j)
         {
            SetColor(color_type);
            printf("%c",a[r][k]);
            printf(" ");
            SetColor(31);
         }
         else
         {
         printf("%c",a[r][k]);
         printf(" ");
         }
        }
        printf("\n");
    }
    }
}
void scan_array(int dim,int a[dim][dim])
{
    int i,j;
     int A[dim][dim];
    for (i=0;i<dim;i=i+2){
        for (j=0;j<dim;j=j+2){
            a[i][j]=46;
        }
    }
    for (i=0;i<dim;i++){
        for (j=0;j<dim;j++){
            if (a[i][j]!=46){
                a[i][j]=32;
            }
        }
    }
}
void CPU_func(int dim,int a[dim][dim],int *row,int *column)
{
    int i,j,m,l,y;
    for( i=0,m=1;i<dim+1;i=i+2,m=m+2)
    {   y=0;
        for(j=1,l=0;j<dim+1;j=j+2,l=l+2)
        {
            if(a[i][j]==32)
            {
                a[i][j]=95;
                y=1;
                *row=i;
                *column=j;
                break;
            }
            else if(a[m][l]==32)
            {
                a[m][l]=124;
                *row=m;
                *column=l;
                y=1;
                break;
            }
        }
        if(y==1)
        {
            break;
        }
    }
}
int Undo(int w,int z,int b,int dim,int a[dim][dim],int C[MAX_SIZE],int D[MAX_SIZE],int*temp_1,int*temp_2,int*temp_3){
    int i1,i2,j1,j2,player_color,f=0,h=0;
    //previous steps
    if (w==3){ j1=C[w-2] ; i1=C[w-3] ; a[i1][j1]=32 ; *temp_1=w-3; *temp_2=z-1; print_array_2(&i2,&j2,dim,a,&f,31);}
    else if(w==0){printf("Invalid Operation\n"); *temp_1=w; *temp_2=z;print_array_2(&i2,&j2,dim,a,&f,31);}
    else{
    int prev_b=D[z-2];
    player_color=(C[w-4]==0) ? 12:9;
    j1=C[w-2] ; i1=C[w-3] ; a[i1][j1]=32;
    j2=C[w-5];
    i2=C[w-6];
    if (b==2){
    a[i1+1][j1]=32; a[i1-1][j1]=32; h=-2;
    }
    else if (b==1){
    a[i1+1][j1]=32; h=-1;
    }
    else if (b==-1){
    a[i1-1][j1]=32; h=-1;
    }
    else if (b==4){
    a[i1][j1+1]=32; a[i1][j1-1]=32; h=-2;
    }
    else if (b==3){
    a[i1][j1-1]=32; h=-1;
    }
    else if (b==-3){
    a[i1][j1+1]=32; h=-1;
    }
    print_array_2(&i2,&j2,dim,a,&prev_b,player_color);
    *temp_1=w-3;
    *temp_2=z-1;
    *temp_3=prev_b;
    }
    return h;
}

int Redo(int w,int z,int b,int dim,int a[dim][dim],int C[MAX_SIZE],int D[MAX_SIZE],int*temp_1,int*temp_2,int*temp_3){
    int i,j,player_color,player_letter,h=0;
    int next_b=D[z];
    if (C[w]==-1 || w>=MAX_SIZE){printf("Invalid Operation\n"); *temp_1=w; *temp_2=z;}
    else if(C[w]!=-1){
      i=C[w]; j=C[w+1];
      player_color=(C[w+2]==0) ? 12:9;
      player_letter=(C[w+2]==0) ? 65:66;
      if (i%2==0 && (i+j)%2==1){a[i][j]=95;}
      else if(i%2==1 && (i+j)%2==1){a[i][j]=124;}
      if(b==2){a[i+1][j]=player_letter; a[i-1][j]=player_letter; h=2;}
      else if(b==-1){a[i-1][j]=player_letter; h=1;}
      else if(b==1){a[i+1][j]=player_letter; h=1;}
      else if(b==4){a[i][j+1]=player_letter; a[i][j-1]=player_letter; h=2;}
      else if(b==-3){a[i][j+1]=player_letter; h=1;}
      else if(b==3){a[i][j-1]=player_letter; h=1;}
       print_array_2(&i,&j,dim,a,&next_b,player_color);
      *temp_1=w+3;
      *temp_2=z+1;
      *temp_3=D[z+1];
    }
    return h;
}
int Comparing_names(char str[STR_LEN],char original[STR_LEN],char temp[STR_LEN]){
    int n;
   strcpy(temp,original);
   strupr(temp);
   strupr(str);
   n=(strcmp(str,temp)==0) ? 1:0;
   return n;
}
int readNumber()
{
	int number;
	int reads = scanf("%d",&number);
	while(reads != 1)
	{
		getchar();
		reads = scanf("%d",&number);
	}
	return number;
}
