/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */
#include <config.h>
#include "output/spv/tlo-parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "libpspp/str.h"
#include "gl/xalloc.h"

bool
tlo_parse_table_look (struct spvbin_input *input, struct tlo_table_look **p_)
{
    *p_ = NULL;
    struct tlo_table_look *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!tlo_parse_p_t_table_look (input, &p->tl))
        goto error;
    if (!tlo_parse_p_v_separator_style (input, &p->ss))
        goto error;
    if (!tlo_parse_p_v_cell_style (input, &p->cs))
        goto error;
    if (!tlo_parse_p_v_text_style (input, &p->ts))
        goto error;
    do {
        struct spvbin_position pos = spvbin_position_save (input);
        size_t save_n_errors = input->n_errors;
        if (!tlo_parse_v2_styles (input, &p->v2_styles))
            goto backtrack;
        break;

    backtrack:
        spvbin_position_restore (&pos, input);
        input->n_errors = save_n_errors;
        break;
    } while (0);

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "TableLook", p->start);
    tlo_free_table_look (p);
    return false;
}

void
tlo_free_table_look (struct tlo_table_look *p)
{
    if (p == NULL)
        return;

    tlo_free_p_t_table_look (p->tl);
    tlo_free_p_v_separator_style (p->ss);
    tlo_free_p_v_cell_style (p->cs);
    tlo_free_p_v_text_style (p->ts);
    tlo_free_v2_styles (p->v2_styles);
    free (p);
}

void
tlo_print_table_look (const char *title, int indent, const struct tlo_table_look *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');

    tlo_print_p_t_table_look ("tl", indent + 1, p->tl);

    tlo_print_p_v_separator_style ("ss", indent + 1, p->ss);

    tlo_print_p_v_cell_style ("cs", indent + 1, p->cs);

    tlo_print_p_v_text_style ("ts", indent + 1, p->ts);

    tlo_print_v2_styles ("v2_styles", indent + 1, p->v2_styles);
}

bool
tlo_parse_p_t_table_look (struct spvbin_input *input, struct tlo_p_t_table_look **p_)
{
    *p_ = NULL;
    struct tlo_p_t_table_look *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\xff\xff\x00\x00\x0b\x00\x50\x54\x54\x61\x62\x6c\x65\x4c\x6f\x6f\x6b", 17))
        goto error;
    do {
        struct spvbin_position pos = spvbin_position_save (input);
        size_t save_n_errors = input->n_errors;
        if (!spvbin_match_bytes (input, "\x00", 1))
            goto backtrack;
        break;

    backtrack:
        spvbin_position_restore (&pos, input);
        input->n_errors = save_n_errors;
        if (!spvbin_match_bytes (input, "\x02", 1))
            goto error;
        break;
    } while (0);
    if (!spvbin_parse_int16 (input, &p->flags))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00", 2))
        goto error;
    if (!spvbin_parse_bool (input, &p->nested_row_labels))
        goto error;
    if (!spvbin_match_bytes (input, "\x00", 1))
        goto error;
    if (!spvbin_parse_bool (input, &p->footnote_marker_subscripts))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x36\x00\x00\x00\x12\x00\x00\x00", 9))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "PTTableLook", p->start);
    tlo_free_p_t_table_look (p);
    return false;
}

void
tlo_free_p_t_table_look (struct tlo_p_t_table_look *p)
{
    if (p == NULL)
        return;

    free (p);
}

void
tlo_print_p_t_table_look (const char *title, int indent, const struct tlo_p_t_table_look *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');



    spvbin_print_int16 ("flags", indent + 1, p->flags);


    spvbin_print_bool ("nested-row-labels", indent + 1, p->nested_row_labels);


    spvbin_print_bool ("footnote-marker-subscripts", indent + 1, p->footnote_marker_subscripts);

}

bool
tlo_parse_p_v_separator_style (struct spvbin_input *input, struct tlo_p_v_separator_style **p_)
{
    *p_ = NULL;
    struct tlo_p_v_separator_style *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\xff\xff\x00\x00\x10\x00\x50\x56\x53\x65\x70\x61\x72\x61\x74\x6f\x72\x53\x74\x79\x6c\x65\x00", 23))
        goto error;
    for (int i = 0; i < 4; i++)
        if (!tlo_parse_separator (input, &p->sep1[i]))
            goto error;
    if (!spvbin_match_bytes (input, "\x03\x80\x00", 3))
        goto error;
    for (int i2 = 0; i2 < 4; i2++)
        if (!tlo_parse_separator (input, &p->sep2[i2]))
            goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "PVSeparatorStyle", p->start);
    tlo_free_p_v_separator_style (p);
    return false;
}

