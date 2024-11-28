#include "RGFW.h"

void keyfunc(RGFW_window* win, u32 keycode, char keyName[16], u8 lockState, u8 pressed) {
  printf("Key %u %u: %s\n", pressed, lockState, keyName);
}

int main() {
  RGFW_window* win = RGFW_createWindow("null0", RGFW_RECT(0, 0, 320, 240), (u64)RGFW_CENTER);
  RGFW_setKeyCallback(keyfunc);
  i32 running = 1;
  while (running) {
    while (RGFW_window_checkEvent(win)) {
      if (win->event.type == RGFW_quit || RGFW_isPressed(win, RGFW_Escape)) {
        running = 0;
        break;
      }
    }
    glClearColor(0xFF / 255.0f, 0XFF / 255.0f, 0xFF / 255.0f, 0xFF / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    RGFW_window_swapBuffers(win);
  }
  RGFW_window_close(win);
}