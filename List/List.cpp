#include "List.h"
#include <iostream>

int main()
{
    List<int> lst;

    // Testing push_back and iteration
    std::cout << "Testing push_back (push 0-9):" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        lst.push_back(i);
    }
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing pop_back
    std::cout << "Testing pop_back (pop the last one):" << std::endl;
    lst.pop_back();
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing push_front
    std::cout << "Testing push_front (with item -1):" << std::endl;
    lst.push_front(-1);
    lst.push_front(-1-1);
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing pop_front
    std::cout << "Testing pop_front (pop the first one):" << std::endl;
    lst.pop_front();
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing clear and empty
    std::cout << "Testing clear and empty:" << std::endl;
    lst.clear();
    std::cout << "List empty? " << std::boolalpha << lst.empty() << std::endl;

    // Testing insert and erase
    std::cout << "Testing insert and erase:" << std::endl;
    lst.push_back(5);
    lst.push_back(10);
    auto itr = lst.begin();
    std::cout << "create a List with 5 10:" << std::endl;
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    std::cout << "Insert 7 after 5:" << std::endl;
    ++itr; // move to 10
    lst.insert(itr, 7);
    lst.insert(itr,3+5);
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    // Move to 7 and erase it
    --itr;
    std::cout << "Erase 3+5:" << std::endl;
    lst.erase(itr);
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing copy constructor
    std::cout << "Testing copy constructor:" << std::endl;
    List<int> copy_lst(lst); // Copy constructor
    for (auto it : copy_lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing assignment operator
    std::cout << "Testing assignment operator:" << std::endl;
    List<int> assign_lst;
    assign_lst = lst; // Assignment operator
    for (auto it : assign_lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing move constructor
    std::cout << "Testing move constructor:" << std::endl;
    List<int> moved_lst(std::move(lst)); // Move constructor
    for (auto it : moved_lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing move assignment operator
    std::cout << "Testing move assignment operator:" << std::endl;
    List<int> move_assign_lst;
    move_assign_lst = std::move(copy_lst); // Move assignment operator
    for (auto it : move_assign_lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // Testing equality and inequality operators
    std::cout << "Testing equality and inequality operators for iterator:" << std::endl;
    List<int> lst1;
    lst1.push_back(0.5+0.5);
    lst1.push_back(1+1);
    for (auto it : lst1)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    auto itr1 = lst1.begin();
    auto itr2 = lst1.begin();
    auto itr3 = lst1.end();
    auto itr4 = --lst1.end();
    std::cout << "itr1 == itr2? " << std::boolalpha << (itr1 == itr2) << std::endl;
    std::cout << "itr1 == itr3? " << std::boolalpha << (itr1 == itr3) << std::endl;
    std::cout << "Testing ++ and -- operators:" << std::endl;
    std::cout << "itr1++ == itr4? " << std::boolalpha << (itr1++ == itr4) << std::endl;
    std::cout << "itr1 == itr4? " << std::boolalpha << (itr1 == itr4) << std::endl;
    std::cout << "itr1-- == itr2? " << std::boolalpha << (itr1-- == itr2) << std::endl;
    std::cout << "itr1 == itr2? " << std::boolalpha << (itr1 == itr2) << std::endl;
    return 0;
}