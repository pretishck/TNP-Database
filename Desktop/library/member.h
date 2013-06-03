#ifndef MEMBER_H
#define MEMBER_H


class member
{
	string id;
	int nob;
	book* issued[7];
	date issuedate[7];
	float dues_per_book[7];
    public:
    member()
    {
    	id="";
    	nob=0;
    	for(int i=0;i<7;i++)
    		{issued[i]=NULL;
    		 dues_per_book[i]=0;
    		 issuedate[i]=new date();
    		}
    }

    member(string i,int n)
    {
    	id=i;
    	nob=n;
    }

    string getid()
    {
    	return id;
    }
    int getnob()
    {
    	return nob;
    }
    float getdues()
    {
    	float sum=0;
    	for(int i=0;i<7;i++)
    		sum+=dues_per_book[i];
    	return sum;
    }   
    void showbookwithdues()
    {
    	for(int i=0;i<7;i++)
    		if(dues_per_book[i]>0)
    			cout<<issued[i]->getbookid()<<"\n";  
    			
    }
    void calculatedues(date today)
    {
       for(i=0;i<7;i++)
       {
       	if(today.subdate(issuedate[i])>30)
         dues_per_book[i]=0.5*(today.subdate(issuedate[i]));  		
       }
    }
    void issue(string iss[],int n,date today)
    {
    	for(int i=nob;i<n+nob;i++)
    	{
    		issued[i]=find_book_from_database(iss[i]);
    		issued[i]->issue_this_book(this,today);
    		issued[i]->writetobookdatabase();
            issuedate[i]=today;
            dues_per_book[i]=0;		
    	}
    	nob+=n;
    }
    void writetomemberdatabase()
    {
    	ifstream newfile("member.txt");
        ofstream outfile("new.txt");
    	if(!newfile)
    		cout<<"FIRST ENTRY TO THE FILE"<<"\n";
    	member temp;
    	while(newfile.read((char *)&temp, sizeof(temp)))
          {if(temp.getid()==id)
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
