#include "Header.h"

#include <iostream>
#include <iomanip>

std::string int_to_hex(const int input) {

	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(string) * 1)
		<< std::hex << input;

	return stream.str();
}

class Hash {
private:
	vector<unsigned long long> CONSTANTS = {
		0xab5722731751f35f, 0xd15ae0dfe36be708, 0xb4716cfb00ef9fa5,
		0x52522227a83e3794, 0xedf51b1025ab4b73, 0xac681f0491e880ae,
		0x37bb06739ddc1e6c, 0xa3d99386e02723d0, 0xee98570b0a2c86c0
	};
	string input;
	unsigned long long hash;

	int __getTotal() {
		return std::accumulate(input.begin(), input.end(), 0);
	}

	void __shiftHash(int shiftNumber) {
		hash <<= shiftNumber;
	}
	void __xorHash(char key) {
		string xored = "";
		for (int i = 0; i < input.size(); ++i) {
			xored += input[i] ^ (int(key) + i) % 255;
		}
		input = xored;
	}
	

public:
	Hash(string input) : input(input), hash(CONSTANTS[__getTotal() % 9]) {}

	unsigned long long getHash() const {
		return hash;
	}

	void hashIt() {
		std::cout << input << std::endl;
		char xorChar = (__getTotal() % 9) + 60;
		__xorHash(xorChar);
		std::cout << input << std::endl;
		int shiftNumber = 2;
		__shiftHash(shiftNumber);


	}


};


int main()
{
	Hash algo("LabaS");
	algo.hashIt();
	std::cout << std::hex << algo.getHash() << std::endl;

	Hash algo1("labaS");
	algo1.hashIt();
	std::cout << std::hex << algo1.getHash() << std::endl;
	//long long hex = 0xa3d99386e02723d0;
	//int value = 0;
	//std::cout << hex << std::endl;
	//hex <<= 1;
	//std::cout << hex << std::endl;
	//std::cout << int_to_hex(value) << std::endl;
}
