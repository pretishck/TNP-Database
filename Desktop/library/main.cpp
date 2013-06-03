#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<ctime>
#include "book.h"
#include "getfromdatabase.h"

//GLOBAL VARIABLES
int i,j,k;
string temp,id;

char ch1;

void get_date( int * month, int * day, int * year ) {
struct tm *current;
time_t timenow;
time(&timenow);
   current = localtime(&timenow);
     *month = current->tm_mon+1;
     *day = current->tm_mday;
     *year = current->tm_year+1900;
return;
}

member* find_member_from_database(string id)
{
	ifstream infile;
	infile.open("memberdata.txt");
	member tmp;
	if(!infile)
	{   cout<<"MEMBER DATABASE NOT FOUND";
		infile.close();
		return new member();
	}
	while( infile.read((char *)&temp, sizeof(temp)))
	{
		if(temp.getid()==id)
		{
			infile.close();
			return &temp;
		}
	}
   infile.close();
   cout<<"MEMBER NOT FOUND";
   return new member();
}

book* find_book_from_database(string id)
{
	ifstream infile;
	infile.open("bookdata.txt");
    	book tmp;
	if(!infile)
	{   cout<<"BOOK DATABASE NOT FOUND";
		infile.close();
		return new book();
	}
	while( infile.read((char *)&temp, sizeof(temp)))
	{
		if(temp.getbookid()==id)
		{
			infile.close();
			return &temp;
		}
	}
   infile.close();
   cout<<"BOOK NOT FOUND";
   return new book();

}


int main()
{
	do
	member tmp;
	while( infile.read ( (char *)&employee, sizeof(employee) ) ){
	int ch;
	cout<<"**********************************************************************"<<"\n";
	cout<<"                       LIBRARY MANAGEMENT                             "<<"\n";
	cout<<"**********************************************************************"<<"\n";
	cout<<"\n\n";
	cout<<"					1.ISSUE"<<"\n";
	cout<<"                 2.RETURN"<<"\n";
	cout<<"                 3.VIEW DATABASE"<<"\n";
	cout<<"                 4.MODIFY DATABASE"<<"\n";
	cout<<"                 5.EXIT"<<"\n";
    cout<<"\nENTER YOUR CHOICE"<<"\n";
    cin>>ch;
    system("CLS");

                                int month,day,year;
                                get_date(month,day,year);
    switch(ch)
    {
    	case 1:
    	        cout<<"ENTER STUDENT ID"<<"\n";
    	        cin>>id;
    	        member* stud=find_member_from_database(id);
    	        if(stud->getid()!="")
    	        	{   stud->calculatedues();
    	        		if(stud->getnob()==7)
    	        			cout<<"ISSUED 7 BOOKS ALREADY.RETURN BEFORE ISSUING AGAIN"<<"\n";
    	        		else if(stud->getdues!=0)
    	        		{
    	        			cout<<"CLEAR DUES BEFORE ISSUING AGAIN"<<"\n";
    	        			stud->showbookwithdues();
    	        		}
    	        		else
    	        		{
    	        			int n;
    	        			cout<<"ENTER NUMBER OF BOOKS TO ISSUE"<<"\n";
    	        			cin>>n;
    	        			if(n+stud->getnob()>7)
    	        				cout<<"SORRY!YOU CAN ISSUE MAXIMUM OF 7 BOOKS ONLY!"<<"\n";
    	        			else
    	        			{   string iss[n];
    	        				cout<<"ENTER ID'S OF BOOKS YOU WOULD LIKE TO ISSUE"<<"\n";
                                for(int i=0;i<n;i++)
                                	cin>>iss[i];
                                date issuetime(day,month,year);
                                stud->issue(iss,n,issuetime);
                                stud->writetomemberdatabase();
                                cout<<"YOUR ACCOUNT HAS BEEN UPDATED.THANK YOU"<<"\n";
    	        			}
    	        		}

    	        	}
    }
	return 0;
}