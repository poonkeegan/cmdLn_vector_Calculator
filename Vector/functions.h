#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

char getFirstChar(){
	string input;
	cin >> input;
	return(tolower(input.at(0)));
}

double getNum(){
	double input;
	cin >> input;
	return input;
}

vector <double> getSecondVector(int length){
	vector <double> vec(length, 0);
	for(int i = 0; i < length; i++){
		cout<< "What is the value of the second vector at position " 
				<< i+1 <<"?"<< endl;
		vec.at(i) =  getNum();
	}
	return vec;
}

double magnitude(vector <double> vec){
	double mag = 0;
	for(int i = 0; i < vec.size(); i++){
		mag += vec.at(i)*vec.at(i);
	}
	mag = sqrt(mag);
	return mag;
}

double dotProduct(vector <double> vec, vector <double> vecB){
	double dotProd = 0;
	for(int i = 0; i < vec.size(); i++){
		dotProd += vec.at(i) * vecB.at(i);
	}
	return dotProd;
}

string vecStr(vector <double> vec){
	stringstream vectorString;
	vectorString << "[";
	for(int i = 0; i < vec.size(); i++){
		vectorString << vec.at(i);
		if(i < vec.size()-1)
			vectorString << ", ";
		else
			vectorString << "]";
	}
	return vectorString.str();
}

vector <double> addVec(vector <double> vecA, vector <double> vecB){
	for(int i = 0; i < vecA.size(); i++){
		vecA.at(i) += vecB.at(i);
	}
	return vecA;
}

vector <double> subVec(vector <double> vecA, vector <double> vecB){
	for(int i = 0; i < vecA.size(); i++){
		vecA.at(i) -= vecB.at(i);
	}
	return vecA;
}

#endif