#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void determine_size(const string, int&);
double* reading(const string, int);
void filter(double*, int);
void savetofile(double*, int, const string);

int main(){
    const string filename_input = "noisy.txt";
    const string filename_output = "filtered.txt";
    const int Nfilter = 1;	//determines how often the filter is applied
    int Nlines = 0;
    double* p;
 
  
    determine_size(filename_input,Nlines); 	//function which determines the number of lines of the file filename_input

    p = reading(filename_input,Nlines);		//function which reads the data into a dynamic array and returns the pointer
    
    for(int i=1;i<=Nfilter;i++){
    filter(p,Nlines);	 //filter function
    }
    
    savetofile(p,Nlines,filename_output);	//save function
    
    delete[] p;
    return 0;
}

void determine_size(const string fname, int& Nlines){
    string templine;
    
    ifstream in(fname.c_str());
    while (getline(in,templine))
	Nlines++;
    in.close();
}

double* reading(const string fname, int N){
    double* pn = new double[N];
    
    ifstream in(fname.c_str());
    for(int i=0; i<N; i++)
	in >> pn[i];
    in.close();
    
    return pn;
}

void filter(double* p, int N){
    double temp1,temp2,tempN;
    
    tempN = p[0];
    temp1 = p[0];
    p[0] = (p[N-1]+p[0]+p[0+1])/3.0;
	    
    for(int i=1; i<N-1; i++){
	  temp2 = p[i];
	  p[i] = (temp1+p[i]+p[i+1])/3.0;
	  temp1 = temp2;
    }
    
    p[N-1] = (temp1+p[N-1]+tempN)/3.0;
}

void savetofile(double* p, int N, const string fname){
    ofstream out(fname.c_str());
    for(int i=0; i<N; i++)
	out << p[i] << endl;
    out.close();
}