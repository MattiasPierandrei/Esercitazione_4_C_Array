//PIERANDREI MATTIAS

#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////

//Import Vectors function
bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r)
{
	ifstream fstr(inputFilePath);
	
	if(fstr.fail()) //check
		return false;
	
	std::string tmp;
	
	//Getting S
	getline(fstr , tmp);
	S=stod( tmp.substr(2) );
	
	//Getting n
	getline(fstr , tmp);
	n=stoi( tmp.substr(2) );
	
	//initializing vectors
	w = new double[n];
	r = new double[n];
	
	getline(fstr , tmp);
	
	//Reading each line and separating w values and r values
	int i=0;
	while (std::getline(fstr, tmp)) {
        std::stringstream ss(tmp);
        std::string W, R;

        std::getline(ss, W, ';');
        std::getline(ss, R);

        w[i] = std::stod(W);
        r[i] = std::stod(R);

        ++i;
    }
	return true;

}


///////////////////////////////////////////////////////////////////////////////////////////////////


//Computing the RoR
double RateOfReturn(const size_t& n,
                   double*& w,
                   double*& r)
{
	double RoR=0;
	for(unsigned int i=0 ; i<n ; i++)
	{
		RoR += w[i]*r[i];
	}
		
	
	return RoR;	
}



///////////////////////////////////////////////////////////////////////////////////////////////////


//Writing in result.txt file the results
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
				  const double& V,
                  const double& RoR)
{
	
	// Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail()) //check
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	
	//Writing in the file:
	
    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
	
	file << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << w[i];
    file << " ]" <<endl;
	
	file << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << r[i];
    file << " ]" <<endl;
    
	file << "Rate of return of the portfolio: " << fixed << setprecision(4) << RoR << endl;
	
	
	file << "V: " << fixed << setprecision(2) << V << endl;

    // Close File
    file.close();

    return true;
}