#include "window.h"
#include "data_buffer.h"

#include <ncurses.h>
#include <string.h>

static struct window* WINDOWS = NULL;
static size_t WINDOWS_SIZE = 0;

void window_add(struct window input) {
    ++WINDOWS_SIZE;

    const struct window* old = WINDOWS;
    WINDOWS = malloc(sizeof(struct window) * WINDOWS_SIZE);
    memcpy(WINDOWS, old, sizeof(struct window) * (WINDOWS_SIZE - 1));

    if(old)
        free((void*) old);

    WINDOWS[WINDOWS_SIZE - 1] = input;

}

struct window* window_get(size_t index) {
    if(index >= WINDOWS_SIZE)
        return NULL; //Should throw an error

    return &(WINDOWS[index]);
}

void window_shutdown() {
    for(size_t i = 0; i < WINDOWS_SIZE; i++)
        window_kill(&(WINDOWS[i]));

    free(WINDOWS);
    WINDOWS_SIZE = 0;
}

void window_draw_all() {
    clear();
    refresh();

    for(size_t i = 0; i < WINDOWS_SIZE; i++)
        window_draw(&(WINDOWS[i]), i * WINDOWS_SIZE);
}

static struct dimension SCREEN_SIZE = {.x = 0, .y = 0};

void window_update_screen_size() {
    getmaxyx(stdscr, SCREEN_SIZE.y, SCREEN_SIZE.x);
}

struct dimension window_screen_size() {
    return SCREEN_SIZE;
}

struct window window_create_empty() {
    return (struct window) {
        .data_buff = NULL,
        .window = NULL
    };
}

void window_load_curses(struct window* input, WINDOW* window) {
    input->window = window;
    wrefresh(input->window);
}

void window_load_data_buffer(struct window* input, 
        struct data_buffer* buff) {
    input->data_buff = buff;
}

enum ErrType window_full_setup_fullscreen(struct data_buffer* input) {
    if(!input)
        return ERR_PTR;

    struct window window = window_create_empty();
    window_load_data_buffer(&window, input);
    const struct dimension screen_size = window_screen_size();
    window_load_curses(&window, newwin(screen_size.y, screen_size.x, 0, 0));

    window_add(window);

    return ERR_NONE;
}

void window_kill(struct window* input) {
    delwin(input->window);
}

void window_draw(struct window* input, size_t index) {
    wclear(input->window);
    wattrset(input->window, A_NORMAL);

    data_callback_behaviours(input->data_buff);

    if(input->data_buff->remark_size) {
        size_t pos = 0;

        for(size_t i = 0; i < (input->data_buff->remark_size); i++) {
            if(input->data_buff->remark_stack[i].pos >= 
                    input->data_buff->buffer.size)
                break; //Should throw an error

            if(input->data_buff->remark_stack[i].pos > pos) {
                waddnstr(input->window, &input->data_buff->buffer.text[pos], 
                        input->data_buff->remark_stack[i].pos - pos);
                pos = input->data_buff->remark_stack[i].pos;
            }
            else if(input->data_buff->remark_stack[i].pos < pos)
                continue; //Should throw an error (maybe)

            switch(input->data_buff->remark_stack[i].type) {
                case RESET:
                    wattrset(input->window, A_NORMAL);
                    break;
                case COLOR:
                    if(has_colors())
                        init_pair(i + 1 + index, (unsigned short)
                                input->data_buff->remark_stack[i].data,
                                (unsigned short)
                                (input->data_buff->remark_stack[i].data
                                 >> 16));
                    wcolor_set(input->window, i + 1 + index, 0);
                    break;
                case FONT:
                    wattrset(input->window, 
                            input->data_buff->remark_stack[i].data);
                    break;
            }
        }

        waddstr(input->window, &input->data_buff->buffer.text[pos]);
    }
    else
        waddstr(input->window, input->data_buff->buffer.text);

    wrefresh(input->window);
}
