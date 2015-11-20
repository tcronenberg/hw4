#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void determine_size(const string, int&);

void reading(const string, double*, int);

void filter(double*, int);

void savetofile(double*, int);

int main(){
    string filename = "noisy.txt";
    int Nlines = 0;
  
    determine_size(filename,Nlines);
    double* p = new double[Nlines];
    cout << Nlines << endl;
    
    reading(filename,p,Nlines);
    
    for(int i=1;i<=1;i++){
    filter(p,Nlines);
    }
    
    savetofile(p,Nlines);
    
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

void reading(const string fname, double* p, int N){
    
    ifstream in(fname.c_str());
    for(int i=0; i<N; i++)
	in >> p[i];
    in.close();
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
	  cout << i << endl;
    }
    p[N-1] = (temp1+p[N-1]+tempN)/3.0;
  
}

void savetofile(double* p, int N){
    ofstream out("filtered.txt");
    for(int i=0; i<N; i++)
	out << p[i] << endl;
    out.close();
}