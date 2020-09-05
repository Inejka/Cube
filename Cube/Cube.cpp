//
// Created by art on 9/2/20.
//

#include "Cube.h"
#include <iostream>
Cube::Cube(int n) {
    matrix = new short *[4 * n];
    for (int i = 0; i < 4 * n; ++i) {
        matrix[i] = new short[3 * n];
        for (int j = 0; j < 3 * n; ++j) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            matrix[i][j] = yellow;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + n][j] = red;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + 2 * n][j] = white;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + 3 * n][j] = orange;
        }
    }

    for (int i = 2 * n; i < 3 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = blue;
        }
        for (int j = 2 * n; j < 3 * n; ++j) {
            matrix[i][j] = green;
        }
    }

    size = n;
}

void Cube::rotateLayer(int number, bool direction) {
    short temp;
    if (direction) {
        for (int i = 0; i < size; ++i) {
            temp = matrix[0][size + number];
            for (int j = 0; j < 4 * size - 1; ++j) {
                matrix[j][size + number] = matrix[j + 1][size + number];
            }
            matrix[4 * size - 1][size + number] = temp;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            temp = matrix[4 * size - 1][size + number];
            for (int j = 4 * size - 1; j > 0; --j) {
                matrix[j][size + number] = matrix[j - 1][size + number];
            }
            matrix[0][size + number] = temp;
        }
    }
    if (number == 0) rotateSide(!direction, true);
    else if (number == size - 1) rotateSide(direction, false);
}

void Cube::rotateCubeVertically(bool direction) {
    for (int i = 0; i < size; ++i) {
        rotateLayer(i, direction);
    }
}

