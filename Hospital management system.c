#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Global variable
bool Exit = 0;

// Enum to help indicate if the room is vacant or full 
enum roomstatus
{
    VACANT,FULL
};
char Statusstring[2][10]={"Vacant","Full"};

// Enum to help indicate the patients status if its critical , recovering or stable
enum patientsstatus
{
    
    RECOVERING,CRITICAL,STABLE 
    
};
char PStatusstring[3][20]={"Recovering","Critical","Stable"};

// Struct to store patients and their ID's
struct Patients {
    
  char patientsName[60] ;
  char patientsID[20];
  enum patientsstatus STATp ;
}P[80];
 
 // Struct to store room numbers
struct Rooms{
    int roomnum;
    enum roomstatus STAT;

}R[10];

// Struct to store the Users and there ID's
struct Users{
    
    char usersName[60];
    char usersID[30];
    
}U[100];

// Function to generate Patients ,Users, Rooms and ID for both Patients and Users
void Datagen ()
{
    char IDlist[20][10]={"5235","7856","4681","3548","2568","1695","9999","8452","6915","0405"};
    char UsersID[20][10]={"1115","2258","3678","4985","8565","2358","7115","5555","9555","6055"};
    char patientslist[10][60] = {"Ahmed Mohammed","Mohammed Mahmmoud","Youssef suliman","Omar khaled","Adel Emmam","Nour Eldin","Naser Khalaf","Naser Mansy","Khalaf Eldahshory","Mostafa Mohammed"}
    ,Usersname[10][60]={"Ahmed Hesham","Nour Mohammed","Islam Ibrahim","Adel Zaky","Ahmed Zaky","Mamdouh Ibrahim","Tarek Al-Hassan","Khaled Ayman","Basil Karem","Tarek Ahmed"};
    for (int i =0; i <10; i ++){
        R[i].roomnum=i+1;
        R[i].STAT =i%2;
        P[i].STATp =i%3;
        strcpy(P[i].patientsName,patientslist[i]);
        strcpy(U[i].usersName,Usersname[i]);
        strcpy(P[i].patientsID,IDlist[i]);
        strcpy(U[i].usersID,UsersID[i]);
        
    }
    
    
        
    for (int j=0;j<10;j++)
    {
        printf("the patient : %s and his id is: %s , status : %s \n",P[j].patientsName,P[j].patientsID,PStatusstring[P[j].STATp]);
        
        printf("Dr.%s  id: %s \n \n",U[j].usersName,U[j].usersID);
    }
    
}

// Function to allow only authorized Users to Access the programme
void Login ()
{
    int k = 0;
    while (0==0)
    {
        int i;
        char id[10], name[20];
        printf("Please enter your Username: \n \n");
        fflush ( stdin );
        gets(name);
        printf("Please enter your ID: \n \n");
        fflush ( stdin ) ;
        gets(id);
        
        //for loop to check if the entered name is tha same as the on in our database
        for ( i = 0 ; i <10 ; i++ )
        {
            
            if( strcmp(name,U[i].usersName) == 0 )
            {
             printf("Welcome Dr.%s \n \n",U[i].usersName);
             break;
            }
           
        }
        
        if ( strcmp(id,U[i].usersID) != 0 )
        {
            printf("there is no such Name/ID Try Again \n \n");
            k++;
        }
        else if ( strcmp(name,U[i].usersName) != 0 )
        {
            printf("there is no such Name/ID Try Again \n \n");
            k++;
        }
        else{
            break;
        }
        // if condition to allow the user to attempt logging in 3 times maximum
        if( k == 3 )
        {
            printf("\nAccess Denied");
            Exit=1;
            break;
        }
    }
    
}

