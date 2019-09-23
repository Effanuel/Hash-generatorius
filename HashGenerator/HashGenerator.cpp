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
	if (argc > 1) {
		input = Failo_nuskaitymas(argv[1]);
		input_arr.push_back(input);
		Hash algo{ input_arr };
		algo.hashInput();

		std::cout << "Failo " << string(argv[1]) << " hash'intos eilutes:\n" << std::string(40, '=') << std::endl;
		for (const auto& line : algo.getHash()) {
			std::cout << std::hex << line << std::endl;
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

		
		try {
			switch (choice) {
			case 1: {
				string input;
				std::cout << "Iveskite string'a (be tarpu):" << std::endl;
				cin >> input;

				Hash algo{ {input} };
				algo.hashInput();
				
				std::cout << std::hex << algo.getHash()[0] << std::endl;
				break;
			}
			case 2: {
				
				std::cout << "Iveskite failo pavadinima:" << std::endl;
				
				string file_name;
				cin >> file_name;

				string input;
				input = Failo_nuskaitymas(file_name);
				input_arr.push_back(input);

				Hash algo{ input_arr };
				algo.hashInput();
				for (const auto& line : algo.getHash()) {
					std::cout << std::hex << line << std::endl;
				}
				break;
			}
			case 3: {
				input_arr = Failo_eiluciu_nuskaitymas("konstitucija.txt");	
				Hash algo{ input_arr };

				Timer laikas;
				algo.hashInput(); // matuojame hash'inimo laika
				std::cout << "Failo 'konstitucija.txt' eiluciu hash'inimas:\n" << laikas.elapsed() << " s" << std::endl; //end
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
				if (check_hash_uniqueness(10)) {

					std::cout << "OK." << std::endl;
					break;
				}
				std::cout << "NOT OK." << std::endl;
				break;
			}
			case 6: {
				calculateBits(1e6);
				break;
			}
			default:
				std::cout << "Nepavyko pasirinkti." << std::endl;
				break;
			}
		} catch (const std::runtime_error& e) {
			std::cout << e.what() << std::endl;
			exit(0);
		}
	}

	//vector<string> input = { "Labas" };
	//Hash algo22("a");
	//algo22.__xorInput('x');
	//std::ostringstream stream;
	//stream <<std::hex<< algo22.getHash()[0];
	//std::cout << stream.str() << std::endl;

	//Hash algo23("ab");
	//algo23.hashInput('x');
	//for (const auto& a : algo23.getHash()) {
	//	std::cout << std::hex << a << std::endl;
	//}

	//Hash algo22("aa");
	//algo22.hashInput('x');
	//for (const auto& a : algo22.getHash()) {
	//	std::cout << std::hex << a << std::endl;
	//}

}