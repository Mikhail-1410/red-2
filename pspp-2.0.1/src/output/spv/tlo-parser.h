/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */
#ifndef TLO_PARSER_H
#define TLO_PARSER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "output/spv/spvbin-helpers.h"

struct tlo_table_look {
    size_t start, len;
    struct tlo_p_t_table_look *tl;
    struct tlo_p_v_separator_style *ss;
    struct tlo_p_v_cell_style *cs;
    struct tlo_p_v_text_style *ts;
    struct tlo_v2_styles *v2_styles;
};
bool tlo_parse_table_look (struct spvbin_input *, struct tlo_table_look **);
void tlo_free_table_look (struct tlo_table_look *);
void tlo_print_table_look (const char *title, int indent, const struct tlo_table_look *);

struct tlo_p_t_table_look {
    size_t start, len;
    uint16_t flags;
    bool nested_row_labels;
    bool footnote_marker_subscripts;
};
bool tlo_parse_p_t_table_look (struct spvbin_input *, struct tlo_p_t_table_look **);
void tlo_free_p_t_table_look (struct tlo_p_t_table_look *);
void tlo_print_p_t_table_look (const char *title, int indent, const struct tlo_p_t_table_look *);

struct tlo_p_v_separator_style {
    size_t start, len;
    struct tlo_separator *sep1[4];
    struct tlo_separator *sep2[4];
};
bool tlo_parse_p_v_separator_style (struct spvbin_input *, struct tlo_p_v_separator_style **);
void tlo_free_p_v_separator_style (struct tlo_p_v_separator_style *);
void tlo_print_p_v_separator_style (const char *title, int indent, const struct tlo_p_v_separator_style *);

struct tlo_separator {
    size_t start, len;
    int type;
    union {
        struct {
        } type_00;
        struct {
            uint32_t color;
            uint16_t style;
            uint16_t width;
        } type_01;
    };
};
bool tlo_parse_separator (struct spvbin_input *, struct tlo_separator **);
void tlo_free_separator (struct tlo_separator *);
void tlo_print_separator (const char *title, int indent, const struct tlo_separator *);

struct tlo_p_v_cell_style {
    size_t start, len;
    struct tlo_area_color *title_color;
};
bool tlo_parse_p_v_cell_style (struct spvbin_input *, struct tlo_p_v_cell_style **);
void tlo_free_p_v_cell_style (struct tlo_p_v_cell_style *);
void tlo_print_p_v_cell_style (const char *title, int indent, const struct tlo_p_v_cell_style *);

struct tlo_p_v_text_style {
    size_t start, len;
    struct tlo_area_style *title_style;
    struct tlo_most_areas *most_areas[7];
};
bool tlo_parse_p_v_text_style (struct spvbin_input *, struct tlo_p_v_text_style **);
void tlo_free_p_v_text_style (struct tlo_p_v_text_style *);
void tlo_print_p_v_text_style (const char *title, int indent, const struct tlo_p_v_text_style *);

struct tlo_most_areas {
    size_t start, len;
    struct tlo_area_color *color;
    struct tlo_area_style *style;
};
bool tlo_parse_most_areas (struct spvbin_input *, struct tlo_most_areas **);
void tlo_free_most_areas (struct tlo_most_areas *);
void tlo_print_most_areas (const char *title, int indent, const struct tlo_most_areas *);

struct tlo_area_color {
    size_t start, len;
    uint32_t color10;
    uint32_t color0;
    uint8_t shading;
};
bool tlo_parse_area_color (struct spvbin_input *, struct tlo_area_color **);
void tlo_free_area_color (struct tlo_area_color *);
void tlo_print_area_color (const char *title, int indent, const struct tlo_area_color *);

struct tlo_area_style {
    size_t start, len;
    uint16_t valign;
    uint16_t halign;
    uint16_t decimal_offset;
    uint16_t left_margin;
    uint16_t right_margin;
    uint16_t top_margin;
    uint16_t bottom_margin;
    uint32_t font_size;
    uint16_t stretch;
    uint32_t rotation_angle;
    uint16_t weight;
    bool italic;
    bool underline;
    bool strikethrough;
    uint32_t rtf_charset_number;
    uint8_t x;
    uint8_t font_name_len;
    uint8_t *font_name;
    uint32_t text_color;
};
bool tlo_parse_area_style (struct spvbin_input *, struct tlo_area_style **);
void tlo_free_area_style (struct tlo_area_style *);
void tlo_print_area_style (const char *title, int indent, const struct tlo_area_style *);

struct tlo_v2_styles {
    size_t start, len;
    struct tlo_separator *sep3[11];
    uint8_t continuation_len;
    uint8_t *continuation;
    uint32_t min_col_heading_width;
    uint32_t max_col_heading_width;
    uint32_t min_row_heading_width;
    uint32_t max_row_heading_width;
};
bool tlo_parse_v2_styles (struct spvbin_input *, struct tlo_v2_styles **);
void tlo_free_v2_styles (struct tlo_v2_styles *);
void tlo_print_v2_styles (const char *title, int indent, const struct tlo_v2_styles *);

#endif /* TLO_PARSER_H */
