// System includes
#include <fstream>
#include <iostream>

// Project includes
#include <json.hpp>

using namespace nlohmann;

int main() {
    std::ifstream ifs( "test.json" );

    // create JSON object
    json object = json::parse( ifs );

    // output element with key "the ugly"
    std::cout << "Printing out 'the ugly' using bracket syntax" << std::endl;
    std::cout << object[ "the ugly" ] << '\n';

    // change element with key "the bad"
    std::cout << "Changing 'the bad' to something else using 'at' method" << std::endl;
    object.at( "the bad" ) = "il cattivo";

    // output changed array
    std::cout << "Printing the whole JSON" << std::endl;
    std::cout << object << '\n';

    // try to write at a nonexisting key
    try {
        object.at("the fast") = "il rapido";
    } catch ( std::out_of_range& e ) {
        std::cout << "out of range: " << e.what() << '\n';
    }

    return 0;
}
