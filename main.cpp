#include <iostream>
#include "Cube3.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void logic(string, Cube3 &, RenderWindow &);

void draw(Cube3 &, RenderWindow &);

void choose_colour(RectangleShape &, const colours &);

int main() {
    Cube3 cube;
    RenderWindow cube_window(VideoMode(500, 700), "Cube"), main_window(VideoMode(500, 50), "Test");
    Text text;
    std::string input, prev_one;
    Event main_event;
    Font blean;
    blean.loadFromFile("good.ttf");
    text.setFont(blean);
    text.setFillColor(Color::Black);
    text.setCharacterSize(20);
    draw(cube, cube_window);
    while (main_window.isOpen()) {
        if (main_window.pollEvent(main_event)) {
            main_window.clear(Color::White);
            if (main_event.type == Event::KeyPressed)
                switch (main_event.key.code) {
                    case sf::Keyboard::Up:
                        input = prev_one;
                        break;
                    case sf::Keyboard::Escape:
                        main_window.close();
                        break;;
                    case sf::Keyboard::Backspace:
                        if (input.size() > 0)input.erase(input.size() - 1, 1);
                        break;
                    case sf::Keyboard::Enter:
                        logic(input, cube, cube_window);
                        draw(cube, cube_window);
                        prev_one = input;
                        input.clear();
                        break;
                }
            if (main_event.type == Event::TextEntered)
                if (main_event.text.unicode >= '0' && main_event.text.unicode <= 'z' ||
                    main_event.text.unicode == '\'' || main_event.text.unicode == ' ')
                    input += main_event.text.unicode;
            text.setString(input);
            main_window.draw(text);
            main_window.display();
        }
    }
}

void logic(string input, Cube3 &cube, RenderWindow &windows) {
    if (input == "ROT") {
        cube.rotateCubeHorizontally(true);
    } else if (input == "ROTA") {
        cube.rotateCubeHorizontally(false);
    } else if (input == "UP") {
        cube.rotateCubeVertically(true);
    } else if (input == "DOWN") {
        cube.rotateCubeVertically(false);
    } else if (input == "SHUFFLE") {
        cube.shuffle();
    } else if (input == "LOAD") {
        cube.load();
    } else if (input == "SAVE") {
        cube.save();
    } else if (input == "CHECK") {
        if (cube.check()) cout << "OK\n"; else cout << "BAD\n";
    } else cube.command(input);
    draw(cube, windows);
}

void draw(Cube3 &cube, RenderWindow &window) {
    window.clear(Color::White);
    RectangleShape tmp1;
    tmp1.setSize({165, 615});
    tmp1.setFillColor(Color::Black);
    tmp1.setPosition({165, 40});
    window.draw(tmp1);
    tmp1.setSize({465, 165});
    tmp1.setPosition({15, 340});
    window.draw(tmp1);
    tmp1.setSize({45, 45});
    for (int i = 0; i < cube.getSize() * 4; i++)
        for (int j = 0; j < cube.getSize(); j++) {
            choose_colour(tmp1, cube.getColor(i, cube.getSize() + j));
            tmp1.setPosition(175 + j * 50, 50 + i * 50);
            window.draw(tmp1);
        }
    for (int i = 0; i < cube.getSize(); i++)
        for (int j = 0; j < cube.getSize() * 3; j++) {
            choose_colour(tmp1, cube.getColor(2 * cube.getSize() + i, j));
            tmp1.setPosition(25 + j * 50, 350 + i * 50);
            window.draw(tmp1);
        }
    window.display();
}

void choose_colour(RectangleShape &tmp1, const colours &tmp2) {
    switch (tmp2) {
        case white:
            tmp1.setFillColor(Color::White);
            break;
        case yellow:
            tmp1.setFillColor(Color::Yellow);
            break;
        case red:
            tmp1.setFillColor(Color::Red);
            break;
        case orange:
            tmp1.setFillColor(Color(255, 165, 0, 255));
            break;
        case blue:
            tmp1.setFillColor(Color::Blue);
            break;
        case green:
            tmp1.setFillColor(Color::Green);
            break;
    }
}
