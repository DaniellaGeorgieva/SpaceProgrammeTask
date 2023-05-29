#include "Day.h"

Day::Day() {
	numOfDay = 0;
	temperature = 0;
	wind = 0;
	humidity = 0;
	precipitation = 0;
	lightning = false;
	clouds = "\n";

}
Day::Day(int numOfDay, int temperature, int wind, unsigned int humidity, unsigned int precipitation, bool lightning, std::string clouds) {
	this->numOfDay = numOfDay;
	this->temperature = temperature;
	this->wind = wind;
	this->humidity = humidity;
	this->precipitation = precipitation;
	this->lightning = lightning;
	this->clouds = clouds;
}
Day::Day(const Day& day) {
	copyFrom(day);
}
Day& Day::operator=(const Day& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}
Day::~Day() = default;

const int Day::getNumOfDay() const {
	return numOfDay;
}
const int Day::getTemp() const {
	return temperature;
}
const int Day::getWind() const {
	return wind;
}
const unsigned int Day::getHumidity() const {
	return humidity;
}
const unsigned int Day::getPrecip() const {
	return precipitation;
}
bool Day::getLightning() const {
	return lightning;
}
std::string Day::getClouds() const {
	return clouds;
}

void Day::setNum(int info) {
	this->numOfDay = info;
}
void Day::setTemp(int info) {
	temperature = info;
}
void Day::setWind(int info) {
	wind = info;
}
void Day::setHum(unsigned int info) {
	humidity = info;
}
void Day::setPrecip(unsigned int info) {
	precipitation = info;
}
void Day::setL(bool info) {
	lightning = info;
}
void Day::setClouds(std::string info) {
	clouds = info;
}

void Day::copyFrom(const Day& other) {
	this->numOfDay = other.numOfDay;
	this->temperature = other.temperature;
	this->wind = other.wind;
	this->humidity = other.humidity;
	this->precipitation = other.precipitation;
	this->lightning = other.lightning;
	this->clouds = other.clouds;
}

Day* Day::clone() const {
	return new Day(*this);
}

std::ostream& operator<<(std::ostream& os, const Day& day) {
	os << day.numOfDay << day.temperature << day.wind << day.humidity << day.precipitation << day.lightning << day.clouds;
	return os;
}
std::istream& operator>>(std::istream& is, Day& day) {
	is >> day.numOfDay >> day.temperature >> day.wind >> day.humidity >> day.precipitation >> day.lightning >> day.clouds;
	return is;
}