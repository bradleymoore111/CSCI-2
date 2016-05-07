#include <iostream>
#include <string>

using namespace std;

void verifyTemp(double* temp);
struct Month{
	double rain;
	double highTemp;
	double lowTemp;
	double avgTemp;
};

int main() {
	string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	Month year[12];
	double tempTemp;
	for (int i = 0;i < 12;i++) {
		cout << "Total Rainfall for " << months[i] << ":";
		cin >> year[i].rain;

		cout << "High Temperature for " << months[i] << ":";
		cin >> tempTemp;
		verifyTemp(&tempTemp);
		year[i].highTemp = tempTemp;

		cout << "Low Temperature for " << months[i] << ":";
		cin >> tempTemp;
		verifyTemp(&tempTemp);
		year[i].lowTemp = tempTemp;

		// Average rainfall does not necessarily equal the average of the highs and lows, but I'll leave it for now
		year[i].avgTemp = (year[i].lowTemp + year[i].highTemp) / 2.0;
		cout << endl;
	}

	// Average monthly rainfall
	double sum = 0.0;
	for (int i = 0;i < 12;i++) {
		sum += year[i].rain;
	}
	double avg = sum/12.0;

	// Lowest Temp for the year
	double minTemp = 140.0;
	string monthMinOccured = "January";
	for (int i = 0;i < 12;i++) {
		if (year[i].lowTemp < minTemp) {
			monthMinOccured = months[i];
			minTemp = year[i].lowTemp;
		}
	}

	// Highest temp for the year
	double maxTemp = -100.0;
	string monthMaxOccured = "January";
	for (int i = 0;i < 12;i++) {
		if (year[i].highTemp > maxTemp) {
			monthMaxOccured = months[i];
			maxTemp = year[i].highTemp;
		}
	}

	// Average temp for the year
	double avgTemp = 0.0;
	for (int i = 0;i < 12;i++) {
		avgTemp += year[i].avgTemp;
	}
	avgTemp /= 12;

	cout << "The important bits are:" << endl;
	cout << "\tAverage monthly rainfall was " << avg << endl;
	cout << "\tTotal rainful was " << sum << endl;
	cout << "\tHighest temperature of the year was " << maxTemp << " and occured in " << monthMaxOccured << endl;
	cout << "\tLowest temperature of the year was " << minTemp << " and occured in " << monthMinOccured << endl;
	cout << "\tAverage monthly temperature was " << avgTemp << endl;

	return 0;
}

void verifyTemp(double* temp) {
	if (*temp < -100.0) {
		*temp = -100.0;
	}
	else if (*temp > 140.0) {
		*temp = 140.0;
	}
}