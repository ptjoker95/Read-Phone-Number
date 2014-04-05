#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// 중복된 경우 앞에 붙여질 접두사 리턴
string NameofCumul( int i )
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

//숫자 이름을 리턴
string NameofNumber( int i )
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
			return "";
	}
}

string CallbyName( string str )
{
	int len, Cumul, indicator, now;
	string Call, temp;

	len = str.length();
	Cumul = 0;
	indicator = int(str[0]) - 48;
	Call = "";

	if( len == 1 )
	{
		//cout << "indicator: " << indicator << endl;
		Call.append( " " );
		Call.append( NameofNumber( indicator ) );
		return Call;
	}

	for( int i=1; i<len+1; i++ )
	{
		if( i<len )
			now = int(str[i]) - 48;
		else
			now = -1;

		if( indicator == now )
		{
			Cumul++;	
		}
		else
		{
			if( Cumul < 1 )
			{
				Call.append( " " );
				Call.append( NameofNumber( indicator ));
				Cumul = 0;
			}
			else
			{
				if( Cumul < 10 )
				{
					Call.append( " " );
					Call.append( NameofCumul( Cumul+1 ) );
					Call.append( " " );
					Call.append( NameofNumber( indicator ));
					Cumul = 0;
				}
				else
				{
					for( int j=0; j<Cumul+1; j++ )
					{
						Call.append( " " );
						Call.append( NameofNumber( indicator ));
					}
				}
			}
		}

		indicator = now;
	}
	
	return Call;
}

class PhoneNumbers
{
	private:
		string PhoneNumber, CallType, PhoneNumberbyNumName;
		int Length;
		vector<string> PhoneNumberbyDigit;
		vector<int> EachDigit;
	public:
		string CallPhoneNumber()
		{
			if( PhoneNumberbyNumName.length() > 0 )
				return PhoneNumberbyNumName;
			else
				return "";
		}
		void callphonenumberbyname()
		{
			int Digitnum;

			PhoneNumberbyNumName = "";

			Digitnum = PhoneNumberbyDigit.size();

			for( int i=0; i<Digitnum; i++ )
			{
				PhoneNumberbyNumName.append( PhoneNumberbyDigit[i] );
			}
		}

		void input( string phonenum, string calltype )
		{
			PhoneNumber = phonenum;
			CallType = calltype;
			Length = phonenum.length();

			SeperateEachDigit();
			SeperateNumberbyDigit();
			callphonenumberbyname();
		}

		void SeperateNumberbyDigit()
		{
			int startpoint, substrlen;
			int DigitCount;
			string NumonDigit;

			startpoint = 0;
			DigitCount = EachDigit.size();

			for( int i=0; i<DigitCount; i++ )
			{
				substrlen = EachDigit[i];
				NumonDigit = PhoneNumber.substr( startpoint, substrlen );
				PhoneNumberbyDigit.push_back( CallbyName(NumonDigit) );
				startpoint += substrlen;
			}	
		}

		void SeperateEachDigit()
		{
			if( PhoneNumber.length() < 1 )
				return;
			
			std::string segment;
			std::stringstream thisstring( CallType );	
			int temp;

			while( getline( thisstring, segment, '-' ) )
			{
				istringstream(segment) >> temp;
				EachDigit.push_back(temp);
			}
			return;
		}
};

int main( int argc, char** argv )
{
	// number of cases
	int CaseNum;
	// PhoneNum: phone number, TypeofCall: 부르는 방식
	string PhoneNum, TypeofCall;
	vector<string> DigitsofPhone;
	vector<int> DigitNum;
	PhoneNumbers *phonenum;

	ifstream myfile;
	myfile.open(argv[1]);

	if( myfile.is_open() )
	{
		myfile >> CaseNum;
		//cout << "CaseNum: " << CaseNum << endl;

		phonenum = new PhoneNumbers[ CaseNum ];

		for( int i=0; i<CaseNum; i++ )
		{
			myfile >> PhoneNum >> TypeofCall;
			phonenum[i].input( PhoneNum, TypeofCall );
			cout << "Case #" << i+1 << ":" << phonenum[i].CallPhoneNumber() << endl;
		}

		cout << "Test 12 ones: " << CallbyName( "111111111111" ) << endl;

		delete[] phonenum;
	}

	//cout << CallbyName( "557771223" ) << endl;

	myfile.close();
	return 0;
}
