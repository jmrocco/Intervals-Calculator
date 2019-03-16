//============================================================================
// Name        : Juliette Rocco
// Date        : October 21st 2018
// Description : Intervals
//============================================================================

#include <iostream>
#include <string>
#include <cmath>

//function declaration
int main();
int interval_calculator();
void print_immed();
void print_memor();
void int_multi(double ac, double ad, double bc, double bd);
void int_inter(double c, double d);
void int_integ();  //performs integers
void int_cart(double a, double b, double c, double d);

//value of parameters initally inside the array that take user input
int args = 0;

//interval struct with the interval type and initialize boolean
struct Interval {
        double upper,lower;
        bool initial;
};

//immediate and memory struct created
Interval immed;
Interval memor;

//calls the interval calculator
int main()
{
        interval_calculator();
        return 0;
}

//where all the calculations are done
int interval_calculator()
{

        //takes a string input
        std::string input{};


        while (input != "exit") //will exit if exit is the input
        {
                //takes input
                args = 0;
                input = "initial";
                std::cout << "input :> ";
                std::cin >> input;
                //depending on what is inputted, it will assign an array with the proper storage
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




                //stores numbers inputted into an array
                double nums[args];
                for(int count{0}; count < args; ++count) {
                        std::cin >> nums[count];
                }
                //if the input is enter will give appropriate information
                if (input == "enter")
                {
                        //invalid interval error message
                        if (nums[0] > nums[1] && immed.initial == false)
                        {
                                std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl;
                                std::cout << "--"<<std::endl;
                        }
                        //invalid interval error message
                        else if  (nums[0] > nums[1] && immed.initial == true)
                        {
                                std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "--" <<std::endl;
                                immed.initial = false;
                        }

                        else
                        {
                                //assings numbers to the immmediate interval and prints
                                immed.upper = nums[1];
                                immed.lower = nums[0];
                                immed.initial = true;
                                print_immed();
                        }

                }
                //if the input is negate will give appropriate information
                else if (input == "negate")
                {       //if no numbers are stored print dashed line
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //switch the signs of the interval and reorder based on greated and lowest numbers
                        else
                        {
                                double lower{immed.upper * -1};
                                double upper{immed.lower * -1};

                                immed.upper = upper;
                                immed.lower = lower;
                                print_immed();

                        }
                }
                //inverts the interval
                else if (input == "invert")
                {
                        //prints dashed lines if no numbers stored
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //switches the interval and then applies appropriate interval changes
                        else
                        {
                                double lower{1/immed.upper};
                                double upper{1/immed.lower};

                                //error message if dividing by 0
                                if (immed.lower <= 0 && immed.upper >= 0)
                                {
                                        std::cout << "Error: division by zero" <<std::endl << "--" <<std::endl;
                                        immed.initial = false;
                                }
                                //assigns new variables
                                else
                                {
                                        immed.upper =upper;
                                        immed.lower =lower;
                                        print_immed();
                                }


                        }
                }
                //assings to memory
                else if (input == "ms")
                {
                        //prints dashed lines if no numbers are stored in memory
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //assigns new variables and prints
                        else
                        {
                                memor.lower= immed.lower;
                                memor.upper = immed.upper;
                                memor.initial = true;
                                print_immed();
                        }
                }
                //prints what is stored in memory
                else if (input == "mr")
                {
                        //if memory is already initialized it will print memory
                        if(memor.initial == true)
                        {
                                immed.upper = memor.upper;
                                immed.lower = memor.lower;
                        }
                        //it will print the immediate interval if nothing in memory
                        if(immed.initial == true)
                        {
                                print_immed();
                        }
                        //prints dashed lines if no numbers are stored
                        else
                        {
                                std::cout << "--" << std::endl;
                        }

                }
                //sets memory
                else if ( input == "mc")
                {

                        //prints dashed lines if no numbers stored and sets memory to false
                        if (immed.initial == false)
                        {

                                std::cout << "--" << std::endl;
                        }

                        //prints the immediate interval and sets memory to false
                        else
                        {
                                memor.initial = false;
                                print_immed();
                        }
                }

                //interval addition of immediate and memory
                else if (input == "m+")
                {
                        //if everything is initialized adds the intervals and makes assignments
                        if (immed.initial == true && memor.initial == true)
                        {
                                double upper =  immed.upper + memor.upper;
                                double lower = immed.lower + memor.lower;

                                memor.upper = upper;
                                memor.lower = lower;

                                print_immed();
                        }
                        // if not initialzed prints dashed lines
                        else if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //default is the immediate interval
                        else
                        {
                                print_immed();
                        }
                }
                //subtraction of intervals
                else if (input == "m-")
                {
                        //if everything is initalized it subtracts the intervals
                        if (immed.initial == true && memor.initial == true)
                        {
                                double upper = memor.upper - immed.upper;
                                double lower = memor.lower - immed.lower;

                                memor.upper = upper;
                                memor.lower = lower;

                                print_immed();
                        }
                        //prints dashed lines if not initialized
                        else if (immed.initial == false || memor.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //default is the immediate interval
                        else
                        {
                                print_immed();
                        }
                }
                //adds a scalar to the interval
                else if (input =="scalar_add")
                {
                        //if no interval prints dashed lines
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //adds the scalar to the variable
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;

                                immed.lower = temp_lower + nums[0];
                                immed.upper = temp_upper + nums[0];
                                print_immed();

                        }
                }
                //scalar subtract from the interval
                else if (input == "scalar_subtract")
                {
                        //prints dashed lines if there is no interval
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //performs the subtraction
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;

                                immed.lower = temp_lower - nums[0];
                                immed.upper = temp_upper - nums[0];
                                print_immed();
                        }
                }
                //multiplies by a scalar
                else if (input == "scalar_multiply")
                {
                         //prints dashed lines if no numbers stored
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //performs the multiplication
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;
                                //switches upper and lower bound if user input is less than 0 and performs multiplication
                                if (nums[0] < 0)
                                {
                                        immed.lower = temp_upper * nums[0];
                                        print_immed();
                                }
                                //otherwise performs regular multiplication
                                else
                                {
                                        immed.lower = temp_lower * nums[0];
                                        immed.upper = temp_upper * nums[0];
                                        print_immed();
                                }
                        }
                }
                //performs divison by a scalar
                else if (input == "scalar_divide")
                {
                        //prints dashed lines if no numbers stored
                        if (immed.initial == false)
                        {
                                std::cout << "--" << std::endl;
                        }
                        //performs the divison
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;

                                //divides and switches endpoints due to negative input
                                if (nums[0] < 0)
                                {
                                        immed.lower = temp_upper / nums[0];
                                        immed.upper = temp_lower / nums[0];
                                        print_immed();
                                }
                                //invalid interval will print error
                                else if (nums[0] == 0)
                                {
                                        std::cout << "Error: division by zero" <<std::endl << "--" << std::endl;
                                        immed.initial = false;
                                }
                                //divides by the scalar
                                else
                                {
                                        immed.lower = temp_lower / nums[0];
                                        immed.upper = temp_upper / nums[0];
                                        print_immed();
                                }
                        }
                }
                //divides number by the interval
                else if (input == "scalar_divided_by")
                {
                        //prints dashed lines if no numbers stored
                        if (immed.initial == false)
                        {
                                std::cout <<"--" <<std::endl;
                        }
                        //prints the intervals
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;

                                 //invalid interval will print error
                                if (immed.lower <= 0 && immed.upper >= 0 )
                                {
                                        std::cout << "Error: division by zero" <<std::endl << "--" <<std::endl;
                                        immed.initial = false;
                                }
                                //switches the bounds and divides
                                else if (nums[0] < 0)
                                {
                                        immed.upper = nums[0] / temp_upper;
                                        immed.lower = nums[0] / temp_lower;
                                        print_immed();
                                }
                                //divides and prints
                                else
                                {

                                        immed.upper = nums[0] / temp_lower;
                                        immed.lower = nums[0] / temp_upper;
                                        print_immed();
                                }
                        }
                }
                //adds intervals
                else if (input == "interval_add")
                {
                        //invalid intervals will cause error messages
                        if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial = false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl;

                                }
                        }
                        //prints dashed lines if no numbers stored
                        else if (immed.initial == false)
                        {
                                std::cout <<"--" <<std::endl;
                        }
                        //adds the intervals
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;


                                immed.lower = temp_lower + nums[0];
                                immed.upper = temp_upper + nums[1];
                                print_immed();
                        }

                }
                //subtracts the intervals
                else if (input == "interval_subtract")
                {
                        //prints dashed lines if no numbers stored
                        if(immed.initial == false)
                        {
                                std::cout << "--" <<std::endl;
                        }
                        //error messages for invalid entiries
                        else if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial = false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl;

                        }
                        //performs the subtraction
                        else
                        {
                                double temp_lower = immed.lower;
                                double temp_upper = immed.upper;


                                immed.lower = temp_lower - nums[1];
                                immed.upper = temp_upper - nums[0];
                                print_immed();
                        }
                }
                //multiplies intervals
                else if (input == "interval_multiply")
                {
                        //prints dashed lines if no numbers are stored
                        if(immed.initial == false)
                        {
                                std::cout << "--" <<std::endl;
                        }
                        //invalid intervals will print error
                        else if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial= false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl;
                                }
                        }
                        //creates variables by multiplying bounds by corresponding user input
                        else
                        {
                                double ac = immed.lower * nums[0];
                                double ad = immed.lower * nums[1];
                                double bc = immed.upper * nums[0];
                                double bd = immed.upper * nums[1];

                                //sends the above variables to function multi where it will perform the calculations
                                int_multi(ac,ad,bc,bd);
                                print_immed();
                        }
                }

                //divides the intervals
                else if (input == "interval_divide")
                {
                        //prints dashed lines if no numbers stored
                        if(immed.initial == false)
                        {
                                std::cout << "--" <<std::endl;
                        }
                        //invalid interval prints error
                        else if (nums[0] == 0 || nums[1] == 0 || (nums[0] < 0 && nums[1] > 0))
                        {
                                std::cout <<"Error: division by zero" <<std::endl << "--" <<std::endl;
                                immed.initial= false;
                        }
                        //invalid interval prints error
                        else if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial = false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl; //invalid interval will print error
                                }
                        }
                        else
                        {
                                //creates variables using bounds and divides by corresponding user input
                                double ac = immed.lower / nums[0];
                                double ad = immed.lower / nums[1];
                                double bc = immed.upper / nums[0];
                                double bd = immed.upper / nums[1];

                                 //sends variables to the multi function
                                int_multi(ac,ad,bc,bd);
                                print_immed();
                        }
                }
                //intersection of the intervals
                else if (input == "intersect")
                {
                        //invalid intervals print error messages
                        if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial = false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl;
                                }
                        }
                        //pritns dashed lines since no numbers are stored
                        else if(immed.initial == false)
                        {
                                std::cout<< "--" <<std::endl;
                        }
                        else
                        {
                                //creates variables from user input and sends it to the function intersect
                                double c = nums[0];
                                double d = nums[1];

                                //calls the interection function
                                int_inter(c,d);

                                //if the immediate interval is initialized after it comes back then print the interval
                                if (immed.initial == true)
                                {
                                        print_immed();
                                }

                                //otherwise print nothing
                                else
                                {
                                        std::cout << "--" <<std::endl;
                                }
                        }
                }
                //integers inbetween
                else if (input == "integers")
                {
                         //prints dashed lines if no numbers stored
                        if (immed.initial == false)
                        {
                                std::cout <<"--" << std::endl;
                        }
                        //goes to function integer to calculate
                        else
                        {

                                int_integ();
                        }
                }
                //determines cartesian integers
                else if (input == "cartesian_integers")
                {
                        //prints dashed lines if no numbers stored
                        if(immed.initial == false)
                        {
                                std::cout<< "--" <<std::endl;
                        }
                        //invalid intervals print error messages
                        else if (nums[0] > nums[1])
                        {
                                if(immed.initial == true)
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] << std::endl << "[" << immed.lower << ", " << immed.upper << "]"  << std::endl;
                                        immed.initial = false;
                                }
                                else
                                {
                                        std::cout << "Error: invalid interval as " << nums[0] << " > " << nums[1] <<std::endl << "--" << std::endl;
                                }
                        }
                        else
                        {
                                //creates variables and sends them to cartesian
                                double a = immed.lower;
                                double b = immed.upper;
                                double c = nums[0];
                                double d = nums[1];

                                int_cart(a,b,c,d);
                                print_immed();
                        }

                }
                // gives error message for invalid command
                else if (input != "exit")
                {
                        std::cout << "Error: illegal command" << std::endl;
                }
        }

        return 0;
}


