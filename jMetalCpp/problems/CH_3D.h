#ifndef _CH_3D_H_
#define _CH_3D_H_

#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <list>
#include <Problem.h>
#include <RealSolutionType.h>
#include <BinaryRealSolutionType.h>
#include <Solution.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <list>
#include <fstream>
#include <Problem.h>
#include <Solution.h>
#include <random>
#include <BinarySolutionType.h>
#include <boost/tokenizer.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
#include <string>
#include <WCoverage.h>
/* struct SensorInfo */
/* { */
/* 	int id; */
/* 	double x; */
/* 	double y; */
/* 	double z; */
/* 	double energy; */
/* SensorInfo():id(0),x(0),y(0),z(0),energy(0){}; */
/* }; */

class CH_3D : public Problem
{
	int networkSize;
	double numOfCubes;
		
	ofstream myfile;

	int uncover;
	vector<int> sleepNodes;
	vector<int> activeNodes;
	vector<int> clusterHeads;
	vector<int> configuration;

	multimap<int,int> network;

	vector <SensorInfo> Sensors;
	vector <vector<double> > adjacencyMatrix;
	vector <vector<double> > coverageMatrix;
	vector <vector<double> > overlappingMatrix;
	
        public:
	

	CH_3D(const vector< vector<double> > & adjacencyM, const vector<SensorInfo> &sensors);
		
	~CH_3D();

	double clusterTheNetwork();

	double getCompactness();
	
	void evaluate(Solution *solution);

};

#endif
