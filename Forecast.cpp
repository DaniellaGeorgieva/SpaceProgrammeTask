#include "Forecast.h"
#include <vector>
#include <algorithm>

Forecast::Forecast() {
	capacity = 15;
	size = 0;
	days = new Day * [capacity];
}
Forecast::Forecast(const Forecast& other) {
	copy(other);
}
Forecast& Forecast::operator=(const Forecast& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}
Forecast::~Forecast() {
	free();
}

void Forecast::addDay(Day& newDay) {
	if (size >= capacity) {
		resize();
	}
	days[size++] = newDay.clone();
}

Day* Forecast::getDay(size_t index) {
	return days[index];
}
//void Forecast::readDay(const char* input, Day& day) {
//
//}
//void Forecast::readDays(std::ifstream& file, Day* daysCollection, size_t daysCount) {
//
//}

size_t Forecast::getSize() const {
	return this->size;
}

int Forecast::getAvgTemp() const {
	int avgTemp = 0;
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += days[i]->getTemp();
	}
	avgTemp = (sum / size);
	return avgTemp;
}
int Forecast::getMaxTemp() const {
	int max = 0;
	for (size_t i = 0; i < size; i++) {
		if (days[i]->getTemp() > max) {
			max = days[i]->getTemp();
		}
	}
	return max;
}
int Forecast::getMinTemp() const {
	int min = days[0]->getTemp();
	for (size_t i = 1; i < size; i++) {
		if (days[i]->getTemp() < min) {
			min = days[i]->getTemp();
		}
	}
	return min;
}
int Forecast::getMedianTemp() const {
	std::vector<unsigned int> temp;
	for (size_t i = 0; i < size; i++) {
		temp.push_back(days[i]->getTemp());
	}
	sort(temp.begin(), temp.end());
	unsigned int median = 0;
	int idx = 0;
	idx = size / 2;
	if (size % 2 == 0) {
		median = (temp.at(idx) + temp.at(idx + 1)) / 2;
	}
	else {
		median = temp.at(idx);
	}
	return median;
}
//int Forecast::getMostAppropriateLaunchTemp() const {
//
//}

int Forecast::getAvgWind() const {
	int avgWind = 0;
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += days[i]->getWind();
	}
	avgWind = (sum / size);
	return avgWind;
}
int Forecast::getMaxWind() const {
	int max = 0;
	for (size_t i = 0; i < size; i++) {
		if (days[i]->getWind() > max) {
			max = days[i]->getWind();
		}
	}
	return max;
}
int Forecast::getMinWind() const {
	int min = days[0]->getWind();
	for (size_t i = 1; i < size; i++) {
		if (days[i]->getWind() < min) {
			min = days[i]->getWind();
		}
	}
	return min;
}
int Forecast::getMedianWind() const {
	std::vector<unsigned int> temp;
	for (size_t i = 0; i < size; i++) {
		temp.push_back(days[i]->getWind());
	}
	sort(temp.begin(), temp.end());
	unsigned int median = 0;
	int idx = 0;
	idx = size / 2;
	if (size % 2 == 0) {
		median = (temp.at(idx) + temp.at(idx + 1)) / 2;
	}
	else {
		median = temp.at(idx);
	}
	return median;
}
//int Forecast::getMostAppropriateLaunchWind() const {
//
//}

unsigned int Forecast::getAvgHum() const {
	unsigned int avgHum = 0;
	unsigned int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += days[i]->getHumidity();
	}
	avgHum = (sum / size);
	return avgHum;
}
unsigned int Forecast::getMaxHum() const {
	unsigned int max = 0;
	for (size_t i = 0; i < size; i++) {
		if (days[i]->getHumidity() > max) {
			max = days[i]->getHumidity();
		}
	}
	return max;
}
unsigned int Forecast::getMinHum() const {
	unsigned int min = days[0]->getHumidity();
	for (size_t i = 1; i < size; i++) {
		if (days[i]->getHumidity() < min) {
			min = days[i]->getHumidity();
		}
	}
	return min;
}
unsigned int Forecast::getMedianHum() const {
	std::vector<unsigned int> temp;
	for (size_t i = 0; i < size; i++) {
		temp.push_back(days[i]->getHumidity());
	}
	sort(temp.begin(), temp.end());
	unsigned int median = 0;
	int idx = 0;
	idx = size / 2;
	if (size % 2 == 0) {
		median = (temp.at(idx) + temp.at(idx + 1)) / 2;
	}
	else {
		median = temp.at(idx);
	}
	return median;
}
//unsigned int Forecast::getMostAppropriateLaunchHum() const {
//
//}

