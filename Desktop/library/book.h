#ifndef BOOK_H
#define BOOK_H

#include "member.h"
#include "date.h"

class book
{
	string bookid;
	string title;
	string author;
	string shelf;
	member* owner;
    date issuedate;
    bool dues_on_it;

  public:
    book()
    {
    	bookid=title=author=shelf="";
    	owner=NULL;
    	dues_on_it=false;
    	issuedate=new date();
    }
    book(string id,string tit,string auth)
    {
    	bookid=id;
    	title=tit;
    	author=auth;
    }
    string getbookid()
    {
    	return bookid;
    }
    member* getowner()
    {
    	return owner;
    }
    bool has_dues_on_it()
    {
    	return dues_on_it;
    }
    void bookdetails()
    {
    	cout<<"TITLE:"<<title<<"\n";
    	cout<<"AUTHOR:"<<author<<"\n";
    	cout<<"BOOKID:"<<bookid<<"\n";
    	if(owner==NULL)
    		cout<<"SHELF:"<<shelf<<"\n";
    	else
    		{ cout<<"OWNER_BY"<<"\n";
              (*owner)->getmemberid();
            }
    }
    void assignshelf()
    {   string s;
    	cout<<"ENTER SHELF FOR THIS BOOK"<<"\n";
        cin>>s;
        shelf=s;
    }
    void issue_this_book(member* mem,date d)
    {
       owner=mem;
       issuedate=d;
       shelf="";
    }
    void return_this_book(member* mem)
    {
    	owner=NULL;
    	dues_on_it=false;
    	issuedate=new date();
    	this.assignshelf();
    }
   void writetobookdatabase()
   {
       ifstream newfile("book.txt");
        ofstream outfile("new.txt");
        if(!newfile)
            cout<<"FIRST ENTRY TO THE FILE"<<"\n";
        book temp;
        while(newfile.read((char *)&temp, sizeof(temp)))
          {if(temp.getbookid()==id)
            outfile.write((char*)this,sizeof(*this));
            else
                outfile.write((char*)&temp,sizeof(temp)); 
           }
         remove("member.txt");
         rename("new.txt","member.txt");    
         newfile.close();
         outfile.close();
   }
};