void Cube::rotateCubeHorizontally(bool direction) {
    short **temp;
    temp = new short *[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = new short[size];
        for (int j = 0; j < size; ++j) {
            temp[i][j] = matrix[i][size + j];
        }
    }
    if (direction) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][size +j ] = matrix[2 * size + i][2 * size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][2 * size + j] = matrix[2 * size + i][size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][size + j] = matrix[ 2*size + i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2*size+i][j] = temp[i][j];
            }
        }
        clockwise(0,size);
        clockwise(0,size);
        clockwise(2*size,0);
        clockwise(2*size,0);
        anotherRotateSide(false, true);
        anotherRotateSide(true, false);
    } else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][size+j] = matrix[2 * size+i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][j] = matrix[2 * size + i][size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][size + j] = matrix[2 * size + i][2 * size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][2 * size + j] = temp[i][j];
            }
        }
        clockwise(0,size);
        clockwise(0,size);
        clockwise(2*size,2*size);
        clockwise(2*size,2*size);
        anotherRotateSide(true, true);
        anotherRotateSide(false, false);
    }

    for (int i = 0; i < size; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

void Cube::putOnTheSide(bool direction) {
        rotateCubeVertically(false);
        rotateCubeHorizontally(!direction);
        rotateCubeVertically(true);
 }

short Cube::getColor(int i, int j) const {
    return matrix[i][j];
}

int Cube::getSize() const {
    return size;
}

std::string Cube::print() const {
    std::string result;
    for (int i = 0; i < 4 * size; ++i) {
        for (int j = 0; j < 3 * size; ++j) {
            result += std::to_string(matrix[i][j]) + "  ";
        }
        result += '\n';
    }
    return result;
}

void Cube::rotateSide(bool direction, bool side) {
    if(side){
        if(direction)
            clockwise(2*size,0); else anticlockwise(2*size,0);
    } else
    if(direction)
        clockwise(2*size,2*size); else anticlockwise(2*size,2*size);
}

void Cube::anotherRotateSide(bool direction, bool side) {
    if(side){
        if(direction)
            clockwise(size,size); else anticlockwise(size,size);
    } else
        if(direction)
            clockwise(3*size,size); else anticlockwise(3*size,size);
}

void Cube::clockwise(int x,int y){
    short **original = new short *[size];
        for (int k = 0; k < size; ++k) {
            original[k] = new short[size];
            for (int i = 0; i < size; ++i)
                original[k][i] = matrix[x + k][y + i];
        }
    for(int i = 0 ; i < size ; i++)
        for(int j = 0 ; j < size ; j++)
            matrix[j+x][y+size-i-1]=original[i][j];
    for (int l = 0; l < 3; ++l) {
        delete[] original[l];
    }
    delete[] original;
}

void Cube::anticlockwise(int x,int y){
        short **original = new short *[size];
        for (int k = 0; k < size; ++k) {
            original[k] = new short[size];
            for (int i = 0; i < size; ++i)
                original[k][i] = matrix[x + k][y + i];
        }
        for(int i = 0 ; i < size ; i++)
            for(int j = 0 ; j < size ; j++)
                matrix[size-j-1+x][i+y]=original[i][j];
        for (int l = 0; l < 3; ++l) {
            delete[] original[l];
        }
        delete[] original;
    }

Cube::~Cube() {
    for(int i = 0 ; i < size ; i++)
        delete [] matrix[i];
    delete [] matrix;
}

Cube::Cube(const Cube &rhs) {
    size=rhs.getSize();
    matrix = new short *[4*size];
    for(int i = 0 ; i < 4 * size ; i++)
        matrix[i]= new short [3*size];
    for(int i = 0 ; i < 4*size ; i++)
        for(int j = 0 ; j < 3*size ; j++)
            matrix[i][j]=rhs.getColor(i,j);
}

Cube &Cube::operator=(const Cube &rhs) {
    if(this==&rhs)
        return *this;
    size=rhs.getSize();
    matrix = new short *[4*size];
    for(int i = 0 ; i < 4 * size ; i++)
        matrix[i]= new short [3*size];
    for(int i = 0 ; i < 4*size ; i++)
        for(int j = 0 ; j < 3*size ; j++)
            matrix[i][j]=rhs.getColor(i,j);
}

std::ostream &operator<<(std::ostream &out, const Cube &rhs) {
    for(int i = 0 ; i < rhs.getSize()*4  ; i++){
        if(i<rhs.getSize()*2||i>rhs.getSize()*3-1)
            for(int j = 0 ; j < rhs.getSize(); j++)
                out << rhs.getColor(i,rhs.getSize()+j);
            else
                for(int j = 0 ; j < rhs.getSize()*3; j++)
                    out << rhs.getColor(i,j);

    }
}

std::istream &operator>>(std::istream &in, Cube &rhs) {
    char *input = new char [rhs.size*rhs.size*6] ;
    in >> input ;
    int counter = 0;
    for(int i = 0 ; i < rhs.getSize()*4  ; i++){
        if(i<rhs.getSize()*2||i>rhs.getSize()*3-1)
            for(int j = 0 ; j < rhs.getSize(); j++,counter++)
                rhs.matrix[i][j+rhs.size]=input[counter]-'0';
        else
            for(int j = 0 ; j < rhs.getSize()*3; j++,counter++)
                rhs.matrix[i][j]=input[counter]-'0';
    }
}

void Cube::back_to_normal() {
    int check = false ;
    for(int i = 0 ; i < 4 ; i++){
        this->rotateCubeVertically(true);
    if(matrix[size*2+size/2][size+size/2]==white){
        check= true;
        break;
        }
    }
    if(!check)
        while (matrix[size*2+size/2][size+size/2]!=white)this->rotateCubeHorizontally(true);
    while(matrix[size+size/2][size+size/2]!=red)this->putOnTheSide(true);
}

bool Cube::operator==(const Cube &rhs) {
    Cube tmp1 = *this , tmp2 = rhs ;
    tmp1.back_to_normal() ; tmp2.back_to_normal() ;
    for(int i = 0 ; i < size * 4  ; i++)
        for(int j = 0 ; j < size * 3 ; j++)
            if(tmp1.getColor(i,j)!=tmp2.getColor(i,j))return false;
    return true;
}



