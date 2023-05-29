#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Day {
private:
	int numOfDay;
	int temperature;
	int wind;
	unsigned int humidity;
	unsigned int precipitation;
	bool lightning;
	std::string clouds;


public:
	Day();
	Day(int, int, int, unsigned int, unsigned int, bool, std::string);
	Day(const Day&);
	Day& operator=(const Day&);
	~Day();

	const int getNumOfDay() const;
	const int getTemp() const;
	const int getWind() const;
	const unsigned int getHumidity() const;
	const unsigned int getPrecip() const;
	bool getLightning() const;
	std::string getClouds() const;

	void setNum(int info);
	void setTemp(int info);
	void setWind(int info);
	void setHum(unsigned int info);
	void setPrecip(unsigned int info);
	void setL(bool info);
	void setClouds(std::string info);

	Day* clone() const;

	friend std::ostream& operator<<(std::ostream& os, const Day& day);
	friend std::istream& operator>>(std::istream& is, Day& day);
private:
	void copyFrom(const Day&);
};