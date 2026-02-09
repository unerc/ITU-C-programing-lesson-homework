#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,i,sum=0,g,num;
struct Patient
{
    char Name[40];
    char Surname[40];
    char Birthday[40];
    char Email[40];
    char Department[40];
}x[1000000];//the struct that we use to hold the data of patients 
void read();
void add();
void search();
void update();
void del();
void show();
void write();
int main()
{
    read();
    int c,k;
    printf("Hospital Management System\n\n\n\n");
    while(c!=4) {

        printf("**Enter your choice**\n\n1. Show All Records\n2. Search Patient\n3. New Patient\n4. Exit\n\nOption=");
        scanf("%d",&c);
        fflush(stdin);
        
		if(c==1){ // shows all the records already entered
            system("cls");
            show();
            
            printf("\n1. Return to Main Menu\n2. Delete Record\n3. Update Record\nOption=");//asks the choice
			scanf("%d",&k);
            while(k!=1){
						    
			if (k==2){//deletes the data of selected patient
				system("cls");
            	del();
            	k=1;
			}
			
			else if (k==3){ // updates the data of selected patient
				system("cls");
			    update();
			    k=1;
			}
			else if(k==1) {//returns main menu
            }
            
			else{
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
            k=1;
            }
              printf("\n\n");
		   }
        }
		else if(c==2)//searches patient
        {
            system("cls");
            search();
        }
		else if(c==3)//adds new patient
        {
            system("cls");
            add();
        }
        else if(c==4)//exit the program
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
	return 0;
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);//shows alredy entered data  
    printf("How many entry do you want to add=\n");//asks how many new patient are there
    scanf("%d",&n);
    sum=n+num;
    for(i=num; i<sum; i++)//starts from last patient to the new last
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name = ");
        gets(x[i].Name);
        fflush(stdin);
        printf("Enter patient's Surname = ");
        gets(x[i].Surname);
        fflush(stdin);
        printf("Enter Birthday = ");
        gets(x[i].Birthday);
        fflush(stdin);
        printf("Enter Email = ");
        gets(x[i].Email);
        fflush(stdin);
        printf("Enter Department = ");
        gets(x[i].Department);
        fflush(stdin);
        printf("\n");
        num++;
        write();//in each iteration it writes the data to the file
    }
}

void show()
{
    for(i=0; i<num; i++)
    {
    	if(strcmp(x[i].Birthday,"Cleared")!=0 || strcmp(x[i].Email,"Cleared")!=0)//shows patient first to last except the deleted ones 
    	{
    		printf("\n");
        	printf("Patient ID=%d\nName = %s\nSurname = %s\n",i,x[i].Name,x[i].Surname);
        	printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[i].Birthday,x[i].Email,x[i].Department);
        	printf("\n\n");
		}
        
    }
}
void update()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Surname\n3.Birthday\n4.Email\n5.Department\n");
    printf("Option=");
    scanf("%d",&q);
    if(q<=5)//takes the change type
    {
        printf("Enter Patient ID= (0 - %d)=",num-1);
        scanf("%d",&p);//takes the patient ıd
        if(p<num)
        {
            if(q==1)//uses the change type
            {
                fflush(stdin);
                printf("Enter the new Name=");
                gets(x[p].Name);
                write();
            }
            else if(q==2)//uses the change type
            {
                fflush(stdin);
                printf("Enter the new Surname=");
                gets(x[p].Surname);
                write();
            }
            else if(q==3)//uses the change type
            {
                fflush(stdin);
                printf("Enter the new Birthday=");
                gets(x[p].Birthday);
                write();
            }

            else if(q==4)//uses the change type
            {
                fflush(stdin);
                printf("Enter the new Email=");
                gets(x[p].Email);
                write();
            }

            else if(q==5)//uses the change type
            {
                fflush(stdin);
                printf("Enter the new Department =");
                gets(x[p].Department);
                write();
            }
        }
        else
        {
            printf("\n\nInvalid ID \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f;
    char u[40];
    printf("By what do you want to search ?\n");
    printf("1.Patient ID\n2.Name\n3.Surname\n4.Birthday\n5.Email\n6.Department\n\nOption = ");
    scanf("%d",&h);//takes the choice of search
    if(h==1)
    {
        printf("Enter Patient ID=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
        	printf("Patient ID=%d\nName = %s\nSurname = %s\n",s,x[s].Name,x[s].Surname);
        	printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[s].Birthday,x[s].Email,x[s].Department);
        	printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)
    {
        int f=1;
        fflush(stdin);
        printf("Enter your Name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Name)==0)//compares the names
            {
                printf("\n");
        		printf("Patient ID=%d\nName = %s\nSurname = %s\n",g,x[g].Name,x[g].Surname);
        		printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[g].Birthday,x[g].Email,x[g].Department);
        		printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");
    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Surname = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Surname)==0)//compares the surnames
            {
                printf("\n");
        		printf("Patient ID=%d\nName = %s\nSurname = %s\n",g,x[g].Name,x[g].Surname);
        		printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[g].Birthday,x[g].Email,x[g].Department);
        		printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");
    }
    else if(h==4)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Birthday = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Birthday)==0)//compares the birthdays
            {
                printf("\n");
        		printf("Patient ID=%d\nName = %s\nSurname = %s\n",g,x[g].Name,x[g].Surname);
        		printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[g].Birthday,x[g].Email,x[g].Department);
        		printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Email = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Email)==0)//compares the emails
            {
                printf("\n");
        		printf("Patient ID=%d\nName = %s\nSurname = %s\n",g,x[g].Name,x[g].Surname);
        		printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[g].Birthday,x[g].Email,x[g].Department);
        		printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("Not Found\n\n");
    }
    else if(h==6)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Department = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Department)==0)//compares the department
            {
                printf("\n");
        		printf("Patient ID=%d\nName = %s\nSurname = %s\n",g,x[g].Name,x[g].Surname);
        		printf("Birthday = %s\nEmail = %s\nDepartmant=%s",x[g].Birthday,x[g].Email,x[g].Department);
        		printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");




}
void del()
{
    int f;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
    if(f<num)//deletes the selected patient
    {
    	strcpy(x[f].Name,"Cleared");
		strcpy(x[f].Surname,"Cleared");
		strcpy(x[f].Birthday,"Cleared");
		strcpy(x[f].Email,"Cleared");
		strcpy(x[f].Department,"Cleared");
		write();
    }
    else
        printf("\n\nInvalid Serial number\n");

}
void read()//reads the file
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, program has created it\n\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct Patient),1000000, fp);//reads the patient struct from the file
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct Patient),num, fp);//writes the patient struct to the file

    fclose(fp);
}
