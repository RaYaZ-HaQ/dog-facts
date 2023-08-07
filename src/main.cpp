#include <cstdlib>
#include <string>
#include "httplib.h"
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main (int argc, char *argv[]) {

	if (argc > 2) {
		std::cerr << "Usage: dogfacts [number]";
		exit(EXIT_FAILURE);
	}
	
	std::string number = "1"; // The number of facts to pull
	if (argc == 2) {
		number = argv[1];
	}

	std::string host = "http://dog-api.kinduff.com";

	httplib::Client client(host);
	client.set_follow_location(true); // Follow redirects
	
	std::string resource = "/api/facts?number=" + number;
	auto res = client.Get(resource);

	json data = json::parse(res->body);

	for (size_t i; i < data["facts"].size(); ++i) {
		std::cout << i+1 << '\t' << data["facts"][i].get<std::string>() << '\n';
	}

	return 0;
}
