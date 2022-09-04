#include <iostream>
#include <exception>
#include "Container.h"

int main()
{
    int index=0, lenght=0, element=0;
    bool open=true;
    
    std::cout<<"Введите размер массива: ";
    std::cin>>lenght;
    try
    {
        Container* intArray1 = new Container(lenght);
        intArray1->show_container();
        std::cout<<"Копируем первоначальный контейнер."<<std::endl;
        Container* intArray2 = new Container(*intArray1);
        while(open==true)
        {
            char key=' ';
            std::cout<<"Меню работы с контейнером."<<std::endl;
            std::cout<<"s - показать содержимое контейнера"<<std::endl;
            std::cout<<"с - изменение величины контейнера"<<std::endl;
            std::cout<<"t - изменить элемент контейнера"<<std::endl;
            std::cout<<"d - удаление элемента контейнера"<<std::endl;
            std::cout<<"a - добавить элемент в контейнер"<<std::endl;
            std::cout<<"b - добавить элемент в начало контейнера"<<std::endl;
            std::cout<<"e - добавить элемент в конец контейнера"<<std::endl;
            std::cout<<"v - поиск элемента по значению"<<std::endl;
            std::cout<<"0 - выход"<<std::endl;
            std::cin>>key;
            switch (key)
            {
            //Отображение контейнера
            case 's':
                {
                    std::cout<<"Контейнер: ";
                    intArray1->show_container();
                    break;
                }
            //Изменение величины контейнера
            case 'c':
                {
                    while(true)
                    { 
                        char f=' ';
                        std::cout<<"Введите на сколько элементов изменить массив или 0 для выхода: ";
                        std::cin>>lenght;
                        if(lenght==0)
                        {
                            break;
                        }
                        std::cout<<"Введите '+' для увеличения или '-' для уменьшения величины контейнера"<<std::endl;
                        std::cin>>f;
                        if(f=='-')
                        {
                            lenght*=-1;
                        }
                        else if(f!='+')
                        {
                            continue;
                        }
                        lenght+=(*intArray1).get_container_lenght();
                        try
                        {
                            intArray1->change_container_lenght(lenght);
                        }
                        catch(const std::exception& e)
                        {
                            std::cout<<"Ошибка: "<<e.what()<<std::endl;
                        }
                    }
                    break;
                }
            //Изменение элемента контейнера
            case 't':
                {
                    while(true)
                    {
                        std::cout<<"Введите номер искомого элемента или 0 для выхода: ";
                        std::cin>>index;
                        if(index==0)
                        {
                            break;
                        }
                        --index;
                        try
                        {
                            std::cout<<"Текущее значение элемента: "<<intArray1->search_element_by_index(index)<<std::endl;
                            while(true)
                            {
                                char f=' ';
                                std::cout<<"Желаете изменить элемент?(y/n) ";
                                std::cin>>f;
                                if(f=='n')
                                {
                                    break;
                                }
                                else if(f=='y')
                                {
                                    std::cout<<"Введите новое значение для "<<index+1<<" элемента: ";
                                    std::cin>>element;
                                    intArray1->set_container_element(element, index);
                                    break;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            
                        }
                        catch(const std::exception& e)
                        {
                            std::cout<<"Ошибка: "<<e.what()<<std::endl;
                        }
                    }
                    break;
                }
            //Удаление элемента контейнера
            case 'd':
                {
                    std::cout<<"Введите номер удаляемого элемента: ";
                    std::cin>>index;
                    --index;
                    try
                    {
                        intArray1->del_container_element(index);
                    }
                    catch(const std::exception& e)
                    {
                        std::cout<<"Ошибка: "<<e.what()<<std::endl;
                    }
                    break;
                }
            //Добавление элемента в контейнер по индексу
            case 'a':
                {
                    std::cout<<"Введите номер позиции для вставки элемента: ";
                    std::cin>>index;
                    --index;
                    std::cout<<"Введите элемент для вставки: ";
                    std::cin>>element;
                    try
                    {
                        intArray1->add_container_element(element, index);
                    }
                    catch(const std::exception& e)
                    {
                        std::cout<<"Ошибка: "<<e.what()<<std::endl;
                    }
                    break;
                }
            //Добавление элемента в начало контейнера
            case 'b':
                {
                    std::cout<<"Введите значение добавляемого элемента: ";
                    std::cin>>element;
                    intArray1->add_element_begin(element);
                    break;
                }
            //Добавление элемента в конец контейнера
            case 'e':
                {
                    std::cout<<"Введите значение добавляемого элемента: ";
                    std::cin>>element;
                    intArray1->add_element_end(element);
                    break;
                }
            //Поиск контейнера по индексу
            case 'v':
                {
                    std::cout<<"Введит искомое значение: ";
                    std::cin>>element;
                    try
                    {
                        intArray1->search_element_by_value(element);
                    }
                    catch(const std::exception& e)
                    {
                        std::cout<<"Ошибка: "<<e.what()<<std::endl;
                    }
                    break;
                }
            //Выход
            case '0':
                {
                    open=false;
                    break;
                }
            default:
                {
                    std::cout<<"Неправильно заданна командная функция."<<std::endl;
                    break;
                }
            }    
        }
        std::cout<<"Контейнер: ";
        intArray1->show_container();
        delete intArray1;
        std::cout<<"Первоначальный контейнер: ";
        intArray2->show_container();
        delete intArray2;
    }
    catch(const std::exception& e)
    {
        std::cout<<"Ошибка: "<<e.what()<<std::endl;
    }
    
    return 0;
}