void
tlo_free_p_v_separator_style (struct tlo_p_v_separator_style *p)
{
    if (p == NULL)
        return;

    for (int i = 0; i < 4; i++)
        tlo_free_separator (p->sep1[i]);
    for (int i2 = 0; i2 < 4; i2++)
        tlo_free_separator (p->sep2[i2]);
    free (p);
}

void
tlo_print_p_v_separator_style (const char *title, int indent, const struct tlo_p_v_separator_style *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');


    for (int i = 0; i < 4; i++) {
        char *elem_name = xasprintf ("sep1[%d]", i);
        tlo_print_separator (elem_name, indent + 1, p->sep1[i]);
        free (elem_name);
    }


    for (int i2 = 0; i2 < 4; i2++) {
        char *elem_name2 = xasprintf ("sep2[%d]", i2);
        tlo_print_separator (elem_name2, indent + 1, p->sep2[i2]);
        free (elem_name2);
    }
}

bool
tlo_parse_separator (struct spvbin_input *input, struct tlo_separator **p_)
{
    *p_ = NULL;
    struct tlo_separator *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (spvbin_match_byte (input, 0x00)) {
        p->type = 0x00;

        if (!spvbin_match_bytes (input, "\x00", 1))
            goto error;
    } else if (spvbin_match_byte (input, 0x01)) {
        p->type = 0x01;

        if (!spvbin_match_bytes (input, "\x00", 1))
            goto error;
        if (!spvbin_parse_int32 (input, &p->type_01.color))
            goto error;
        if (!spvbin_parse_int16 (input, &p->type_01.style))
            goto error;
        if (!spvbin_parse_int16 (input, &p->type_01.width))
            goto error;
    }

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "Separator", p->start);
    tlo_free_separator (p);
    return false;
}

void
tlo_free_separator (struct tlo_separator *p)
{
    if (p == NULL)
        return;

    if (p->type == 0x00) {
    } else if (p->type == 0x01) {
    }
    free (p);
}

void
tlo_print_separator (const char *title, int indent, const struct tlo_separator *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');

    spvbin_print_case ("type", indent + 1, p->type);
    if (p->type == 0x00) {

    } else if (p->type == 0x01) {


        spvbin_print_int32 ("color", indent + 1, p->type_01.color);

        spvbin_print_int16 ("style", indent + 1, p->type_01.style);

        spvbin_print_int16 ("width", indent + 1, p->type_01.width);
    }
}

bool
tlo_parse_p_v_cell_style (struct spvbin_input *input, struct tlo_p_v_cell_style **p_)
{
    *p_ = NULL;
    struct tlo_p_v_cell_style *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\xff\xff\x00\x00\x0b\x00\x50\x56\x43\x65\x6c\x6c\x53\x74\x79\x6c\x65", 17))
        goto error;
    if (!tlo_parse_area_color (input, &p->title_color))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "PVCellStyle", p->start);
    tlo_free_p_v_cell_style (p);
    return false;
}

void
tlo_free_p_v_cell_style (struct tlo_p_v_cell_style *p)
{
    if (p == NULL)
        return;

    tlo_free_area_color (p->title_color);
    free (p);
}

void
tlo_print_p_v_cell_style (const char *title, int indent, const struct tlo_p_v_cell_style *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');


    tlo_print_area_color ("title-color", indent + 1, p->title_color);
}

bool
tlo_parse_p_v_text_style (struct spvbin_input *input, struct tlo_p_v_text_style **p_)
{
    *p_ = NULL;
    struct tlo_p_v_text_style *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\xff\xff\x00\x00\x0b\x00\x50\x56\x54\x65\x78\x74\x53\x74\x79\x6c\x65\x00", 18))
        goto error;
    if (!tlo_parse_area_style (input, &p->title_style))
        goto error;
    for (int i = 0; i < 7; i++)
        if (!tlo_parse_most_areas (input, &p->most_areas[i]))
            goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "PVTextStyle", p->start);
    tlo_free_p_v_text_style (p);
    return false;
}

void
tlo_free_p_v_text_style (struct tlo_p_v_text_style *p)
{
    if (p == NULL)
        return;

    tlo_free_area_style (p->title_style);
    for (int i = 0; i < 7; i++)
        tlo_free_most_areas (p->most_areas[i]);
    free (p);
}

