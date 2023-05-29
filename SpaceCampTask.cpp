
#include <iostream>
#include <fstream>
#include "Interface.h"

const int MAX_SIZE = 100;

void executeApplication(const char* filePath, const char* emailSender, const char* passwordSender, const char* emailReceiver) {
    Forecast forecast;
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        throw "File cannot be openned";
        return;
    }
    readForecast(inFile, forecast);

    int indexMostAppropriateLaunch = forecast.getMostAppropriateDayIndex();
    if (indexMostAppropriateLaunch < 0) {
        throw "Not found possible day launch";
        return;
    }
    int dayLaunch = forecast.getDay(indexMostAppropriateLaunch)->getNumOfDay();
    const char* newFileName = "WeatherReport.csv";
    if (saveForecastToFile(forecast, newFileName) == 0) {
        if (sendEmail(forecast, filePath, emailSender, passwordSender, emailReceiver) == 0) {
            std::cout << "Successfully sent email";
            return;
        }
        else {
            throw "Not able to send an email";
            return;
        }
    }
    else {
        throw "Not able to create weather report";
        return;
    }
}


int main()
{
    char filePath [MAX_SIZE];
    char emailSender [MAX_SIZE];
    char passwordSender [MAX_SIZE];
    char emailReceiver [MAX_SIZE];

    std::cout << "Enter file path: ";
    std::cin >> filePath;

    std::cout << "Enter email of sender: ";
    std::cin >> emailSender;

    std::cout << "Enter password of sender: ";
    std::cin >> passwordSender;

    std::cout << "Enter email of receiver: ";
    std::cin >> emailReceiver;

    executeApplication(filePath, emailSender,passwordSender, emailReceiver);
    return 0;
}

