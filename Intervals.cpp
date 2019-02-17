//============================================================================
// Name        : Juliette Rocco
// Date        : October 21st 2018
// Description : Intervals
//============================================================================

#include <iostream>
#include <string>
#include <cmath>

int main();
int interval_calculator(); 	//the main function where calculations are done
void print_immed();  //prints the immediate interval
void print_memor();  // prints the memory interval
void int_multi(double ac, double ad, double bc, double bd); //performs interval_divide and multiply
void int_inter(double c, double d); //performs intersect
void int_integ();  //performs integers
void int_cart(double a, double b, double c, double d); //performs cartesian integers

int args = 0; //initial value for the number of parameters inside the nums array that takes user input


struct Interval {  //struct for interval
								double upper,lower; //upper and lower bound for the interval
								bool initial; //is it initialized or not

};

Interval immed;  //immediate struct
Interval memor;  //memory struct


int main()
{



								interval_calculator();
								return 0;

}

int interval_calculator()
{


								std::string input{}; // has a string for the input


								while (input != "exit") //will exit if exit is the input
								{
																args = 0; //starts with 0 numbers in the array nums which is number of numbers brought in from user input
																input = "initial"; //if you just type numbers it doesnt clear the row
																std::cout << "input :> ";
																std::cin >> input; //takes the input
																//depending on what is inputted it will assign an array with the proper space
																if (input == "enter" || input == "interval_add" || input == "interval_subtract" || input == "interval_multiply" || input == "interval_divide" || input == "intersect" || input == "cartesian_integers" )
																{
																								args = 2;
																}
																else if (input == "scalar_add" || input == "scalar_subtract" ||input == "scalar_multiply" || input == "scalar_divide" ||input == "scalar_divided_by" )
																{
																								args = 1;
																}
																else if (input == "exit")
																{
																								std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
																}





																double nums[args];
																for(int count{0}; count < args; ++count) {
																								std::cin >> nums[count]; //this loop stores the numbers inputed into an array nums


																}

																if (input == "enter") //if input is enter
																{

																								if (nums[0] > nums[1] && immed.initial == false) //invalid interval will print error
																								{
																																std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl;
																																std::cout << "--"<<std::endl;
																								}
																								else if  (nums[0] > nums[1] && immed.initial == true)//invalid interval will print error
																								{
																																std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "--" <<std::endl;

																																immed.initial = false;
																								}

																								else
																								{
																																immed.upper = nums[1]; //assigns numbers to immed and initializes and prints
																																immed.lower = nums[0];
																																immed.initial = true;
																																print_immed();
																								}

																}
																else if (input == "negate")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double lower{immed.upper * -1}; //multiplies by 1
																																double upper{immed.lower * -1};

																																immed.upper = upper; //assigns new numbers to immed memory
																																immed.lower = lower;
																																print_immed();

																								}
																}
																else if (input == "invert")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double lower{1/immed.upper}; //divides 1 by the intervals
																																double upper{1/immed.lower};

																																if (immed.lower <= 0 && immed.upper >= 0) //invalid interval will print error
																																{
																																								std::cout << "Error: division by zero" <<std::endl << "--" <<std::endl;
																																								immed.initial = false; //do i need this
																																}
																																else
																																{
																																								immed.upper =upper; //assigns new variables and prints
																																								immed.lower =lower;
																																								print_immed();
																																}


																								}
																}
																else if (input == "ms")
																{
																								if (immed.initial == false) //prints dashed lines if no numbers stored
																								{
																																std::cout << "--" << std::endl;
																								}
																								else
																								{
																																memor.lower= immed.lower; //assigns new variables and prints
																																memor.upper = immed.upper;
																																memor.initial = true;
																																print_immed();
																								}
																}
																else if (input == "mr")
																{
																								if(memor.initial == true) //if memory is already initialized it will print memory
																								{
																																immed.upper = memor.upper;
																																immed.lower = memor.lower;
																								}

																								if(immed.initial == true) //it will print immed otherwise
																								{
																																print_immed();
																								}
																								else
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}

																}

																else if ( input == "mc")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored and sets memory to false
																																memor.initial = false;
																								}
																								else
																								{
																																memor.initial = false; //sets memory to false and prints immed
																																print_immed();
																								}
																}
																else if (input == "m+")
																{
																								if (immed.initial == true && memor.initial == true) //only if everything is initailized
																								{
																																double upper =  immed.upper + memor.upper;// adds  immed and memory together
																																double lower = immed.lower + memor.lower;

																																memor.upper = upper; //assigns new variables
																																memor.lower = lower;

																																print_immed(); //prints immed
																								}
																								else if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																print_immed(); //prints immed
																								}
																}
																else if (input == "m-")
																{
																								if (immed.initial == true && memor.initial == true) //only if immed and memory are true
																								{
																																double upper = memor.upper - immed.upper; //subtracts intervals
																																double lower = memor.lower - immed.lower;

																																memor.upper = upper; //reassigns new variables
																																memor.lower = lower;

																																print_immed(); //prints immed
																								}
																								else if (immed.initial == false || memor.initial == false) //if nothing is initial then it just prints dashed lines
																								{
																																std::cout << "--" << std::endl;
																								}
																								else
																								{
																																print_immed();
																								}
																}
																else if (input =="scalar_add")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double temp_lower = immed.lower; //assigns temp variables
																																double temp_upper = immed.upper;

																																immed.lower = temp_lower + nums[0]; //adds user input to upper and lower bounds of immed
																																immed.upper = temp_upper + nums[0];
																																print_immed();

																								}
																}
																else if (input == "scalar_subtract")
																{
																								if (immed.initial == false)//prints dashed lines if no numbers stored
																								{
																																std::cout << "--" << std::endl;
																								}
																								else
																								{
																																double temp_lower = immed.lower; //assigns temp variables
																																double temp_upper = immed.upper;

																																immed.lower = temp_lower - nums[0]; //makes new upper and lower bound
																																immed.upper = temp_upper - nums[0];
																																print_immed();
																								}
																}
																else if (input == "scalar_multiply")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double temp_lower = immed.lower; //temp variables
																																double temp_upper = immed.upper;

																																if (nums[0] < 0)
																																{
																																								immed.lower = temp_upper * nums[0]; //switches upper and lower bound if user input is less than 0 and performs multiplication
																																								immed.upper = temp_lower * nums[0];
																																								print_immed();
																																}
																																else
																																{
																																								immed.lower = temp_lower * nums[0]; //otherwise just multiplies
																																								immed.upper = temp_upper * nums[0];
																																								print_immed();
																																}
																								}
																}
																else if (input == "scalar_divide")
																{
																								if (immed.initial == false)
																								{
																																std::cout << "--" << std::endl;
																								} //prints dashed lines if no numbers stored
																								else
																								{
																																double temp_lower = immed.lower;
																																double temp_upper = immed.upper;

																																if (nums[0] < 0)
																																{
																																								immed.lower = temp_upper / nums[0]; //divides bounds by user input and switches bounds
																																								immed.upper = temp_lower / nums[0];
																																								print_immed();
																																}
																																else if (nums[0] == 0)
																																{
																																								std::cout << "Error: division by zero" <<std::endl << "--" << std::endl; //invalid interval will print error
																																								immed.initial = false;
																																}
																																else
																																{
																																								immed.lower = temp_lower / nums[0]; //divides bounds by user input
																																								immed.upper = temp_upper / nums[0];
																																								print_immed();
																																}
																								}
																}
																else if (input == "scalar_divided_by")
																{
																								if (immed.initial == false)
																								{
																																std::cout <<"--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double temp_lower = immed.lower; //temp variables
																																double temp_upper = immed.upper;


																																if (immed.lower <= 0 && immed.upper >= 0 )
																																{
																																								std::cout << "Error: division by zero" <<std::endl << "--" <<std::endl; //invalid interval will print error
																																								immed.initial = false;
																																}
																																else if (nums[0] < 0)
																																{
																																								immed.upper = nums[0] / temp_upper;
																																								immed.lower = nums[0] / temp_lower;
																																								print_immed();
																																}
																																else
																																{

																																								immed.upper = nums[0] / temp_lower;
																																								immed.lower = nums[0] / temp_upper;
																																								print_immed();
																																}
																								}
																}
																else if (input == "interval_add")
																{

																								if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial = false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error

																																}
																								}
																								else if (immed.initial == false)
																								{
																																std::cout <<"--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double temp_lower = immed.lower; //temporary variables for upper and lower bound
																																double temp_upper = immed.upper;


																																immed.lower = temp_lower + nums[0]; //adds user input and bounds
																																immed.upper = temp_upper + nums[1];
																																print_immed();
																								}

																}
																else if (input == "interval_subtract")
																{
																								if(immed.initial == false)
																								{
																																std::cout << "--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial = false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
																																}

																								}

																								else
																								{
																																double temp_lower = immed.lower; //temporary variables for lower and upper
																																double temp_upper = immed.upper;


																																immed.lower = temp_lower - nums[1]; //subtracts user input from bounds
																																immed.upper = temp_upper - nums[0];
																																print_immed();
																								}
																}

																else if (input == "interval_multiply")
																{
																								if(immed.initial == false)
																								{
																																std::cout << "--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial= false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
																																}
																								}
																								else
																								{
																																double ac = immed.lower * nums[0]; //creates variables by multiplying bounds by corresponding user input
																																double ad = immed.lower * nums[1];
																																double bc = immed.upper * nums[0];
																																double bd = immed.upper * nums[1];

																																int_multi(ac,ad,bc,bd); //sends the above variables to function multi where it will perform the calculations
																																print_immed(); //prints the immed intervals after
																								}
																}
																else if (input == "interval_divide")
																{
																								if(immed.initial == false)
																								{
																																std::cout << "--" <<std::endl; //prints dashed lines if no numbers stored
																								}

																								else if (nums[0] == 0 || nums[1] == 0 || (nums[0] < 0 && nums[1] > 0))
																								{
																																std::cout <<"Error: division by zero" <<std::endl << "--" <<std::endl;
																																immed.initial= false; //invalid interval will print error
																								}
																								else if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial = false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
																																}
																								}
																								else
																								{
																																double ac = immed.lower / nums[0];
																																double ad = immed.lower / nums[1];
																																double bc = immed.upper / nums[0]; //creates variables using bounds and divides by corresponding user input
																																double bd = immed.upper / nums[1];

																																int_multi(ac,ad,bc,bd); //sends variables to the multi function
																																print_immed();
																								}
																}
																else if (input == "intersect")
																{

																								if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial = false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
																																}
																								}
																								else if(immed.initial == false)
																								{
																																std::cout<< "--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{
																																double c = nums[0]; //creates variables from user input and sends it to the function intersect
																																double d = nums[1];
																																int_inter(c,d);
																																if (immed.initial == true)
																																{
																																								print_immed(); //if the immediate interval is initial after it comes back then print the interval
																																}
																																else
																																{
																																								std::cout << "--" <<std::endl; //otherwise print nothing
																																}
																								}
																}
																else if (input == "integers")
																{
																								if (immed.initial == false)
																								{
																																std::cout <<"--" << std::endl; //prints dashed lines if no numbers stored
																								}
																								else
																								{

																																int_integ(); //goes to function integer to calculate
																								}
																}
																else if (input == "cartesian_integers")
																{
																								if(immed.initial == false)
																								{
																																std::cout<< "--" <<std::endl; //prints dashed lines if no numbers stored
																								}
																								else if (nums[0] > nums[1])
																								{
																																if(immed.initial == true)
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
																																								immed.initial = false; //invalid interval will print error
																																}
																																else
																																{
																																								std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
																																}
																								}
																								else
																								{
																																double a = immed.lower; //creates variables and sends them to cartesian
																																double b = immed.upper;
																																double c = nums[0];
																																double d = nums[1];

																																int_cart(a,b,c,d); //
																																print_immed();
																								}

																}
																else if (input != "exit")
																{
																								std::cout << "Error: illegal command" << std::endl; //prints error if input is not a valid command
																}
								}

								return 0;
}