unsigned int Forecast::getAvgPrecip() const {
	unsigned int avgPrecip = 0;
	unsigned int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += days[i]->getPrecip();
	}
	avgPrecip = (sum / size);
	return avgPrecip;
}
unsigned int Forecast::getMaxPrecip() const {
	unsigned int max = 0;
	for (size_t i = 0; i < size; i++) {
		if (days[i]->getPrecip() > max) {
			max = days[i]->getPrecip();
		}
	}
	return max;
}
unsigned int Forecast::getMinPrecip() const {
	unsigned int min = days[0]->getPrecip();
	for (size_t i = 1; i < size; i++) {
		if (days[i]->getPrecip() < min) {
			min = days[i]->getPrecip();
		}
	}
	return min;
}
unsigned int Forecast::getMedianPrecip() const {
	std::vector<unsigned int> temp;
	for (size_t i = 0; i < size; i++) {
		temp.push_back(days[i]->getPrecip());
	}
	sort(temp.begin(), temp.end());
	int median = 0;
	size_t idx = 0;
	idx = size / 2;
	if (size % 2 == 0) {
		median = (temp.at(idx) + temp.at(idx + 1)) / 2;
	}
	else {
		median = temp.at(idx);
	}
	return median;
}
//unsigned int Forecast::getMostAppropriateLaunchPrecip() const {
//
//}
//
//unsigned int Forecast::getMostAppropriateLaunchLightning() const {
//
//}
//
//unsigned int Forecast::getMostAppropriateLaunchClouds() const {
//
//}

bool Forecast::checkTemp(size_t index) const {
	if (days[index]->getTemp() > 2 && days[index]->getTemp() <= 31)
		return true;
	else
		return false;

}
bool Forecast::checkWind(size_t index) const {
	if (days[index]->getWind() <= 10)
		return true;
	else
		return false;
}
bool Forecast::checkHum(size_t index) const {
	if (days[index]->getHumidity() > 60)
		return true;
	else
		return false;
}
bool Forecast::checkPrecip(size_t index) const {
	if (days[index]->getPrecip() == 0)
		return true;
	else
		return false;
}
bool Forecast::checkLightning(size_t index) const {
	if (days[index]->getLightning() == 0)
		return true;
	else
		return false;
}
bool Forecast::checkClouds(size_t index) const {
	if (days[index]->getClouds() != "cumulus" && days[index]->getClouds() != "numbus")
		return true;
	else
		return false;

}

size_t Forecast::getMostAppropriateDayIndex() const {
	size_t index = 0;
	std::vector<int> possible;
	for (size_t i = 0; i < size; i++) {
		if (checkTemp(i) == 1 && checkPrecip(i) == 1 && checkLightning(i) == 1 && checkClouds(i) == 1) {
			if (checkWind(i) == 1 && checkHum(i))
				possible.push_back(i);
		}
	}
	if (possible.size() == 1) {
		return possible.at(0);
	}
	else if (possible.size() == 0) {
		throw std::logic_error("Not found an appropriate index");
		return -1;
	}
	else {
		size_t minWind = 0;
		size_t minHum = 0;
		for (size_t i = 0; i < possible.size(); i++) {
			if (days[i]->getWind() < days[minWind]->getWind()) {
				minWind = i;
			}
			if (days[i]->getHumidity() < days[minWind]->getHumidity()) {
				minHum = i;
			}
		}
		if (minHum != minWind) {
			//not sure about it
			return minHum;
		}
		else {
			return minWind;
		}
	}
	
}

void Forecast::setNumDay(size_t index, int info) {
	days[index]->setNum(info);
}
void Forecast::setTempToDay(size_t index, int info) {
	days[index]->setTemp(info);
}
void Forecast::setWindToDay(size_t index, int info) {
	days[index]->setWind(info);
}
void Forecast::setHumToDay(size_t index, int info) {
	days[index]->setHum(info);
}
void Forecast::setPrecipToDay(size_t index, int info) {
	days[index]->setPrecip(info);
}
void Forecast::setLightToDay(size_t index, bool info) {
	days[index]->setL(info);
}
void Forecast::setCloudsToDay(size_t index, std::string info) {
	days[index]->setClouds(info);
}

void Forecast::resize() {
	Day** daysTemp = new Day * [capacity * 2];
	for (size_t i = 0; i < size; i++) {
		daysTemp[i] = days[i];
	}
	delete[] days;
	days = daysTemp;
	daysTemp = nullptr;
}

void Forecast::copy(const Forecast& other) {
	capacity = other.capacity;
	size = other.size;
	days = new Day*[capacity];

	for (size_t i = 0; i < size; i++) {
		days[i] = other.days[i];
	}
}

void Forecast::free() {
	for (size_t i = 0; i < size; i++) {
		delete days[i];
	}
	delete[] days;
}

