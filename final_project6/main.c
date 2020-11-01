#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#define STR_LEN 50
#define MAX_SIZE 100
char A_name[STR_LEN],B_name[STR_LEN];
int A_score,B_score;
int D[MAX_SIZE];///for completed squares return
int C[MAX_SIZE];///for saving steps
int w=0,z=0;
time_t initial_time;
///----------------------------------------struct players------------------------------------------------------//
typedef struct
{
    int score;
    char Name[10];
    int Rank;
     } player;
///_____________________________________________main_____________________________________________________________________
int main()
{
    player player_A;
    player player_B;
    int score=0;
    initial_time= time(NULL);
    time_t k=time(NULL)-initial_time;
    player_A.score=0; player_B.score=0; player_A.Rank=0; player_B.Rank=0;
    int x=0;int Y=0;int n=0;int outrange;int num_of_turns;int counter_save=0;
    int m,l,newgame,decision;
    int i,j;
    int dim,sum,column,row,complete_square,save,load,start,range;
    int temp_1=0,temp_2=0,temp_3=0;
    char temp_4[STR_LEN],temp_5[STR_LEN],temp_6[STR_LEN];
    int User1_Index=0,User2_Index=0;
    int h=0;
///-----------------------------------------initializing of arrays----------------------------------------------------
    for(i=0;i<MAX_SIZE;i++){C[i]=-1; D[i]=0;}
    char Player_Names[MAX_SIZE][STR_LEN];
    int ranks[MAX_SIZE];
    FILE *fNAMES;
    fNAMES=fopen("Players&&Ranks.txt","r");
    if (fNAMES==NULL){printf("Unable to open the file");}
    else{
    for(i=0;i<MAX_SIZE;i++){fscanf(fNAMES,"%s\t%d",Player_Names[i],&ranks[i]);} ///____________FFF >> means There are No Names Yet
    }
    fclose(fNAMES);
///_________________________________________________________save files_________________________________________________________________
    FILE *save_game_1;
    FILE *save_game_2;
    FILE *save_game_3;
    FILE *fbeginner_1;
    FILE *fbeginner_2;
    FILE *fexpert_1;
    FILE *fexpert_2;
    int CPU;
    int RF=1;
    ///_________________________________________________while loop to start game or select from save files______________________________
    while(RF==1){
        n=0;
    while(1){
        printf("(1)Start.\t(2)load saved game.\t(3)Top10\n");
        start=readNumber();
        if(start==1)
        {
            break;
        }
        else if(start==2)
        {
   ///_________________________________________________while loop to save file in the desired destination__________________________________________
            while(1){
            printf("load game: (1)save_1.  (2)save_2. (3)save_3. (4)back.\n");
            load=readNumber();
            if(load==1)
            {
             save_game_1=fopen("save_game_1.text","r");
               fscanf(save_game_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name,&CPU,&Y,&dim);


                break;

            }
        else if(load==2)
        {
                 save_game_2=fopen("save_game_2.text","r");
                fscanf(save_game_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name,&CPU,&Y,&dim);

                break;
            }
        else if(load==3)
        {
            save_game_3=fopen("save_game_3.text","r");
              fscanf(save_game_3,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name,&CPU,&Y,&dim);

                        break;
        }
        else if(load==4){break;}
        else{printf("Invalid");}
            }
        }
        else if(start==3){
            char Sorted_Names[MAX_SIZE][STR_LEN];
            int Sorted_Ranks[MAX_SIZE];
            int Swap,temp_7; char temp_8[STR_LEN];
            for (i=0;i<MAX_SIZE;i++){strcpy(Sorted_Names[i],Player_Names[i]); Sorted_Ranks[i]=ranks[i];}
            while(1){
                Swap=0;
                for(i=0;i<MAX_SIZE-1;i++)
                {
                if(Sorted_Ranks[i]<Sorted_Ranks[i+1])
                {
                temp_7=Sorted_Ranks[i]; strcpy(temp_8,Sorted_Names[i]); Sorted_Ranks[i]=Sorted_Ranks[i+1]; Sorted_Ranks[i+1]=temp_7;
                strcpy(Sorted_Names[i],Sorted_Names[i+1]); strcpy(Sorted_Names[i+1],temp_8); Swap=1;
                }
                }
                if(Swap==0){break;}
                }
             for (i=0;i<10;i++){printf("%s\t%d\n",Sorted_Names[i],Sorted_Ranks[i]);}
            }
        else{printf("Invalid");}
        if(load==1||load==2||load==3){break;}
    }

    if(start!=2){
    ///_________________________________________________while to choose game mode (1-player or 2-player) ______________________________________________________________
    while(1){
    printf("Mode:\n(1)player.\n(2)players.\n");
    CPU=readNumber();
    system("cls");
    if(CPU==1||CPU==2)
    {
        break;
    }
    }
    ///______________________________________________________while to choose expert or beginner__________________________________________________________________
    while(1){
    printf("choose the level:(1)beginner. (2)expert.\n");
    Y=readNumber();
    system("cls");
    if((Y==1)||(Y==2))
        break;
    }
    ///____________________________________________________while to choose new game *Or* Load Last game____________________________________________________________________
     while(1)
    {
    printf("1-Start new Game.\n");
    printf("2-Load last Game.\n");
    newgame=readNumber();
    system("cls");
        if(newgame==1||newgame==2)
         {break;}
    }

   ///__________________________________________________________________Enter player's name_______________________________________________________________________________________
    if(newgame!=2){
    if(CPU==1){
    printf("Enter player A Name:\n");
    scanf("%s",player_A.Name);
    strcpy(player_B.Name,"CPU");
    }
    else if(CPU==2){
    printf("Enter player A Name:\n");
    scanf("%s",player_A.Name);
    printf("Enter player B Name:\n");
    scanf("%s",player_B.Name);
    }
    int found=0;
    strcpy(temp_4,player_A.Name);
    strcpy(temp_5,player_B.Name);
    for(i=0;i<MAX_SIZE;i++){
        if(Comparing_names(temp_4,Player_Names[i],temp_6)==1){found=1; break;}
    }
    if(found==1){
        User1_Index=i;
    }
    else{
        for(i=0;i<MAX_SIZE;i++){if(strcmp(Player_Names[i],"FFF")==0){strcpy(Player_Names[i],player_A.Name); break;}}
        User1_Index=i; ranks[User1_Index]=0;
    }
    found=0;
    for(i=0;i<MAX_SIZE;i++){
        if(Comparing_names(temp_5,Player_Names[i],temp_6)==1){found=1; break;}
    }
    if(found==1){
        User2_Index=i;
    }
    else{
        for(i=0;i<MAX_SIZE;i++){if(strcmp(Player_Names[i],"FFF")==0){strcpy(Player_Names[i],player_B.Name); break;}}
        User2_Index=i; ranks[User2_Index]=0;
    }
    }
///_______________________________________________________________________________________________________//
    SetColor(14);
    printf("Time : %i\n",k);
    SetColor(31);
    }
    if(Y==1)
    {
        dim=5;
        outrange=7;
        num_of_turns=12;
        range=4;
    }
    else{(dim=11);
    outrange=19;
    num_of_turns=60;
    range=10;
    }
    int A[dim][dim];
    ///_____________________________________________________________________Load last game_________________________________________________///
    if(newgame==2||start==2){
    if((CPU==1)&&(Y==1))
    {
     fbeginner_1=fopen("fbeginner_1.text","r");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(fbeginner_1,"%d\n",&A[i][j]);}
                    }
            fscanf(fbeginner_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name);
                fclose(fbeginner_1);
                }
    else if((CPU==2)&&(Y==1))
    {
         fbeginner_2=fopen("fbeginner_2.text","r");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(fbeginner_2,"%d\n",&A[i][j]);}
            }
      fscanf(fbeginner_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name);
     fclose(fbeginner_2);
        }
    else if((CPU==1)&&(Y==2)){
          fexpert_1=fopen("fexpert_1.text","r");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(fexpert_1,"%d\n",&A[i][j]);}
            }
      fscanf(fexpert_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name);
     fclose(fexpert_1);
    }
    else if((CPU==2)&&(Y==2))
    {
         fexpert_2=fopen("fexpert_2.text","r");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(fexpert_2,"%d\n",&A[i][j]);}
            }
      fscanf(fexpert_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",&player_A.score,&player_B.score,&n,&x,&complete_square,&row,&column,&player_A.Name,&player_B.Name);
     fclose(fexpert_2);

    }
    else if(load==1)
    {
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(save_game_1,"%d\n",&A[i][j]);}
                    }
                    fclose(save_game_1);
    }
    else if(load==2)
    {
                    for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(save_game_2,"%d\n",&A[i][j]);}
                    }
                     fclose(save_game_2);
    }
    else if(load==3)
    {
                    for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fscanf(save_game_3,"%d\n",&A[i][j]);}
                    }
                    fclose(save_game_3);

    }
    }
    else{scan_array(dim,A);}
 ///_________________________________________________________________________________________________________________________
    int A_color=12;
   print_array_2(&row,&column,dim,A,&complete_square,A_color);


   while(n<num_of_turns){ ///the program
  ///___________________________________________________________***while loop to take Turns***_______________________________________________________///
    while (1)
    {
    if(x==0){SetColor(12); printf("%s\n",Player_Names[User1_Index]); printf("player A turn\n"); SetColor(31);}
    else{SetColor(9); printf("%s\n",Player_Names[User2_Index]); printf("player B turn\n"); SetColor(31);}
///___________________________________________________while loop to ask you continue or save or undo or redo__________________________________________
   while(1){
        printf("You want to: (1)continue.\t(2)save this Game.\t(3)Undo.\t(4)Redo\n");
        decision=readNumber();
        if(decision==1)
        {
            break;
        }
        else if(decision==2)
        {
            while(1){
            printf("Save in : (1)save_1.  (2)save_2.  (3)save_3.  (4)back.\n");
            scanf("%d",&save);
            if(save==1)
            { save_game_1=fopen("save_game_1.text","w");
             fprintf(save_game_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name,CPU,Y,dim);

                    for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(save_game_1,"%d\n",A[i][j]);}
                    }
                fclose(save_game_1);
                break;
            }
            else if(save==2)
            { save_game_2=fopen("save_game_2.text","w");
            fprintf(save_game_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name,CPU,Y,dim);

                    for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(save_game_2,"%d\n",A[i][j]);}
                    }
                fclose(save_game_2);
                break;
            }
            else if(save==3)
            { save_game_3=fopen("save_game_3.text","w");
             fprintf(save_game_3,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %d\n %d\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name,CPU,Y,dim);

                    for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(save_game_3,"%d\n",A[i][j]);}
                    }
                fclose(save_game_3);
                break;
            }
            else if(save==4){break;}
            else printf("invalid answer");
            }
        }
        else if(decision==3){
            if(w!=0){n-=1;}
            h=Undo(w,z,complete_square,dim,A,C,D,&temp_1,&temp_2,&temp_3);
            w=temp_1; z=temp_2; if(C[w+2]!=-1){x=C[w+2];} complete_square=temp_3;
                }
        else if(decision==4){
            if(C[w+2]!=-1){n+=1;}
            h=Redo(w,z,complete_square,dim,A,C,D,&temp_1,&temp_2,&temp_3);
            w=temp_1; z=temp_2; if(C[w-1]!=-1 && w>0){x=C[w-1];} complete_square=temp_3;
                }
        else {printf("Unaccepted option\n");}
   }
     ///__________________________***this if condition makes you input row and column and prevent computer***____________________________///

    if((CPU==2)||((CPU==1)&&(x==0)))
    {
    printf("enter number of row:\n");
    row=readNumber();
    printf("enter number of column:\n");
    column=readNumber();
    }
     else if((CPU==1)&&(x==1))
    {
    CPU_func(dim,A,&row,&column);
    }
    sum=row+column;
    k=time(NULL)-initial_time;
    if((CPU==2)||((CPU==1)&&(x==0))){
    if((row>range&&column>range))
   {
       printf("Invalid number of row or column");
   }
    else if(sum%2==0)
    {
        printf("invalid number of row and column\n");
    }
     else if  (sum>outrange)
    {
        printf("out of range\n");
    }
    else if  (A[row][column]!=32)
    {
        printf("this line is already choosen before\n");
    }
    else{break;}
    }
    else{break;}
    }
    if((CPU==2)||((CPU==1)&&(x==0))){
    if((row==0)||(row==2)||(row==4)||(row==6)||(row==8)||(row==10))
    {
        A[row][column]=95;
    }
    else{
            A[row][column]=124;
    }
    }
    system("cls");
    k=time(NULL)-initial_time;
    time_t minutes=k/60;
    k=k%60;
    SetColor(14);
    printf("Time :minutes: %i, seconds: %i\n",minutes,k);
    SetColor(31);

   complete_square=check_array(dim,A,row,column,x);
   score=check_score(complete_square);

   if(x==0){
        int A_color=12;
        ///player A turn
        C[w]=row;
        C[w+1]=column;
        C[w+2]=x;
        D[z]=complete_square;
        for (i=w+3;i<MAX_SIZE;i++){C[i]=-1; D[i]=0;}
        w+=3;
        z++;
        print_array_2(&row,&column,dim,A,&complete_square,A_color);
        player_A.score=player_A.score+score+h;
   }
   else
    {
        int B_color=9;
        ///player B turn
        C[w]=row;
        C[w+1]=column;
        C[w+2]=x;
        D[z]=complete_square;
        for (i=w+3;i<MAX_SIZE;i++){C[i]=-1; D[i]=0;}
        w+=3;
        z++;
        print_array_2(&row,&column,dim,A,&complete_square,B_color);
        player_B.score=player_B.score+score+h;
   }
 printf("player A score=%d  ,player B score=%d\n",player_A.score,player_B.score);
 x=take_turns(x,complete_square);
