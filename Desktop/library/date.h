#ifndef DATE_H
#define DATE_H

class date
{
	int day;
	int month;
	int year;
    public:
    date()
    {
    day=month=year=0;
    }
    date(int d,int m,int y)
    {
    	day=d;month=m;year=y;
    }
    void showdate()
    {
    	cout<<day<<"/"<<month<<"/"<<year;
    }
    int subdate(date d)
    {
    	int i,dfactor[13],monthdiff=0,daydiff=0;
    	int yeardiff=year-d.year;
    	dfactor[0]=0;
    	for(i=1;i<13;i++)
    	{
    		if(i%2==1)
    			dfactor[i]=31;
    		else if(i==2)
    			dfactor[i]=28;
    		else
    			dfactor[i]=30;
    	}
    	if(month>d.month)
    		for(i=d.month+1;i<month;i++)
    			monthdiff+=dfactor[i];
    	else
    	    {
    	     for(i=1;i<d.month;i++)
    	     	monthdiff+=dfactor[i];
    	     for(i=month;i<=12;i++)
    	     	monthdiff+=dfactor[i];
    	    }	
        if(day>d.day)
        	daydiff+=day-d.day;
        else
        	daydiff+=d.day+dfactor[month]-day;
    
       return yeardiff+monthdiff+daydiff;
    }
};