void print_immed()
{
								std::cout << "[" << immed.lower << ", " << immed.upper << "]" << std::endl; //prints the immediate interval
}

void print_memor()
{
								std::cout << "[" << memor.lower << ", " << memor.upper << "]" << std::endl; //prints the memory interval
}

void int_multi(double ac, double ad, double bc,double bd)
{

								double check_array[4] = {ac,ad,bc,bd}; //assigns the variables to an array
								double smallest = check_array[0];
								for (int i{1}; i < 4; ++i) //loop to check for the smallest array in the set
								{
																if (check_array[i] <= smallest)
																{
																								smallest = check_array[i];
																}
								}

								for(int i{1}; i < 4; ++i) //loop to check for the largest array in the set
								{

																if(check_array[0] < check_array[i])
																{
																								check_array[0] = check_array[i];
																}

								}
								immed.lower = smallest; //sets the lower and upper bound based on what was assigned in the loops after checking
								immed.upper = check_array[0];

}

void int_inter(double c, double d)
{
								double temp_lower = immed.lower;//temporary variables for lower and upper
								double temp_upper = immed.upper;

								if (c >= temp_lower && c < temp_upper) // checks to see if the user input is in the bounds of the interval
								{
																immed.lower = c; //if c is inbetween it will become the new lower bound
								}

								if (d > temp_lower && d <= temp_upper) //checks to see if the user input is in the bounds of the interval
								{
																immed.upper = d; //if d is in between it will become the new upper bound
								}

								if (c < immed.lower && d < immed.lower)
								{
																immed.initial = false; //not in the bound, so now it erases numbers//uninitializes
								}
								else if (c > immed.lower && d > immed.upper) //not in bound
								{
																immed.initial = false;
								}

}

void int_integ()
{

								int temp_lower = std::ceil(immed.lower); //temporary variables for lower and upper, rounded up and down
								int temp_upper = std::floor(immed.upper);

								for (int i{temp_lower}; i <= temp_upper; ++i) //loop to print the numbers in between
								{

																if (temp_upper == i ) //last number to be printed, prints without a comma
																{
																								std::cout << i <<std::endl;
																}
																else
																{
																								std::cout << i << ", "; //if its not the last number to be printed will print with a comma

																}
								}
								print_immed();

}
void int_cart(double a, double b, double c, double d)
{
								int temp_a = std::ceil(a);
								int temp_b = std::floor(b);
								int temp_c = std::ceil(c);
								int temp_d = std::floor(d);

								for (int i{temp_a}; i <= temp_b; i++ )
								{
																for (int x(temp_c); x <= temp_d; x++)
																{
																								if (x == temp_d && i == temp_b)
																								{
																																std::cout<< "(" << i << "," << x << ")" << std::endl;
																								}
																								else
																								{
																																std::cout<< "(" << i << "," << x << "), ";
																								}
																}
								}
}
