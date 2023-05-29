#pragma once
#include "Forecast.h"


void readForecast(std::ifstream& file, Forecast& forecast);
void readParameter(const char* input, Forecast& forecast);
int countLines(std::ifstream& file);
void resetToStart(std::ifstream& file);
bool saveForecastToFile(const Forecast& forecast, const char* fileName);
bool sendEmail(Forecast& forecast, const char* filePath, const char* emailSender, const char* passwordSender, const char* emailReceiver);

