#include <fstream>
#include <iostream>
#include "MyClass.hpp"


void save(const MyClass &s, const char *filename) {
    std::ofstream ofs(filename);
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}

void load(MyClass &s, const char *filename) {
    std::ifstream ifs(filename);
    boost::archive::xml_iarchive ia(ifs);
    ia >> BOOST_SERIALIZATION_NVP(s);
}

int main() {
    MyClass obj(1, "example");
    const char *filename = "myclass.xml";

    // Serialize
    save(obj, filename);

    // Deserialize
    MyClass new_obj;
    load(new_obj, filename);

    std::cout << "Deserialized Object:" << std::endl;
    std::cout << "Member1: " << new_obj.member1 << std::endl;
    std::cout << "Member2: " << new_obj.member2 << std::endl;

    return 0;
}
