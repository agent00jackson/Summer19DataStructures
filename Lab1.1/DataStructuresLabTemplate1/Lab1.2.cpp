//Jackson Randolph
//Lab 1.1
//Page 45 Problem 8
// Add a new throttle member function that will return true if the current
//flow is more than half. The body of your implementation should activate
//flow and use the guidelines for boolean values listed above.
#include <iostream> // Provides cout and cin
#include <cstdlib> // Provides EXIT_SUCCESS
using namespace std; // Allows all Standard Library items to be used



class throttle
{
public:
	// MODIFICATION MEMBER FUNCTIONS
	void shut_off();
	void shift(int amount);
	// CONSTANT MEMBER FUNCTIONS
	double flow() const;
	bool is_on() const;
	bool more_than_half() const;
private:
	int position;
};

void throttle::shut_off()
// Precondition: None.
// Postcondition: The throttle has been turned off.
{
	position = 0;
}

void throttle::shift(int amount)
// Precondition: shut_off has been called at least once to initialize the throttle.
// Postcondition: The throttle’s position has been moved by amount (but
// not below 0 or above 6).
{
	position += amount;
	if (position < 0)
		position = 0;
	else if (position > 6)
		position = 6;
}

double throttle::flow() const
// Precondition: shut_off has been called at least once to initialize the throttle.
// Postcondition: The value returned is the current flow as a proportion of
// the maximum flow.
{
	return position / 6.0;
}

bool throttle::is_on() const
// Precondition: shut_off has been called at least once to initialize the throttle.
// Postcondition: If the throttle’s flow is above 0, then the function
// returns true; otherwise, it returns false.
{
	return (flow() > 0);
}

bool throttle::more_than_half() const
// Precondition: shut_off has been called at least once to initialize the throttle.
// Postcondition: If the throttle’s flow is above .5, then the function
// returns true; otherwise, it returns false.
{
	return (flow() > .5);
}

int main()
{
	throttle sample;
	int user_input;
	// Set the sample throttle to a position indicated by the user.
	cout << "I have a throttle with 6 positions." << endl;
	cout << "Where would you like to set the throttle? " << endl;
	cout << "Please type a number from 0 to 6: ";
	cin >> user_input;
	sample.shut_off();
	sample.shift(user_input);
	// Shift the throttle down to zero, printing the flow along the way.
	while (sample.is_on())
	{
		cout << "The flow is now " << sample.flow() << "\tThis is ";
		if (sample.more_than_half())
		{
			cout << "more than half.";
		}
		else
		{
			cout << "less than or equal to half.";
		}
		cout << endl;
		sample.shift(-1);
	}
	cout << "The flow is now off" << endl;
	return EXIT_SUCCESS;
}