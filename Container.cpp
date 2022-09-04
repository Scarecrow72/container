#include <iostream>
#include <exception>
#include "Container.h"

Container::Container(int lenght): _lenght(lenght)
{
    if(lenght<1)
    {
        throw BadLenght();
    }
    _array = new int[lenght];
    for(int i=0;i<_lenght;++i)
    {
        _array[i]=i;
    }
}

Container::Container(const Container &other)
{
    this->_lenght=other._lenght;
    int* new_array = new int [_lenght];
    _array=new_array;
    for(int i=0;i<_lenght;++i)
    {
        this->_array[i]=other._array[i];
    }
}

int Container::get_container_lenght() const
{
    return _lenght;
}

void Container::set_container_element(int element, int index)
{
    _array[index]=element;
}

void Container::show_container() const
{
    for(int i=0;i<_lenght;++i)
    {
        std::cout<<_array[i]<<" ";
    }
    std::cout<<std::endl;
}

void Container::change_container_lenght(int lenght)
{
    if(lenght<=1)
    {
        throw BadContainer();
    }
    int* new_array=new int[lenght];
    for(int i=0;i<lenght;++i)
    {
        new_array[i]=0;
    }
    if(_lenght<lenght)
    {
        for(int i=0;i<_lenght;++i)
        {
            new_array[i]=_array[i];
        }
    }
    else
    {
        for(int i=0;i<lenght;++i)
        {
            new_array[i]=_array[i];
        }
    }
    delete[] _array;
    _array=new_array;
    _lenght=lenght;
}

void Container::add_container_element(int element, int position)
{
    if(position<0||position>_lenght-1)
    {
        throw BadRange();
    }
    ++_lenght;
    int* new_array = new int[_lenght];
    for(int i=0;i<position;++i)
    {
        new_array[i]=_array[i];
    }
    new_array[position]=element;
    for(int i=position+1;i<_lenght;++i)
    {
        new_array[i]=_array[i-1];
    }
    delete[] _array;
    _array=new_array;
}
void Container::del_container_element(int position)
{
    if(position<0||position>_lenght)
    {
        throw BadRange();
    }
    if(_lenght-1<=0)
    {
        throw BadContainer();
    }
    int* new_array = new int[_lenght-1];
    for(int i=0;i<position;++i)
    {
        new_array[i]=_array[i];
    }
    for(int i=position;i<_lenght;++i)
    {
        new_array[i]=_array[i+1];
    }
    delete[] _array;
    _array=new_array;
    --_lenght;
}

void Container::add_element_begin(int element)
{
    ++_lenght;
    int* new_array = new int[_lenght];
    new_array[0]=element;
    for(int i=1;i<_lenght;++i)
    {
        new_array[i]=_array[i-1];
    }
    delete[] _array;
    _array=new_array;
}
void Container::add_element_end(int element)
{
    ++_lenght;
    int* new_array = new int[_lenght];
    for(int i=0;i<_lenght-1;++i)
    {
        new_array[i]=_array[i];
    }
    new_array[_lenght-1]=element;
    delete[] _array;
    _array=new_array;
}
    
int Container::search_element_by_index(int index) const
{
    if(index<0||index>(_lenght-1))
    {
        throw BadRange();
    }
    else
    {
        return _array[index];
    }
}
void Container::search_element_by_value(int value) const
{
    int match=0;
    for(int i=0;i<_lenght;++i)
    {
        if(_array[i]==value)
        {
            std::cout<<"Элемент значением "<<value<<" содержится в контейнере под "<<i+1<<" номером"<<std::endl;
            ++match;
        }
    }
    if(match==0)
    {
        throw BadValue();
    }
}

Container::~Container()
{
    std::cout<<"Контейнер удален."<<std::endl;
    delete[] _array;
}