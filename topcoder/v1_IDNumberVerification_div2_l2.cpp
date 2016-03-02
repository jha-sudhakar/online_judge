#include <iostream>
using namespace std;


class IDNumberVerification
{


public:
	string verify(string id, string[] regionCodes);

};

string IDNumberVerification::verify(string id, string[] regionCodes)
{
		   012345-6789-10111213-  	
	//id = RRRRRR-YYYY M M D D - zzz-x

	int length_of_code = sizeof(regionCodes/regionCodes[0]);
	// 1. Validate region code.
	for(int i=0; i<length_of_code; i++)
	{
		bool region_code_match = false;
		if(0 == id.compare(0,6, regionCodes[i])
		{
			region_code_match = true;
			cout<<"\n Matches with region code= " << regionCodes[i];
			break;
		}
	}
	if(region_code_match == false)
	{
		return "Invalid";
	}

	//2. Validate DOB
	string dob = id.substr(6,8);
	unsigned int num = stoi(dob);
	cout<<"\n DOB= " << dob <<", dob-num= " << num;

	int year = num/10000;
	if(year<1900 || year > 2011)
	{
		cout<<"\n year is invalid";
		return "Invalid";
	}

	if(!(dob[4] == '0' && (dob[5]>= '1' && dob[5] <='9')))
	{
		cout<<"\n Month is invalid";
		return "Invalid";
	} else if (!(dob[4] == '1'&& (dob[5] >= '1' && dob[5] <= '2')))
		cout<<"\n Month_B is invalid";
		return "Invalid";
	}

    if(!(dob[6] == '0' && (dob[7]>= '1' && dob[7] <='9')))
    {
        cout<<"\n Day is invalid";
        return "Invalid";
    } else if (!((dob[6] == '1' || dob[6] == '2')&& (dob[7] >= '0' && dob[7] <= '9')))
        cout<<"\n Day_B is invalid";
        return "Invalid";
    } else if (!(dob[6] == '3' && (dob[7]>= '0' && dob[7] <='1')))
	{
        cout<<"\n Day_C is invalid";
        return "Invalid";
	}

	

}
int main()
{


return 0;
}
