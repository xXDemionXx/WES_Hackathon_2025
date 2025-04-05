SET(SOURCES screens/ui_Home_Scr.c
    screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_queue.c)

add_library(ui ${SOURCES})
