#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include "SFML/Graphics.hpp"

// -------------------------------------------
// Constants
// -------------------------------------------
const unsigned int SCREEN_SIZE { 1200 };
const unsigned int TOTAL_CELLS_ON_GRID { 100 };
const unsigned int ROWS { 10 }, COLS { 10 };

static void handleKeyPress(const sf::Event &event, sf::RenderWindow &window)
{
    std::cout << "Handle Key Press fn called" << std::endl;
    std::cout << event.key.code << std::endl;

    if (event.key.code == sf::Keyboard::Q) {
        window.close();
        return;
    }
}

class Tile
{
    int x;
    int y;
    sf::RectangleShape rectangleShape;
    Tile(int x, int y) : x { x }, y { y } {}
    ~Tile() {}
};

static void createGrid(sf::RenderWindow &window)
{
    const float SQUARE_WIDTH = SCREEN_SIZE / ROWS;
    const float SQUARE_HEIGHT = SCREEN_SIZE / COLS;

    // explicit RectangleShape(const Vector2f& size = Vector2f(0, 0));
    const sf::Vector2f SQUARE_SIZE { SQUARE_WIDTH, SQUARE_HEIGHT };
    sf::RectangleShape square(SQUARE_SIZE);

    sf::RectangleShape testSquare(SQUARE_SIZE);
    testSquare.setFillColor(sf::Color::Cyan);
    testSquare.setOrigin(20, 20);

    window.draw(testSquare);

    // Create
    std::vector<std::pair<int, int>> matrix;
    int r { 0 }, c { 0 };
    while (r < ROWS && c < COLS) {
        for (int i = 0; i < ROWS; ++i) {
            matrix.push_back({ r, c });
            r += 10;
        }
        c += 10;
    }
}

int main()
{
    std::cout << "Game Started" << std::endl;

    // Title
    const std::string WINDOW_TITLE { "Snake 1.0" };

    // SFML Main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE),
                            WINDOW_TITLE);
    // ImGui Initialize
    ImGui::SFML::Init(window);

    // ImGui State
    bool circleExists = true;
    float circleRadius = 200.0f;
    int circleSegments = 100;
    float circleColor[3] = { (float)204 / 255, (float)77 / 255,
                             (float)5 / 255 };
    sf::CircleShape shape(circleRadius, circleSegments);
    shape.setFillColor(sf::Color((int)(circleColor[0] * 255),
                                 (int)(circleColor[1] * 255),
                                 (int)(circleColor[2] * 255))); // Color circle
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(SCREEN_SIZE / 2, SCREEN_SIZE / 2); // Center circle

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            switch (event.type) {
            case sf::Event::KeyPressed:
                handleKeyPress(event, window);
                break;

            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("ImGui Window title");
        ImGui::Text("Window text!");
        ImGui::Checkbox("Circle", &circleExists);
        ImGui::SliderFloat("Radius", &circleRadius, 50.0f, SCREEN_SIZE / 2);
        ImGui::SliderInt("Sides", &circleSegments, 3, 150);
        ImGui::ColorEdit3("Color Circle", circleColor);
        ImGui::End();

        shape.setRadius(circleRadius);
        shape.setOrigin(circleRadius, circleRadius);
        shape.setPointCount(circleSegments);
        shape.setFillColor(
            sf::Color((int)(circleColor[0] * 255), (int)(circleColor[1] * 255),
                      (int)(circleColor[2] * 255))); // Color circle

        window.clear(sf::Color(18, 33, 43)); // Color background
        createGrid(window);
        // if (circleExists)
        // window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    std::cout << "Game ENDED" << std::endl;
    return 0;
}
