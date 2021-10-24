// ---- - program start------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <thread>

void getInput(int* buffer_ptr, int* flag_ptr) // T1
{
	while (true)
	{
		//Hvis det skal v�re flere tr�der av type T1, da m� det v�re noe l�s
		// slik at input stream g�r til bare til den ene tr�d
		if ((*buffer_ptr) == 0 && (*flag_ptr)==0 )
		{
			*buffer_ptr = 1; // da er input stream er l�st til denne tr�d mens bruker taster in tall
			std::cout << "Skiv in en heltal>";
			std::cin >> (*buffer_ptr);
			if((*buffer_ptr) != 0) *flag_ptr = 1;
		}
		if ((*buffer_ptr) == 666) break;
	}
} //end getInput
void sumInput(int* buffer_ptr, int* sum_ptr, int* flag_ptr) //T2
{
	while (true)
	{
		if ((*buffer_ptr) != 0 && (*flag_ptr) == 1) {
			*sum_ptr += *buffer_ptr;
			*buffer_ptr = 0;
			*flag_ptr = 2;
		}
		if ((*buffer_ptr) == 666) break;
	}
} // end sumInput
void printSum(int* buffer_ptr, int* sum_ptr, int* flag_ptr) //T3
{
	while (true)
	{
		if ( (*flag_ptr) == 2)
		{
			std::cout << "Total sum is: " << *sum_ptr << std::endl;
			*flag_ptr = 0;
		}
		if ((*buffer_ptr) == 666) break;
	}
} //end printSum
int main() // -------------------------------------------------------MAIN-----------------------------------------------------------------
{
	int buffer{}; //tall fra bruker
	int* buffer_ptr{ &buffer };
	int sum{ 0 }; //summen av alle tall fra bruker
	int* sum_ptr{ &sum };
	int flag{ 0 };
	int* flag_ptr{ &flag };

	std::thread T1(getInput, buffer_ptr, flag_ptr);
	std::thread T2(sumInput, buffer_ptr, sum_ptr, flag_ptr);
	std::thread T3(printSum, buffer_ptr, sum_ptr, flag_ptr);
	// venter p� tr�dene f�r avslutter programmet
	T1.join();
	T2.join();
	T3.join();
	std::cout << "program end";
	return 0;
}
