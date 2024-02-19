#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

class MyClass {
private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(member1);
        ar & BOOST_SERIALIZATION_NVP(member2);
    }


public:
    int member1;
    std::string member2;

    MyClass();
    MyClass(int m1, std::string m2);
};

#endif // MYCLASS_HPP