//prints the immediate interval
void print_immed()
{
    std::cout << "[" << immed.lower << ", " << immed.upper << "]" << std::endl;
}
//prints the memory interval
void print_memor()
{
        std::cout << "[" << memor.lower << ", " << memor.upper << "]" << std::endl;
}

//performs multiplication and division on the interval
void int_multi(double ac, double ad, double bc,double bd)
{

        double check_array[4] = {ac,ad,bc,bd};
        double smallest = check_array[0];

        //loop to check for the smallest array in the set
        for (int i{1}; i < 4; ++i)
        {
                if (check_array[i] <= smallest)
                {
                        smallest = check_array[i];
                }
        }
         //loop to check for the largest array in the set
        for(int i{1}; i < 4; ++i)
        {

                if(check_array[0] < check_array[i])
                {
                        check_array[0] = check_array[i];
                }

        }
        //sets the lower and upper bound based on what was assigned in the loops after checking
        immed.lower = smallest;
        immed.upper = check_array[0];

}
//intersect on the interval
void int_inter(double c, double d)
{
        double temp_lower = immed.lower;
        double temp_upper = immed.upper;

        // checks to see if the user input is in the bounds of the interval
        if (c >= temp_lower && c < temp_upper)
        {
                 //if c is inbetween it will become the new lower bound
                immed.lower = c;
        }
        //checks to see if the user input is in the bounds of the interval
        if (d > temp_lower && d <= temp_upper)
        {
                //if d is in between it will become the new upper bound
                immed.upper = d;
        }
        //not in the bound, so now it erases numbers//uninitializes
        if (c < immed.lower && d < immed.lower)
        {
                immed.initial = false;
        }
         //not in bound
        else if (c > immed.lower && d > immed.upper)
        {
                immed.initial = false;
        }

}
//interger calculations
void int_integ()
{

        int temp_lower = std::ceil(immed.lower);
        int temp_upper = std::floor(immed.upper);

        //loop to print the numbers in between
        for (int i{temp_lower}; i <= temp_upper; ++i)
        {
                //last number to be printed, prints without a comma
                if (temp_upper == i )
                {
                        std::cout << i <<std::endl;
                }
                //if its not the last number to be printed will print with a comma
                else
                {
                        std::cout << i << ", ";

                }
        }
        print_immed();

}
//cartesian calculations
void int_cart(double a, double b, double c, double d)
{
        //rounds the endpoints
        int temp_a = std::ceil(a);
        int temp_b = std::floor(b);
        int temp_c = std::ceil(c);
        int temp_d = std::floor(d);

        //loops through the intervals and prints the cartesian integers
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
