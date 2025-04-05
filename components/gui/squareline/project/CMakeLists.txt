SET(SOURCES screens/ui_Home_Scr.c
    screens/ui_StocksScreen.c
    screens/ui_CasinoScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_tesla_png.c
    images/ui_img_arc_big_png.c
    images/ui_img_arc_mid_png.c
    images/ui_img_arc_small_png.c
    fonts/ui_font_Font1.c
    fonts/ui_font_FontStocks.c
    
    ui_queue.c
    )

add_library(ui ${SOURCES})
