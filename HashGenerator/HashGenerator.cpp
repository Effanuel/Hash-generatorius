#include "Header.h"




int main(int argc, char *argv[])
{
	//vector<string> arr_1;
	//vector<string> arr_2;
	//pair_generator(arr_1, arr_2, 1000000);
	//std::cout << "done" << std::endl;
	////for (const auto& a: arr_1) {
	////	std::cout << a << std::endl;
	////}
	////for (const auto& b : arr_2) {
	////	std::cout << b << std::endl;
	////}
	vector<string> input_arr;
	string input;
	try {
		if (argc > 1) {
			if (string(argv[1]) == "konstitucija.txt") {
				printHashSpeed("konstitucija.txt");
			}
			else {
				for (int i = 1; i < argc; ++i) {
					if (isFileName(string(argv[i]), ".txt")) {
						printFileHash(string(argv[i]));
					}
					else {
						printStringHash(string(argv[i]));
					}
				}
			}

		}
		else if (argc == 1) {
			std::cout << "Programa hash'ina jusu pasirinkta simboliu eilute(s)\n" << std::string(40, '=') << std::endl;
			std::cout <<
				"1 - Ivesti data rankomis;\n"
				"2 - Hash'inti faila;\n"
				"3 - Efektyvumas;\n"
				"4 - Kriterijus;\n"
				"5 - Reikalavimas 6;\n"
				"6 - Reikalavimas 7;\n" << std::string(40, '=') << std::endl;

			int choice;
			choice = cin_and_checkFormat_in_interval(1, 6);

			switch (choice) {
			case 1: {
				string input;
				std::cout << "Iveskite string'a (be tarpu):" << std::endl;
				cin >> input;
				printStringHash(input);
				break;
			}
			case 2: {

				std::cout << "Iveskite failo pavadinima:" << std::endl;

				string file_name;
				cin >> file_name;
				printFileHash(file_name);
				break;
			}
			case 3: {
				printHashSpeed("konstitucija.txt");
				break;
			}
			case 4: {
				if (kriterijus()) {
					std::cout << "OK." << std::endl;
					break;
				}
				std::cout << "NOT OK." << std::endl;
				break;
			}
			case 5: {
				if (check_hash_uniqueness(1e6)) {
					std::cout << "OK." << std::endl;
					break;
				}
				std::cout << "NOT OK." << std::endl;
				break;
			}
			case 6: {
				std::cout << "Total bits per hash: 64" << std::endl;
				calculateBits(1e6);
				break;
			}
			default:
				std::cout << "Nepavyko pasirinkti." << std::endl;
				break;
			}
		}
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(0);
	}
}