#pragma once
#include "Hash.h"

///-----------------------
int cin_and_checkFormat_in_interval(double, double);
///-----------------------
string Failo_nuskaitymas(string);
///-----------------------
std::string int_to_hex(uint64_t);
///-----------------------
bool kriterijus();
///-----------------------
vector<string> Failo_eiluciu_nuskaitymas(string);
///-----------------------
string generate_string(size_t);
///-----------------------
void pair_generator(vector<string>&, vector<string>&, int);
///-----------------------
void pair_generator_bits(vector<string>&, vector<string>&, int);
///-----------------------
bool check_hash_uniqueness(int);
///-----------------------
unsigned int countBits(uint64_t);
///-----------------------
void calculateBits(size_t);


int cin_and_checkFormat_in_interval(double a, double b) {
	int input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << std::endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}

string Failo_nuskaitymas(string file_name) {
	string input;
	std::ifstream failas(file_name.c_str());
	if (failas.fail()) throw std::runtime_error("Nera tokio failo."); //jei nera failo

	std::stringstream buffer;
	buffer << failas.rdbuf();

	failas.close();
	return buffer.str();
}

std::string int_to_hex(uint64_t input)
{
	std::stringstream stream;
	stream <<
		std::setfill('0') << std::setw(sizeof(uint64_t) * 2) <<
		std::hex << input;
	return stream.str();
}

bool kriterijus() {
	vector<string> files = {
		"diff_1.txt" , "diff_2.txt", "empty.txt",
		"same_1.txt", "same_2.txt", "single_1.txt",
		"single_2.txt" };
	vector<string> input_arr;
	for (const auto& file : files) {
		input_arr.push_back(Failo_nuskaitymas(file));
	}
	Hash algo{ input_arr };
	algo.hashInput();

	for (const auto& inp : algo.getHash()) {
		if (int_to_hex(inp).length() == 16) {
			std::cout << int_to_hex(inp) << std::endl;
		}
		else {
			return false;
		}
	}
	return true;
}


vector<string> Failo_eiluciu_nuskaitymas(string file_name) {
	vector<string> input_arr;

	std::ifstream failas(file_name.c_str());

	if (failas.fail()) throw std::runtime_error("Nera tokio failo."); //jei nera failo

	string line;
	while (std::getline(failas, line)) {
		input_arr.push_back(line);
		//if ((!(failas >> input) || failas.fail() )) throw std::runtime_error("Blogas failo formatas."); // paieskoma ar formatas failo yra geras
	}
	failas.close();
	return input_arr;

}


string generate_string(size_t length) {
	const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	const size_t max_index = (sizeof(charset) - 1);

	static std::mt19937 gen(0);
	//gen.seed(std::random_device()());
	static std::uniform_int_distribution<int> distr(1, max_index);

	std::string str(length, 0);
	std::generate(str.begin(), str.end(), [&charset, &max_index]() {
		return charset[distr(gen) % max_index];
		});

	return str;
}


void pair_generator(vector<string>& arr_1, vector<string>& arr_2, int size) {
	for (int i = 0; i < size; ++i) {
		arr_1.push_back(generate_string(5));
		arr_2.push_back(generate_string(5));

	}
}

void pair_generator_bits(vector<string>& arr_1, vector<string>& arr_2, int size) {

	for (int i = 0; i < size; ++i) {
		arr_1.push_back(generate_string(4) + 'd');
		arr_2.push_back(generate_string(4) + 'r');

	}
}


bool check_hash_uniqueness(int size) {

	vector<string> arr_1;
	arr_1.reserve(size);
	vector<string> arr_2;
	arr_2.reserve(size);

	pair_generator(arr_1, arr_2, size);


	Hash algo_arr_1{ arr_1 };
	algo_arr_1.hashInput();
	vector<uint64_t> hashed_arr_1 = algo_arr_1.getHash();

	Hash algo_arr_2{ arr_2 };
	algo_arr_2.hashInput();
	vector<uint64_t> hashed_arr_2 = algo_arr_2.getHash();

	
	MAPstring pairs;
	for (int i = 0; i < size; ++i) {
		pairs.insert(MAPstring::value_type(int_to_hex(hashed_arr_1[i]), int_to_hex(hashed_arr_2[i])));
	}
	for (const auto& pair : pairs) { //check for duplicate strings
		if (pair.first == pair.second) {
			std::cout << "Duplicates: " << pair.first << " " << pair.second << std::endl;
			return false;
		}
	}
	return true;
}

unsigned int countBits(uint64_t n)
{
	unsigned int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}




void calculateBits(size_t size) {

	vector<string> arr_1;
	arr_1.reserve(size);
	vector<string> arr_2;
	arr_2.reserve(size);

	pair_generator_bits(arr_1, arr_2, size);


	Hash algo_arr_1{ arr_1 };
	algo_arr_1.hashInput();
	vector<uint64_t> hashed_arr_1 = algo_arr_1.getHash();

	Hash algo_arr_2{ arr_2 };
	algo_arr_2.hashInput();
	vector<uint64_t> hashed_arr_2 = algo_arr_2.getHash();


	MAPuint pairs;
	for (unsigned int i = 0; i < size; ++i) {
		//std::cout << std::hex << hashed_arr_1[i] << "\t" << int_to_hex(hashed_arr_1[i])
		//	<< "|||" << hashed_arr_2[i] << "\t" << int_to_hex(hashed_arr_2[i]) << std::endl;
		pairs.insert(MAPuint::value_type(hashed_arr_1[i], hashed_arr_2[i]));
	}
	unsigned int totalNumberOfBits = 64 * size;
	unsigned int pairBits;

	unsigned int differentBits = 0;
	unsigned int minBits = totalNumberOfBits;
	unsigned int maxBits = 0;
	for (const auto& pair : pairs) { 
		pairBits = countBits(pair.first ^ pair.second);
		if (pairBits > maxBits) {
			maxBits = pairBits;
		}
		else if (pairBits < minBits) {
			minBits = pairBits;
		}
		differentBits += pairBits;
	}

	double averageBits = static_cast<double>(differentBits) / static_cast<double>(totalNumberOfBits);
	double minBitsPercentage = static_cast<double>(minBits) / 64;
	double maxBitsPercentage = static_cast<double>(maxBits) / 64;

	printf("Average bit difference: %.2f%% \n", averageBits * 100);
	printf("Minimum bit difference: %.2f%% \n", minBitsPercentage * 100);
	printf("Maximum bit difference: %.2f%% \n", maxBitsPercentage * 100);
}