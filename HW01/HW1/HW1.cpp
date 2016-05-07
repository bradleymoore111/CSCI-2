/*
 *	Homework assignment 1, by Bradley Moore, in CSCI-2-0118
 *	email: bradleym007@gmail.com
 *	phone: 310-906-6659
 *	Github: github.com/trashy111
 */

// Don't need to import strings
#include <iostream>

// Makes life way easier
using namespace std;

// Defining struct to hold each element of the monthly budget, each being a double as representing cash amounts.
struct MonthlyBudget {
	double housing;
	double utilities;
	double householdExpenses;
	double transportation;
	double food;
	double medication;
	double insurance;
	double entertainment;
	double clothing;
	double misc;
};

// Predefining functions so that we can reference them within main.
void getUserData(MonthlyBudget* budget);
void showErrors(MonthlyBudget actual, MonthlyBudget ideal);

int main() {
	system("color 17");

	/*	
	 *	First declaring a variable "budget" to hold the data for the month to calculate, 
	 *	then passing it into the getUserData() function by reference so that we can modify 
	 *	it directly, without having to set it equal to a possible returned MonthlyBudget struct
	 */
	MonthlyBudget budget;
	getUserData(&budget);
	
	/*
	 *	Defining an ideal MonthlyBudget to be used for comparison (allows general case, 
	 *	in case the ideal changes later on, we can just change this).
	 */
	MonthlyBudget ideal = { 500.0, 150.0, 65.0, 50.0, 250.0, 30.0, 100.0, 150.0, 75.0, 50.0 };

	// Outputing discrepencies by comparing the budget to ideal, passing by value instead of reference.S
	showErrors(budget, ideal);

	return 0;
}

/*	
 *	This function works primarily by just a ton of in order cout's and cin's. 
 *	I originally had an issue with applying the reference value, which I rectified by 
 *	Originally creating a function with a return type of MonthlyBudget and returning
 *	a newly created MonthlyBudget, instead of modifying the one that was passed in.
 *	Then I realized that it was trying to cin towards the reference at point 
 *	*(budget.housing) instead of (*budget).housing, which I fixed.
 */ 
void getUserData(MonthlyBudget* budget) {
	cout << "Welcome to the MonthlyBudget program. Please enter for each category, how much you spent this month (as compared to how much you're supposed to be spending)." << endl;
	cout << "Expenses for this month:" << endl;

	cout << "\tHousing: ";
	cin >> (*budget).housing;

	cout << "\tUtilities: ";
	cin >> (*budget).utilities;

	cout << "\tHousehold Expenses: ";
	cin >> (*budget).householdExpenses;

	cout << "\tTransportation: ";
	cin >> (*budget).transportation;

	cout << "\tFood: ";
	cin >> (*budget).food;

	cout << "\tMedication: ";
	cin >> (*budget).medication;

	cout << "\tInsurance: ";
	cin >> (*budget).insurance;

	cout << "\tEntertainment: ";
	cin >> (*budget).entertainment;

	cout << "\tClothing: ";
	cin >> (*budget).clothing;

	cout << "\tMISC: ";
	cin >> (*budget).misc;
}

/*
 *	This function just outputs a TON of formatting. Wasn't particularly
 *	difficult to make, just time consuming.
 */
void showErrors(MonthlyBudget a, MonthlyBudget i) {
	cout << "Discrepencies in the monthly budget. Positive numbers represent spare assets, while negative numbers represent overspending." << endl;
	cout << "Housing: $" <<				i.housing - a.housing						<< endl;
	cout << "Utilities: $" <<			i.utilities - a.utilities					<< endl;
	cout << "Household Expenses: $" <<	i.householdExpenses - a.householdExpenses	<< endl;
	cout << "Transportation: $" <<		i.transportation - a.transportation			<< endl;
	cout << "Food: $" <<				i.food - a.food								<< endl;
	cout << "Medication: $" <<			i.medication - a.medication					<< endl;
	cout << "Insurance: $" <<			i.insurance - a.insurance					<< endl;
	cout << "Entertainment: $" <<		i.entertainment - a.entertainment			<< endl;
	cout << "Clothing: $" <<			i.clothing - a.clothing						<< endl;
	cout << "MISC: $" <<				i.misc - a.misc								<< endl;

	cout << endl;
	cout << "Discrepencies for the entire monthly budget:" << endl;
	double sumActual = a.housing + a.utilities + a.householdExpenses + a.transportation + a.food + a.medication + a.insurance + a.entertainment + a.clothing + a.misc;
	double sumIdeal = i.housing + i.utilities + i.householdExpenses + i.transportation + i.food + i.medication + i.insurance + i.entertainment + i.clothing + i.misc;

	cout << "$" << sumIdeal - sumActual << endl;
}