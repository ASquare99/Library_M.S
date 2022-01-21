#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h> //for exit(0)
#include<time.h> //

void newadd();//
void del();//
void view();//
void srch();//
void issue();//
void issue_list();//
void logins();//
void clr();

struct books
{
    int id;
    char name[25];
    char author[25];
    int quantity;
    float price;
};
        struct books b1;

struct student
{
        char name[25];
        int rollno;
};
    struct student s1;

    int id1,captcha,found,k=0;;  //global
    char uid[4];
    int dd,mm,yy;

        //*//*//*//*//*//*//*//*//Start-Up Menu //*//*//*//*//*//*//*//*//*//

void main()
{
       FILE *fp,*fa,*fv,*fs,*fi;
       char ab;
       int sel;
       fetch: //label
       system("cls"); // clrscr
       printf("\n \t\t\t\t\t************ ************ ************ ************ ************ ************  ************\t\t\t\n");

       printf("\n\t\t\t\t\t\t\t\t Welcome To ReadALong Library Database..!! \t\n\n");
       printf("\n \t\t\t\t\t************ ************ ************ ************ ************ ************  ************\t\t\t");
       printf("\n\n\n\n\n \t\t\t\t\t\t\t\t Are You A Student (y/n) : \t");

       scanf("%c",&ab);
       if (ab=='y' || ab=='Y' )
    {
        again: //label
        another:
        fp=fopen("logins.txt","a");

        system ("cls");
        printf("\n\n\t\t\t\t\t\t\t\t ## ##  STUDENT PANEL  ## ## \t\t\t \t\t\t\t\n\n") ;

        printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Your 4 Digit STU_ID : \t\t");
        scanf("%s", uid);
        if( uid<0 && uid>=4)
        {
            exit(0);
        }
        else
        printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Enter Your Name : \t\t");
        scanf("%s", s1.name);
        printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Enter The Roll No. :\t\t");
        scanf("%d", &s1.rollno);
        system ("cls");
        printf("\n\n\t\t\t\t\t\t\t\t Success ! Logged In As : %s%s \n ", strupr(s1.name),uid);

        fprintf(fp,"%s%s...",s1.name,uid);
        fclose(fp);

        printf("\n \n Enter Any Key (1-9) To Proceed  :\t \t  ");

        scanf("%d",&sel);

        if (sel >= 1 && sel<=9 )
        {
            goto label;
        }
        else
        {
            exit(0);
        }

    }
     else if(ab=='n'||ab=='N')
    {

    char id[15], pss[15];//
    char user[15],code[15];

    FILE *fp;
    fp = fopen("match.txt" , "r");

    fscanf(fp,"%s %s",id,pss);
     time_t t;
     time(&t);
     system ("cls");
     printf("\n\n\t\t\t\t\t\t\t\t ## ##  ADMIN PANEL  ## ## \t\t\t \t\t\t\t\n\n") ;
     retry:

    printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Please Enter Your Admin ID :\t");
    scanf("%s",user);

    printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Now  Enter Your  Password  :\t");
    scanf("%s",code);


    if((strcmp(id,user)==0)&&(strcmp(pss,code)==0))
      {
          system ("cls");
          printf("\n\t\t\t\t\t\t\t\t## ## :: LOGIN_SUCCESS :: ## ##\n\n \t\t\t\t\t\t\t\t    %s ",ctime(&t));
          goto point;
     }
      else
       {
         k++;
         printf("\n\n \t\t\t\t\t\t\t OOPs Sorry! Wrong Credentials..Try Again \n\n");

         if(k>=3)
        {
            printf("\t\t\t\t\t\t\t     You Reached Out Limit....PLS EXIT\n");
            getch();
            exit(0);
         }
         goto retry;
       }
    }

     else
        goto fetch;

               //**//**//**//**//**///Defined Functions Definition //**//**//**//**//**//**//

  void newadd() //1st
  {
        int an;
        one:
        fa = fopen("books.txt","a+");

        if(fa==NULL)
        {
            printf("\n\n\t\t\t\t\t\t\t\t  Error! 404 ..Not Found  \n\n");
            return;
        }
        printf("\n\n\t\t\t\t\t\t\t\t SETTING_UP_NEW_RECORD  \n\n");

        printf("\n \t\t\t\t\t\t  $$ Enter Book Code :  \t");
        scanf("%d",&b1.id);
        fflush(stdin);
        printf("\n \t\t\t\t\t\t  $$ Enter Book Name :  \t");
        gets(b1.name);
        printf("\n \t\t\t\t\t\t  $$ Enter Up Writer :  \t");
        gets(b1.author);

        printf("\n \t\t\t\t\t\t  $$ Enter The Pc(s) :  \t");
        scanf("%d",&b1.quantity);
        fflush(stdin);
        printf("\n \t\t\t\t\t\t  $$ Enter The Price :  \t");
        scanf("%f",&b1.price);

        fwrite(&b1,sizeof(b1),1,fa);
        {
            printf("\n\n\t\t\t\t\t\t --------------------------------- ");
            printf("\n \t\t\t\t\t\t (1) Record Added Successfully...:) ");
            printf("\n \t\t\t\t\t\t --------------------------------- ");
            fclose(fa);
        }
            printf("\n\n\t\t\t\t\t\t Want To Add More Record (Press 1) :\t");

            scanf("%d",&an);
            system ("cls");

            if(an==1)
            {
                goto one;
            }
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");
  }

void view()  //2nd
{
     fv = fopen("books.txt","r");

       if(fv==NULL)
        {
            printf("\n\n\t\t\t\t\t\t\t\t  Error! 404 ..Not Found  \n\n");
            return;
        }

        else

        printf("\n \t\t\t\t\t\t\t\t   AVAILABLE_BOOKS_AS_FOLLOW :  \t\n\n");
        printf("\n\t\t\t Book Id \t  Book Name     \t  Name Of Author   \t  Quantity   \t      Max Price\t\t\n");
        printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n");
        while(fread(&b1,sizeof(b1),1,fv)==1)
        {
                 printf("\n\t\t\t %d  \t   \t %s  \t   \t %s   \t   \t  %d  \t   \t     %.2f  \t   \t ",b1.id,b1.name,b1.author,b1.quantity,b1.price);
        }
           printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n");
           fclose(fv);
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");
}

void issue() //3rd
{
            fp = fopen("books.txt","r+");
            fi  = fopen("issue.txt","w+");
            time_t t1;
            time(&t1);

            system("cls");
            printf("\n\n\n\t\t\t\t\t\t\t\t \tISSUE_SECTION  \n\n\n\n");

             printf(" \n \t\t\t\t\t\t\tEnter BOOK ID : ");
             scanf("%d",&id1);

        while(fread(&b1,sizeof(b1),1,fp))
           {
           if( b1.id==id1 )
              {
                   k=1;
                   printf("\n \t\t\t\t\t\t\tAprx %d Books Of %s Are Availabe\n " ,b1.quantity,b1.name);
                   found = b1.quantity;
              }
           }

            if(k==0)
              {
                printf(" \n\n \t\t\t\t\t\t\t\t NOT AVAILABLE");
                getch();
                exit(0);
              }

             printf("\n\n\t\t\t\t\t\t\tEnter 1 To Issue This One : \t ");
             scanf("%d",&id1);
             system ("cls");

             if(id1==1)
             {
                printf("\n\n\t\t\t\t\t\t\t @G-ONE \t ISSUE-SLIP \t @G-ONE \n\n");

                struct tm *local = localtime(&t1);
                dd = local->tm_mday+10;
                mm = local->tm_mon+2;
                yy = local->tm_year+1900;

                printf("\n \n\t\t\t\t\t\t #. UID Of Student : \t%s",uid);
                printf("\n\n \t\t\t\t\t\t #. Name Of Student : \t%s",s1.name);
                printf("\n\n \t\t\t\t\t\t #. Issued Book ID : \t%d",b1.id);
                printf("\n\n \t\t\t\t\t\t #. Issued Book Is : \t%s by %s",b1.name,b1.author);
                printf("\n\n \t\t\t\t\t\t #. Date Of Issue : \t%s", ctime(&t1));
                printf("\n \t\t\t\t\t\t #. Date Of Return :\t07.%d.%d ",mm,yy);

                printf("\n\n \t\t\t\t\t\t No < 100 To Confirm : \t");
                scanf("%d", &captcha);

                if(captcha<100)
                {
                    fwrite(&b1,sizeof(b1),1,fi);
                      //found --;
                     //b1.quantity = found;
                     //fwrite(&b1,sizeof(b1),1,fp);


                     fclose(fi);
                     fclose(fp);

                    printf("\n\n\t\t\t\t\t\t\t\t  (1) BOOK ISSUED. . .");
                    printf("\n\t\t\t\t\t\t\t\t  RETURN PERIOD OVER IN 10 DAYS \n");
                    printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n");
                    printf("\t\t\t\t\t\t --- --- --- Take Slip ScreenShot For Future Reference --- --- ---");
                    printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n");
                }

            else
                {
                      printf("\n \t\t\t\t\t\t Something Went Wrong...Error In Confirmation :( \n\n\n");
                      exit(0);
                }
             }
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");
}

void issue_list()  //4th
{

    fi = fopen("issue.txt","r+");

     if(fi==NULL)
        {
            printf("\n\n\t\t\t\t\t\t\t\t  Error! 404 ..Not Found  \n\n");
        }
    else
        {
        printf("\n\n \t\t\t\t\t\t\t\t\t DISPLAYING_ISSUED_BOOKS \n\n");

        printf("\n \t\t\t STU_ID \t\t Book ID \t\t Book Name \t\t Book Author \t\t Return Date");

        printf("\n \t\t\t---------------------------------------------------------------------------------------------------------------\t\t\n");

        while(fread(&b1,sizeof(b1),1,fi))
        {
                printf("\n \t\t\t %s \t\t\t %d \t\t\t %s \t\t %s \t\t 07.%d.%d",uid,b1.id,b1.name,b1.author,mm,yy);
        }

        printf("\n \t\t\t--------------------------------------------------------------------------------------------------------------\t\t\n");
        }
        fclose(fi);
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");
}

void srch() //5th
{
    int id;

    fs = fopen("books.txt","r");

      if(fs==NULL)
        {
           printf("\n\n\t\t\t\t\t\t\t\t  Error! 404 ..Not Found  \n\n");
        }

        else
        {
        printf("\n \t\t\t\t\t\t\t\t   SEARCHING_SECTION  \t\n\n");
        printf("\n\n \t\t\t\t\t\t      Enter 'Book ID' To Search Among :\t");
        scanf("%d",&id);


        while(fread(&b1,sizeof(b1),1,fs)!=NULL)
        {
            if(b1.id==id)
            {
                k=1;
         printf("\n \t\t\t\t\t\t      Search For Book-ID  '%d'  Is Success \n\n",id);

        printf("\n\t\t\t Book Id \t  Book Name     \t  Name Of Author   \t  Quantity   \t      Max Price\t\t\n");
         printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n" );
         printf("\n\t\t\t %d  \t   \t %s  \t   \t %s   \t   \t  %d  \t   \t     %f  \t   \t ",b1.id,b1.name,b1.author,b1.quantity,b1.price);
         printf("\n\t\t\t------------------------------------------------------------------------------------------------------------\t\t\n" );
            }
        }

         if(k==0)
            {
                printf(" \n\n \t\t\t\t\t\t       Nothing Found With Respect To  '%d' ",id);
            }
        fclose(fs);
        }
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");
}

void clr()
{
     remove("logins.txt");
     fp = fopen("logins.txt","r");
     remove("logins.txt");

    if(fp!=NULL)
        {
        printf("\n\n\ \t\t\t\t \t\t\t\t Something Went Wrong");
        }
    else
      {
         printf("\n\n\n \t\t\t\t \t\t\t\t All Login Records Has Been Cleared ");
      }

      getch();
}

void del()  //6th
{
    printf("\n\n \t\t\t\t\t\t\t\t ELIMINATE_RECORD\n");
    printf("\n\n\n \t\t\t\t\t\t\t Enter The Book ID To Delete : \t ");
    scanf("%d",&id1);

          fp = fopen("books.txt", "r");
          found = 0;
          while (fread(&b1, sizeof(b1), 1, fp))
          {
                if (b1.id == id1)
                  {
                    found = 1;
                    break;
                  }
          }
          fclose(fp);

          if (found == 0)
            {
              printf(" \n\n \t\t\t\t\t\t\tNothing Found With Respect To  '%d' ",id1);
            }
         else
            {
            // create a temporary file
            FILE * temp;
            temp = fopen("book1.txt", "a");
            if (temp == NULL)
             {
              printf("\n\n\t\t\t\t\t\t\t\t  Error! 404 ..Not Found  \n\n");
              exit(1);
            }

            fp = fopen("books.txt", "r");

            // to temporary file
            while(fread(&b1,sizeof(b1), 1, fp))
            {
              if (b1.id != id1)
              {
                fwrite(&b1,sizeof(b1), 1, temp);
              }

            }
            fclose(fp);
            fclose(temp);
            // delete original file
            remove("books.txt");
            // rename the temporary file
            rename("book1.txt", "books.txt");
            printf("\n\n\t\t\t\t\t\t\t Success... %d Deleted  From Records \n\n\n",id1);
          }

           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");

}

void logins() //7th
{
     char ch[10];

     fp = fopen("logins.txt","r");

      if(fp==NULL)
        {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 NO_LOGINS_TODAY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        }
    else
     {
        printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ACTIVE_USERS_TODAY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");
        fscanf(fp, "%s", ch);

        printf("\n\t\t\t +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\t\t\n");

        printf("\n\t\t\t\t\t\t\t\t ID-Name : %s",strupr(ch));

        printf("\n\n\t\t\t ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\t\t\n\n\n");
     }
           printf("\n\n\t\t \t\t\t \t\t \tPress Any Key To Continue\n");
           printf("\t\t\t\t \t \t \t\t\t \t\t");getch();
           system("cls");

}
/////////////////Calling Of Above Defined Function//////////////////////////

    int opt;
    label:

     while(1)
    {

    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 1 To View Books :\n");
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 2 To Search Books : \n");
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 3 To Issue Books :\n");
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 9 To Log-In With Another ID : \n");
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 0 To Exit OUT :\n");



     printf("\n\n  # Select The Operation (1-3): ");

     scanf("%d",&opt);

     if(opt==9)
     goto another;
     else

    switch(opt)
    {
                  case 1: system ("cls");
                      view();
                    break;
                  case 2: system ("cls");
                      srch();
                    break;
                case 3: system ("cls");
                    issue();
                    break;
                 case 0:
                    goto fetch;
                    break;
                 default:
                    printf("\n OOPs This Is An Invalid Entry ");
    }
 }

    int choice;
    point:

   while(1)
    {

    printf("\n\n\n\n\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 1 To Add Record :\n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 2 To View Books :\n");
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 3 To Search Books :\n");
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 4 To Delete Record : \n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 5 To Issue Books :\n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 6 To View Issued One :\n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 7 To Check Logins :\n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 8 To Exit n Clr Logins :\n");//
           printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 # Press 0 To Exit OUT :\n");


        printf("\n\n  # Select the Operation (1-8) : ");
        scanf("%d",&choice);
        switch(choice)
        {
       case 1: system ("cls");
           newadd();
        break;

       case 2: system ("cls");
            view();
            break;

       case 3: system ("cls");
           srch();
           break;

        case 4: system ("cls");
             del();
            break;

        case 5: system ("cls");
            issue();
            break;

        case 6: system ("cls");
            issue_list();
            break;

        case 7 : system ("cls");
            logins();
            break;

       case 8 : system("cls");
             clr();
             goto fetch;
             break;

        case 0: system ("cls");
           goto fetch;
           exit(0);

        default:
        printf("\n\nSorry! Its An Invalid Input :( ");

        system ("cls");
        break;
        }
    }
}
