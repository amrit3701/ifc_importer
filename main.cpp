#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const string emptyString = "";
string ExtractString( string source, string start, string end )
{
	size_t startIndex = source.find( start );
	
	// If the starting delimiter is not found on the string
	// stop the process, you're done!	
    if( startIndex == string::npos )
    {
       return emptyString;
	}
	
	// Adding the length of the delimiter to our starting index
	// this will move us to the beginning of our sub-string.
	startIndex += start.length();
	
	// Looking for the end delimiter
	string::size_type endIndex = source.find( end, startIndex );

	// Returning the substring between the start index and
	// the end index. If the endindex is invalid then the
	// returned value is empty string.
	return source.substr( startIndex, endIndex - startIndex );
}


int main () {
	string line;
	
	// Enter file name
	ifstream myfile ("mini_ifc.ifc");
	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) ){
			string extracted = ExtractString( line, "=", "(" );
			
			// Calling differnt funtions according to the entity present in
			// STEP file.

			if (extracted == "IFCCARTESIANPOINT"){
				// Using /step/step-g/CartesianPoint.cpp 
			}

			else if (extracted == "IFCDIRECTION"){
				// using /step/step-g/Direction.cpp  
			}

			// Similarly adding all the entities present in IFC file. 

			else{
				// Conversion of all entities present in IFC file is done.
				cout << "Done" << endl;
			}



		}	
		myfile.close();
	}

	else cout << "Unable to open file";

	return 0;
}
