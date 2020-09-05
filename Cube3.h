//
// Created by art on 9/2/20.
//

#ifndef MAGICCUBE2_CUBE3_H
#define MAGICCUBE2_CUBE3_H

/**
 * Заголовочный файл с описанием методов кубика 3на3
 */

#include <string>
#include "Cube/Cube.h"

class Cube3: public Cube{
public:
    ///Конструктор,задающий размер кубика
    Cube3();

    /**
     * Проверка кубика на собранность
     * @return true=>кубик собран , false=>кубик разобран
     */
    bool check();

     /**
      * Ввод строки управления на языке поворотов
      * @param[in] commands строка,состоящая из следующих комманд,разделённых пробелом:L,R,F,B,U,D,L',R',F',B',U',D'
      */
    void command(std::string commands);

    /**
     * Запутывание кубика
     */
    void shuffle();

    /**
     * Загрузка кубик из файла "input.txt",формат загрузки создаётся функцией save
     */
    void load();

    /**
     * Сохранение кубика в файл "output.txt"
     */
    void save();
private:
    void U();
    void U_();
    void D();
    void D_();
    void R();
    void R_();
    void L();
    void L_();
    void F();
    void F_();
    void B();
    void B_();
};


#endif //MAGICCUBE2_CUBE3_H
