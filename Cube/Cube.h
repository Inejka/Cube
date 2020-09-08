//
// Created by art on 9/2/20.
//
/**
 * Заголовочный файл с описанием методов и структуры ядра кубика
 */
#ifndef MAGICCUBE2_CUBE_H
#define MAGICCUBE2_CUBE_H
enum colours {
    unknown, white, yellow, red, orange, blue, green
};

#include <string>

class Cube {
private:
    colours **matrix;   ///< Основная матрица
    int size;         ///< Размер куба
    // Тот самый поворот цветов вокруг центра, но только для левой и право сторон
    void rotateSide(bool direction, bool side); //работает
    //то же что и RotateSide,но для верхней и нижней грани side=true>> up side  direction = true >> clockwise
    void anotherRotateSide(bool direction, bool side); //работает

    void clockwise(int, int); //работает
    void anticlockwise(int, int); //работает
    void back_to_normal();


public:

    /**
      Положить кубик на бок (правый или левый)
      \param[in] direction направление поворота:true=>правый бок,false=>левый бок
     */
    void putOnTheSide(bool direction); //не работает


    ///\brief Конструктор
    ///\param n Размер куба
    Cube(int n);

    ///Деструктор
    ~Cube();

    ///Конструктор-копировщик
    Cube(const Cube &);

    Cube &operator=(const Cube &);

    friend std::ostream &operator<<(std::ostream &, const Cube &);

    friend std::istream &operator>>(std::istream &, Cube &);

    bool operator==(const Cube &);

    //Те самые повороты, из-за которых нужно крутить цвета
    /**
     Поворот кубика вертикально
     \param[in] direction направление поворота:true=>вверх,false=>вниз
     */
    void rotateCubeVertically(bool direction);

    //Те самые повороты, из-за которых нужно крутить цвета
    /**
     Поворот кубика горизонтально
     \param[in] direction направление поворота:true=>вправо,false=>влево
     */
    void rotateCubeHorizontally(bool direction);

    /**
     * Получение цвета из индекса i,j
     * @param[in] i номер строки
     * @param[in] j номер столбца
     * @return цвет в matrix[i][j]
     */
    colours getColor(int i, int j) const; //работает

    /**
     * @return размер кубика
     */
    int getSize() const; //работает

    /**
     Перевод матрицы кубика в строку
     */
    std::string print() const;

protected:
    /**
     * Вращение столбца
     * @param number номер столбца
     * @param direction направление вращения:true=>вверх,false=>вниз
     */
    void rotateLayer(int number, bool direction); //работает

};


#endif //MAGICCUBE2_CUBE_H