n++;
///________________________________________________if conditions to save the game every time_________________________________
   if((CPU==1)&&(Y==1))
    {
     fbeginner_1=fopen("fbeginner_1.text","w");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(fbeginner_1,"%d\n",A[i][j]);}
                    }
            fprintf(fbeginner_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name);
                fclose(fbeginner_1);
                }
    else if((CPU==2)&&(Y==1))
    {
         fbeginner_2=fopen("fbeginner_2.text","w");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(fbeginner_2,"%d\n",A[i][j]);}
            }
      fprintf(fbeginner_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name);
     fclose(fbeginner_2);
        }
    else if((CPU==1)&&(Y==2)){
          fexpert_1=fopen("fexpert_1.text","w");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(fexpert_1,"%d\n",A[i][j]);}
            }
      fprintf(fexpert_1,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name);
     fclose(fexpert_1);
    }
    else if((CPU==2)&&(Y==2))
    {
         fexpert_2=fopen("fexpert_2.text","w");
            for(i=0;i<dim;i++){
                    for(j=0;j<dim;j++){
                    fprintf(fexpert_2,"%d\n",A[i][j]);}
            }
      fprintf(fexpert_2,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n",player_A.score,player_B.score,n,x,complete_square,row,column,player_A.Name,player_B.Name);
     fclose(fexpert_2);

    }
    }

   if(player_A.score>player_B.score)
   {
       SetColor(12);
       printf("%s winner\n",player_A.Name);
       SetColor(31);
   }
   else if(player_A.score<player_B.score)
   {
       SetColor(12);
       printf("%s winner\n",player_B.Name);
       SetColor(31);
   }
   else{printf("tie\n");}
    k=time(NULL)-initial_time;
    time_t minutes=k/60;
    k=k%60;
    printf("Time :minutes: %i, seconds: %i\n",minutes,k);
    ranks[User1_Index]+=player_A.score;
    ranks[User2_Index]+=player_B.score;
    fNAMES=fopen("Players&&Ranks.txt","w");
    for(i=0;i<MAX_SIZE;i++){fprintf(fNAMES,"%s\t%d\n",Player_Names[i],ranks[i]);}
    fclose(fNAMES);
    printf("Rank : %d\n",ranks[User1_Index]);
    while(1){
    printf("Do You want to : (1)continue\t(2)exit\n");
    RF=readNumber();
    if (RF==2 || RF==1){break;}
    else {printf("Invalid Input");}
    }
    if(RF==1){continue;}
    else{break;}
    }
    system("cls");
    return 0;
}
