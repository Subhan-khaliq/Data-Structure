#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *head;
	int size,len,*current,*temp;
public:

    //Constructor for initializing List
	list()
	{
		size=5;
		len=0;
		current=NULL;
		temp=NULL;
		head=new int[size];
		current=head;
		for(int i=0;i<size;i++)
		{
			*current=0;
			current++;
		}
		current=NULL;
		current=head;
	}

    //Deep Copy Constructor
	list(list& otherList)
{
	size = otherList.size;
	len =otherList.len;
	head=otherList.head;//create the array
	current=head;
}
    //Clear Or Empty the List
	void clear()
	{
		current=head;
		for(int i=0;i<size;i++)
		{
			*current=0;
			current++;
		}
		temp=NULL;
		current=NULL;
		
	
	}


    //Insert a Value at Specific Position
	void insert(int value,int pos)
	{
		if(len==5)
		{
			cout<<"Array is filled.";
			return;
		}
		current=head;
		temp=head;
		temp=temp+len;
		current=current+pos;
		while(temp!=current)
		{
			*temp=*(temp-1);
			temp--;
		}
		*current=value;
		

	}

    //Insert the given value in the list at the next available position
    void insert(int value)
	{
		if(len==5)
		{
			cout<<"Array is filled . ";
			return;
		}
		if(len==0)
		{
			*head=value;
			current=head;
			len++;
			return;
		}
		else
		{
			current=head;
			current=current+len;
			*current=value;
			len++;
		}
	}


    //Remove a value at specific position
	void remove(int value)
	{
		current=head;
		temp=current;
		temp=temp+len;
		for(int i=0;i<len;i++)
		{
			if(*current==value)
			{
				while(current!=temp)
				{
				*current=*(current+1);
				current++;
			}
			}
			current++;
		}

	}



    //Get value stored at a specific position
	int get(int pos)
	{
		temp=head;
		temp=temp+pos;
		//temp--;
		cout<<*temp;
	}

    //Update Existing value at a position
	void update(int value,int pos)
	{
	

	}


    //Find a value in the list
	bool find(int value)
	{
	

	}


    //Return Current Length of the list
	void length()
	{
		int count=0;
		current=head;
		temp=head;
		temp=temp+len;
		while(current!=temp)
		{
			count++;
			current++;
		}
		cout<<count;
	}


    //Move to starting position of the list
	void start()
	{
		current=head;
	}

    //Move to the end of the list
	void end()
	{
		current=head;
		current=current+len;
		current--;
		cout<<*current;
	}
	void show()
	{
		temp=head;
		for(int i=0;i<size;i++)
		{
			cout<<*temp<<" ";
			temp++;
		}
	}
};

int main()
{
	list t1;
	t1.insert(2);
	t1.insert(3);
	t1.insert(4);
	t1.insert(5);
	t1.show();
	cout<<endl;
	list t2(t1);
	t2.show();
	t2.insert(6,1);
	cout<<endl;
	t2.show();
	return 0;
}    
