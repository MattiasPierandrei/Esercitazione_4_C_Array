//Esercitazione_4_Array    PIERANDREI MATTIAS	

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Utils.hpp" //Library

using namespace std;

int main()
{
	std::string inputFile = "data.txt" ;
	std::string outputFile = "result.txt" ;
	size_t n;
	double S;
	double V;
	double *ptr1 = nullptr;
	double *ptr2 = nullptr;
	
	//Reading File data.txt
	if(!ImportVectors(inputFile , n , S , ptr1 , ptr2))
		return 1;
	
	//Computing RoR
	double R = RateOfReturn( n , ptr1 , ptr2 );
	
	//Computing the final value of our portfolio usinfìg the RoR
	V = (R+1)*S ;
	
	//Writing results in result.txt
	if(!ExportResult(outputFile , n , S, ptr1 , ptr2 , V , R))
		return 1;
	
	//deallocating memory
	delete[] ptr1;
	delete[] ptr2;
	
    return 0;
}

