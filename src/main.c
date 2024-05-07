#include "raylib.h"

int main(int argc, char** argv) {
    const char* TITLE = "Simple Raylib Template";
    const int WIDTH = 1280;
    const int HEIGHT = 768;

    ConfigFlags config_flags =
        FLAG_MSAA_4X_HINT | 
        FLAG_WINDOW_RESIZABLE |
        FLAG_VSYNC_HINT;

    SetConfigFlags(config_flags);

    InitWindow(WIDTH, HEIGHT, TextFormat("Raylib %s - %s", RAYLIB_VERSION, TITLE));
    InitAudioDevice();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}