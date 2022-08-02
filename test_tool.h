#pragma once


#include <iostream>
#include <exception>
#include <sstream>

template<typename T, typename V>
void AssertEqual(const T& t, const V& v){
    if (t != v){
        std::ostringstream os;
        os << "Assertion filed: " << t << " != " << v;
        throw std::runtime_error(os.str());
    }
}

class TestRunner{
    private:
        int fail_cnt = 0;

    public:
        template<typename TestFunc>
        void RunTest(TestFunc func, const std::string& test_name){
            try{
                func();
                std::cerr << test_name << " OK" << std::endl;
            } catch(std::runtime_error& e){
                fail_cnt++;
                std::cerr << test_name << " fail: " << e.what() << std::endl;
                
            }
        }

        ~TestRunner(){
            if (fail_cnt > 0){
                std::cerr << fail_cnt << " tests failed. Terminate (1)" << std::endl;
                exit(1);
            }
        }
};
