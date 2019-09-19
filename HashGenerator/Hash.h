#include "Header.h"



class Hash {
private:
	vector<unsigned long long> CONSTANTS = {
		0xab5722731751f35f, 0xd15ae0dfe36be708, 0xb4716cfb00ef9fa5,
		0x52522227a83e3794, 0xedf51b1025ab4b73, 0xac681f0491e880ae,
		0x37bb06739ddc1e6c, 0xa3d99386e02723d0, 0xee98570b0a2c86c0
	};
	string input_;
	string hashedInput_;
	unsigned long long hash_;

	int __getTotal() {
		return std::accumulate(input_.begin(), input_.end(), 0);
	}

	void __shiftHash(int shiftNumber) {
		hash_ <<= shiftNumber;
	}
	void __xorHash(char key) {
		string xored = "";
		for (unsigned int i = 0; i < input_.size(); ++i) {
			xored += input_[i] ^ (int(key) + i) % 255;
		}
		input_ = xored;
	}


public:
	Hash() : input_(""), hash_(CONSTANTS[__getTotal() % 9]) {}
	Hash(string input) : input_(input), hash_(CONSTANTS[__getTotal() % 9]) {}

	unsigned long long getHash() const {
		return hash_;
	}

	void hashIt() {
		std::cout << input_ << std::endl;
		char xorChar = (__getTotal() % 9) + 60;
		__xorHash(xorChar);
		std::cout << input_ << std::endl;
		int shiftNumber = 2;
		__shiftHash(shiftNumber);
	}
	void setInput(string input) {
		input_ = input;
	}


};