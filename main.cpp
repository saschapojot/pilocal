#include <msgpack.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <Eigen/Dense>
#include <tuple>
#include<complex>
#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Eigenvalues>

using mat20c = Eigen::Matrix<std::complex<double>, 20, 20>;
using eigVal20 = Eigen::SelfAdjointEigenSolver<mat20c>::RealVectorType;
using vecVal20 = Eigen::SelfAdjointEigenSolver<mat20c>::EigenvectorsType;

int main() {

    //output a vector
//    std::vector<double> EAll{0.1,-10,9.1,4.3};
//    std::ofstream outF("EAll",std::ios::out| std::ios::binary);
//
//    msgpack::pack(outF,EAll);
//    outF.seekp(0);
//    outF.close();

//output vector within vector
//std::vector<std::vector<double>>sAll={{-1,1},{1,1},{-1,-1}};
//std::ofstream outF("sAll",std::ios::out| std::ios::binary);
//msgpack::pack(outF,sAll);
//outF.seekp(0);
//outF.close();


//output vector<tuple>
    Eigen::SelfAdjointEigenSolver<mat20c> esA;
    Eigen::SelfAdjointEigenSolver<mat20c> esB;
    mat20c X = mat20c::Random(20, 20);
    mat20c Y = mat20c::Random(20, 20);
    mat20c A = X + X.transpose().conjugate();
    mat20c B = Y + Y.transpose().conjugate();
    esA.compute(A);
    esB.compute(B);
    eigVal20 valsA = esA.eigenvalues();
    vecVal20 vecsA = esA.eigenvectors();
    std::vector<double> stdVecValsA;
    std::vector<std::complex<double>>stdVectorizedEigVecA;
    for(auto x: valsA){
        stdVecValsA.emplace_back(x);
    }
    for(auto x:A.reshaped()){
        stdVectorizedEigVecA.emplace_back(x);
    }


    eigVal20 valsB = esB.eigenvalues();
    vecVal20 vecsB = esB.eigenvectors();
    std::vector<double> stdVecValsB;
    std::vector<std::complex<double>>stdVectorizedEigVecB;
    for(auto x: valsB){
        stdVecValsB.emplace_back(x);
    }
    for(auto x:B.reshaped()){
        stdVectorizedEigVecB.emplace_back(x);
    }


    std::tuple<int, std::vector<double>, std::vector<std::complex<double>>> tpA = std::make_tuple(10, stdVecValsA, stdVectorizedEigVecA);

    std::tuple<int, std::vector<double>, std::vector<std::complex<double>>> tpB = std::make_tuple(15, stdVecValsB, stdVectorizedEigVecB);
    std::vector<std::tuple<int, std::vector<double>, std::vector<std::complex<double>>>> outVecTp = {tpA, tpB};

    std::ofstream outF("vectp", std::ios::out | std::ios::binary);
    msgpack::pack(outF, outVecTp);
    outF.seekp(0);
    outF.close();


}