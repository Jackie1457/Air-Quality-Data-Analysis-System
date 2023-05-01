#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits
#include "AirQuality.h"
#include "AirQuality.cpp"
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"

using namespace std;

int inputMonth;
int inputYear;
double aveTemp;
double averageRH;
double averageAH;
const int CHOICE1 = 1;
const int CHOICE2 = 2;
const int CHOICE3 = 3;
const int CHOICE4 = 4;
const int CHOICE5 = 5;
const int CHOICE6 = 6;
const int CHOICE7 = 7;
const int CHOICE8 = 8;
const int CHOICE9 = 9;
const int CHOICE10 = 10;
const int CHOICE11 = 11;
const int INPUT_MONTH12 = 12;
const int MISSING_VALUE = -200;
const int INPUT_YEAR1 = 2004;
const int INPUT_YEAR2 = 2005;

const int ADD_ON_YEAR = 2000;
const int INDEX_ONE = 1;
const int INDEX_TWO = 2;
const int SPLIT_DELIM12 = 12;
const int SPLIT_DELIM13 = 13;
const int SPLIT_DELIM14 = 14;
const int INPUT_MONTH3 = 3; 
const int INPUT_DAY10 = 10; 
const int INPUT_DAY31 = 31;
const int INPUT_MONTH1 = 1;
const int INPUT_MONTH4 = 4;
const int INPUT_DAY1 = 1;
const int INPUT_DAY4 = 4;


/**helper method to split string with specific delimeter*/
vector<string> split(string input, char delim)
{
    vector<string> result;
    stringstream s_stream(input); /**create string stream from the string*/
    while(s_stream.good())
    {
        string substr;
        getline(s_stream, substr, delim); /**get first string delimited by delim*/
        result.push_back(substr);
    }
    return result;
}

/** helper method to show the content of menu*/
void showMenu(){
    cout << "Here is the AirReport menu, choose from 1 to 10, choose 11 to quit" << endl;
    cout << "1.Enter the month and get the average temperature for that month" << endl;
    cout << "2.Enter the month and get the average relative humidity for that month" << endl;
    cout << "3.Enter the month and get the average absolute humidity for that month" << endl;
    cout << "4.Enter the valid date and time and get the temperature, and relative humidity at that date and time" << endl;
    cout << "5.Enter the month and get the highest temperature for that month" << endl;
    cout << "6.Enter the month and get the highest relative humidity for that month" << endl;
    cout << "7.Enter the month and get the highest absolute humidity for that month" << endl;
    cout << "8.Enter the dates and time for a month and get the temperature when the temperature is higher than the average temperature for that month along with values of the temperature." << endl;
    cout << "9.Enter the dates and time for a month and get the relative humidity when the relative humidity is higher than the average relative humidity for that month along with values of the relative humidity." << endl;
    cout << "10.Enter the dates and time for a month and get the absolute humidity when the absolute humidity is higher than the average absolute humidity for that month along with values of the absolute humidity." << endl;
    cout << "11. Quit the system." << endl;
}

void promptYearAndMonth(){
    inputYear = -1;
    bool validYear = false;
    do{
        cout << "Please enter the year(ex:2004/2005), input year must be 2004 or 2005" << endl;
        cin >> inputYear;
        if(cin.good()){
            if(inputYear >= INPUT_YEAR1 && inputYear <= INPUT_YEAR2)
                validYear = true;
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
                cout << "Please input year and year must be 2004 or 2005: " << endl;
            }
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
            cout << "Please input year and year must be 2004 or 2005: " << endl;
        }
    }while(!validYear);


    inputMonth = -1;
    bool validMonth = false;
    do{
        cout << "Please enter the month to get the average temperature for that month(ex:mm): " << endl;
        cin >> inputMonth;
        if(cin.good()){
            if(inputMonth >= 1 && inputMonth <= INPUT_MONTH12)
                validMonth = true;
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
                cout << "Please input number from 1 to 12: " << endl;
            }
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
            cout << "Please input number from 1 to 12: " << endl;
        }
    }while(!validMonth);
}