void
tlo_print_p_v_text_style (const char *title, int indent, const struct tlo_p_v_text_style *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');


    tlo_print_area_style ("title-style", indent + 1, p->title_style);

    for (int i = 0; i < 7; i++) {
        char *elem_name = xasprintf ("most-areas[%d]", i);
        tlo_print_most_areas (elem_name, indent + 1, p->most_areas[i]);
        free (elem_name);
    }
}

bool
tlo_parse_most_areas (struct spvbin_input *input, struct tlo_most_areas **p_)
{
    *p_ = NULL;
    struct tlo_most_areas *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\x06\x80", 2))
        goto error;
    if (!tlo_parse_area_color (input, &p->color))
        goto error;
    if (!spvbin_match_bytes (input, "\x08\x80\x00", 3))
        goto error;
    if (!tlo_parse_area_style (input, &p->style))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "MostAreas", p->start);
    tlo_free_most_areas (p);
    return false;
}

void
tlo_free_most_areas (struct tlo_most_areas *p)
{
    if (p == NULL)
        return;

    tlo_free_area_color (p->color);
    tlo_free_area_style (p->style);
    free (p);
}

void
tlo_print_most_areas (const char *title, int indent, const struct tlo_most_areas *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');


    tlo_print_area_color ("color", indent + 1, p->color);


    tlo_print_area_style ("style", indent + 1, p->style);
}

bool
tlo_parse_area_color (struct spvbin_input *input, struct tlo_area_color **p_)
{
    *p_ = NULL;
    struct tlo_area_color *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_match_bytes (input, "\x00\x01\x00", 3))
        goto error;
    if (!spvbin_parse_int32 (input, &p->color10))
        goto error;
    if (!spvbin_parse_int32 (input, &p->color0))
        goto error;
    if (!spvbin_parse_byte (input, &p->shading))
        goto error;
    if (!spvbin_match_bytes (input, "\x00", 1))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "AreaColor", p->start);
    tlo_free_area_color (p);
    return false;
}

void
tlo_free_area_color (struct tlo_area_color *p)
{
    if (p == NULL)
        return;

    free (p);
}

void
tlo_print_area_color (const char *title, int indent, const struct tlo_area_color *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');


    spvbin_print_int32 ("color10", indent + 1, p->color10);

    spvbin_print_int32 ("color0", indent + 1, p->color0);

    spvbin_print_byte ("shading", indent + 1, p->shading);

}

bool
tlo_parse_area_style (struct spvbin_input *input, struct tlo_area_style **p_)
{
    *p_ = NULL;
    struct tlo_area_style *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    if (!spvbin_parse_int16 (input, &p->valign))
        goto error;
    if (!spvbin_parse_int16 (input, &p->halign))
        goto error;
    if (!spvbin_parse_int16 (input, &p->decimal_offset))
        goto error;
    if (!spvbin_parse_int16 (input, &p->left_margin))
        goto error;
    if (!spvbin_parse_int16 (input, &p->right_margin))
        goto error;
    if (!spvbin_parse_int16 (input, &p->top_margin))
        goto error;
    if (!spvbin_parse_int16 (input, &p->bottom_margin))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00\x01\x00", 4))
        goto error;
    if (!spvbin_parse_int32 (input, &p->font_size))
        goto error;
    if (!spvbin_parse_int16 (input, &p->stretch))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00", 2))
        goto error;
    if (!spvbin_parse_int32 (input, &p->rotation_angle))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00\x00\x00", 4))
        goto error;
    if (!spvbin_parse_int16 (input, &p->weight))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00", 2))
        goto error;
    if (!spvbin_parse_bool (input, &p->italic))
        goto error;
    if (!spvbin_parse_bool (input, &p->underline))
        goto error;
    if (!spvbin_parse_bool (input, &p->strikethrough))
        goto error;
    if (!spvbin_parse_int32 (input, &p->rtf_charset_number))
        goto error;
    if (!spvbin_parse_byte (input, &p->x))
        goto error;
    if (!spvbin_parse_byte (input, &p->font_name_len))
        goto error;
    p->font_name = xcalloc (p->font_name_len, sizeof *p->font_name);
    for (int i = 0; i < p->font_name_len; i++)
        if (!spvbin_parse_byte (input, &p->font_name[i]))
            goto error;
    if (!spvbin_parse_int32 (input, &p->text_color))
        goto error;
    if (!spvbin_match_bytes (input, "\x00\x00", 2))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "AreaStyle", p->start);
    tlo_free_area_style (p);
    return false;
}

void
tlo_free_area_style (struct tlo_area_style *p)
{
    if (p == NULL)
        return;

    free (p->font_name);
    free (p);
}

