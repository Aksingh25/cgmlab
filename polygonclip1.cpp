#include <iostream>
#include <graphics.h>
#include <vector>

struct Point {
    int x, y;
};

std::vector<Point> sutherlandHodgman(std::vector<Point> subjectPolygon, int clipperLeft, int clipperTop, int clipperRight, int clipperBottom) {
    std::vector<Point> resultPolygon;

    int edges = 4; // Four edges of the clipping window
    int xMin = clipperLeft;
    int yMin = clipperTop;
    int xMax = clipperRight;
    int yMax = clipperBottom;

    for (int i = 0; i < edges; i++) {
        std::vector<Point> inputPolygon = resultPolygon;
        resultPolygon.clear();

        int x1 = inputPolygon.back().x;
        int y1 = inputPolygon.back().y;

        for (size_t j = 0; j < inputPolygon.size(); j++) {
            int x2 = inputPolygon[j].x;
            int y2 = inputPolygon[j].y;

            // Check if the current point is inside or outside the clipper
            bool isInside1 = (x1 >= xMin) && (x1 <= xMax) && (y1 >= yMin) && (y1 <= yMax);
            bool isInside2 = (x2 >= xMin) && (x2 <= xMax) && (y2 >= yMin) && (y2 <= yMax);

            if (isInside1 && isInside2) {
                // Both points inside, keep the second point
                resultPolygon.push_back({x2, y2});
            } else if (isInside1 && !isInside2) {
                // First point inside, second point outside
                // Add intersection point
                int intersectX = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                resultPolygon.push_back({intersectX, yMin});
            } else if (!isInside1 && isInside2) {
                // First point outside, second point inside
                // Add intersection point
                int intersectX = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                resultPolygon.push_back({intersectX, yMax});
                resultPolygon.push_back({x2, y2});
            }

            x1 = x2;
            y1 = y2;
        }
    }

    return resultPolygon;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " (char*)C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

    // Define the subject polygon
    std::vector<Point> subjectPolygon = {{50, 150}, {200, 50}, {350, 150}, {350, 300}, {250, 300}, {200, 250}, {150, 350}, {100, 250}};

    // Draw the subject polygon
    setcolor(BLUE);
    for (size_t i = 0; i < subjectPolygon.size(); i++) {
        line(subjectPolygon[i].x, subjectPolygon[i].y, subjectPolygon[(i + 1) % subjectPolygon.size()].x, subjectPolygon[(i + 1) % subjectPolygon.size()].y);
    }

    // Define the clipping window
    int clipperLeft = 150, clipperTop = 100, clipperRight = 300, clipperBottom = 250;

    // Draw the clipping window
    rectangle(clipperLeft, clipperTop, clipperRight, clipperBottom);

    // Apply Sutherland–Hodgman polygon clipping
    std::vector<Point> clippedPolygon = sutherlandHodgman(subjectPolygon, clipperLeft, clipperTop, clipperRight, clipperBottom);

    // Draw the clipped polygon
    setcolor(GREEN);
    for (size_t i = 0; i < clippedPolygon.size(); i++) {
        line(clippedPolygon[i].x, clippedPolygon[i].y, clippedPolygon[(i + 1) % clippedPolygon.size()].x, clippedPolygon[(i + 1) % clippedPolygon.size()].y);
    }

    delay(5000); // Delay to show the result

    closegraph();
    return 0;
}