vector<AirQuality> generateAirQualityReport(string fileName){
    /**1. read file and store into a vector of string;
    string fileName("AirQualityUCI.csv");
    string fileName("testAQ.csv"); // This is the test file.*/

    vector<string> lines;
    string line;

    ifstream input_file(fileName);
    if(!input_file.is_open()){
        cerr << "Could not open the file.'"
             << fileName << "'" << endl;
        // return EXIT_FAILURE;
        //cerr is the standard error stream which is used to output the errors.
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    // // Test:
    // // To compare the vector header content and size with original csv file
    // // to check if the read file line by line into a vector is correct
    // cout << "Size of vector:" << lines.size() << endl;
    // cout << "Header of vector:" << lines[0] << endl;
    // input_file.close();
    // return EXIT_SUCCESS;

    /** 2. split each line by colon to get each column of each line and store each line into a vector*/
    vector<string> splittedLine;
    vector<AirQuality> airQualityReport;

    for(int i = 1; i < lines.size(); i++){
        string eachLine = lines[i];
        splittedLine = split(eachLine, ','); // each line splitted with ,

        /**get date*/
        string getDate = splittedLine[0]; /** get the date column information, store in a dateInfo vector*/
        vector<string> dateInfo = split(getDate, '/'); /**split each date info with*/
        int month = stoi(dateInfo[0]);
        int day = stoi(dateInfo[INDEX_ONE]);
        int year = stoi(dateInfo[INDEX_TWO]) + ADD_ON_YEAR;
        Date oneDate;
        oneDate.SetDate(day, month, year);
        // oneDate.printDate(); // test printDate();

         /**get time*/
        string getTime = splittedLine[1];
        vector<string> timeInfo = split(getTime, ':');
        int hour = stoi(timeInfo[0]);
        int minute = stoi(timeInfo[1]);
        Time oneTime;
        oneTime.SetTime(hour, minute);
        // oneTime.printTime(); // test printTime();

        /**get temp*/
        string getTemp = splittedLine[SPLIT_DELIM12];
        // cout << showpoint << fixed << setprecision(2);
        double eachTemp = stod(getTemp);
        // cout << eachTemp << " "; // test get correct temp;

        // get relativeHumidity
        string getRH = splittedLine[SPLIT_DELIM13];
        double RH = stod(getRH);
        // cout << RH << " "; // test get correct RH;

        // get Absolute Humidity
        string getAH = splittedLine[SPLIT_DELIM14];
        double AH = stod(getAH);
        // cout << AH << " "; // test get correct AH;

        AirQuality airLog;
        airLog.SetDate(day, month, year);
        airLog.SetTime(hour, minute);
        airLog.SetTemp(eachTemp);
        airLog.SetRelativeHumidity(RH);
        airLog.SetAbsoluteHumidity(AH);
        airQualityReport.push_back(airLog); // vector of airLog which is an AirQuality class
    }
    return airQualityReport;
}

void choiceOne(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth(); // prompt the input year and month

    aveTemp = 0;
    double sumTemp = 0;
    int countTemp = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            if(airQualityReport[i].GetTemp() == MISSING_VALUE){
                continue;
            }
            countTemp = countTemp + 1;
            sumTemp += airQualityReport[i].GetTemp();
        }
    }
    cout << showpoint << fixed << setprecision(2);
    aveTemp = sumTemp / countTemp;
    // cout << countTemp << endl;
    // cout << sumTemp << endl;
    cout << "The average temperature for that month is: " << aveTemp << endl;
    cout << endl;
}

void choiceTwo(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth();

    averageRH = 0;
    double sumRH = 0;
    int countRH = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            if(airQualityReport[i].GetTemp() == MISSING_VALUE){
                continue;
            }
            countRH = countRH + 1;
            sumRH += airQualityReport[i].GetRelativeHumidity();
        }
    }
    cout << showpoint << fixed << setprecision(2);
    averageRH = sumRH / countRH;
    // cout << countTemp << endl;
    // cout << sumTemp << endl;
    cout << "The average relative humidity for that month is: " << averageRH << endl;
    cout << endl;
}

void choiceThree(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth();

    averageAH = 0;
    double sumAH = 0;
    int countAH = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            if(airQualityReport[i].GetTemp() == MISSING_VALUE){
                continue;
            }
            countAH = countAH + 1;
            sumAH += airQualityReport[i].GetAbsoluteHumidity();
        }
    }
    cout << showpoint << fixed << setprecision(2);
    averageAH = sumAH / countAH;
    // cout << countTemp << endl;
    // cout << sumTemp << endl;
    cout << "The average absolute humidity for that month is: " << averageAH << endl;
    cout << endl;
}