void
tlo_print_area_style (const char *title, int indent, const struct tlo_area_style *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');

    spvbin_print_int16 ("valign", indent + 1, p->valign);

    spvbin_print_int16 ("halign", indent + 1, p->halign);

    spvbin_print_int16 ("decimal-offset", indent + 1, p->decimal_offset);

    spvbin_print_int16 ("left-margin", indent + 1, p->left_margin);

    spvbin_print_int16 ("right-margin", indent + 1, p->right_margin);

    spvbin_print_int16 ("top-margin", indent + 1, p->top_margin);

    spvbin_print_int16 ("bottom-margin", indent + 1, p->bottom_margin);


    spvbin_print_int32 ("font-size", indent + 1, p->font_size);

    spvbin_print_int16 ("stretch", indent + 1, p->stretch);


    spvbin_print_int32 ("rotation-angle", indent + 1, p->rotation_angle);


    spvbin_print_int16 ("weight", indent + 1, p->weight);


    spvbin_print_bool ("italic", indent + 1, p->italic);

    spvbin_print_bool ("underline", indent + 1, p->underline);

    spvbin_print_bool ("strikethrough", indent + 1, p->strikethrough);

    spvbin_print_int32 ("rtf-charset-number", indent + 1, p->rtf_charset_number);

    spvbin_print_byte ("x", indent + 1, p->x);

    spvbin_print_byte ("font-name-len", indent + 1, p->font_name_len);

    for (int i = 0; i < p->font_name_len; i++) {
        char *elem_name = xasprintf ("font-name[%d]", i);
        spvbin_print_byte (elem_name, indent + 1, p->font_name[i]);
        free (elem_name);
    }

    spvbin_print_int32 ("text-color", indent + 1, p->text_color);

}

bool
tlo_parse_v2_styles (struct spvbin_input *input, struct tlo_v2_styles **p_)
{
    *p_ = NULL;
    struct tlo_v2_styles *p = xzalloc (sizeof *p);
    p->start = input->ofs;

    for (int i = 0; i < 11; i++)
        if (!tlo_parse_separator (input, &p->sep3[i]))
            goto error;
    if (!spvbin_parse_byte (input, &p->continuation_len))
        goto error;
    p->continuation = xcalloc (p->continuation_len, sizeof *p->continuation);
    for (int i2 = 0; i2 < p->continuation_len; i2++)
        if (!spvbin_parse_byte (input, &p->continuation[i2]))
            goto error;
    if (!spvbin_parse_int32 (input, &p->min_col_heading_width))
        goto error;
    if (!spvbin_parse_int32 (input, &p->max_col_heading_width))
        goto error;
    if (!spvbin_parse_int32 (input, &p->min_row_heading_width))
        goto error;
    if (!spvbin_parse_int32 (input, &p->max_row_heading_width))
        goto error;

    p->len = input->ofs - p->start;
    *p_ = p;
    return true;

error:
    spvbin_error (input, "V2Styles", p->start);
    tlo_free_v2_styles (p);
    return false;
}

void
tlo_free_v2_styles (struct tlo_v2_styles *p)
{
    if (p == NULL)
        return;

    for (int i = 0; i < 11; i++)
        tlo_free_separator (p->sep3[i]);
    free (p->continuation);
    free (p);
}

void
tlo_print_v2_styles (const char *title, int indent, const struct tlo_v2_styles *p)
{
    spvbin_print_header (title, p ? p->start : -1, p ? p->len : -1, indent);
    if (p == NULL) {
        printf ("none\n");
        return;
    }
    putchar ('\n');

    for (int i = 0; i < 11; i++) {
        char *elem_name = xasprintf ("sep3[%d]", i);
        tlo_print_separator (elem_name, indent + 1, p->sep3[i]);
        free (elem_name);
    }

    spvbin_print_byte ("continuation-len", indent + 1, p->continuation_len);

    for (int i2 = 0; i2 < p->continuation_len; i2++) {
        char *elem_name2 = xasprintf ("continuation[%d]", i2);
        spvbin_print_byte (elem_name2, indent + 1, p->continuation[i2]);
        free (elem_name2);
    }

    spvbin_print_int32 ("min-col-heading-width", indent + 1, p->min_col_heading_width);

    spvbin_print_int32 ("max-col-heading-width", indent + 1, p->max_col_heading_width);

    spvbin_print_int32 ("min-row-heading-width", indent + 1, p->min_row_heading_width);

    spvbin_print_int32 ("max-row-heading-width", indent + 1, p->max_row_heading_width);
}
