#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

std::string NameofCumul( int i )
{
	switch( i )
	{
		case 2:
			return "double";
		case 3:
			return "triple";
		case 4:
			return "quadruple";
		case 5:
			return "quintuple";
		case 6:
			return "sextuple";
		case 7:
			return "septuple";
		case 8:
			return "octuple";
		case 9:
			return "nonuple";
		case 10:
			return "decuple";
		default:
			return "";
	}
}

std::string NameofNumber( int i )
{
	switch( i )
	{
		case 0:
			return "zero";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		default:
			return "No Number";
	}
}

string CallbyName( string str )
{
	int len, Cumul, indicator, now;
	string Call, temp;

	Call = str;

	return Call;
}

class PhoneNumbers
{
	private:
		string	PhoneNumber, CallType, Call;
		int Length;
		std::vector<string>	CallTypesString;
		std::vector<int> CallTypesInt;
		std::vector<string> PhoneNumberbyDigit;

	public:
		void DividebyDigit()
		{
			int startpoint, substrlen;
			int DigitCount;
			string NumonDigit;
			
			startpoint = 0;
			DigitCount = CallTypesInt.size();

			for( int i=0; i<DigitCount; i++ )
			{
				substrlen = CallTypesInt[i];
				NumonDigit = PhoneNumber.substr( startpoint, substrlen );
				PhoneNumberbyDigit.push_back( NumonDigit );
				startpoint += substrlen;
			}
		}
		
		void Input( string num )
		{
			PhoneNumber = num;
			Length = num.length();
		}
		
		void Input( string num, string calltype )
		{
/*
			PhoneNumber = num;
			CallType = calltype;
			Length = num.length();

			std::string segment;
			std::stringstream thisstring(calltype);
			int temp;

			while( getline( thisstring, segment, '-' )  )
			{
				CallTypesString.push_back(segment);	
				istringstream(segment) >> temp;
				CallTypesInt.push_back(temp);
			}

			DividebyDigit();
*/
		}
		
		string Output()
		{
			return PhoneNumber;
		}
		
		void OutputCalltype()
		{
			for( int i=0; i < CallTypesString.size(); i++ )	
			{
				cout << CallTypesInt[i] << ", ";
			}
		}
};

int main( int argc, char** argv )
{
	int	CaseNum;
	string	PhoneNum, TypeofCall;	
	PhoneNumbers *phonenum;

	ifstream myfile;
	myfile.open(argv[1]);

	if( myfile.is_open() )
	{
		myfile >> CaseNum;
		cout << "CaseNum: " << CaseNum << endl;
		phonenum = new PhoneNumbers[CaseNum];
	
		for( int i=0; i<CaseNum; i++ )
		{
			myfile >> PhoneNum >> TypeofCall;
			phonenum[i].Input( PhoneNum, TypeofCall );
		}
	}
	
	delete phonenum; myfile.close();
	return 0;
}
