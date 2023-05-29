#include "Interface.h"
#include <fstream>


void readForecast(std::ifstream& file, Forecast& forecast) {
	while (!file.eof()) {
		char buff[1024];
		file.getline(buff, 1024);
		readParameter(buff, forecast);
	}
	resetToStart(file);
}
void readParameter(const char* input, Forecast& forecast) {
	size_t index = 0;
	char buffer[100];
	while (input[index] != ',') {
		buffer[index] = input[index];
		index++;
	}
	index++;
	buffer[index] = '\n';
	index++;
	size_t indPar = 0;
	size_t counter = 0;
	char* par = new char[50];
	if (strcmp(buffer, "Day/Parameter")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				int info = atoi(par);
				forecast.setNumDay(counter, info);
				counter++;
				delete[] par;
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Temperature(C)")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				int info = atoi(par);
				forecast.setTempToDay(counter, info);
				counter++;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Wind(m/s)")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				int info = atoi(par);
				forecast.setWindToDay(counter, info);
				counter++;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Humidity(%)")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				int info = atoi(par);
				forecast.setHumToDay(counter, info);
				counter++;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Precipitation(%)")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				int info = atoi(par);
				forecast.setPrecipToDay(counter, info);
				counter++;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Lightning")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				bool info = false;
				if (strcmp(par, "YES"))
					info = true;
				forecast.setLightToDay(counter, info);
				counter++;
				char* temp = new char[50];
				temp = par;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}
	else if (strcmp(buffer, "Clounds")) {
		while (input[index] != '\n') {
			if (input[index] == ',') {
				index++;
				indPar = 0;
				std::string info = par;
				forecast.setCloudsToDay(counter, info);
				counter++;
				delete[] par;
				char* par = new char[50];
			}
			par[indPar] = input[index];
			index++;
		}
	}

}

int countLines(std::ifstream& file) {
	size_t counter = 0;
	while (!file.eof()) {
		char buffer[1024];
		file.getline(buffer, 1024);
		counter++;
	}
	resetToStart(file);
	return counter - 1;
}
void resetToStart(std::ifstream& file) {
	file.clear();
	file.seekg(0, std::ios::beg);
}
bool saveForecastToFile(Forecast& forecast, const char* fileName) {
	std::ofstream out(fileName, std::ios::trunc);

	if (!out.is_open())
		return false;
	out << "Day/Parameter" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getNumOfDay() << ",";
	}
	out << "Average" << "," << "Max" << "," << "Min" << "," << "Median" << "," << "Most appropriate launch day value" << std::endl;
	
	size_t indMostAppropriate = forecast.getMostAppropriateDayIndex();
	out << "Temperature(C)" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getTemp() << ",";
	}
	out << forecast.getAvgTemp() << "," << forecast.getMaxTemp() << "," << forecast.getMinTemp() << "," << forecast.getMedianTemp() << "," << forecast.getDay(indMostAppropriate)->getTemp() << std::endl;

	out << "Wind(m/s)" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getWind() << ",";
	}
	out << forecast.getAvgWind() << "," << forecast.getMaxWind() << "," << forecast.getMinWind() << "," << forecast.getMedianWind() << "," << forecast.getDay(indMostAppropriate)->getWind() << std::endl;

	out << "Humidity(%)" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getHumidity() << ",";
	}
	out << forecast.getAvgHum() << "," << forecast.getMaxHum() << "," << forecast.getMinHum() << "," << forecast.getMedianHum() << "," << forecast.getDay(indMostAppropriate)->getHumidity() << std::endl;

	out << "Precipitation(%)" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getPrecip() << ",";
	}
	out << forecast.getAvgPrecip() << "," << forecast.getMaxPrecip() << "," << forecast.getMinPrecip() << "," << forecast.getMedianPrecip() << "," << forecast.getDay(indMostAppropriate)->getPrecip() << std::endl;

	out << "Lightning" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		if (forecast.getDay(i)->getLightning() == 0)
			out << "No" << ",";
		else
			out << "Yes" << ",";
	}
	out << "-" << "," << "-" << "," << "-" << "," << "-" << ",";
	if (forecast.getDay(indMostAppropriate)->getLightning() == 0)
		out << "No" << std::endl;
	else
		out << "Yes" << std::endl;

	out << "Clouds" << ",";
	for (size_t i = 0; i < forecast.getSize(); i++) {
		out << forecast.getDay(i)->getClouds() << ",";
	}
	out << "-" << "," << "-" << "," << "-" << "," << "-" << ",";
	out << forecast.getDay(indMostAppropriate)->getClouds() << std::endl;

	out.close();
	return true;
}

bool sendEmail(Forecast& forecast, const char* filePath, const char* emailSender, const char* passwordSender, const char* emailReceiver) {
	int index = forecast.getMostAppropriateDayIndex();
	int numOfDay = forecast.getDay(index)->getNumOfDay();
	//code to send an email
	return true;
}