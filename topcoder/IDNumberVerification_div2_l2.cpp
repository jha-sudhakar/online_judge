#include <stdlib.h>
#include <iostream>
using namespace std;


class IDNumberVerification
{


public:
	string verify(string id, string regionCodes[]);

};

string IDNumberVerification::verify(string id, string regionCodes[])
{
	//	   012345-6789-10111213-  	
	//id = RRRRRR-YYYY M M D D - zzz-x

	int length_of_code = sizeof(regionCodes) / sizeof(regionCodes[0]);
	cout<<"\n Id= " << id;
	cout<<"\n Count= " << length_of_code <<", Region-code= ";
	for(int kk=0; kk < length_of_code; kk++)
		cout<<" " << regionCodes[kk];
	cout<<endl;

	bool region_code_match = false;
	// 1. Validate region code.
	for(int i=0; i<length_of_code; i++)
	{
		if(0 == id.compare(0,6, regionCodes[i]))
		{
			region_code_match = true;
			cout<<"\n Matches with region code= " << regionCodes[i];
			break;
		}
	}
	if(region_code_match == false)
	{
		cout<<"\n Reason code did not match";
		return "Invalid";
	}

	//2. Validate DOB
	string dob = id.substr(6,8);
	unsigned int num = atoi(dob.c_str());
	cout<<"\n DOB= " << dob <<", dob-num= " << num;

	int year = num/10000;
	if(year<1900 || year > 2011)
	{
		cout<<"\n year is invalid";
		return "Invalid";
	}

	for(int i=10; i<14; i++)
	{
		if(id[i] <'0' || id[i] > '9')
		{
			cout<<"\n Month-date is invalid, index[" <<i <<"]= " << id[i];
			return "Invalid";
		}
	}	

	int month =  (num %10000) / 100;
	if(month <1 || month > 12)
	{
		cout<<"\n Month is invalid, val= " << month;
		return "Invalid";
	}

	int day = num%100;
	if(day<1 || day > 31)
	{
		cout<<"\n Day is invalid, val= " << day;
		return "Invalid";
	}

	// Validate for leap year.
	if(month == 2)
	{
		if((year%400 == 0) || (year%4 == 0 && year%100 != 0))
		{
			if(day > 29)
			{
				cout<<"\n day " << day <<"  is not matching for feb leap year " << year;
				return "Invalid";
			}
		} 
		else
		{
            if(day > 28)
            {
                cout<<"\n day " << day <<"  is not matching for feb year " << year;
                return "Invalid";
            }
		}
	}

	// Validate for 30, 31 and 28 days.
	if((day == 31) && !(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
	{	
		cout<<"\n Validated months for 31 days";
		return "Invalid";
	}


	 string code = id.substr(14,3);
	 int code_num = atoi(code.c_str());
	 if(code_num == 0)
	 {
		cout<<"\n code is invalid";
		return "Invalid";
	 }

	int multiplyer = 16;
	unsigned long val=0;
	for(int i=0; i<17; i++)
	{

		unsigned int tmp2 = 2 << multiplyer;;
		int id_val_num = id[i] - 48;
//		cout<<"\n Multiplyer = " << tmp2 << ", id[" <<i+1 <<"]= " << (id_val_num);

		unsigned long tmp3 = (tmp2*(id_val_num));		
		val += tmp3;
		multiplyer--;
        cout<<"\n Multiplyer = " << tmp2 << ", id[" <<i+1 <<"]= " << (id_val_num) <<", val= " << val;;

	}

	int x=0;
	val = val%11;
	cout<<"\n Reminder= " << val;
	if(val == 1) 
		x = 0;
	else if (val == 0)
		x = 1;
	else
		x = 12-val;

	if((id[17] == 'X' && x !=10) || (id[17] != 'X' && x != id[17]-48))
	{
		cout<<"\n checksum is not matching, checksum= " << x <<", id[17]= " << ((id[17] == 'X')?'X': id[17]-48);
		return "Invalid";
	}

	if(code_num % 2)
	{
		return "Male";
	} else
	{
		return "Female";
	}
}

int main()
{
IDNumberVerification obj1;

//string id1 = "441323200312060636"; string r1[] = {"441323"}; cout<<"\n" << obj1.verify(id1, r1);
//string id2 = "62012319240507058X"; string r2[] = {"620123"}; cout<<"\n" << obj1.verify(id2, r2);
//string id3 = "230231198306900162"; string r3[] = {"230231"}; cout<<"\n" << obj1.verify(id3, r3);
//string id4 = "341400198407260005"; string r4[] = {"341400"}; cout<<"\n" << obj1.verify(id4, r4);
string id5 = "520381193206090891"; string r5[] = {"532922","520381"}; cout<<"\n" << obj1.verify(id5, r5);

cout<<endl;
return 0;
}
