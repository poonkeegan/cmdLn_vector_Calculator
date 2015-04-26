#ifndef LINE_H
#define LINE_H

using namespace std;

class Line
{
	private:
	vector <double> posVec;
	vector <double> dirVec;
	int dimensions;
	public:
	Line(vector <double> pV, vector <double> dV);
	void printLine();
};

Line::Line(vector <double> pV, vector <double> dV)
{
	posVec = pV;
	dirVec = dV;
	dimensions = pV.size();
}

void Line::printLine(){
	cout<< "["; 
		for(int i = 0; i < posVec.size(); i++){
			char temp = 120 + i;
			cout << temp;
			if(i != posVec.size() -1)
				cout << ", ";
		}
	cout<< "] = " <<vecStr(posVec) <<" + t"<< vecStr(dirVec) << endl;
	
	for(int i = 0; i < posVec.size(); i++){
		char temp = 120 + i;
		cout << temp << " = " << posVec.at(i) << " + t" << dirVec.at(i) << endl;
	}
	if(dimensions == 2){
		stringstream vectorString;
		vector <double> normalVector(2,0);
		normalVector.at(0) = dirVec.at(1) * -1;
		normalVector.at(1) = dirVec.at(0);
		int c = -1*dotProduct(normalVector, posVec);
		vectorString <<"("<< normalVector.at(0) << "x) + ("
								<<normalVector.at(1)<<"y) + ("<<c<<+") = 0";
		cout << vectorString.str() << endl;
	}
	
}


#endif
