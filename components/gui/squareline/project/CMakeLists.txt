SET(SOURCES screens/ui_Home_Scr.c
    screens/ui_CasinoScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_tesla_png.c
    images/ui_img_arc_big_2_png.c
    images/ui_img_arc_mid_2_png.c
    images/ui_img_arc_small_2_png.c
    images/ui_img_wood_3_bg_png.c
    images/ui_img_card_back_png.c
    images/ui_img_spin_scroll_png.c
    fonts/ui_font_PizzaFont.c
    fonts/ui_font_PizzaFontSmall.c)

add_library(ui ${SOURCES})
