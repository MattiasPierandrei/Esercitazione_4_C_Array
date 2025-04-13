//PIERANDREI MATTIAS

#pragma once
#include <iostream>
using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r);


double RateOfReturn(const size_t& n,
                   double*& w,
                   double*& r);


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
				  const double& V,
                  const double& RoR);