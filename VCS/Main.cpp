#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	//fs::current_path(fs::temp_directory_path());
	//std::cout << "Entered..:" << argc << std::endl;
	//std::cout << argv[1] << std::endl;
	// Easy-mode    
	std::vector<std::string> args(argv, argv + argc);
	//for (size_t i = 1; i < args.size(); ++i) {
	//	if (args[i] == "yes") {
			// do something
	//	}
	//}
	if (args[1] == "init") {
		// Directory already exists (false returned, no error)
		//assert(!fs::create_directory(".git"));
		fs::create_directory(".git");
		fs::create_directory(".git/objects");
		fs::create_directory(".git/refs");
		std::ofstream o(".git/HEAD");
		o << "ref: refs/heads/master\n";
		std::cout << "Intialized git directory" << std::endl;
	}
	else {
		std::cout << "Unknown command: " << args[1]<<std::endl;
	}
	return 0;
}