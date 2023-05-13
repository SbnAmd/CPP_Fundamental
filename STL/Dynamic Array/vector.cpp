//
// Created by Sbn on 5/13/2023.
//

#include "vector.h"

template<typename T>
void display_vector(const std::vector<T>& vec){

    for(auto i=vec.cbegin(); i != vec.cend(); i++)
        std::cout << *i << "\t";
    std::cout << std::endl;
}

template<typename T>
void display_deque(const std::deque<T>& vec){

    for(auto i=vec.cbegin(); i != vec.cend(); i++)
        std::cout << *i << "\t";
    std::cout << std::endl;
}


// Different ways of vector template initialization
void example_1(){

    {
        std::vector<double> doubles;        // Creates an empty vector of type double
        std::cout << doubles.size() << std::endl;        // Will print 0
        std::cout << doubles.capacity() << std::endl;    // Will print 0
    }

    {
        std::vector<double> doubles{10.1, 2.71, 3.14, -0.15, -56};      // Create a vector with 5 elements with values in curly braces
        std::cout << doubles.size() << std::endl;        // Will print 5
        std::cout << doubles.capacity() << std::endl;    // Will print 5
    }

    {
        std::vector<double> doubles(10);        // Creates a vector with 10 empty elements
        std::cout << doubles.size() << std::endl;        // Will print 10
        std::cout << doubles.capacity() << std::endl;    // Will print 10
    }

    {
        std::vector<double> doubles(10, -3.14);        // Creates a vector with 10 elements all with value -3.14
        std::cout << doubles.size() << std::endl;        // Will print 10
        std::cout << doubles.capacity() << std::endl;    // Will print 10

        {
            std::vector<double> copy_vector(doubles);           // Creates a copy of previous vector
            std::cout << copy_vector.size() << std::endl;       // Will print 10
            std::cout << copy_vector.capacity() << std::endl;   // Will print 10
        }

        {
            std::vector<double> copy_vector(doubles.cbegin(), doubles.cend() - 5);   // Creates a copy of previous vector just with 5 elements
            std::cout << copy_vector.size() << std::endl;       // Will print 5
            std::cout << copy_vector.capacity() << std::endl;   // Will print 5
        }
    }

}


void example_2(){

    std::vector<double> doubles{-3.14, -1, 0.25, 2.56, 2.71, 15.236589};
    std::vector<double> another_doubles{5.236, -89.25, 20, 63.025};

    doubles.push_back(-3.1548);                             // Insert value at the end of vector
    doubles.insert(doubles.cend(), -10);         // Insert value at the end of vector
    doubles.insert(doubles.cbegin()+1, another_doubles.cbegin(), another_doubles.cend()-1);     // Insert some element of other vector at position 1
    doubles.insert(doubles.cend(), 5, -10);         // Insert 5 elements with value of -10

    display_vector(doubles);

    doubles.erase(doubles.cbegin(), doubles.cend()-2);  // Will clear all elements but last 2 elements
    doubles.pop_back(); // Will remove last value

    display_vector(doubles);


}


void example_3(){

    std::deque<double> doubles;

    doubles.push_front(2);
    doubles.push_back(3);
    doubles.push_front(1);
    doubles.push_back(4);
    doubles.push_front(0);
    doubles.push_back(5);

    display_deque(doubles);

}

int main(){

//    example_1();
//    example_2();
    example_3();

    return 0;
}