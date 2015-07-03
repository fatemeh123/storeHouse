//============================================================================
// Name        : file2.cpp
// Author      : FatemehAbdi
// Version     :
// Copyright   : Dast Nazan Bache Boro Oonvar :)
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class file1{
	ifstream myfile ;
	string name;
	string cate;
public:
	void input();
	void output1();            //number of each object
	void output2();            // number of all objects
	void output3(string k);    // a function for searching in a file by name
	void output4(string y);    //find out the number of line which user search

};
void file1:: input()
{
	myfile.open ("Object-List.txt");
	if(! myfile)
	{
		cerr<<"File cannot be opened"<<endl;

	}

}
//*********************************************************************
//number of each object

void file1 ::output1()
{
	int  drinkCntr=0,foodCntr=0,snackCntr=0,fruitCntr=0,cleaningCntr=0;


	while (myfile)
	{
		string strInput;
		getline (myfile,strInput);
		istringstream iss(strInput);
		string word;
		iss>>word;

		iss>>word;
        if (word=="drink" )
        	drinkCntr ++;
        if (word=="food" )
        	foodCntr ++;
        if (word=="snack" )
        	snackCntr ++;
        if (word=="fruit" )
        	fruitCntr ++;
        if (word=="cleaning" )
        	cleaningCntr ++ ;

	}
	cout<<endl<<"drink"<<drinkCntr<<endl;
	 cout<<"food"<<foodCntr<<endl;
	 cout<<"cleaning"<<cleaningCntr<<endl;
	 cout<<"snack"<<snackCntr<<endl;
	 cout<<"fruit"<<fruitCntr<<endl;

}
//*********************************************************************
// number of all objects
void file1::output2(){
	int number_line;
	string line;
	while (getline (myfile,line))
		 {
		 number_line ++;
		 }
	 cout<<"number of all objects"<<number_line;

}
// a function for searching in a file by name
//*********************************************************************

void file1:: output3(string k)    // k is a name which user searchs
{

	string strInput;
	while (myfile)
	{
		getline (myfile,strInput);
		istringstream iss(strInput);
		string word=k;
		string g;
		iss>>g;
		 if( !g.compare(word) )
			 cout<<strInput;
		iss>>g;
		 if( !g.compare(word) )
			 cout<<strInput;


	}

}
/**
 * find out the number of line which user search
 * *********************************************************************
 */
void file1:: output4(string y)
{
	string strInput;
	int number_line=0;
	while (myfile)
	{
		number_line ++ ;
		getline (myfile,strInput);
		istringstream iss(strInput);
		string word=y;
		string g;
		iss>>g;
		 if( !g.compare(word) )
			 cout<<number_line<<endl<<"******"<<endl;
		iss>>g;
		 if( !g.compare(word) )
			 cout<<number_line<<endl<<"******"<<endl;
	}

}



int main() {
	file1 f;
	string p,k;
	f.input();
//	f.output2();
	f.output1();
//	cout<<"write a word for searching in a file ";
//	cin>>p;
//	f.output3(p);
//
//	cout<<"enter name of object which you want that ID";
//	cin>>k;
//	f.output4(k);
	return 0;
}