void choiceFour(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    int userInputDay;
    int userInputMonth;
    int userInputYear;

    do{//check if the input year is 2004 or 2005
        cout << "Please enter the year(ex:2004/2005), input year must be 2004 or 2005" << endl;
        cin >> userInputYear;
    }while(userInputYear < INPUT_YEAR1 || userInputYear > INPUT_YEAR2);

    while(userInputYear == INPUT_YEAR1){
        do{
            cout << "Please enter the month(ex:mm): " << endl;
            cout << "Input month must be from 3 to 12: " << endl;
            cin >> userInputMonth;
        }while(userInputMonth < INPUT_MONTH3 || userInputMonth > INPUT_MONTH12);
        if(userInputMonth >= INPUT_MONTH3 && userInputMonth <= INPUT_MONTH12) break;
    }

    while(userInputYear == INPUT_YEAR2){
        do{
            cout << "Please enter the month(ex:mm): " << endl;
            cout << "Input month must be from 1 to 4: " << endl;
            cin >> userInputMonth;
        }while(userInputMonth < INPUT_MONTH1 && userInputMonth > INPUT_MONTH4);
        if(userInputMonth >= INPUT_MONTH1 && userInputMonth <= INPUT_MONTH4) break;
    }

    cout << "Please enter the day(ex:dd): " << endl;
    cin >> userInputDay;

    while(userInputYear == INPUT_YEAR1){
        if(userInputMonth != INPUT_MONTH3){
            break;
        }
        if(userInputMonth == INPUT_MONTH3){
            if(userInputDay >= INPUT_DAY10) break;
            do{
            cout << "Please enter valid day(ex:dd), and the input Day of March 2004 must be from 10 to 31: " << endl;
            cin >> userInputDay;
            }while(userInputDay < INPUT_DAY10);
        }
    }

    while(userInputYear == INPUT_YEAR2){
        if(userInputMonth != INPUT_MONTH4){
            break;
        }
        while(userInputMonth == INPUT_MONTH4){
            if(userInputDay <= INPUT_DAY4) break;
            do{
            cout << "Please enter valid day(ex:dd), and the input Day of April 2005 must be from 1 to 4: " << endl;
            cin >> userInputDay;
            }while(userInputDay > INPUT_DAY4);
        }
        if(userInputDay >= INPUT_DAY1 && userInputDay <= INPUT_DAY4) break;
    }

    int userInputHour;
    int userInputMinute;
    cout << "Please enter the hour(ex:hh): " << endl;
    cin >> userInputHour;
    cout << "Please enter the minute(ex:mn): " << endl;
    cin >> userInputMinute;
    double specificTemp;
    double specificRH;
    for(int i = 0; i < airQualityReport.size(); i++){
        if (airQualityReport[i].GetDate().GetYear() == userInputYear && 
            airQualityReport[i].GetDate().GetMonth() == userInputMonth && 
            airQualityReport[i].GetDate().GetDay() == userInputDay && 
            airQualityReport[i].GetTime().GetHour() == userInputHour &&
            airQualityReport[i].GetTime().GetMin() == userInputMinute){
            specificTemp = airQualityReport[i].GetTemp();
            specificRH = airQualityReport[i].GetRelativeHumidity();
        }
    }
    cout << "The temperature of the date and time you input is: " << specificTemp << endl;
    cout << "The relative humidity of the date and time you input is: " << specificRH << endl;
    cout << endl;
}

void choiceFive(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth();

    double highestTemp = 0;
    double currTemp = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            currTemp = airQualityReport[i].GetTemp();
            if(currTemp > highestTemp)
                highestTemp = currTemp;
        }
    }
    cout << "The highest temperature for that month is: " << highestTemp << endl;
    cout << endl;
}

void choiceSix(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth();

    double highestRH = 0;
    double currRH = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            currRH = airQualityReport[i].GetRelativeHumidity();
            if(currRH > highestRH)
                highestRH = currRH;
        }
    }
    cout << "The highest relative humidity value for that month is: " << highestRH << endl;
    cout << endl;
}

