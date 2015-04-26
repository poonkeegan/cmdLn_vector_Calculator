#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <math.h>
#include "functions.h"
#include "line.h"

using namespace std;

int main()
{
	char loop = 'y';
	while(loop == 'y'){
		int vecLen;
		DIMENSIONS:
		cout << "How many dimensions is the vector?" << endl;
		cin >> vecLen;
		if(vecLen > 3 || vecLen < 1){
			cout << "Too many/few dimensions, only between 1-3 dimensions" << endl;
			goto DIMENSIONS;
		}
		vector <double> vectorA (vecLen,0);
		for(int i = 0; i < vectorA.size(); i++){
			cout<< "What is the value of the vector at position " << i+1 <<"?"<< endl;
			vectorA.at(i) = getNum();
		}
		COMMAND:
		cout<< "Your vector is: " << vecStr(vectorA)<< endl;		
		cout<< endl;
		cout<< "What would you like to do with it? (type "
		<<"the character with no dash)" <<endl
		<<"Calculate Magnitude -m"		<<endl
		<<"Add a vector -a"				<<endl
		<<"Subtract a vector -s"		<<endl
		<<"Calculate Dot product -d"	<<endl
		<<"Calculate Angle -n"			<<endl
		<<"Create a Line -l"			<<endl;
		if(vectorA.size() == 3){
			cout<<"Calculate Cross product -c" << endl;
		}
		cout<<"Exit Program -x"				<<endl;
		char input = getFirstChar();
		
		switch (input)
		{
			case 'm':{
				cout << "The magnitude of the vector is : "<< magnitude(vectorA) <<endl;
			break;
			}
				
			case 'a':{
				cout << "The added Vector is "<< endl;
				vector <double> vectorB = getSecondVector(vectorA.size());
				vectorA = addVec(vectorA, vectorB);
				cout<< vecStr(vectorA) <<endl;
			break;
			}
				
			case 's':{
				cout << "The subtracted Vector is "<< endl;
				vector <double> vectorB = getSecondVector(vectorA.size());
				vectorA = subVec(vectorA, vectorB);
				cout<< vecStr(vectorA) <<endl;
				break;
			}
			case 'd':{
				vector <double> vectorB = getSecondVector(vectorA.size());
				cout<< "The Dot Product is: " << dotProduct(vectorA, vectorB) <<endl;
				break;
			}
			case 'n':{
				vector <double> vectorB = getSecondVector(vectorA.size());
				double radians = acos(dotProduct(vectorA, vectorB)/
								(magnitude(vectorA) * magnitude(vectorB)));
				cout << "The angle is : " << radians*(180/(4*atan(1)))<< " degrees." << endl;
				//4*atan(1) = pi
				break;
			}
			case 'x':
				return(0);
				break;
			case 'l':{
				if(vectorA.size() < 2)
					goto INVALID;
				WHAT_VECTOR:
				cout << "What is your vector " 	<<endl
						<<"A position -p"				<<endl
						<<"A direction vector -d"		<<endl;
				char inputVec = getFirstChar();
				switch(inputVec)
				{
					case 'p':{
						WHAT_NEXT_VECTOR:
						cout << "What is your next vector " 	<<endl
							<<"A position -p"				<<endl
							<<"A direction vector -d"		<<endl;
						char inputVec2 = getFirstChar();
						switch(inputVec2)
						{
							case 'p':{
								vector <double> vectorB = getSecondVector(vectorA.size());
								Line lineA(vectorB, subVec(vectorB, vectorA));
								lineA.printLine();
								break;
							}
							case 'd':{
								vector <double> vectorB = getSecondVector(vectorA.size());
								Line lineA(vectorA, vectorB);
								lineA.printLine();
								break;
							}
							default:{
								cout << "\nInvalid command" << endl;
								goto WHAT_NEXT_VECTOR;
							}
						}
						break;
					}
					case 'd':{
						cout<< "Please input a position Vector" <<endl;
						vector <double> vectorB = getSecondVector(vectorA.size());
						Line lineA(vectorB, vectorA);
						lineA.printLine();
						break;
					}
					default:{
						cout << "\nInvalid command" << endl;
						goto WHAT_VECTOR;
					}
				}
				break;
			}
			case 'c':{
				if(vectorA.size() < 3)
					goto INVALID;
					vector <double> vectorB = getSecondVector(vectorA.size());
					vector <double> vectorC (vectorA.size(), 0);
					vectorC.at(0) = vectorA.at(1) * vectorB.at(2) - vectorA.at(2) * vectorB.at(1);
					vectorC.at(1) = vectorA.at(2) * vectorB.at(0) - vectorA.at(0) * vectorB.at(2);
					vectorC.at(2) = vectorA.at(0) * vectorB.at(1) - vectorA.at(1) * vectorB.at(0);
					cout<< "The cross product is " << vecStr(vectorC)<< endl;		
					break;
			}
			default:{
				INVALID:
				cout << "\nInvalid command" << endl;
				goto COMMAND;
			}
		}
		CONTINUE:
		cout << "Would you like to continue? y/n" <<endl;
		loop = getFirstChar();
		if(loop != 'n' && loop != 'y'){
			cout << "\nInvalid command" << endl;
			goto CONTINUE;
		}
	}
	return(0);
}

