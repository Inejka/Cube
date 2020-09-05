//
// Created by art on 9/2/20.
//

#include "Cube3.h"
#include <ctime>
#include <fstream>
#include <iostream>
Cube3::Cube3() : Cube(3){}

void Cube3::command(std::string commands) {
    short times;
    bool isInverse;
    for (int i = 0; i < commands.size(); ++i) {
        times = 1;
        isInverse = false;
        if (commands[i] != ' ') {
            if (commands[i] == '2') {
                times = 2;
                i++;
            }
            if (commands[i + 1] == '\'') isInverse = true;
            switch (commands[i]) {
                case 'F': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?F_():F();
                    }
                    break;
                }
                case 'B': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?B_():B();
                    }
                    break;
                }
                case 'L': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?L_():L();
                    }
                    break;
                }
                case 'R': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?R_():R();
                    }
                    break;
                }
                case 'U': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?U_():U();
                    }
                    break;
                }
                case 'D': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?D_():D();
                    }
                    break;
                }
            }
            while (commands[i] != ' ' && i < commands.size())i++;
        }
    }
}

void Cube3::U() {
    putOnTheSide(false);
    rotateLayer(2, true);
    putOnTheSide(true);
}

void Cube3::U_() {
    putOnTheSide(false);
    rotateLayer(2, false);
    putOnTheSide(true);
}

void Cube3::D() {
    putOnTheSide(true);
    rotateLayer(2, true);
    putOnTheSide(false);
}

void Cube3::D_() {
    putOnTheSide(true);
    rotateLayer(2, false);
    putOnTheSide(false);
}

void Cube3::R() {
    rotateLayer(2, true);
}

void Cube3::R_() {
    rotateLayer(2, false);

}

void Cube3::L() {
    rotateLayer(0, false);
}

void Cube3::L_() {
    rotateLayer(0, true);
}

void Cube3::F() {
    rotateCubeHorizontally(true);
    rotateLayer(2, true);
    rotateCubeHorizontally(false);
}

void Cube3::F_() {
    rotateCubeHorizontally(true);
    rotateLayer(2, false);
    rotateCubeHorizontally(false);
}

void Cube3::B() {
    rotateCubeHorizontally(true);
    rotateLayer(0, true);
    rotateCubeHorizontally(false);
}

void Cube3::B_() {
    rotateCubeHorizontally(true);
    rotateLayer(0, false);
    rotateCubeHorizontally(false);
}

void Cube3::shuffle() {
    srand(time(0));
    int random ;
    for(int i = 0 ; i < 40 ; i++){
        random = rand() % 12 ;
        switch (random) {
            case 0:
                L();
                break;
            case 1:
                L_();
                break;
            case 2:
                R();
                break;
            case 3:
                R_();
                break;
            case 4:
                F();
                break;
            case 5:
                F_();
                break;
            case 6:
                D();
                break;
            case 7:
                D_();
                break;
            case 8:
                B_();
                break;
            case 9:
                B();
                break;
            case 10:
                U();
                break;
            case 11:
                U_();
                break;
        }
    }
}

void Cube3::load() {
    freopen("input.txt","r",stdin);
    std::cin >> (*this) ;
    fclose(stdin);
    freopen("CON","r",stdin);
}

void Cube3::save() {
    freopen("output.txt","w",stdout);
    std::cout << (*this);
    fclose(stdout);
    freopen("CON","r",stdout);
}

bool check_near(const Cube & cube,int pos_x,int pos_y){
    return ( cube.getColor(pos_x,pos_y)==cube.getColor(pos_x-1,pos_y-1) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x,pos_y-1) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x+1,pos_y-1) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x+1,pos_y) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x-1,pos_y) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x-1,pos_y+1) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x,pos_y+1) &&
            cube.getColor(pos_x,pos_y)==cube.getColor(pos_x+1,pos_y+1)
            );
}


bool Cube3::check() {
    return (check_near(*this,1,4) &&
            check_near(*this,4,4) &&
            check_near(*this,7,4) &&
            check_near(*this,10,4) &&
            check_near(*this,7,1) &&
            check_near(*this,7,7)
    );
}