// Function to Add Patient deetails to the database
void addpatient ()
{
    int s = 0 ,d;
    printf("Please enter the patient name: \n");
    for(int i = 0 ; i <2 ; i++)
    {
        fflush ( stdin ) ;
        getchar();
        gets(P[i].patientsName);
        printf ( "Enter ID number:  \n" ) ; 
        fflush ( stdin ) ;
        gets(P[ i ].patientsID) ;
        printf("Please enter one of the following numbers to add the patient status \n 1)Recovering \n 2) Critical \n 3) Stable \n");
        fflush ( stdin ) ;
        scanf("%d",&s);
        
        // switch to let the user choose one of the three patient status and a default to break out of the switch if the user entered a wrong number
        switch(s)
        {
            case 1:
            {
               printf("\n");
               printf(" the patient name is: %s \n the patient id is: %s \n the patient status: %s \n \n",P[i].patientsName,P[i].patientsID,PStatusstring[P[0].STATp]); 
               break;
            }
            case 2:
            {
               printf("\n");
               printf(" the patient name is: %s \n the patient id is: %s \n the patient status: %s \n \n",P[i].patientsName,P[i].patientsID,PStatusstring[P[1].STATp]); 
               break;
            }
            case 3:
            {
               printf("\n");
               printf(" the patient name is: %s \n the patient id is: %s \n the patient status: %s \n \n",P[i].patientsName,P[i].patientsID,PStatusstring[P[2].STATp]); 
               break;
            }
            default:
            {
                break;
            }
        }
        
        break;

    }

}

// Function to Remove the Patient details from the database
void Remove()
{
    
    char garbagename[2]={"*"};
    char n[20];
    int k ;
    
    printf("Please enter the patient ID to remove their details: \n \n");
    fflush ( stdin ) ;
    getchar();
    gets(n);
    
    // for loop with an if condition to check if the entered ID is in the database then clears the patients Name and ID by replacing it with garbage value "*"
  for(  k = 0; k < 10 ; k++ )
  {
       
      
      if( strcmp(n,P[k].patientsID) == 0 )
      {
          strcpy(P[k].patientsName,garbagename);
          if( strcmp(P[k].patientsName,"*") == 0 )
          {
            printf(" the patient details has been removed \n \n");
            break;
          }
      }
      
  }
       if( strcmp(n,P[k].patientsID) != 0  )
      {
        printf(" there is no patient with this id \n \n");
       
      }
    strcpy(P[k].patientsID,garbagename);
}

// Function to Check if the Room is Vacant or Full
void Check()
{
    int r = 0, i ;
    printf("Please enter the Room number \n \n");
    fflush ( stdin ) ;
    scanf("%d",&r);
    for(i=0;i<10;i++)
    {
       
        if(r == R[i].roomnum)
        {
            printf("the room is %s \n \n",Statusstring[R[i].STAT]);
            break;
        }
        
    }
    if(i==10)
    {
        printf(" there is no such room \n \n");
    }
    
}


// Function to Update Patient details 
void updatepatient()
{
    int i;
    char id[10],d[10];
    printf("Please enter the Patient ID:  \n \n");
    fflush ( stdin ) ;
    getchar();
    gets(id);
    
    // for loop to check if the id is in the database
    for(i = 0 ; i <= 10 ; i++)
    {
        if ( strcmp(id,P[i].patientsID) == 0 )
        {
            printf("Please enter the Updated name: \n");
            fflush ( stdin ) ;
            gets(P[i].patientsName);
            fflush ( stdin ) ;
            printf("Please enter the Updated id: \n");
            gets(d);
            strcpy(P[i].patientsID,d);
            printf("\n");
            printf("Patient details : \n Patient Name : %s \n Patient ID : %s \n Patient status : %s \n \n ",P[i].patientsName,P[i].patientsID,PStatusstring[P[i].STATp]);
            break;
        }
    }
    if(i >= 10 )
    {
        printf("There is no Patient with this ID \n");
    }
    
}

int main()
{
    int Choice = 0 ;
    Datagen();
    Login();
    
    // while loop in order to make the programme always running
    while(Exit==0)
    {
        printf("Please choose the operation you want :\n 1) to Add a Patient \n 2) to Remove a Patient details \n 3) to Check if a specific Room is Vacant \n 4) to Update patient details \n 5) to Exit the programme \n \n");
        fflush ( stdin ) ;
        scanf("%d",&Choice);
        // Switch to choose which operation the User want
        switch(Choice)
        {
            case 1:
            {
                printf("\n");
                addpatient();
                break;
            }
            case 2:
            {
                printf("\n");
                Remove();
                break;
            }
            case 3:
            {
                printf("\n");
                Check();
                break;
            }
            case 4:
            {
                printf("\n");
                updatepatient();
                break;
            }
            case 5:
            {
                Exit = 1 ;
                break;
            }
            default:
            {
                break;
            }
        }
        
    }
    return 0;
}