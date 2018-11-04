#include <boost/lambda/lambda.hpp>

//header for foreach function
#include <boost/foreach.hpp>

//headers for the random funtions 
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

//header used for trim, and split functions
#include <boost/algorithm/string.hpp>

//header for format function
#include <boost/format.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace boost;
using namespace boost::lambda;
using namespace std;

// the mt19937 produces an integer in a huge range used a seed then the uniform_in_ditribution<> takes it and makes a number between 1 and 6 in this case
boost::random::mt19937 gen;
int roll_die() {
	boost::random::uniform_int_distribution<> dist(1, 6);
	return dist(gen);
}


int main()
{
	cout << "ForEach function" << endl;
	//the for each function for something for each of something, so in my example it is displaying the character to each character in the string
	string str("abcdefghijklmnopqrstuvwxyz");
	BOOST_FOREACH(char ch, str)
	{
		cout << ch << endl;
	}

	system("pause");

	cout << "Random Funtion" << endl;
	int RandNum = roll_die();
	cout << RandNum<< endl;

	system("pause");

	cout << "Trim Function" << endl;
	//the trim functions deletes the white space from either side of the string ,
	//you can also usetrim_left_copy to just trim the left etc
	string Trim = "                               hello                      ";
	cout << Trim << endl;
	trim(Trim);
	cout << Trim << endl;

	system("pause");

	cout << "Split Function" << endl;
	//the split functions takes a string and then spits it into multiple strings at the character you choose int the is_any_of()
	//and then stores all the string in a vector
	string SplitString = "Aaaaa-Bbbbb/Ccccc";
	cout << SplitString << endl;
	typedef vector<string> SplitVector;
	SplitVector SVector;
	split(SVector, SplitString, is_any_of("-/"));
	
	cout << SVector[0] << endl;
	cout << SVector[1] << endl;
	cout << SVector[2] << endl;
	
	system("pause");

	cout << "Format Function" << endl;
	//format lets you set a format for the information to be put in, you seperate them with %
	//and the info you give it will be put in between the percetsigns so this will att the . inbetween each number
	cout << boost::format{ "%1%.%2%.%3%" } % 8 % 31 % 1997 << '\n';

	system("pause");
}




