/*
 * main.cpp
 */

#include <iostream>
#include <numeric>
#include <random>

#include "algorithms.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 600), "Sorting Visualizer");

    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 1);
    auto rng = std::default_random_engine{};
    std::shuffle(v.begin(), v.end(), rng);

    bool is_sorted = false;

    // std::vector<std::string> options = {"Insertion Sort", "Merge Sort", "Bubble Sort"};
    // DropdownMenu dropdown(window, options);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // dropdown.handleEvent(event);
        }

        if (!is_sorted)
        {
            render(window, v, 0);
            merge_sort(window, v, 0, 99, is_sorted);
        }
    }
}