void choiceSeven(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    promptYearAndMonth();

    double highestAH = 0;
    double currAH = 0; 
    for(int i = 0; i < airQualityReport.size(); i++){
        if((airQualityReport[i].GetDate().GetYear() == inputYear) && (airQualityReport[i].GetDate().GetMonth() == inputMonth)){
            currAH = airQualityReport[i].GetAbsoluteHumidity();
            if(currAH > highestAH)
                highestAH = currAH;
        }
    }
    cout << "The highest absolute humidity value for that month is: " << highestAH << endl;
    cout << endl;
}

void choiceEight(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    choiceOne(); // get the average temp for specific month and year.

    cout << "The temperature is higher than the average temperature for that month along with values of the temperature: " << endl;
    int countTempHigher = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if(airQualityReport[i].GetDate().GetYear() == inputYear){
            if(airQualityReport[i].GetDate().GetMonth() == inputMonth){
                if(airQualityReport[i].GetTemp() > aveTemp){
                    airQualityReport[i].GetDate().printDate();
                    airQualityReport[i].GetTime().printTime();
                    cout << "Temperature: " << airQualityReport[i].GetTemp() << endl;
                    countTempHigher = countTempHigher + 1;
                }
            }
        }
    }
    cout << "The number of temperature higher than average of that month:" << countTempHigher; // Test the size of result
    cout << endl;

}

void choiceNine(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    choiceTwo();
    cout << "The relative humidity is higher than the average relative humidity for that month along with values of the relative humidity: " << endl;

    int countRHHigher = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if(airQualityReport[i].GetDate().GetYear() == inputYear){
            if(airQualityReport[i].GetDate().GetMonth() == inputMonth){
                if(airQualityReport[i].GetRelativeHumidity() > averageRH){
                    airQualityReport[i].GetDate().printDate();
                    airQualityReport[i].GetTime().printTime();
                    cout << "Relative humidity: " << airQualityReport[i].GetRelativeHumidity() << endl;
                    countRHHigher += 1;
                }
            }
        }
    }
    cout << "The number of RH higher than average of that month: " << countRHHigher; // Test the size of result
    cout << endl;
}

void choiceTen(){
    vector<AirQuality> airQualityReport = generateAirQualityReport("AirQualityUCI.csv");
    choiceThree();

    int countAHHigher = 0;
    for(int i = 0; i < airQualityReport.size(); i++){
        if(airQualityReport[i].GetDate().GetYear() == inputYear){
            if(airQualityReport[i].GetDate().GetMonth() == inputMonth && airQualityReport[i].GetAbsoluteHumidity() > averageAH){
            countAHHigher += 1;
            airQualityReport[i].GetDate().printDate();
            airQualityReport[i].GetTime().printTime();
            cout << "Absolute humidity: " << airQualityReport[i].GetAbsoluteHumidity();
            cout << endl;
            }
        }
    }
    cout << "The number AH higher than average of that month: " << countAHHigher;
    cout << endl;
}

int main(){
    // make choice and display the result
    int choice;
    bool valid = false;
    do{
        showMenu();
        cout << endl;

        do{
        cout << "Your choice is(1-11): " << endl;
        cin >> choice;
        if(cin.good()){
            if(choice >= 1 && choice <= CHOICE11)
                valid = true;
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
                cout << "Please input number from 1 to 11: " << endl;
            }
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This function is used to ignore inputs upto given range.
            cout << "Please input number from 1 to 11: " << endl;
        }
        }while(!valid);

        // Choice 1:
        if(choice == CHOICE1){
            choiceOne();
        }
        // Choice 2:
        else if(choice == CHOICE2){
            choiceTwo();
        }
        // choice 3:
        else if(choice == CHOICE3){
            choiceThree();
        }
        // choice 4:
        else if(choice == CHOICE4){
            choiceFour();
        }
        // choice 5:
        else if(choice == CHOICE5){
            choiceFive();
        }
        // choice 6:
        else if(choice == CHOICE6){
            choiceSix();
        }
        // choice 7:
        else if(choice == CHOICE7){
            choiceSeven();
        }
        // choice 8:
        else if(choice == CHOICE8){
            choiceEight();
        }
        // choice 9:
        else if(choice == CHOICE9){
            choiceNine();
        }
        // choice 10:
        else if(choice == CHOICE10){
            choiceTen();
        }
    }while(choice != CHOICE11); // break out of the menu

    return 0;
}