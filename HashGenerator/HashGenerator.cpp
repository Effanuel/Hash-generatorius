#include "Hash.h"

template <typename T=int> T cin_and_checkFormat_in_interval(double, double);
template <typename T=string> T Failo_nuskaitymas(string);


std::string int_to_hex(const int input) {

	std::stringstream stream;
	stream << "0x" << std::setfill('0') << std::setw(sizeof(string) * 1)
		<< std::hex << input;

	return stream.str();
}


int main()
{
	int choice;
	std::cout << "Programa hash'ina jusu pasirinkta simboliu eilute\n" << std::string(40, '=') << std::endl;
	std::cout << "1 - Ivesti data rankomis;\n2 - Skaityti data is failo \"input.txt\";\n4 - Testai;\n" << std::string(40, '=') << std::endl;
	choice = cin_and_checkFormat_in_interval(1, 3);

	Hash algo;
	string input;
	try {
		switch (choice) {
		case 1: {
			cin >> input;
			algo.setInput(input);
			algo.hashIt();
			break;
		}
		case 2: {
			input = Failo_nuskaitymas("input.txt");
			algo.setInput(input);
			algo.hashIt();
			break;
		}
		case 3:
		default:
			std::cout << "Nepavyko pasirinkti." << std::endl;
			break;
		}
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}

	Hash algo22("LabaS");
	algo.hashIt();
	std::cout << std::hex << algo22.getHash() << std::endl;

	Hash algo1("labaS");
	algo1.hashIt();
	std::cout << std::hex << algo1.getHash() << std::endl;
}




template <typename T> T cin_and_checkFormat_in_interval(double a, double b) {
	T input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << std::endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}

template <typename T> T Failo_nuskaitymas(string file_name) {
	string input{};

	std::ifstream failas(file_name.c_str());

	if (failas.fail()) throw std::runtime_error("Nera tokio failo."); //jei nera failo

	double balas_temp;
	while (!failas.eof()) {
		if ((!(failas >> input) || failas.fail() )) throw std::runtime_error("Blogas failo formatas."); // paieskoma ar formatas failo yra geras
	}
	failas.close();
	return input;

}
