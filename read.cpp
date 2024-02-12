#include <msgpack.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include<complex>
#include <Eigen/Dense>
#include <tuple>

int main(){
//read EAll
//std::ifstream  inF("EAll",std::ios::in|std::ios::binary);
//std::stringstream sEAll;
//sEAll<<inF.rdbuf();
//inF.close();
//
//std::string contentEAll=sEAll.str();
//msgpack::object_handle oh=msgpack::unpack(contentEAll.data(),contentEAll.size());
//    msgpack::object deserialized = oh.get();
//    auto vec=deserialized.as<std::vector<double>>();
//    for (auto elem : vec){
//        std::cout<<elem*3.1<<",";
//    }
//    std::cout<<std::endl;


//read sAll
//std::ifstream inF("sAll",std::ios::in|std::ios::binary);
//    std::stringstream ssAll;
//    ssAll<<inF.rdbuf();
//    inF.close();
//    std::string contentsAll=ssAll.str();
//    msgpack::object_handle oh=msgpack::unpack(contentsAll.data(),contentsAll.size());
//    msgpack::object deserialized = oh.get();;
//    auto vecvec=deserialized.as<std::vector<std::vector<double>>>();
//
//    for (const auto &vec : vecvec){
//        double sum=0;
//        for (auto s: vec){
//            sum+=s;
//        }
//        std::cout<<"total spin is "<<sum<<std::endl;
//    }

// read vector<tuple>
    std::ifstream inF("vectp",std::ios::in|std::ios::binary);
    std::stringstream vectpAll;
    vectpAll<<inF.rdbuf();
    inF.close();
    std::string contentvectpAll=vectpAll.str();
    msgpack::object_handle oh=msgpack::unpack(contentvectpAll.data(),contentvectpAll.size());
    msgpack::object deserialized = oh.get();
    auto vectp=deserialized.as<std::vector<std::tuple<int, std::vector<double>, std::vector<std::complex<double>>>>>();

    auto tp0=vectp[0];
    std::cout<<std::get<0>(tp0)<<std::endl;
    for(auto elem : std::get<1>(tp0)){
        std::cout<<elem<<",";
    }
    std::cout<<std::endl;

}