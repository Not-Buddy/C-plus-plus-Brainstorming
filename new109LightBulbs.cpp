// C++ implementation of above approach
#include <iostream>
using namespace std;

int findOnBulbs(int numberOfBulbs)
{
	// initializing the result
	int onBulbs = 0; 
	
	// to loop over all bulbs from 1 to numberOfBulbs
	int bulb = 1; 
	
	// to loop over persons to check whether their person number
	int person = 1; 
	
	
	// is a factor of light bulb number or not
	for (bulb = 1; bulb <= numberOfBulbs; bulb++) {
		
		// inner loop to find factors of given bulb
		// to count the number of factors of a given bulb
		int factors = 0; 
		
		for (person = 1; person * person <= numberOfBulbs; person++) {
			
			if (bulb % person == 0) // person is a factor
			{
				factors++;
				
				// bulb != person*person
				if (bulb / person != person) 
				{
					factors++;
				}
			}
		}
		
		// if number of factors is odd, then the
		if (factors % 2 == 1) 
		
		{
			// light bulb will be "on" in the end
			cout << "Light bulb "
				<< bulb
				<< " will be on"
				<< "\n";
			onBulbs++;
		}
	}
	
	
	return onBulbs;
}


// Driver program to test above function
int main()
{
	// total number of light bulbs
	int numberOfBulbs = 1000; 
	cin>>numberOfBulbs;
	
	// to find number of on bulbs in
	// the end after all persons have
	// flipped the light bulbs
	int onBulbs = findOnBulbs(numberOfBulbs); 
	
	

	cout << "Total "
		<< onBulbs
		<< " light bulbs will be on in the end out of "
		<< numberOfBulbs
		<< " light bulbs"
		<< "\n";
	return 0;
}

