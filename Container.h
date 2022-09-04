#pragma once

#include <iostream>
#include <exception>

class BadRange: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "выход из диапазона";
    }
};

class BadLenght: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "неправильная размерность";
    }
};

class BadContainer: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "контейнер не может быть уничтожен.";
    }
};

class BadValue: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "данного значения не существует";
    }
};

class Container
{
private:
    int _lenght=0;
    int* _array=nullptr;

public:
    Container()=default;

    Container(int lenght);
    
    Container(const Container& other);

    int get_container_lenght() const;

    void set_container_element(int element, int index);
    
    void show_container() const;

    void change_container_lenght(int lenght);

    void add_container_element(int element, int position);
    void del_container_element(int position);

    void add_element_begin(int element);
    void add_element_end(int element);

    int search_element_by_index(int index) const;
    void search_element_by_value(int value) const;

    ~Container();
};