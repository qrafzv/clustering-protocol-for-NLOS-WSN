#include <CH_LOS_3D.h>

	CH_LOS_3D :: CH_LOS_3D(vector< vector<double>> adjacencyM, vector<SensorInfo> sensors)
	{
		networkSize = sensors.size();
		numberOfObjectives_  = 4;
		numberOfConstraints_ = 0;
		
		problemName_         = "CH_LOS_3D";
			
		numberOfVariables_   = networkSize;
		
		for (int i = 0 ; i < networkSize ; i++)
		{
			vector<double> r;
			for (int j = 0 ; j < networkSize ; j++)
			{
				r.push_back(0);
			}
			clusterHeads.push_back(0);
			adjacencyMatrix.push_back(r);
			Sensors.push_back(SensorInfo());
		}

		for (int i = 0 ; i < networkSize; i++)
		{
			Sensors[i].id = sensors[i].id;
			Sensors[i].x = sensors[i].x;
			Sensors[i].y = sensors[i].y;
			Sensors[i].z = sensors[i].z;
			Sensors[i].energy = sensors[i].energy;

			for (int j = 0 ; j < networkSize ; j++)
			{
				adjacencyMatrix[i][j] = adjacencyM[i][j];
			}
		}
		
		solutionType_ = new BinarySolutionType(this);

		length_       = new int[numberOfVariables_];
  		for (int i = 0; i < numberOfVariables_; i++) length_  [i] = 1 ;

	}

	double CH_LOS_3D :: clusterTheNetwork()
	{
		network.clear();
		int numberOfClusteredNodes = 0;
		
		for (int i = 1 ; i < networkSize ; i++)
     		{
			double maxRSSI = -10000;
			int cHead = 0;

			for (int j = 0; j < clusterHeads.size() ; j++)
       			{
				int node2 = i;
				int node1 = clusterHeads[j];

				double rssi = adjacencyMatrix[node1][node2];

				if (rssi != 0)
				{
					if ( (rssi > maxRSSI) && (rssi >= -85) && (node2 != node1 ))
       					{
							maxRSSI = rssi;
       							cHead = clusterHeads[j];
					}
				}
			}

                        if (maxRSSI != -10000)
			{
			  network.insert(pair<int,int>(i,cHead));
			  numberOfClusteredNodes++;
			}
		}

		return numberOfClusteredNodes;
	}

	double CH_LOS_3D :: getCompactness()
	{
		double maxRSSI = -100;
		double maxCompactness = -100;
		double maxAvgRSSI = 0;
		double totalRSSI = 0;
				
		for (int i = 0 ; i < clusterHeads.size() ; i++)
		{
		    vector<int> members;

		    for (multimap<int,int>::iterator iter = network.begin(); iter != network.end(); iter++)
		    {
			if (iter->second == clusterHeads[i]) members.push_back(iter->first);
		    }
			
		    double clusterCompactness = 0;

		    for(int j = 0 ; j < members.size() ; j++)
		    {
			int node1 = clusterHeads[i];
			int node2 = members[j];
			clusterCompactness += (adjacencyMatrix[node1][node2] / maxRSSI); 
			totalRSSI +=  adjacencyMatrix[node1][node2] / maxRSSI;
		    }

		    if (members.size() > 0)
		    {
			maxAvgRSSI = clusterCompactness / members.size();
		    }
		    else
		    {
			maxAvgRSSI = 100;
		    }

		    if (maxAvgRSSI > maxCompactness)
		    {
				maxCompactness = maxAvgRSSI;			
		    }

		}
		if (clusterHeads.size() == 0) maxCompactness = 100;
		
		return maxCompactness;
 	}


	
	
	CH_LOS_3D :: ~CH_LOS_3D() 
	{
		delete []length_ ;
  		delete solutionType_ ;
                adjacencyMatrix.clear();
  	}

	
	void CH_LOS_3D :: evaluate(Solution *solution) 
	{
	     double totalEnergy = 0;
	    
	     network.clear();
	     clusterHeads.clear();
	   
	     Binary * variable ;

	     for (int i = 1; i < numberOfVariables_ ; i++)
	     {
     		 variable = (Binary *)(solution->getDecisionVariables()[i]) ;
               	 if (variable->getIth(0)){ clusterHeads.push_back(i);totalEnergy+= 18720 / Sensors[i].energy;}
	     }

            double noOfCHs = clusterHeads.size();
	    double cnOfClusteredNodes = clusterTheNetwork();
            double compactness = getCompactness();
	    double avgRemainingEnergy = totalEnergy;
	    double numberOfUnClusteredNodes = networkSize - cnOfClusteredNodes;
	  
	    solution->setObjective(0,noOfCHs);
	    solution->setObjective(1,totalEnergy);
	    solution->setObjective(2,compactness);
	    solution->setObjective(3,numberOfUnClusteredNodes);
	}


